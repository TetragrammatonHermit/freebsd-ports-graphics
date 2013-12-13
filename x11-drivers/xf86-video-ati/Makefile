# $FreeBSD$

PORTNAME=	xf86-video-ati
PORTVERSION=	7.2.0
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org ati display driver

USE_GL=		gl
XORG_CAT=	driver
USE_XORG=	xf86driproto xineramaproto xf86miscproto glproto

CONFIGURE_ARGS+=--disable-udev

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000051
BROKEN=		Needs KMS support in kernel
.endif

.include <bsd.port.post.mk>
