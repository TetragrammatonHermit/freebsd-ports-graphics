--- ./imakemdep.h.orig	2012-03-08 06:47:32.000000000 +0100
+++ ./imakemdep.h	2013-06-12 13:41:33.446657735 +0200
@@ -312,7 +312,7 @@
 #   if defined(__386BSD__)
 #    define DEFAULT_CPP "/usr/libexec/cpp"
 #   endif
-#   if defined(__FreeBSD__)  || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
+#   if defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
 #    define USE_CC_E
 #   endif
 #   if defined(__sgi) && defined(__ANSI_CPP__)
@@ -345,6 +345,9 @@
 #     define DEFAULT_CC "gcc"
 #    endif
 #   endif
+#   if defined(__FreeBSD__)
+#   undef USE_CC_E
+#   endif
 
 #  endif /* !defined (CROSSCOMPILE) || defined (CROSSCOMPILE_CPP) */
 /*
