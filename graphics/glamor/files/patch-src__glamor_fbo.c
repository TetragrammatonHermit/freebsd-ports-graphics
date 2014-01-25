--- src/glamor_fbo.c.orig	2014-01-25 21:56:30.893669151 +0100
+++ src/glamor_fbo.c	2014-01-25 21:57:02.604665024 +0100
@@ -72,7 +72,8 @@
 			    int w, int h, GLenum format, int flag)
 {
 	struct xorg_list *cache;
-	glamor_pixmap_fbo *fbo_entry, *ret_fbo = NULL;
+	glamor_pixmap_fbo *fbo_entry = NULL;
+	glamor_pixmap_fbo *ret_fbo = NULL;
 	int n_format;
 #ifdef NO_FBO_CACHE
 	return NULL;
