# $FreeBSD$

PORTNAME=	xf86-video-ati
PORTVERSION=	7.1.0
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org ati display driver

USE_GL=		gl
XORG_CAT=	driver
USE_XORG=	xf86driproto xineramaproto xf86miscproto glproto
MAN4=		ati.4x radeon.4x

CONFIGURE_ARGS+=--disable-udev

EXTRA_PATCHES+=	${FILESDIR}/extra-src__radeon_kms.c

pre-everything::
	@${ECHO_CMD}
	@${ECHO_CMD} "This port is KMS/TTM only, and only for testing the upcoming"
	@${ECHO_CMD} "radeon KMS/TTM kernel support. When that kernel supports lands"
	@${ECHO_CMD} "this port will be merged into the regular ati driver port."
	@${ECHO_CMD}
	@/bin/sleep 7

.include <bsd.port.mk>
