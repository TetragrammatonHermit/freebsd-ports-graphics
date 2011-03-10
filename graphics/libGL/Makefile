# New ports collection makefile for:    xorg-server
# Date created:		7 May 2004
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD: ports/graphics/libGL/Makefile,v 1.17 2011/02/25 16:52:06 miwi Exp $
#

PORTNAME=	libGL
PORTVERSION=	${MESAVERSION}
CATEGORIES=	graphics

COMMENT=	OpenGL library that renders using GLX or DRI

BUILD_DEPENDS+=	makedepend:${PORTSDIR}/devel/makedepend \
		${PYTHON_SITELIBDIR}/libxml2mod.so:${PORTSDIR}/textproc/py-libxml2
LIB_DEPENDS+=	drm:${PORTSDIR}/graphics/libdrm \
		expat.6:${PORTSDIR}/textproc/expat2

USE_XORG=	glproto x11 xext xxf86vm xdamage xfixes dri2proto:both
USE_PYTHON=	yes

do-install:
	${RM} -f ${WRKSRC}/include/GL/glu*.h
	cd ${WRKSRC}/src/mesa; ${GMAKE} install-libgl

.include "${.CURDIR}/bsd.mesalib.mk"
.include <bsd.port.mk>
