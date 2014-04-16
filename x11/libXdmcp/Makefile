# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD: head/x11/libXdmcp/Makefile 351411 2014-04-16 18:28:47Z zeising $

PORTNAME=	libXdmcp
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Display Manager Control Protocol library

LICENSE=	MIT

XORG_CAT=	lib
USE_XORG=	xproto:both

CONFIGURE_ARGS+=--disable-docs --without-xmlto

post-patch:
	@${REINPLACE_CMD} '/^SUBDIRS/,/^$$/ \
		s/doc//' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
