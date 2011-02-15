# New ports collection makefile for:	xorg-cf-files
# Date created:				Nov 18 2006
# Whom:					Dave Grochowski
#
# $FreeBSD: ports/x11/xorg-cf-files/Makefile,v 1.3 2010/05/01 11:40:26 miwi Exp $
#

PORTNAME=	xorg-cf-files
PORTVERSION=	1.0.3
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.org cf files for use with imake builds

XORG_CAT=	util

post-patch:
		@${REINPLACE_CMD} 's|\(define ExtraXaw[^ ]*\) [$$].*|\1 /**/|' \
			${WRKSRC}/X11.tmpl

.include <bsd.port.mk>
