# $FreeBSD$

PORTNAME=	xf86-video-tdfx
PORTVERSION=	1.4.5
PORTREVISION=	2
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org tdfx display driver

.include <bsd.port.options.mk>

.if defined(WITH_NEW_XORG)
EXTRA_PATCHES+=	${PATCHDIR}/extra-mibstore
.endif

USE_GL=		gl

XORG_CAT=	driver
USE_XORG=	xf86driproto glproto
MAN4=		tdfx.4x

.include <bsd.port.mk>
