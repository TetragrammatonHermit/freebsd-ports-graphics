# Created by: Dave Grochowski
# $FreeBSD: head/x11/xorg-cf-files/Makefile 319055 2013-05-25 14:37:02Z zeising $

PORTNAME=	xorg-cf-files
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.org cf files for use with imake builds

LICENSE=	MIT

XORG_CAT=	util

post-patch:
		@${REINPLACE_CMD} 's|\(define ExtraXaw[^ ]*\) [$$].*|\1 /**/|' \
			${WRKSRC}/X11.tmpl
		@${REINPLACE_CMD} -e 's|/usr/bin/cpp|${LOCALBASE}/bin/tradcpp|' \
			-e 's|-traditional||' ${WRKSRC}/FreeBSD.cf

.include <bsd.port.mk>
