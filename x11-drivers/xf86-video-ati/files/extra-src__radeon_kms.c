--- src/radeon_kms.c.orig	2013-03-02 12:22:34.000000000 +0100
+++ src/radeon_kms.c	2013-03-02 12:26:26.000000000 +0100
@@ -564,7 +564,7 @@
 		      dev->domain, dev->bus, dev->dev, dev->func);
 #endif
 
-    info->dri2.drm_fd = drmOpen("radeon", busid);
+    info->dri2.drm_fd = drmOpen("radeonkms", busid);
     if (info->dri2.drm_fd == -1) {
 
 	xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
