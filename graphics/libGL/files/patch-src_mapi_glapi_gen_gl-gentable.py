--- src/mapi/glapi/gen/gl_gentable.py.orig	2013-11-19 22:05:23.000000000 +0100
+++ src/mapi/glapi/gen/gl_gentable.py	2013-11-19 22:06:41.000000000 +0100
@@ -42,7 +42,7 @@
 #endif
 
 #if (defined(GLXEXT) && defined(HAVE_BACKTRACE)) \\
-	|| (!defined(GLXEXT) && defined(DEBUG) && !defined(_WIN32_WCE) && !defined(__CYGWIN__) && !defined(__MINGW32__) && !defined(__OpenBSD__) && !defined(__NetBSD__))
+	|| (!defined(GLXEXT) && defined(DEBUG) && !defined(_WIN32_WCE) && !defined(__CYGWIN__) && !defined(__MINGW32__) && !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__FreeBSD__))
 #define USE_BACKTRACE
 #endif
 
