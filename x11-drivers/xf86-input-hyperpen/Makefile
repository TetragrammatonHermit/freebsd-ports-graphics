# $FreeBSD$

PORTNAME=	xf86-input-hyperpen
PORTVERSION=	${HYPERVER}
PORTREVISION=	${HYPERREVISION}
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org hyperpen input driver

XORG_CAT=	driver

.if defined(WITH_NEW_XORG)
HYPERVER=	1.4.1
HYPERREVISION=	0
.else
HYPERVER=	1.3.0
HYPERREVISION=	5
.endif

.include <bsd.port.mk>
