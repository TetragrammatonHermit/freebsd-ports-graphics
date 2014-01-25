--- src/radeon_kms.c.orig	2013-12-24 21:13:42.000000000 +0100
+++ src/radeon_kms.c	2014-01-25 15:48:21.000000000 +0100
@@ -270,7 +270,7 @@
 radeon_dirty_update(ScreenPtr screen)
 {
 	RegionPtr region;
-	PixmapDirtyUpdatePtr ent;
+	PixmapDirtyUpdatePtr ent = NULL;
 
 	if (xorg_list_is_empty(&screen->pixmap_dirty_list))
 		return;
