--- xf86drmMode.c.orig	2010-09-08 14:23:39.000000000 +0200
+++ xf86drmMode.c	2011-10-02 14:45:33.000000000 +0200
@@ -659,7 +659,7 @@ int drmModeConnectorSetProperty(int fd, 
 */
 int drmCheckModesettingSupported(const char *busid)
 {
-#ifdef __linux__
+#if defined (__linux__)
 	char pci_dev_dir[1024];
 	int domain, bus, dev, func;
 	DIR *sysdir;
@@ -709,6 +709,39 @@ int drmCheckModesettingSupported(const c
 	closedir(sysdir);
 	if (found)
 		return 0;
+#elif defined(__FreeBSD__)
+	char kbusid[1024], sbusid[1024];
+	char oid[128];
+	int domain, bus, dev, func;
+	int i, modesetting, ret;
+	size_t len;
+
+	ret = sscanf(busid, "pci:%04x:%02x:%02x.%d", &domain, &bus, &dev,
+	    &func);
+	if (ret != 4)
+		return -EINVAL;
+	snprintf(kbusid, sizeof(kbusid), "pci:%04x:%02x:%02x.%d", domain, bus,
+	    dev, func);
+
+	/* How many GPUs do we expect in the machine ? */
+	for (i = 0; i < 16; i++) {
+		snprintf(oid, sizeof(oid), "hw.dri.%d.busid", i);
+		len = sizeof(sbusid);
+		ret = sysctlbyname(oid, sbusid, &len, NULL, 0);
+		if (ret == -1) {
+			if (errno == ENOENT)
+				continue;
+			return -EINVAL;
+		}
+		if (strcmp(sbusid, kbusid) != 0)
+			continue;
+		snprintf(oid, sizeof(oid), "hw.dri.%d.modesetting", i);
+		len = sizeof(modesetting);
+		ret = sysctlbyname(oid, &modesetting, &len, NULL, 0);
+		if (ret == -1 || len != sizeof(modesetting))
+			return -EINVAL;
+		return (modesetting ? 0 : -ENOSYS);
+	}
 #endif
 	return -ENOSYS;
 
