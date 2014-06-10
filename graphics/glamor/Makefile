# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	glamor-egl
PORTVERSION=	0.6.0
CATEGORIES=	graphics

MAINTAINER=	x11@FreeBSD.org
COMMENT=	2D graphics common driver for the X Window System

LIB_DEPENDS=	libdrm.so:${PORTSDIR}/graphics/libdrm

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		pathfix pkgconfig
USE_GL=		gl egl
XORG_CAT=       driver
USE_XORG=	xorg-server dri3proto presentproto pixman

# needs libgbm >=9
CONFIGURE_ARGS+=--disable-glamor-dri3
# needs libglesv2
CONFIGURE_ARGS+=--disable-glamor-gles2

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libglamor.so.0
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/xorg/modules/libglamoregl.so

.include <bsd.port.mk>
