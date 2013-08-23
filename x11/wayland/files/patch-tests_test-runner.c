--- tests/test-runner.c.orig	2013-08-20 11:33:18.000000000 +0200
+++ tests/test-runner.c	2013-08-20 11:37:36.000000000 +0200
@@ -22,6 +22,12 @@
 
 #define _GNU_SOURCE
 
+#include "../config.h"
+
+#ifdef HAVE_SYS_PARAM_H
+#include <sys/param.h>
+#endif
+
 #include <unistd.h>
 #include <stdio.h>
 #include <stdlib.h>
@@ -34,15 +40,18 @@
 #include "test-runner.h"
 
 static int num_alloc;
+int leak_check_enabled;
+
+extern const struct test __start_test_section, __stop_test_section;
+
+/* This is all disabled for FreeBSD because it gives "can't allocate initial
+ * thread" aborts otherwise. */
+#ifndef __FreeBSD__
 static void* (*sys_malloc)(size_t);
 static void (*sys_free)(void*);
 static void* (*sys_realloc)(void*, size_t);
 static void* (*sys_calloc)(size_t, size_t);
 
-int leak_check_enabled;
-
-extern const struct test __start_test_section, __stop_test_section;
-
 __attribute__ ((visibility("default"))) void *
 malloc(size_t size)
 {
@@ -76,6 +85,7 @@ calloc(size_t nmemb, size_t size)
 
 	return sys_calloc(nmemb, size);
 }
+#endif /* !__FreeBSD__ */
 
 static const struct test *
 find_test(const char *name)
@@ -127,8 +137,13 @@ int main(int argc, char *argv[])
 	const struct test *t;
 	pid_t pid;
 	int total, pass;
+#ifdef HAVE_WAITID
 	siginfo_t info;
+#else /* if HAVE_WAITPID */
+	int status;
+#endif /* HAVE_WAITPID */
 
+#ifndef __FreeBSD__
 	/* Load system malloc, free, and realloc */
 	sys_calloc = dlsym(RTLD_NEXT, "calloc");
 	sys_realloc = dlsym(RTLD_NEXT, "realloc");
@@ -136,6 +151,10 @@ int main(int argc, char *argv[])
 	sys_free = dlsym(RTLD_NEXT, "free");
 
 	leak_check_enabled = !getenv("NO_ASSERT_LEAK_CHECK");
+#else /* if !__FreeBSD__ */
+	/* Disable leak checking on FreeBSD since we can't override malloc(). */
+	leak_check_enabled = 0;
+#endif /* __FreeBSD */
 
 	if (argc == 2 && strcmp(argv[1], "--help") == 0)
 		usage(argv[0], EXIT_SUCCESS);
@@ -160,6 +179,7 @@ int main(int argc, char *argv[])
 		if (pid == 0)
 			run_test(t); /* never returns */
 
+#ifdef HAVE_WAITID
 		if (waitid(P_ALL, 0, &info, WEXITED)) {
 			fprintf(stderr, "waitid failed: %m\n");
 			abort();
@@ -178,6 +198,23 @@ int main(int argc, char *argv[])
 			break;
 		}
 
+#else /* if HAVE_WAITPID */
+		if (waitpid(-1, &status, 0) == -1) {
+			fprintf(stderr, "waitpid failed: %s\n",
+			        strerror(errno));
+			abort();
+		}
+
+		fprintf(stderr, "test \"%s\":\t", t->name);
+		if (WIFEXITED(status)) {
+			fprintf(stderr, "exit status %d", WEXITSTATUS(status));
+			if (WEXITSTATUS(status) == EXIT_SUCCESS)
+				success = 1;
+		} else if (WIFSIGNALED(status)) {
+			fprintf(stderr, "signal %d", WTERMSIG(status));
+		}
+#endif /* HAVE_WAITPID */
+
 		if (t->must_fail)
 			success = !success;
 
