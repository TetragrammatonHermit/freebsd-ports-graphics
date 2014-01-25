# $FreeBSD$

PORTNAME=	xf86-video-ati
PORTVERSION=	7.3.0
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org ati display driver

LIB_DEPENDS=	libglamor.so:${PORTSDIR}/graphics/glamor

USE_GL=		gl
XORG_CAT=	driver
USE_XORG=	xf86driproto xineramaproto xf86miscproto glproto

CONFIGURE_ARGS+=--disable-udev

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000051
BROKEN=		Needs KMS support in kernel
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/xorg/modules/drivers/*.so

.include <bsd.port.post.mk>
