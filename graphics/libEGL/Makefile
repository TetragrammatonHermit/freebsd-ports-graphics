# Created by: kwm@FreeBSD.org
# $FreeBSD$

PORTNAME=	libEGL
PORTVERSION=	${MESAVERSION}
CATEGORIES=	graphics

COMMENT=	OpenEGL library

LIB_DEPENDS+=	libpthread-stubs.so:${PORTSDIR}/devel/libpthread-stubs

USE_XORG=	x11 xau xcb xdmcp

# stuff not needed by libEGL but configure wants it
USE_XORG+=	glproto dri2proto dri3proto xext xdamage xfixes presentproto \
		xshmfence
LIB_DEPENDS+=	libexpat.so:${PORTSDIR}/textproc/expat2 \
		libdrm.so:${PORTSDIR}/graphics/libdrm

.if defined(WITH_NEW_MESA)
BUILD_WRKSRC=	src/egl/drivers/dri2 src/egl/main
INSTALL_WRKSRC=	src/egl/drivers/dri2 src/egl/main
.else
BUILD_WRKSRC=	${WRKSRC}/src/egl
INSTALL_WRKSRC=	${WRKSRC}/src/egl
.endif

.include <bsd.port.options.mk>
.include "${.CURDIR}/../../graphics/libGL/bsd.mesalib.mk"

.if defined(WITH_NEW_MESA)
do-build: egl-do-build
do-install: egl-do-install

egl-do-build:
. for dir in ${BUILD_WRKSRC}
	@(cd ${WRKSRC}/${dir}; ${DO_MAKE_BUILD} ${ALL_TARGET};)
. endfor

egl-do-install:
. for dir in ${INSTALL_WRKSRC}
	@(cd ${WRKSRC}/${dir} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})

. endfor
.endif
.include <bsd.port.mk>
