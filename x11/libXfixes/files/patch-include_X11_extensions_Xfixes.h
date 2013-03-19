Temparly patch to fix symbol conflict between libXi and libXfixes.
http://lists.x.org/archives/xorg-devel/2013-March/035729.html
This is needed because Xi header might be included before the Xfixes header

--- include/X11/extensions/Xfixes.h.orig	2013-03-19 12:07:49.000000000 +0000
+++ include/X11/extensions/Xfixes.h	2013-03-19 12:09:51.000000000 +0000
@@ -252,7 +252,9 @@
 
 #if XFIXES_MAJOR >= 5
 
+#if !defined _XINPUT2_H_
 typedef XID PointerBarrier;
+#endif
 
 PointerBarrier
 XFixesCreatePointerBarrier(Display *dpy, Window w, int x1, int y1,
