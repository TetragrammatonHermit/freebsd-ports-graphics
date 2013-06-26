# $FreeBSD$

PORTNAME=	xf86-video-ark
PORTVERSION=	0.7.5
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org ark display driver

.include <bsd.port.options.mk>

.if defined(WITH_NEW_XORG)
EXTRA_PATCHES+=	${PATCHDIR}/extra-mibstore
.endif

XORG_CAT=	driver

.include <bsd.port.mk>
