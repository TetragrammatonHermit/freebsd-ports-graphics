--- src/xshmfence_futex.h.orig	2013-11-20 17:13:08.000000000 -0500
+++ src/xshmfence_futex.h	2013-12-04 14:06:21.000000000 -0500
@@ -1,5 +1,6 @@
 /*
  * Copyright © 2013 Keith Packard
+ * Copyright © 2013 Jung-uk Kim <jkim@FreeBSD.org>
  *
  * Permission to use, copy, modify, distribute, and sell this software and its
  * documentation for any purpose is hereby granted without fee, provided that
@@ -24,37 +25,59 @@
 #define _XSHMFENCE_FUTEX_H_
 
 #include <errno.h>
+
+#ifdef __FreeBSD__
+
+#include <sys/types.h>
+#include <sys/umtx.h>
+
+typedef u_long futex_t;
+
+static inline int futex_wake(futex_t *addr) {
+	return umtx_wake(addr, INT_MAX);
+}
+
+static inline int futex_wait(futex_t *addr, futex_t value) {
+	return umtx_wait(addr, value, NULL);
+}
+
+#else
+
 #include <stdint.h>
 #include <values.h>
 #include <linux/futex.h>
 #include <sys/time.h>
 #include <sys/syscall.h>
 
+typedef int32_t futex_t;
+
 static inline long sys_futex(void *addr1, int op, int val1, struct timespec *timeout, void *addr2, int val3)
 {
 	return syscall(SYS_futex, addr1, op, val1, timeout, addr2, val3);
 }
 
-static inline int futex_wake(int32_t *addr) {
+static inline int futex_wake(futex_t *addr) {
 	return sys_futex(addr, FUTEX_WAKE, MAXINT, NULL, NULL, 0);
 }
 
-static inline int futex_wait(int32_t *addr, int32_t value) {
+static inline int futex_wait(futex_t *addr, futex_t value) {
 	return sys_futex(addr, FUTEX_WAIT, value, NULL, NULL, 0);
 }
 
+#endif
+
 #define barrier() __asm__ __volatile__("": : :"memory")
 
-static inline void atomic_store(int32_t *f, int32_t v)
+static inline void atomic_store(futex_t *f, futex_t v)
 {
 	barrier();
 	*f = v;
 	barrier();
 }
 
-static inline int32_t atomic_fetch(int32_t *a)
+static inline futex_t atomic_fetch(futex_t *a)
 {
-	int32_t v;
+	futex_t v;
 	barrier();
 	v = *a;
 	barrier();
@@ -62,7 +85,7 @@
 }
 	
 struct xshmfence {
-    int32_t     v;
+	futex_t v;
 };
 
 #define xshmfence_init(fd)
