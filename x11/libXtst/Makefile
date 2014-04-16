# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD: head/x11/libXtst/Makefile 351411 2014-04-16 18:28:47Z zeising $

PORTNAME=	libXtst
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Test extension

LICENSE=	MIT

XORG_CAT=	lib
USE_XORG=	x11 xext recordproto:both xextproto inputproto:both \
		xi

CONFIGURE_ARGS+=--disable-specs --without-xmlto

post-patch:
	@${REINPLACE_CMD} '/^SUBDIRS/,/^$$/ \
		s/specs//' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
