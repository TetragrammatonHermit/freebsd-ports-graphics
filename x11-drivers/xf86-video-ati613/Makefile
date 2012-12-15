# Created by: Florent Thoumie <flz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xf86-video-ati613
PORTVERSION=	6.13.2
CATEGORIES=	x11-drivers
DISTNAME=	xf86-video-ati-${PORTVERSION}

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org ati display driver

USE_GL=		gl

XORG_CAT=	driver
USE_XORG=	xf86driproto xineramaproto xf86miscproto glproto
MAN4=		ati.4x radeon.4x

.if defined(WITH_NEW_XORG)
IGNORE=		Please use x11-drivers/xf86-video-ati
.endif

.include <bsd.port.mk>
