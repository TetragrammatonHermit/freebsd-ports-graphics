# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD: head/x11-toolkits/libXt/Makefile 351411 2014-04-16 18:28:47Z zeising $

PORTNAME=	libXt
PORTVERSION=	1.1.4
PORTREVISION=	1
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
