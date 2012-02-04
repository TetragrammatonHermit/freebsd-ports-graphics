# New ports collection makefile for:	xf86-input-hyperpen
# Date Created:				17 Feb 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xf86-input-hyperpen
PORTVERSION=	1.4.1
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org hyperpen input driver

XORG_CAT=	driver
USE_XORG=	xextproto videoproto

.if defined(WITH_NEW_XORG)
IGNORE=		does not build with Xorg-server 1.7.7
.endif

.include <bsd.port.mk>
