--- src/gallium/drivers/radeonsi/r600_buffer.c.orig	2013-02-26 21:00:02.000000000 +0100
+++ src/gallium/drivers/radeonsi/r600_buffer.c	2013-06-26 23:34:06.000000000 +0200
@@ -24,7 +24,13 @@
  *      Jerome Glisse
  *      Corbin Simpson <MostAwesomeDude@gmail.com>
  */
+
+#if defined(__linux__)
 #include <byteswap.h>
+#elif defined(__FreeBSD__)
+#include <sys/endian.h>
+#defined bswap_32(x)	bswap32((x))
+#endif
 
 #include "pipe/p_screen.h"
 #include "util/u_format.h"
