# New ports collection makefile for:    libGLU
# Date created:		7 May 2004
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD: ports/graphics/libGLU/Makefile,v 1.14 2011/02/25 16:52:06 miwi Exp $
#

PORTNAME=	libGLU
PORTVERSION=	${MESAVERSION}
CATEGORIES=	graphics

COMMENT=	OpenGL utility library

BUILD_DEPENDS+=	makedepend:${PORTSDIR}/devel/makedepend \
		${PYTHON_SITELIBDIR}/libxml2mod.so:${PORTSDIR}/textproc/py-libxml2

USE_PYTHON=	yes
USE_GL=		gl
USE_XORG=	glproto x11 xext xxf86vm xdamage xfixes dri2proto

do-install:
	cd ${WRKSRC}/src/glu; ${GMAKE} install
	${INSTALL_DATA} ${WRKSRC}/include/GL/glu*.h ${PREFIX}/include/GL/
	cd ${WRKSRC}/src/glu; ${GMAKE} install

.include "${.CURDIR}/../../graphics/libGL/bsd.mesalib.mk"
.include <bsd.port.mk>
