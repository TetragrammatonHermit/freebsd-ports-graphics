Temparly patch to fix symbol conflict between libXi and libXfixes.
http://lists.x.org/archives/xorg-devel/2013-March/035729.html

diff --git a/include/X11/extensions/XInput2.h b/include/X11/extensions/XInput2.h
index a746012..8de4aeb 100644
--- include/X11/extensions/XInput2.h
+++ include/X11/extensions/XInput2.h
@@ -169,7 +169,11 @@ typedef struct
     int                 status;
 } XIGrabModifiers;
 
+/* Xfixes.h typedefs PointerBarrier and gcc pre-4.6 (or with -pedantic) will
+   complain about the duplicate typedef */
+#if !defined _XFIXES_H_ || XFIXES_MAJOR < 5
 typedef XID PointerBarrier;
+#endif
 typedef unsigned int BarrierEventID;
 
 typedef struct
