--- src/s3_driver.c.orig	2013-06-24 13:49:10.000000000 +0200
+++ src/s3_driver.c	2013-06-24 13:50:16.000000000 +0200
@@ -52,7 +52,6 @@
 #include "compiler.h"
 #include "mipointer.h"
 #include "micmap.h"
-#include "mibstore.h"
 #include "fb.h"
 #include "inputstr.h"
 #include "shadowfb.h"
@@ -822,7 +821,6 @@
 	fbPictureInit (pScreen, 0, 0);
 	S3DGAInit(pScreen);
 
-        miInitializeBackingStore(pScreen);
         xf86SetBackingStore(pScreen);
 
 	/* framebuffer manager setup */
