--- ./src/gallium/winsys/svga/drm/vmw_screen_ioctl.c.orig	2014-01-31 21:40:50.000000000 +0100
+++ ./src/gallium/winsys/svga/drm/vmw_screen_ioctl.c	2014-02-15 21:11:34.000000000 +0100
@@ -66,6 +66,13 @@
  */
 #define SVGA3D_SURFACE_HINT_SCANOUT (1 << 9)
 
+#if defined(__DragonFly__) || \
+    defined(__FreeBSD__) ||   \
+    defined(__NetBSD__) ||    \
+    defined(__OpenBSD__)
+#define	ERESTART EINTR
+#endif
+
 uint32
 vmw_ioctl_context_create(struct vmw_winsys_screen *vws)
 {
