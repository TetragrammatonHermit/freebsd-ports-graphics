--- src/freeglut_joystick.c.orig	2011-09-28 03:37:26.000000000 +0200
+++ src/freeglut_joystick.c	2012-01-30 20:25:02.000000000 +0100
@@ -80,11 +80,13 @@
 #        include <string.h>
 #    endif
 #    if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__)
+#        include <osreldate.h>
 /* XXX The below hack is done until freeglut's autoconf is updated. */
 #        define HAVE_USB_JS    1
 
 #        if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
 #            include <sys/joystick.h>
+#            include <dev/usb/usb_ioctl.h>
 #        else
 /*
  * XXX NetBSD/amd64 systems may find that they have to steal the
@@ -152,7 +154,7 @@
 #                include <libusbhid.h>
 #            endif
 #        endif
-#        include <legacy/dev/usb/usb.h>
+#        include <dev/usb/usb.h>
 #        include <dev/usb/usbhid.h>
 
 /* Compatibility with older usb.h revisions */
@@ -199,7 +201,7 @@
  */
 static char *fghJoystickWalkUSBdev(int f, char *dev, char *out, int outlen)
 {
-  struct usb_device_info di;
+/*  struct usb_device_info di;
   int i, a;
   char *cp;
 
@@ -220,6 +222,7 @@
         return out;
       }
   }
+  */
   return NULL;
 }
 
