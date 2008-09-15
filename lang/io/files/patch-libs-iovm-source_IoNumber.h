--- libs/iovm/source/IoNumber.h.orgi	2008-09-15 19:23:19.000000000 +0200
+++ libs/iovm/source/IoNumber.h	2008-09-15 19:23:41.000000000 +0200
@@ -19,9 +19,8 @@
 #define IONUMBER(num) IoState_numberWithDouble_((IoState*)IOSTATE, (double)num)
 #define CNUMBER(self) IoObject_dataDouble((IoNumber *)self)
 
-#ifdef WIN32
 #define log2(num) log(num) / log(2)
-#endif
+
 
 typedef IoObject IoNumber;
 
