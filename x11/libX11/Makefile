# New ports collection makefile for:   libX11
# Date Created:			28 Oct, 2003
# Whom:				Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD: ports/x11/libX11/Makefile,v 1.36 2010/12/04 07:34:04 ade Exp $
#

PORTNAME=	libX11
PORTVERSION=	1.3.6
PORTEPOCH=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X11 library

BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/xcb.pc:${PORTSDIR}/x11/libxcb \
		${LOCALBASE}/share/aclocal/xorg-macros.m4:${PORTSDIR}/devel/xorg-macros
RUN_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/xcb.pc:${PORTSDIR}/x11/libxcb

XORG_CAT=	lib
USE_XORG=	bigreqsproto xau xcmiscproto xdmcp xextproto xtrans \
		kbproto:both inputproto xf86bigfontproto xproto:both
CONFIGURE_ARGS+=	--datadir=${PREFIX}/lib \
			--with-xcb=yes \
			--disable-specs
CONFIGURE_ENV+=	ac_cv_path_PS2PDF=""

.include "${.CURDIR}/manpages"
.include <bsd.port.mk>
