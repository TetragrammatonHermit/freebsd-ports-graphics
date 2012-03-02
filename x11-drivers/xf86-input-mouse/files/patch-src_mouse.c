--- ./src/mouse.c.orig	2011-06-25 07:26:47.000000000 +0200
+++ ./src/mouse.c	2012-03-02 14:02:43.000000000 +0100
@@ -271,13 +271,39 @@
 
     pMse = pInfo->private;
 
-    pMse->buttons = xf86SetIntOption(pInfo->options, "Buttons", 0);
+    i = xf86SetIntOption(pInfo->options, "Buttons", 0);
+    if (i != 0)
+	pMse->buttons = i;
     if (!pMse->buttons) {
 	pMse->buttons = MSE_DFLTBUTTONS;
 	buttons_from = X_DEFAULT;
     }
     origButtons = pMse->buttons;
 
+    s = xf86SetStrOption(pInfo->options, "ButtonMapping", NULL);
+    if (s) {
+       int b, n = 0;
+       char *s1 = s;
+       /* keep getting numbers which are buttons */
+       while (s1 && n < MSE_MAXBUTTONS && (b = strtol(s1, &s1, 10)) != 0) {
+	   /* check sanity for a button */
+	   if (b < 0 || b > MSE_MAXBUTTONS) {
+	       xf86Msg(X_WARNING,
+		       "ButtonMapping: Invalid button number = %d\n", b);
+	       break;
+	   };
+	   pMse->buttonMap[n++] = 1 << (b-1);
+	   if (b > pMse->buttons) pMse->buttons = b;
+       }
+       free(s);
+    }
+    /* get maximum of mapped buttons */
+    for (i = pMse->buttons-1; i >= 0; i--) {
+	int f = ffs (pMse->buttonMap[i]);
+	if (f > pMse->buttons)
+	    pMse->buttons = f;
+    }
+
     pMse->emulate3Buttons = xf86SetBoolOption(pInfo->options,
 					      "Emulate3Buttons", FALSE);
     if (!xf86FindOptionValue(pInfo->options,"Emulate3Buttons")) {
@@ -289,6 +315,8 @@
 					     "Emulate3Timeout", 50);
     if (pMse->emulate3Buttons || pMse->emulate3ButtonsSoft) {
 	MessageType from = X_CONFIG;
+	if (pMse->buttons < 3)
+	    pMse->buttons = 3;
 	if (pMse->emulate3ButtonsSoft)
 	    from = X_DEFAULT;
 	xf86Msg(from, "%s: Emulate3Buttons, Emulate3Timeout: %d\n",
@@ -296,6 +324,8 @@
     }
 
     pMse->chordMiddle = xf86SetBoolOption(pInfo->options, "ChordMiddle", FALSE);
+    if (pMse->chordMiddle && pMse->buttons < 3)
+	    pMse->buttons = 3;
     pMse->flipXY = xf86SetBoolOption(pInfo->options, "FlipXY", FALSE);
     if (xf86SetBoolOption(pInfo->options, "InvX", FALSE)) {
 	pMse->invX = -1;
@@ -306,7 +336,7 @@
     } else
 	pMse->invY = 1;
     pMse->angleOffset = xf86SetIntOption(pInfo->options, "AngleOffset", 0);
-    
+    pMse->sensitivity = xf86SetRealOption(pInfo->options, "Sensitivity", 1.0);
 
     if (pMse->pDragLock)
 	free(pMse->pDragLock);
@@ -416,14 +446,17 @@
 	free(s);
     }
 
