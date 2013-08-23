--- src/wayland-os.c.orig	2013-01-23 23:25:21.000000000 +0100
+++ src/wayland-os.c	2013-08-20 12:19:38.000000000 +0200
@@ -22,14 +22,21 @@
 
 #define _GNU_SOURCE
 
+#include "../config.h"
+
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <errno.h>
+#ifdef HAVE_SYS_EPOLL_H
 #include <sys/epoll.h>
+#endif
+#ifdef HAVE_SYS_EVENT_H
+#include <sys/types.h>
+#include <sys/event.h>
+#endif
 
-#include "../config.h"
 #include "wayland-os.h"
 
 static int
@@ -59,26 +66,51 @@
 {
 	int fd;
 
+#ifdef SOCK_CLOEXEC
 	fd = socket(domain, type | SOCK_CLOEXEC, protocol);
 	if (fd >= 0)
 		return fd;
 	if (errno != EINVAL)
 		return -1;
 
+#endif
+
 	fd = socket(domain, type, protocol);
 	return set_cloexec_or_close(fd);
 }
 
 int
+wl_os_socketpair_cloexec(int domain, int type, int protocol, int sv[2])
+{
+	int retval;
+
+#ifdef SOCK_CLOEXEC
+	retval = socketpair(domain, type | SOCK_CLOEXEC, protocol, sv);
+	if (retval >= 0)
+		return retval;
+	if (errno != EINVAL)
+		return -1;
+#endif
+
+	retval = socketpair(domain, type, protocol, sv);
+	if (set_cloexec_or_close(sv[0]) < 0 || set_cloexec_or_close(sv[1]) < 0)
+		retval = -1;
+
+	return retval;
+}
+
+int
 wl_os_dupfd_cloexec(int fd, long minfd)
 {
 	int newfd;
 
+#ifdef F_DUPFD_CLOEXEC
 	newfd = fcntl(fd, F_DUPFD_CLOEXEC, minfd);
 	if (newfd >= 0)
 		return newfd;
 	if (errno != EINVAL)
 		return -1;
+#endif
 
 	newfd = fcntl(fd, F_DUPFD, minfd);
 	return set_cloexec_or_close(newfd);
@@ -118,6 +150,7 @@
 ssize_t
 wl_os_recvmsg_cloexec(int sockfd, struct msghdr *msg, int flags)
 {
+#ifdef MSG_CMSG_CLOEXEC
 	ssize_t len;
 
 	len = recvmsg(sockfd, msg, flags | MSG_CMSG_CLOEXEC);
@@ -125,10 +158,12 @@
 		return len;
 	if (errno != EINVAL)
 		return -1;
+#endif
 
 	return recvmsg_cloexec_fallback(sockfd, msg, flags);
 }
 
+#ifdef HAVE_SYS_EPOLL_H
 int
 wl_os_epoll_create_cloexec(void)
 {
@@ -145,6 +180,19 @@
 	fd = epoll_create(1);
 	return set_cloexec_or_close(fd);
 }
+#endif
+
+#ifdef HAVE_SYS_EVENT_H
+int
+wl_os_kqueue_create_cloexec(void)
+{
+	int fd;
+
+	fd = kqueue();
+
+	return set_cloexec_or_close(fd);
+}
+#endif
 
 int
 wl_os_accept_cloexec(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
