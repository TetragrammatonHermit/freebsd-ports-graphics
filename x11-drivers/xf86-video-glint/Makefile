# $FreeBSD$

PORTNAME=	xf86-video-glint
PORTVERSION=	1.2.8
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org glint display driver

.include <bsd.port.options.mk>

.if defined(WITH_NEW_XORG)
EXTRA_PATCHES+=	${PATCHDIR}/extra-mibstore
.endif

USE_GL=		gl

XORG_CAT=	driver
USE_XORG=	xf86driproto xf86dgaproto glproto
MAN4=		glint.4x

.include <bsd.port.mk>
