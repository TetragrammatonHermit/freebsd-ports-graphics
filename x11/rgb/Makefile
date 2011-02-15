# New ports collection makefile for:	rgb
# Date Created:				17 Feb 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD: ports/x11/rgb/Makefile,v 1.2 2010/05/01 11:40:16 miwi Exp $
#

PORTNAME=	rgb
PORTVERSION=	1.0.3
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Uncompile an rgb corl-name database

CONFIGURE_ARGS=	--with-rgb-db-dir=${PREFIX}/lib/X11/rgb

XORG_CAT=	app
USE_XORG=	x11 xproto

PLIST_FILES=	bin/showrgb lib/X11/rgb.txt

MAN1=		showrgb.1

.include <bsd.port.mk>
