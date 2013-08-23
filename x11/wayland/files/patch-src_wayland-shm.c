--- src/wayland-shm.c.orig	2013-08-20 12:48:07.000000000 +0200
+++ src/wayland-shm.c	2013-08-20 12:53:05.000000000 +0200
@@ -27,6 +27,8 @@
 
 #define _GNU_SOURCE
 
+#include "../config.h"
+
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -41,6 +43,9 @@
 	int refcount;
 	char *data;
 	int size;
+#ifdef HAVE_SYS_UCRED_H
+	int fd;
+#endif
 };
 
 struct wl_shm_buffer {
@@ -59,6 +64,10 @@
 	if (pool->refcount)
 		return;
 
+#ifdef HAVE_SYS_UCRED_H
+	close(pool->fd);
+#endif
+
 	munmap(pool->data, pool->size);
 	free(pool);
 }
@@ -155,14 +164,87 @@
 	wl_resource_destroy(resource);
 }
 
+#ifdef HAVE_MREMAP
+static void *
+mremap_compat_maymove(void *old_address, size_t old_size, size_t new_size,
+                      int old_prot, int old_flags, int old_fd)
+{
+	return mremap(old_address, old_size, new_size, MREMAP_MAYMOVE);
+}
+#else
+static void *
+mremap_compat_maymove(void *old_address, size_t old_size, size_t new_size,
+                      int old_prot, int old_flags, int old_fd)
+{
+	/* FreeBSD doesn't support mremap() yet, so we have to emulate it.
+	 * This assumes MREMAP_MAYMOVE is the only flag in use. */
+	if (new_size == old_size) {
+		return old_address;
+	} else if (new_size < old_size) {
+		/* Shrinking: munmap() the spare region. */
+		munmap(old_address + old_size, new_size - old_size);
+		return old_address;
+	} else {
+		void *ret;
+
+		/* Growing. Try and mmap() the extra region at the end of
+		 * our existing allocation. If that gets mapped in the
+		 * wrong place, fall back to mmap()ing an entirely new
+		 * region of new_size and copying the data across. */
+		ret = mmap(old_address + old_size, new_size - old_size,
+		           old_prot, old_flags, old_fd, 0);
+
+/* TODO: msync() before munmap()? */
+		if (ret == MAP_FAILED) {
+			/* Total failure! */
+			return ret;
+		} else if (ret == old_address + old_size) {
+			/* Success. */
+			return old_address;
+		} else if (ret != old_address + old_size) {
+			/* Partial failure. Fall back to mapping an
+			 * entirely new region. Unmap the region we
+			 * just mapped first. */
+			munmap(ret, new_size - old_size);
+
+			/* Map an entirely new region. */
+			ret = mmap(NULL, new_size,
+			           old_prot, old_flags, old_fd, 0);
+			if (ret == MAP_FAILED) {
+				/* Total failure! */
+				return ret;
+			}
+
+			/* Copy the old data across. Implicit assumption
+			 * that the old and new regions don't overlap. */
+			memcpy(ret, old_address, old_size);
+
+			/* Unmap the old region. */
+			munmap(old_address, old_size);
+
+			return ret;
+		}
+	}
+
+	/* Unreachable. */
+	return MAP_FAILED;
+}
+#endif
+
 static void
 shm_pool_resize(struct wl_client *client, struct wl_resource *resource,
 		int32_t size)
 {
 	struct wl_shm_pool *pool = wl_resource_get_user_data(resource);
 	void *data;
+	int fd = -1;
 
-	data = mremap(pool->data, pool->size, size, MREMAP_MAYMOVE);
+#ifdef HAVE_SYS_UCRED_H
+	fd = pool->fd;
+#endif
+
+	data = mremap_compat_maymove(pool->data, pool->size, size,
+				     PROT_READ | PROT_WRITE, MAP_SHARED, fd);
 
 	if (data == MAP_FAILED) {
 		wl_resource_post_error(resource,
@@ -210,7 +292,13 @@
 				       "failed mmap fd %d", fd);
 		goto err_free;
 	}
-	close(fd);
+#ifdef HAVE_SYS_UCRED_H
+	/* We need to keep the FD around on FreeBSD so we can implement
+	 * mremap(). See: mremap_compat_maymove(). */
+	pool->fd = fd;
+#else
+ 	close(fd);
+#endif
 
 	pool->resource =
 		wl_resource_create(client, &wl_shm_pool_interface, 1, id);
