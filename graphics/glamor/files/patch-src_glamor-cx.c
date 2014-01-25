--- src/glamor_xv.c.orig	2014-01-25 15:26:43.000000000 +0100
+++ src/glamor_xv.c	2014-01-25 15:28:17.000000000 +0100
@@ -35,9 +35,11 @@
 #include "glamor_priv.h"
 
 #ifdef GLAMOR_XV
+#include "damage.h"
 #include "xf86xv.h"
 #include <X11/extensions/Xv.h>
 #include "fourcc.h"
+
 /* Reference color space transform data */
 typedef struct tagREF_TRANSFORM
 {
