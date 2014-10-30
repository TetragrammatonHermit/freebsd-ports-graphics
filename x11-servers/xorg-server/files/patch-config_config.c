Index: config/config.c
@@ -55,6 +55,9 @@
 #elif defined(CONFIG_WSCONS)
     if (!config_wscons_init())
         ErrorF("[config] failed to initialise wscons\n");
+#elif defined(CONFIG_DEVD)
+     if (!config_devd_init())
+         ErrorF("[config] failed to initialise devd\n");
 #endif
 }
 
@@ -73,6 +76,8 @@
     config_dbus_core_fini();
 #elif defined(CONFIG_WSCONS)
     config_wscons_fini();
+#elif defined(CONFIG_DEVD)
+     config_devd_fini();
 #endif
 }
 
