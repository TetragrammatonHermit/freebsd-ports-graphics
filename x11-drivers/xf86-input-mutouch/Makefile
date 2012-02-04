# New ports collection makefile for:	xf86-input-mutouch
# Date Created:				17 Feb 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xf86-input-mutouch
PORTVERSION=	${TOUCH_VERSION}
PORTREVISION=	${TOUCH_REVISION}
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org mutouch input driver

XORG_CAT=	driver
USE_XORG=	xextproto videoproto
MAN4=		mutouch.4x

.if defined(WITH_NEW_XORG)
TOUCH_VERSION=	1.3.0
TOUCH_REVISION=	0
.else
TOUCH_VERSION=	1.2.1
TOUCH_REVISION=	6
.endif

.include <bsd.port.mk>
