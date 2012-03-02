From 3715cd752bac912a56aa1cbb9dd874624a709aab Mon Sep 17 00:00:00 2001
From: Alan Coopersmith <alan.coopersmith@oracle.com>
Date: Sun, 02 Oct 2011 16:16:05 +0000
Subject: Add const attributes to fix gcc -Wwrite-strings warnings

Signed-off-by: Alan Coopersmith <alan.coopersmith@oracle.com>
Reviewed-by: Jeremy Huddleston <jeremyhu@apple.com>
---
(limited to 'src/util/atom.c')

--- src/util/atom.c.orig	2010-10-07 06:12:21.000000000 +0200
+++ src/util/atom.c	2012-03-02 12:09:16.000000000 +0100
@@ -54,7 +54,7 @@
 static Atom	    lastAtom;
 
 static int
-Hash(char *string, int len)
+Hash(const char *string, int len)
 {
     int	h;
 
@@ -147,7 +147,7 @@
 #endif
 
 weak Atom 
-MakeAtom(char *string, unsigned len, int makeit)
+MakeAtom(const char *string, unsigned len, int makeit)
 {
     AtomListPtr	a;
     int		hash;
