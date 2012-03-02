From 3715cd752bac912a56aa1cbb9dd874624a709aab Mon Sep 17 00:00:00 2001
From: Alan Coopersmith <alan.coopersmith@oracle.com>
Date: Sun, 02 Oct 2011 16:16:05 +0000
Subject: Add const attributes to fix gcc -Wwrite-strings warnings

Signed-off-by: Alan Coopersmith <alan.coopersmith@oracle.com>
Reviewed-by: Jeremy Huddleston <jeremyhu@apple.com>
---
(limited to 'include/X11/fonts/fontmisc.h')

diff --git a/include/X11/fonts/fontmisc.h b/include/X11/fonts/fontmisc.h
index 3da1e63..73a8247 100644
--- include/X11/fonts/fontmisc.h
+++ include/X11/fonts/fontmisc.h
@@ -52,7 +52,7 @@ in this Software without prior written authorization from The Open Group.
 #define FALSE 0
 #endif
 
-extern Atom MakeAtom ( char *string, unsigned len, int makeit );
+extern Atom MakeAtom ( const char *string, unsigned len, int makeit );
 extern int ValidAtom ( Atom atom );
 extern char *NameForAtom (Atom atom);
 
--
cgit v0.9.0.2-2-gbebe
