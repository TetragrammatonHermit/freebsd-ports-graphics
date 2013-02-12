--- src/sna/compiler.h.orig	2013-02-02 00:01:23.000000000 +0000
+++ src/sna/compiler.h	2013-02-02 00:01:33.000000000 +0000
@@ -36,7 +36,6 @@
 #define fastcall __attribute__((regparm(3)))
 #define must_check __attribute__((warn_unused_result))
 #define constant __attribute__((const))
-#define __packed__ __attribute__((__packed__))
 #else
 #define likely(expr) (expr)
 #define unlikely(expr) (expr)
@@ -45,7 +44,6 @@
 #define fastcall
 #define must_check
 #define constant
-#define __packed__
 #endif
 
 #ifdef HAVE_VALGRIND
