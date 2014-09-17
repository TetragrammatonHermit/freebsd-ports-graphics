# Created by: lesi@FreeBSD.org
# $FreeBSD$

PORTNAME=	xf86-video-intel
PORTVERSION=	2.99.916
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Driver for Intel integrated graphics chipsets

#LIB_DEPENDS=	libglamor.so:${PORTSDIR}/graphics/glamor
LIB_DEPENDS+=	libxcb-util.so:${PORTSDIR}/x11/xcb-util

# only keep this until xorg-server in ports is updated. Using a function
# not present in xorg-server.
BUILD_DEPENDS+=	xorg-server>=1.14:${PORTSDIR}/x11-servers/xorg-server
RUN_DEPENDS+=	xorg-server>=1.14:${PORTSDIR}/x11-servers/xorg-server

ONLY_FOR_ARCHS=	amd64 i386
USE_GL=		gl

USE_LDCONFIG=	yes
XORG_CAT=	driver
USE_XORG=	glproto \
		pixman \
		x11 \
		xext \
		xf86driproto \
		xineramaproto \
		xrender \
		xvmc \
		dri3proto \
		presentproto

CONFIGURE_ENV+=	xorg_cv_cc_flag__Wno_maybe_uninitialized=no
CONFIGURE_ARGS+=--enable-sna --disable-glamor --disable-dri3
CPPFLAGS+=	-I${LOCALBASE}/include
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
