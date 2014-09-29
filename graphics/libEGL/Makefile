# Created by: kwm@FreeBSD.org
# $FreeBSD: head/graphics/libEGL/Makefile 354307 2014-05-17 09:56:00Z kwm $

PORTNAME=	libEGL
PORTVERSION=	${MESAVERSION}
PORTREVISION=	2
CATEGORIES=	graphics

COMMENT=	OpenEGL library

LIB_DEPENDS+=	libpthread-stubs.so:${PORTSDIR}/devel/libpthread-stubs

.if defined(WITH_NEW_XORG)
LIB_DEPENDS+=	libdevq.so:${PORTSDIR}/devel/libdevq
.endif

USE_XORG=	x11 xau xcb xdmcp

# stuff not needed by libEGL but configure wants it
USE_XORG+=	glproto dri2proto xext xdamage xfixes
LIB_DEPENDS+=	libexpat.so:${PORTSDIR}/textproc/expat2 \
		libdrm.so:${PORTSDIR}/graphics/libdrm

BUILD_WRKSRC=	${WRKSRC}/src/egl
INSTALL_WRKSRC=	${WRKSRC}/src/egl

.include <bsd.port.options.mk>

.if ! defined(WITH_NEW_XORG)
IGNORE=	Please enable WITH_NEW_XORG, libEGL needs libdrm higher then 2.4.24
.endif

.include "${.CURDIR}/../../graphics/libGL/bsd.mesalib.mk"
.include <bsd.port.mk>
