--- ./src/mousePriv.h.orig	2009-10-16 23:40:45.000000000 +0200
+++ ./src/mousePriv.h	2012-03-02 14:02:43.000000000 +0100
@@ -63,8 +63,6 @@
     int		acc;
     CARD32	pnpLast;
     Bool	disablePnPauto;
-    float	fracdx,fracdy; 
-    float	sensitivity;
 } mousePrivRec, *mousePrivPtr;
 
 /* mouse proto flags */
