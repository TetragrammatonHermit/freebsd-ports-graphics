# $FreeBSD$

PORTNAME=	xf86-video-ati
PORTVERSION=	7.5.0
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org ati display driver

USE_GL=		gl
XORG_CAT=	driver
USE_XORG=	xf86driproto \
		xineramaproto \
		xf86miscproto \
		glproto \
		presentproto
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS+=--disable-udev

OPTIONS_DEFINE=	GLAMOR
OPTIONS_SUB=	yes

GLAMOR_DESC=	Warning experimental and might not work.
GLAMOR_CONFIGURE_ENABLE=glamor
GLAMOR_LIB_DEPENDS=libglamor.so:${PORTSDIR}/graphics/glamor

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 902508
BROKEN=		Needs KMS support in kernel
.endif

.include <bsd.port.post.mk>
