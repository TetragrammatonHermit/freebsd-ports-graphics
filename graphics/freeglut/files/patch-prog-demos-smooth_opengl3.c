--- progs/demos/smooth_opengl3/smooth_opengl3.c.orig	2011-12-14 04:35:07.000000000 +0100
+++ progs/demos/smooth_opengl3/smooth_opengl3.c	2012-01-31 19:11:53.000000000 +0100
@@ -94,6 +94,7 @@
 typedef ptrdiff_t ourGLsizeiptr;
 typedef char ourGLchar;
 
+#if defined(WIN32)
 #ifndef APIENTRY
 #define APIENTRY
 #endif
@@ -117,6 +118,7 @@
 typedef void (APIENTRY *PFNGLENABLEVERTEXATTRIBARRAYPROC) (GLuint index);
 typedef GLint (APIENTRY *PFNGLGETUNIFORMLOCATIONPROC) (GLuint program, const ourGLchar *name);
 typedef void (APIENTRY *PFNGLUNIFORMMATRIX4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
+#endif /* WIN32 */
 
 PFNGLGENBUFFERSPROC gl_GenBuffers;
 PFNGLBINDBUFFERPROC gl_BindBuffer;
