Fix ivb (ivybridge) gt1 systems
https://bugs.freedesktop.org/show_bug.cgi?id=52382
http://cgit.freedesktop.org/mesa/mesa/commit/?id=fbf86c7f0f1f12e52b927e3870535073879d0a4d

--- src/mesa/drivers/dri/i965/brw_context.c.orig	2012-09-25 08:49:02.000000000 +0000
+++ src/mesa/drivers/dri/i965/brw_context.c	2012-09-25 08:49:33.000000000 +0000
@@ -240,7 +240,7 @@
    /* WM maximum threads is number of EUs times number of threads per EU. */
    if (intel->gen >= 7) {
       if (intel->gt == 1) {
-	 brw->max_wm_threads = 86;
+	 brw->max_wm_threads = 48;
 	 brw->max_vs_threads = 36;
 	 brw->max_gs_threads = 36;
 	 brw->urb.size = 128;
