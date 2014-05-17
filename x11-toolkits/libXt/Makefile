# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD: head/x11-toolkits/libXt/Makefile 351936 2014-04-23 13:25:16Z tijl $

PORTNAME=	libXt
PORTVERSION=	1.1.4
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	x11-toolkits

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Toolkit library

XORG_CAT=	lib
USE_XORG=	x11 sm xproto:both kbproto
CONFIGURE_ARGS=	--disable-specs

post-patch:
	@${REINPLACE_CMD} 's/test.*-traditional.*;/true;/' \
		${WRKSRC}/configure

.include <bsd.port.mk>