-    s = xf86SetStrOption(pInfo->options, "ZAxisMapping", "4 5");
+    s = xf86SetStrOption(pInfo->options, "ZAxisMapping",
+	pMse->hasZ ? ( pMse->hasW ? "4 5 6 7" : "4 5" ) : "off");
     if (s) {
 	int b1 = 0, b2 = 0, b3 = 0, b4 = 0;
 	char *msg = NULL;
 
 	pMse->negativeZ = pMse->positiveZ = MSE_NOAXISMAP;
 	pMse->negativeW = pMse->positiveW = MSE_NOAXISMAP;
-	if (!xf86NameCmp(s, "x")) {
+	if (!xf86NameCmp(s, "off")) {
+	    msg = xstrdup("off");
+	} else if (!xf86NameCmp(s, "x")) {
 	    pMse->negativeZ = pMse->positiveZ = MSE_MAPTOX;
 	    msg = xstrdup("X axis");
 	} else if (!xf86NameCmp(s, "y")) {
@@ -559,29 +592,6 @@
 		pInfo->name, wheelButton, pMse->wheelInertia,
 		pMse->wheelButtonTimeout);
     }
-    s = xf86SetStrOption(pInfo->options, "ButtonMapping", NULL);
-    if (s) {
-       int b, n = 0;
-       char *s1 = s;
-       /* keep getting numbers which are buttons */
-       while (s1 && n < MSE_MAXBUTTONS && (b = strtol(s1, &s1, 10)) != 0) {
-	   /* check sanity for a button */
-	   if (b < 0 || b > MSE_MAXBUTTONS) {
-	       xf86Msg(X_WARNING,
-		       "ButtonMapping: Invalid button number = %d\n", b);
-	       break;
-	   };
-	   pMse->buttonMap[n++] = 1 << (b-1);
-	   if (b > pMse->buttons) pMse->buttons = b;
-       }
-       free(s);
-    }
-    /* get maximum of mapped buttons */
-    for (i = pMse->buttons-1; i >= 0; i--) {
-	int f = ffs (pMse->buttonMap[i]);
-	if (f > pMse->buttons)
-	    pMse->buttons = f;
-    }
     if (origButtons != pMse->buttons)
 	buttons_from = X_CONFIG;
     xf86Msg(buttons_from, "%s: Buttons: %d\n", pInfo->name, pMse->buttons);
@@ -659,7 +669,6 @@
     }
     pMse->sampleRate = xf86SetIntOption(pInfo->options, "SampleRate", 0);
     pMse->resolution = xf86SetIntOption(pInfo->options, "Resolution", 0);
-    mPriv->sensitivity = xf86SetRealOption(pInfo->options, "Sensitivity", 1.0);
 }
 
 static void
@@ -948,6 +957,8 @@
     /* Default Mapping: 1 2 3 8 9 10 11 ... */
     for (i = 0; i < MSE_MAXBUTTONS; i++)
 	pMse->buttonMap[i] = 1 << (i > 2 && i < MSE_MAXBUTTONS-4 ? i+4 : i);
+    pMse->hasZ = 1;
+    pMse->hasW = 0;
 
     protocol = MousePickProtocol(pInfo, device, protocol, &protocolID);
 
@@ -2085,6 +2096,9 @@
 			}
 		    }
 		}
+	    } else {
+		pMse->wheelXDistance = 0;
+		pMse->wheelYDistance = 0;
 	    }
 
 	    /* Absorb the mouse movement while the wheel button is pressed. */
@@ -2102,7 +2116,7 @@
     if (pMse->emulate3ButtonsSoft && pMse->emulate3Pending && (dx || dy))
 	buttonTimer(pInfo);
 
-    if (dx || dy)
+    if ((dx || dy) && !pMse->disableXY)
 	xf86PostMotionEvent(pInfo->dev, 0, 0, 2, dx, dy);
 
     if (change) {
@@ -2312,13 +2326,13 @@
 
     /* Accumulate the scaled dx, dy in the private variables 
        fracdx,fracdy and return the integer number part */
-    if (mousepriv) {
-	mousepriv->fracdx += mousepriv->sensitivity*dx;
-	mousepriv->fracdy += mousepriv->sensitivity*dy;
-	mousepriv->fracdx -= ( dx=(int)(mousepriv->fracdx) );
-	mousepriv->fracdy -= ( dy=(int)(mousepriv->fracdy) );
+    if (pMse->sensitivity != 0) {
+	pMse->fracdx += pMse->sensitivity*dx;
+	pMse->fracdy += pMse->sensitivity*dy;
+	pMse->fracdx -= ( dx=(int)(pMse->fracdx) );
+	pMse->fracdy -= ( dy=(int)(pMse->fracdy) );
     }
-    
+
     /* If mouse wheel movement has to be mapped on a button, we need to
      * loop for button press and release events. */
     do {
