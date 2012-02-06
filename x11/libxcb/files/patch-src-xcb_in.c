For some reason the recv() hangs on FreeBSD, but works on linux.

--- src/xcb_in.c
+++ src/xcb_in.c
@@ -269,7 +269,7 @@ static int read_block(const int fd, void *buf, const ssize_t len)
     int done = 0;
     while(done < len)
     {
-        int ret = recv(fd, ((char *) buf) + done, len - done,MSG_WAITALL);
+        int ret = read(fd, ((char *) buf) + done, len - done);
         if(ret > 0)
             done += ret;
 #ifndef _WIN32
@@ -661,7 +661,7 @@ void _xcb_in_replies_done(xcb_connection_t *c)
 
 int _xcb_in_read(xcb_connection_t *c)
 {
-    int n = recv(c->fd, c->in.queue + c->in.queue_len, sizeof(c->in.queue) - c->in.queue_len,MSG_WAITALL);
+    int n = read(c->fd, c->in.queue + c->in.queue_len, sizeof(c->in.queue) - c->in.queue_len);
     if(n > 0)
         c->in.queue_len += n;
     while(read_packet(c))
