# Created by: kwm@FreeBSD.org
# $FreeBSD$

PORTNAME=	libEGL
PORTVERSION=	${MESAVERSION}
CATEGORIES=	graphics

COMMENT=	OpenEGL library

LIB_DEPENDS+=	libpthread-stubs.so:${PORTSDIR}/devel/libpthread-stubs

USE_XORG=	x11 xau xcb xdmcp

# stuff not needed by libEGL but configure wants it
USE_XORG+=	glproto dri2proto xext xdamage xfixes
LIB_DEPENDS+=	libexpat.so:${PORTSDIR}/textproc/expat2 \
		libdrm.so:${PORTSDIR}/graphics/libdrm

BUILD_WKRSRC=	${WRKSRC}/src/egl
INSTALL_WRKSRC=	${WRKSRC}/src/egl

WITH_NEW_XORG=	yes

.include "${.CURDIR}/../../graphics/libGL/bsd.mesalib.mk"
.include <bsd.port.mk>
