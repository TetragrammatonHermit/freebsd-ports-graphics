--- src/wayland-server.c.orig	2013-07-09 22:56:13.000000000 +0200
+++ src/wayland-server.c	2013-08-20 13:19:05.000000000 +0200
@@ -22,6 +22,8 @@
 
 #define _GNU_SOURCE
 
+#include "../config.h"
+
 #include <stdlib.h>
 #include <stdint.h>
 #include <stddef.h>
@@ -41,6 +43,11 @@
 #include <sys/stat.h>
 #include <ffi.h>
 
+#ifdef HAVE_SYS_UCRED_H
+#include <sys/types.h>
+#include <sys/ucred.h>
+#endif
+
 #include "wayland-private.h"
 #include "wayland-server.h"
 #include "wayland-server-protocol.h"
@@ -75,7 +82,13 @@ struct wl_client {
 	struct wl_list link;
 	struct wl_map objects;
 	struct wl_signal destroy_signal;
-	struct ucred ucred;
+#ifdef HAVE_SYS_UCRED_H
+	/* FreeBSD. */
+	struct xucred xucred;
+#else
+	/* Linux. */
+ 	struct ucred ucred;
+#endif
 	int error;
 };
 
@@ -236,7 +249,7 @@ wl_client_connection_data(int fd, uint32
 	len = 0;
 	if (mask & WL_EVENT_READABLE) {
 		len = wl_connection_read(connection);
-		if (len < 0 && errno != EAGAIN) {
+		if (len <= 0 && errno != EAGAIN) {
 			wl_client_destroy(client);
 			return 1;
 		}
@@ -354,10 +367,20 @@ wl_client_create(struct wl_display *disp
 	if (!client->source)
 		goto err_client;
 
+#if defined(SO_PEERCRED)
+	/* Linux. */
 	len = sizeof client->ucred;
 	if (getsockopt(fd, SOL_SOCKET, SO_PEERCRED,
 		       &client->ucred, &len) < 0)
 		goto err_source;
+#elif defined(LOCAL_PEERCRED)
+	/* FreeBSD. */
+	len = sizeof client->xucred;
+	if (getsockopt(fd, SOL_SOCKET, LOCAL_PEERCRED, &client->xucred,
+	               &len) < 0 ||
+	    client->xucred.cr_version != XUCRED_VERSION)
+		goto err_source;
+#endif
 
 	client->connection = wl_connection_create(fd);
 	if (client->connection == NULL)
@@ -392,12 +415,23 @@ WL_EXPORT void
 wl_client_get_credentials(struct wl_client *client,
 			  pid_t *pid, uid_t *uid, gid_t *gid)
 {
+#ifdef HAVE_SYS_UCRED_H
+	/* FreeBSD. */
+	if (pid)
+		*pid = 0; /* FIXME: not defined on FreeBSD */
+	if (uid)
+		*uid = client->xucred.cr_uid;
+	if (gid)
+		*gid = client->xucred.cr_gid;
+#else
+	/* Linux. */
 	if (pid)
 		*pid = client->ucred.pid;
 	if (uid)
 		*uid = client->ucred.uid;
 	if (gid)
 		*gid = client->ucred.gid;
+#endif
 }
 
 WL_EXPORT struct wl_resource *
@@ -472,7 +506,7 @@ wl_resource_get_link(struct wl_resource 
 WL_EXPORT struct wl_resource *
 wl_resource_from_link(struct wl_list *link)
 {
-	struct wl_resource *resource;
+	struct wl_resource *resource = NULL;
 
 	return wl_container_of(link, resource, link);
 }
