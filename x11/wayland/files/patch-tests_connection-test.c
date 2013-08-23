--- tests/connection-test.c.orig	2013-08-20 11:17:58.000000000 +0200
+++ tests/connection-test.c	2013-08-20 11:19:22.000000000 +0200
@@ -32,6 +32,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 
+#include "wayland-os.h"
 #include "wayland-private.h"
 #include "test-runner.h"
 
@@ -42,7 +43,7 @@
 {
 	struct wl_connection *connection;
 
-	assert(socketpair(AF_UNIX, SOCK_STREAM | SOCK_CLOEXEC, 0, s) == 0);
+	assert(wl_os_socketpair_cloexec(AF_UNIX, SOCK_STREAM, 0, s) == 0);
 
 	connection = wl_connection_create(s[0]);
 	assert(connection);
@@ -136,8 +137,7 @@
 static void
 setup_marshal_data(struct marshal_data *data)
 {
-	assert(socketpair(AF_UNIX,
-			  SOCK_STREAM | SOCK_CLOEXEC, 0, data->s) == 0);
+	assert(wl_os_socketpair_cloexec(AF_UNIX, SOCK_STREAM, 0, data->s) == 0);
 	data->read_connection = wl_connection_create(data->s[0]);
 	assert(data->read_connection);
 	data->write_connection = wl_connection_create(data->s[1]);
