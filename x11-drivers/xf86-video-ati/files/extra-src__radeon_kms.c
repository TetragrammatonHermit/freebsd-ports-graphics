--- src/radeon_kms.c.orig	2013-08-30 17:34:45.402399526 +0200
+++ src/radeon_kms.c	2013-08-30 17:36:31.138391972 +0200
@@ -606,7 +606,7 @@
 		      dev->domain, dev->bus, dev->dev, dev->func);
 #endif
 
-    info->dri2.drm_fd = drmOpen("radeon", busid);
+    info->dri2.drm_fd = drmOpen("radeonkms", busid);
     if (info->dri2.drm_fd == -1) {
 
 	xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
