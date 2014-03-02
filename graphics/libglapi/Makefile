# Created by: kwm@FreeBSD.org
# $FreeBSD$

PORTNAME=	libglapi
PORTVERSION=	${MESAVERSION}
CATEGORIES=	graphics

COMMENT=	OpenEGL library

LIB_DEPENDS+=	libpthread-stubs.so:${PORTSDIR}/devel/libpthread-stubs

USE_XORG=	x11 xau xcb xdmcp

# stuff not needed by libglapi but configure wants it
USE_XORG+=	glproto dri2proto xext xdamage xfixes
LIB_DEPENDS+=	libexpat.so:${PORTSDIR}/textproc/expat2 \
		libdrm.so:${PORTSDIR}/graphics/libdrm

.if defined (WITH_NEW_MESA)
BUILD_WRKSRC=	${WRKSRC}/src/mapi
INSTALL_WRKSRC=	${WRKSRC}/src/mapi
.else
BUILD_WRKSRC=	${WRKSRC}/src/mapi/shared-glapi
INSTALL_WRKSRC=	${WRKSRC}/src/mapi/shared-glapi
.endif

.include <bsd.port.options.mk>
.include "${.CURDIR}/../../graphics/libGL/bsd.mesalib.mk"
.include <bsd.port.mk>
