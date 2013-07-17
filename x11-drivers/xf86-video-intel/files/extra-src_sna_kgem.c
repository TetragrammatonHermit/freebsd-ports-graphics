--- src/sna/kgem.c.orig	2013-07-17 15:16:33.145697556 +0200
+++ src/sna/kgem.c	2013-07-17 15:22:43.826678496 +0200
@@ -38,7 +38,9 @@
 #include <time.h>
 #include <errno.h>
 #include <fcntl.h>
+#ifdef __linux__
 #include <cpuid.h>
+#endif
 
 #include <xf86drm.h>
 
@@ -697,8 +699,9 @@
 	return 0;
 }
 
+#ifdef __linux__
 static unsigned
-cpu_cache_size(void)
+cpu_cache_size__cpuid4(void)
 {
 	/* Deterministic Cache Parmaeters (Function 04h)":
 	 *    When EAX is initialized to a value of 4, the CPUID instruction
@@ -739,6 +742,42 @@
 
 	 return llc_size;
 }
+#endif /* __linux__ */
+
+static unsigned
+cpu_cache_size(void)
+{
+	unsigned size;
+#ifdef __linux__
+	FILE *file;
+
+	size = cpu_cache_size__cpuid4();
+	if (size)
+		return size;
+
+	file = fopen("/proc/cpuinfo", "r");
+	if (file) {
+		size_t len = 0;
+		char *line = NULL;
+		while (getline(&line, &len, file) != -1) {
+			int kb;
+			if (sscanf(line, "cache size : %d KB", &kb) == 1) {
+				/* Paranoid check against gargantuan caches */
+				if (kb <= 1<<20)
+					size = kb * 1024;
+				break;
+			}
+		}
+		free(line);
+		fclose(file);
+	}
+
+	if (size == 0)
+#endif /* __linux__ */
+		size = 64 * 1024;
+
+	return size;
+}
 
 static int gem_param(struct kgem *kgem, int name)
 {
@@ -1242,6 +1281,7 @@
 		kgem->buffer_size = kgem->half_cpu_cache_pages << 12;
 	DBG(("%s: buffer size=%d [%d KiB]\n", __FUNCTION__,
 	     kgem->buffer_size, kgem->buffer_size / 1024));
+	assert(kgem->buffer_size);
 
 	kgem->max_object_size = 3 * (kgem->aperture_high >> 12) << 10;
 	kgem->max_gpu_size = kgem->max_object_size;
@@ -5617,6 +5657,7 @@
 		alloc = ALIGN(size, kgem->buffer_size);
 	if (alloc > MAX_CACHE_SIZE)
 		alloc = PAGE_ALIGN(size);
+	assert(alloc);
 
 	if (alloc > kgem->aperture_mappable / 4)
 		flags &= ~KGEM_BUFFER_INPLACE;
