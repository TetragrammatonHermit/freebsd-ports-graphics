# Created by: Florent Thoumie <flz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xf86-video-openchrome
PORTVERSION=	0.3.0
CATEGORIES=	x11-drivers
MASTER_SITES=	http://www.openchrome.org/releases/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org openChrome display driver

USE_GL=		gl

XORG_CAT=	driver
USE_XORG=	xf86driproto xvmc glproto
MAN4=		openchrome.4x

MAKE_ARGS+=	drivermandir=${LOCALBASE}/man/man4

ONLY_FOR_ARCHS=	amd64 i386 ia64

.include <bsd.port.mk>
