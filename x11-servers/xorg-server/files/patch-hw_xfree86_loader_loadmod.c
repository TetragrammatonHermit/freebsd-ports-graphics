--- hw/xfree86/loader/loadmod.c.orig	2013-12-12 20:57:34.332434430 +0100
+++ hw/xfree86/loader/loadmod.c	2013-12-12 20:57:50.132421416 +0100
@@ -490,7 +490,7 @@
     char **elem;
     const char **subdirs;
     const char **s;
-    PatternPtr patterns;
+    PatternPtr patterns = NULL;
     PatternPtr p;
     DIR *d;
     struct dirent *dp;
