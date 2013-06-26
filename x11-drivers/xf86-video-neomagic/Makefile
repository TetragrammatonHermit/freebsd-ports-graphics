# $FreeBSD$

PORTNAME=	xf86-video-neomagic
PORTVERSION=	1.2.7
PORTREVISION=	1
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org neomagic display driver

.include <bsd.port.options.mk>

.if defined(WITH_NEW_XORG)
EXTRA_PATCHES+=	${PATCHDIR}/extra-mibstore
.endif

XORG_CAT=	driver
USE_XORG=	xf86dgaproto
MAN4=		neomagic.4x

.include <bsd.port.mk>
