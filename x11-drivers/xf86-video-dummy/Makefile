# $FreeBSD$

PORTNAME=	xf86-video-dummy
PORTVERSION=	0.3.6
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org dummy display driver

.include <bsd.port.options.mk>

.if defined(WITH_NEW_XORG)
EXTRA_PATCHES+=	${PATCHDIR}/extra-mibstore
.endif

XORG_CAT=	driver
USE_XORG=	xf86dgaproto

.include <bsd.port.mk>
