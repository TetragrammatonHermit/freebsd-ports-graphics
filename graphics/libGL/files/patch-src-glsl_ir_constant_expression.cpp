--- src/glsl/ir_constant_expression.cpp.orgi	2011-03-10 18:30:39.000000000 +0800
+++ src/glsl/ir_constant_expression.cpp	2011-03-10 18:31:19.000000000 +0800
@@ -39,6 +39,11 @@
 #include "ir_visitor.h"
 #include "glsl_types.h"
 
+#include <sys/param.h>
+#if __FreeBSD_version <= 704100 || (__FreeBSD_version >= 800000 && __FreeBSD_version < 802502) || (__FreeBSD_version >= 900000 && __FreeBSD_version < 900027)
+#define log2(x) (log(x) / log(2))
+#endif
+
 static float
 dot(ir_constant *op0, ir_constant *op1)
 {
