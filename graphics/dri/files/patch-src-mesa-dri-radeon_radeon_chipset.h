
--- src/mesa/drivers/dri/radeon/radeon_chipset.h.orig	2009-11-18 02:54:28.000000000 +0100
+++ src/mesa/drivers/dri/radeon/radeon_chipset.h	2010-09-14 15:38:09.000000000 +0200
@@ -340,6 +340,7 @@
 #define PCI_CHIP_RS880_9712             0x9712
 #define PCI_CHIP_RS880_9713             0x9713
 #define PCI_CHIP_RS880_9714             0x9714
+#define PCI_CHIP_RS880_9715             0x9715
 #define PCI_CHIP_RV770_9440             0x9440
 #define PCI_CHIP_RV770_9441             0x9441
--- src/mesa/drivers/dri/radeon/radeon_screen.c.orig	2009-12-22 03:31:19.000000000 +0100
+++ src/mesa/drivers/dri/radeon/radeon_screen.c	2010-09-14 15:38:46.000000000 +0200
@@ -837,6 +837,7 @@
    case PCI_CHIP_RS880_9712:
    case PCI_CHIP_RS880_9713:
    case PCI_CHIP_RS880_9714:
+   case PCI_CHIP_RS880_9715:
       screen->chip_family = CHIP_FAMILY_RS880;
       screen->chip_flags = RADEON_CHIPSET_TCL;
       break;

