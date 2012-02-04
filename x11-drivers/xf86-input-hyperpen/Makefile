# New ports collection makefile for:	xf86-input-hyperpen
# Date Created:				17 Feb 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xf86-input-hyperpen
PORTVERSION=	${HYPER_VERSION}
PORTREVISION=	${HYPER_REVISION}
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org hyperpen input driver

XORG_CAT=	driver
USE_XORG=	xextproto videoproto

.if defined(WITH_NEW_XORG)
HYPER_VERSION=	1.4.1
HYPER_REVISION=	0
.else
HYPER_VERSION=	1.3.0
HYPER_REVISION=	5
.endif

.include <bsd.port.mk>
