--- ./src/glx/dri3_common.c.orig	2014-02-03 18:42:39.000000000 +0100
+++ ./src/glx/dri3_common.c	2014-02-15 21:11:55.000000000 +0100
@@ -74,8 +74,14 @@
 #define DRIVER_MAP_DRI3_ONLY
 #include "pci_ids/pci_id_driver_map.h"
 
+#if defined(HAVE_LIBUDEV)
 #include <libudev.h>
+#elif defined(HAVE_LIBDEVQ)
+#include <libdevq.h>
+#include <stdlib.h>
+#endif
 
+#if defined(HAVE_LIBUDEV)
 static struct udev_device *
 dri3_udev_device_new_from_fd(struct udev *udev, int fd)
 {
@@ -95,14 +101,17 @@
 
    return device;
 }
+#endif /* defined(HAVE_LIBUDEV) */
 
 char *
 dri3_get_driver_for_fd(int fd)
 {
+   char *driver = NULL;
+
+#if defined(HAVE_LIBUDEV)
    struct udev *udev;
    struct udev_device *device, *parent;
    const char *pci_id;
-   char *driver = NULL;
    int vendor_id, chip_id, i, j;
 
    udev = udev_new();
@@ -141,6 +150,25 @@
 out:
    udev_device_unref(device);
    udev_unref(udev);
+#elif defined(HAVE_LIBDEVQ)
+   int ret;
+   size_t driver_len;
+
+   ret = devq_device_drm_get_drvname_from_fd(fd,
+       NULL, &driver_len);
+   if (ret < 0)
+      return (NULL);
+
+   driver = malloc(driver_len + 1);
+   ret = devq_device_drm_get_drvname_from_fd(fd,
+       driver, &driver_len);
+   if (ret < 0) {
+      free(driver);
+      return (NULL);
+   }
+
+   driver[driver_len] = '\0';
+#endif
 
    return driver;
 }
