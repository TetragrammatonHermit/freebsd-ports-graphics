--- ./src/mesa/main/compiler.h.orig	2014-01-31 21:44:08.000000000 +0100
+++ ./src/mesa/main/compiler.h	2014-02-15 21:11:34.000000000 +0100
@@ -162,6 +162,9 @@
 #if defined(__linux__)
 #include <byteswap.h>
 #define CPU_TO_LE32( x )	bswap_32( x )
+#elif defined(__FreeBSD__)
+#include <sys/endian.h>
+#define CPU_TO_LE32( x )	bswap32( x )
 #elif defined(__APPLE__)
 #include <CoreFoundation/CFByteOrder.h>
 #define CPU_TO_LE32( x )	CFSwapInt32HostToLittle( x )
