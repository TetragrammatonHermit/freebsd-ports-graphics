--- tests/queue-test.c.orig	2013-07-10 01:15:29.000000000 +0200
+++ tests/queue-test.c	2013-08-20 12:26:12.000000000 +0200
@@ -20,6 +20,8 @@
  * OF THIS SOFTWARE.
  */
 
+#include "../config.h"
+
 #include <stdlib.h>
 #include <stdio.h>
 #include <stdbool.h>
@@ -27,6 +29,9 @@
 #include <sys/types.h>
 #include <sys/wait.h>
 #include <assert.h>
+#ifdef HAVE_SIGNAL_H
+#include <signal.h>
+#endif
 
 #include "wayland-client.h"
 #include "wayland-server.h"
@@ -81,7 +86,7 @@ client_test_proxy_destroy(void)
 	registry = wl_display_get_registry(display);
 	wl_registry_add_listener(registry, &registry_listener,
 				 &counter);
-	wl_display_roundtrip(display);
+	client_assert(wl_display_roundtrip(display) > -1);
 
 	client_assert(counter == 1);
 
