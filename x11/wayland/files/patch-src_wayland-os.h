--- src/wayland-os.h.orig	2013-01-23 23:25:21.000000000 +0100
+++ src/wayland-os.h	2013-08-20 12:20:50.000000000 +0200
@@ -27,13 +27,23 @@
 wl_os_socket_cloexec(int domain, int type, int protocol);
 
 int
+wl_os_socketpair_cloexec(int domain, int type, int protocol, int sv[2]);
+
+int
 wl_os_dupfd_cloexec(int fd, long minfd);
 
 ssize_t
 wl_os_recvmsg_cloexec(int sockfd, struct msghdr *msg, int flags);
 
+#ifdef HAVE_SYS_EPOLL_H
 int
 wl_os_epoll_create_cloexec(void);
+#endif
+
+#ifdef HAVE_SYS_EVENT_H
+int
+wl_os_kqueue_create_cloexec(void);
+#endif
 
 int
 wl_os_accept_cloexec(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
