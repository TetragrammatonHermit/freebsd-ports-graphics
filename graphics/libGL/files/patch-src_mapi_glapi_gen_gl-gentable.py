--- src/mapi/glapi/gen/gl_gentable.py.orig	2013-08-14 03:34:42.000000000 +0200
+++ src/mapi/glapi/gen/gl_gentable.py	2013-08-20 18:03:41.000000000 +0200
@@ -42,7 +42,7 @@
 #endif
 
 #if (defined(GLXEXT) && defined(HAVE_BACKTRACE)) \\
-	|| (!defined(GLXEXT) && defined(DEBUG) && !defined(_WIN32_WCE) && !defined(__CYGWIN__) && !defined(__MINGW32__) && !defined(__OpenBSD__))
+	|| (!defined(GLXEXT) && defined(DEBUG) && !defined(_WIN32_WCE) && !defined(__CYGWIN__) && !defined(__MINGW32__) && !defined(__OpenBSD__) && !defined(__FreeBSD__))
 #define USE_BACKTRACE
 #endif
 
