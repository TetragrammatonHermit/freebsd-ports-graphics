# Created by: kwm@FreeBSD.org
# $FreeBSD$

PORTNAME=	gbm
PORTVERSION=	${MESAVERSION}
CATEGORIES=	graphics

COMMENT=	gbm library

LIB_DEPENDS+=	libpthread-stubs.so:${PORTSDIR}/devel/libpthread-stubs \
		libglapi.so:${PORTSDIR}/graphics/libglapi

USE_XORG=	x11 xau xcb xdmcp

# stuff not needed by gbm but configure wants it
USE_XORG+=	glproto dri2proto dri3proto xext xdamage xfixes
LIB_DEPENDS+=	libexpat.so:${PORTSDIR}/textproc/expat2 \
		libdrm.so:${PORTSDIR}/graphics/libdrm

BUILD_WRKSRC=	${WRKSRC}/src/gbm
INSTALL_WRKSRC=	${WRKSRC}/src/gbm

.include <bsd.port.options.mk>
.include "${.CURDIR}/../../graphics/libGL/bsd.mesalib.mk"

pre-build:
	@cd ${WRKSRC}/src/mapi/shared-glapi && ${MAKE_CMD}

.include <bsd.port.mk>
