--- src/connection.c.orig	2013-08-20 12:40:17.000000000 +0200
+++ src/connection.c	2013-08-20 12:41:12.000000000 +0200
@@ -278,10 +278,19 @@ wl_connection_flush(struct wl_connection
 		msg.msg_namelen = 0;
 		msg.msg_iov = iov;
 		msg.msg_iovlen = count;
-		msg.msg_control = cmsg;
-		msg.msg_controllen = clen;
+		msg.msg_control = NULL;
+		msg.msg_controllen = 0;
 		msg.msg_flags = 0;
 
+		/* FreeBSD requires msg_control to be set to NULL iff
+		 * msg_controllen is 0 (see
+		 * http://www.freebsd.org/cgi/query-pr.cgi?pr=docs/99356#reply2)
+		 * Can't hurt to do that on all platforms. */
+		if (clen > 0) {
+			msg.msg_controllen = clen;
+			msg.msg_control = cmsg;
+		}
+
 		do {
 			len = sendmsg(connection->fd, &msg,
 				      MSG_NOSIGNAL | MSG_DONTWAIT);
