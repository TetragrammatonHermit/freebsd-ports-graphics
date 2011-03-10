--- src/glsl/lower_jumps.cpp.orig	2011-03-10 18:40:52.000000000 +0800
+++ src/glsl/lower_jumps.cpp	2011-03-10 18:41:18.000000000 +0800
@@ -66,7 +66,7 @@
    strength_always_clears_execute_flag,
    strength_continue,
    strength_break,
-   strength_return,
+   strength_return
 };
 
 struct block_record
