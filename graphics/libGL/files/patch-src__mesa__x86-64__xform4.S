--- src/mesa/x86-64/xform4.S.orig	2011-07-17 12:42:15.000000000 +0200
+++ src/mesa/x86-64/xform4.S	2011-07-17 12:42:35.000000000 +0200
@@ -118,7 +118,7 @@ p4_constants:
 .byte  0x00, 0x00, 0x00, 0x00
 .byte  0x00, 0x00, 0x00, 0x00
 .byte  0x00, 0x00, 0x00, 0x00
-.float 0f+1.0
+.float 1.0
 
 .text
 .align 16
