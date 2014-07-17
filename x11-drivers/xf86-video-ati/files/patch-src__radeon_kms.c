--- src/radeon_kms.c.orig	2014-06-25 15:32:37.000000000 +0200
+++ src/radeon_kms.c	2014-07-17 20:22:53.688560483 +0200
@@ -30,6 +30,8 @@
 
 #include <errno.h>
 #include <sys/ioctl.h>
+#include <sys/param.h>
+#include <sys/linker.h>
 /* Driver data structures */
 #include "radeon.h"
 #include "radeon_reg.h"
@@ -597,7 +599,7 @@
     RADEONEntPtr pRADEONEnt = RADEONEntPriv(pScrn);
     struct pci_device *dev = info->PciInfo;
     char *busid;
-    int fd;
+    int err, fd;
 
 #ifdef XF86_PDEV_SERVER_FD
     if (pRADEONEnt->platform_dev) {
@@ -616,6 +618,16 @@
 		      dev->domain, dev->bus, dev->dev, dev->func);
 #endif
 
+    err = kldload("radeonkms");
+    if (err == -1 && errno != EEXIST) {
+
+	xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
+		   "[drm] Failed to load kernel module for %s: %s\n",
+		   busid, strerror(errno));
+	free(busid);
+	return FALSE;
+    }
+
     fd = drmOpen(NULL, busid);
     if (fd == -1)
 	xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
