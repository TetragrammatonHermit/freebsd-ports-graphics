--- ./src/mouse.h.orig	2011-06-25 07:24:41.000000000 +0200
+++ ./src/mouse.h	2012-03-02 14:02:43.000000000 +0100
@@ -217,10 +217,12 @@
     Bool		emulate3ButtonsSoft;
     int			emulate3Timeout;/* Timeout for 3 button emulation */
     Bool		chordMiddle;
+    Bool		disableXY;
     Bool                flipXY;
     int                 invX;
     int                 invY;
     int			resolution;
+    Bool		hasZ, hasW;
     int			negativeZ;	/* button mask */
     int			positiveZ;	/* button mask */
     int			negativeW;	/* button mask */
@@ -259,6 +261,8 @@
     int			doubleClickOldSourceState;
     int			lastMappedButtons;
     int			buttonMap[MSE_MAXBUTTONS];
+    float		fracdx,fracdy;
+    float		sensitivity;
 } MouseDevRec, *MouseDevPtr;
 
 #endif /* _XF86OSMOUSE_H_ */
