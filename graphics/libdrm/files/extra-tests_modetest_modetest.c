--- tests/modetest/modetest.c.orig	2013-02-01 14:53:11.555562039 +0100
+++ tests/modetest/modetest.c	2013-02-01 15:05:06.400559742 +0100
@@ -159,6 +159,27 @@
 
 bit_name_fn(mode_flag)
 
+/*
+ * This is needed to make this build on FreeBSD, which lacks strchrnul().  This
+ * works for now, but if the usage of strchrnul() becomes more prevalent a
+ * better solution must be thought out.
+ * This implementation is
+ * Copyright (c) 2012-2013 Niclas Zeising
+ * All rights reserved
+ */
+static char *
+strchrnul(const char *p, int ch)
+{
+	char c;
+
+	c = ch;
+	for (;; ++p) {
+		if (*p == c || *p == '\0')
+			return ((char *)p);
+	}
+	/* NOTREACHED */
+}
+
 void dump_encoders(void)
 {
 	drmModeEncoder *encoder;
