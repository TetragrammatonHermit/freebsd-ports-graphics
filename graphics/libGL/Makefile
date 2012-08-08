# New ports collection makefile for:    xorg-server
# Date created:		7 May 2004
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libGL
PORTVERSION=	${MESAVERSION}
PORTREVISION=	1
CATEGORIES=	graphics

COMMENT=	OpenGL library that renders using GLX or DRI

LIB_DEPENDS+=	drm:${PORTSDIR}/graphics/libdrm \
		expat.6:${PORTSDIR}/textproc/expat2

USE_XORG=	glproto x11 xext xxf86vm xdamage xfixes dri2proto

SUB_FILES=    pkg-install pkg-deinstall

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	${RM} -f ${WRKSRC}/include/GL/glu*.h
	cd ${WRKSRC}/src/mesa; ${GMAKE} install-libgl

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include "${.CURDIR}/bsd.mesalib.mk"
.include <bsd.port.mk>
