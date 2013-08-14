--- src/sna/compiler.h.orig	2013-08-01 21:00:51.000000000 +0200
+++ src/sna/compiler.h	2013-08-14 11:19:53.441221636 +0200
@@ -37,7 +37,6 @@
 #define must_check __attribute__((warn_unused_result))
 #define constant __attribute__((const))
 #define pure __attribute__((pure))
-#define __packed__ __attribute__((__packed__))
 #define flatten __attribute__((flatten))
 #define page_aligned __attribute__((aligned(4096)))
 #else
@@ -49,7 +48,6 @@
 #define must_check
 #define constant
 #define pure
-#define __packed__
 #define flatten
 #define page_aligned
 #endif
@@ -67,6 +65,8 @@
 
 #if HAS_GCC(4, 6) && defined(__OPTIMIZE__)
 #define fast __attribute__((optimize("Ofast")))
+#else
+#define fast
 #endif
 
 #if HAS_GCC(4, 6) && defined(__OPTIMIZE__)
