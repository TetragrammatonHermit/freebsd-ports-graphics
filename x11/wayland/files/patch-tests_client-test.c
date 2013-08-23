--- tests/client-test.c.orig	2013-08-20 11:15:42.000000000 +0200
+++ tests/client-test.c	2013-08-20 11:16:39.000000000 +0200
@@ -31,6 +31,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 
+#include "wayland-os.h"
 #include "wayland-private.h"
 #include "wayland-server.h"
 #include "test-runner.h"
@@ -56,7 +57,7 @@
 	struct client_destroy_listener a, b;
 	int s[2];
 
-	assert(socketpair(AF_UNIX, SOCK_STREAM | SOCK_CLOEXEC, 0, s) == 0);
+	assert(wl_os_socketpair_cloexec(AF_UNIX, SOCK_STREAM, 0, s) == 0);
 	display = wl_display_create();
 	assert(display);
 	client = wl_client_create(display, s[0]);
