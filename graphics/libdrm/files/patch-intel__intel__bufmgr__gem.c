--- intel/intel_bufmgr_gem.c.orig	2012-07-21 19:14:20.000000000 +0200
+++ intel/intel_bufmgr_gem.c	2012-07-21 19:14:46.000000000 +0200
@@ -1488,7 +1488,7 @@
  *
  * Returns 0 if the wait was successful ie. the last batch referencing the
  * object has completed within the allotted time. Otherwise some negative return
- * value describes the error. Of particular interest is -ETIME when the wait has
+ * value describes the error. Of particular interest is -ETIMEDOUT when the wait has
  * failed to yield the desired result.
  *
  * Similar to drm_intel_gem_bo_wait_rendering except a timeout parameter allows
@@ -1517,7 +1517,7 @@
 			drm_intel_gem_bo_wait_rendering(bo);
 			return 0;
 		} else {
-			return drm_intel_gem_bo_busy(bo) ? -ETIME : 0;
+			return drm_intel_gem_bo_busy(bo) ? -ETIMEDOUT : 0;
 		}
 	}
 
