--- ./src/gallium/auxiliary/pipe-loader/pipe_loader_drm.c.orig	2014-01-23 18:02:42.000000000 +0100
+++ ./src/gallium/auxiliary/pipe-loader/pipe_loader_drm.c	2014-02-23 22:01:50.000000000 +0100
@@ -32,7 +32,11 @@
 
 #include <fcntl.h>
 #include <stdio.h>
+
+#if defined(HAVE_LIBUDEV)
 #include <libudev.h>
+#endif
+
 #include <xf86drm.h>
 
 #ifdef HAVE_PIPE_LOADER_XCB
