--- src/sna/kgem.c.orig	2012-12-03 11:37:46.000000000 +0100
+++ src/sna/kgem.c	2012-12-11 20:48:26.000000000 +0100
@@ -624,7 +624,11 @@
 	if (file) {
 		size_t len = 0;
 		char *line = NULL;
+#ifdef __GLIBC__
 		while (getline(&line, &len, file) != -1) {
+#else
+		while ((line = fgetln(file, &len)) != (char *) NULL) {
+#endif
 			int mb;
 			if (sscanf(line, "cache size : %d KB", &mb) == 1) {
 				/* Paranoid check against gargantuan caches */
@@ -1474,7 +1478,8 @@
 static struct kgem_bo *
 search_snoop_cache(struct kgem *kgem, unsigned int num_pages, unsigned flags)
 {
-	struct kgem_bo *bo, *first = NULL;
+	struct kgem_bo *bo = NULL;
+	struct kgem_bo *first = NULL;
 
 	DBG(("%s: num_pages=%d, flags=%x\n", __FUNCTION__, num_pages, flags));
 
@@ -1699,7 +1704,8 @@
 
 static bool kgem_retire__flushing(struct kgem *kgem)
 {
-	struct kgem_bo *bo, *next;
+	struct kgem_bo *bo = NULL;
+	struct kgem_bo *next;
 	bool retired = false;
 
 	list_for_each_entry_safe(bo, next, &kgem->flushing, request) {
@@ -1916,7 +1922,8 @@
 static void kgem_commit(struct kgem *kgem)
 {
 	struct kgem_request *rq = kgem->next_request;
-	struct kgem_bo *bo, *next;
+	struct kgem_bo *bo = NULL;
+	struct kgem_bo *next;
 
 	list_for_each_entry_safe(bo, next, &rq->buffers, request) {
 		assert(next->request.prev == &bo->request);
@@ -1995,7 +2002,8 @@
 
 static void kgem_finish_buffers(struct kgem *kgem)
 {
-	struct kgem_buffer *bo, *next;
+	struct kgem_buffer *bo = NULL;
+	struct kgem_buffer *next;
 
 	list_for_each_entry_safe(bo, next, &kgem->batch_buffers, base.list) {
 		DBG(("%s: buffer handle=%d, used=%d, exec?=%d, write=%d, mmapped=%d\n",
@@ -2678,7 +2686,8 @@
 static struct kgem_bo *
 search_linear_cache(struct kgem *kgem, unsigned int num_pages, unsigned flags)
 {
-	struct kgem_bo *bo, *first = NULL;
+	struct kgem_bo *bo = NULL;
+	struct kgem_bo *first = NULL;
 	bool use_active = (flags & CREATE_INACTIVE) == 0;
 	struct list *cache;
 
@@ -3167,7 +3176,7 @@
 			       uint32_t flags)
 {
 	struct list *cache;
-	struct kgem_bo *bo;
+	struct kgem_bo *bo = NULL;
 	uint32_t pitch, untiled_pitch, tiled_height, size;
 	uint32_t handle;
 	int i, bucket, retry;
@@ -4360,7 +4369,7 @@
 void kgem_clear_dirty(struct kgem *kgem)
 {
 	struct list * const buffers = &kgem->next_request->buffers;
-	struct kgem_bo *bo;
+	struct kgem_bo *bo = NULL;
 
 	list_for_each_entry(bo, buffers, request) {
 		if (!bo->dirty)
@@ -4599,7 +4608,7 @@
 				   uint32_t size, uint32_t flags,
 				   void **ret)
 {
-	struct kgem_buffer *bo;
+	struct kgem_buffer *bo = NULL;
 	unsigned offset, alloc;
 	struct kgem_bo *old;
 
