--- ./src/loader/loader.c.orig	2014-02-05 21:59:10.000000000 +0100
+++ ./src/loader/loader.c	2014-02-23 22:01:50.000000000 +0100
@@ -202,6 +202,24 @@
    return (*chip_id >= 0);
 }
 
+#elif defined(HAVE_LIBDEVQ)
+#include <libdevq.h>
+
+int
+loader_get_pci_id_for_fd(int fd, int *vendor_id, int *chip_id)
+{
+   int ret;
+
+   *chip_id = -1;
+
+   ret = devq_device_get_pciid_from_fd(fd, vendor_id, chip_id);
+   if (ret < 0)
+      goto out;
+
+out:
+   return (*chip_id >= 0);
+}
+
 #elif defined(ANDROID) && !defined(__NOT_HAVE_DRM_H)
 
 /* for i915 */
