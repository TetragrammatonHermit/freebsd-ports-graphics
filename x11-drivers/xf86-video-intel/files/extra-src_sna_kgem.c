--- src/sna/kgem.c.orig	2013-07-14 10:05:25.000000000 +0200
+++ src/sna/kgem.c	2013-07-17 15:53:23.800554823 +0200
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
@@ -1831,7 +1871,8 @@
 static struct kgem_bo *
 search_snoop_cache(struct kgem *kgem, unsigned int num_pages, unsigned flags)
 {
-	struct kgem_bo *bo, *first = NULL;
+	struct kgem_bo *bo = NULL;
+	struct kgem_bo *first = NULL;
 
 	DBG(("%s: num_pages=%d, flags=%x\n", __FUNCTION__, num_pages, flags));
 
@@ -2044,7 +2085,8 @@
 
 static bool kgem_retire__flushing(struct kgem *kgem)
 {
-	struct kgem_bo *bo, *next;
+	struct kgem_bo *bo = NULL;
+	struct kgem_bo *next;
 	bool retired = false;
 
 	list_for_each_entry_safe(bo, next, &kgem->flushing, request) {
@@ -2249,7 +2291,8 @@
 static void kgem_commit(struct kgem *kgem)
 {
 	struct kgem_request *rq = kgem->next_request;
-	struct kgem_bo *bo, *next;
+	struct kgem_bo *bo = NULL;
+	struct kgem_bo *next;
 
 	list_for_each_entry_safe(bo, next, &rq->buffers, request) {
 		assert(next->request.prev == &bo->request);
@@ -2330,7 +2373,8 @@
 
 static void kgem_finish_buffers(struct kgem *kgem)
 {
-	struct kgem_buffer *bo, *next;
+	struct kgem_buffer *bo = NULL;
+	struct kgem_buffer *next;
 
 	list_for_each_entry_safe(bo, next, &kgem->batch_buffers, base.list) {
 		DBG(("%s: buffer handle=%d, used=%d, exec?=%d, write=%d, mmapped=%s\n",
@@ -3191,7 +3235,8 @@
 static struct kgem_bo *
 search_linear_cache(struct kgem *kgem, unsigned int num_pages, unsigned flags)
 {
-	struct kgem_bo *bo, *first = NULL;
+	struct kgem_bo *bo = NULL;
+	struct kgem_bo *first = NULL;
 	bool use_active = (flags & CREATE_INACTIVE) == 0;
 	struct list *cache;
 
@@ -3795,7 +3840,7 @@
 			       uint32_t flags)
 {
 	struct list *cache;
-	struct kgem_bo *bo;
+	struct kgem_bo *bo = NULL;
 	uint32_t pitch, tiled_height, size;
 	uint32_t handle;
 	int i, bucket, retry;
@@ -5243,7 +5288,7 @@
 void kgem_clear_dirty(struct kgem *kgem)
 {
 	struct list * const buffers = &kgem->next_request->buffers;
-	struct kgem_bo *bo;
+	struct kgem_bo *bo = NULL;
 
 	list_for_each_entry(bo, buffers, request) {
 		if (!bo->gpu_dirty)
@@ -5519,7 +5564,7 @@
 				   uint32_t size, uint32_t flags,
 				   void **ret)
 {
-	struct kgem_buffer *bo;
+	struct kgem_buffer *bo = NULL;
 	unsigned offset, alloc;
 	struct kgem_bo *old;
 
@@ -5612,6 +5657,7 @@
 		alloc = ALIGN(size, kgem->buffer_size);
 	if (alloc > MAX_CACHE_SIZE)
 		alloc = PAGE_ALIGN(size);
+	assert(alloc);
 
 	if (alloc > kgem->aperture_mappable / 4)
 		flags &= ~KGEM_BUFFER_INPLACE;
