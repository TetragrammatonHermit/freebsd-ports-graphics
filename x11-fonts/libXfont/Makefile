# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD: head/x11-fonts/libXfont/Makefile 351411 2014-04-16 18:28:47Z zeising $

PORTNAME=	libXfont
PORTVERSION=	1.4.8
PORTEPOCH=	2
CATEGORIES=	x11-fonts

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X font library

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2

XORG_CAT=	lib
USE_XORG=	xproto:both xtrans fontsproto:both fontenc

CONFIGURE_ARGS=--without-xmlto --disable-devel-docs

.include <bsd.port.mk>
