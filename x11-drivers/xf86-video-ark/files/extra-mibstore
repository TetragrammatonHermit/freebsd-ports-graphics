--- src/ark_driver.c.orig	2013-06-24 00:00:22.000000000 +0200
+++ src/ark_driver.c	2013-06-24 00:02:22.000000000 +0200
@@ -39,7 +39,6 @@
 #include "compiler.h"
 #include "mipointer.h"
 #include "micmap.h"
-#include "mibstore.h"
 #include "fb.h"
 #include "ark.h"
 
@@ -538,7 +537,6 @@
 
 	fbPictureInit (pScreen, 0, 0);
 
-	miInitializeBackingStore(pScreen);
 	xf86SetBackingStore(pScreen);
 
 	if (!pARK->NoAccel) {
