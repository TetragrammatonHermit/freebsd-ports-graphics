# New ports collection makefile for:    libglut
# Date created:         Tue Feb  7 12:02:49  1995
# Whom:                 anholt
#
# $FreeBSD: ports/graphics/libglut/Makefile,v 1.25 2011/02/25 16:52:07 miwi Exp $
#

PORTNAME=	libglut
PORTVERSION=	${MESAVERSION}
CATEGORIES=	graphics

MAINTAINER=	x11@FreeBSD.org
COMMENT=	OpenGL utility toolkit

BUILD_DEPENDS+=	makedepend:${PORTSDIR}/devel/makedepend \
		${PYTHON_SITELIBDIR}/libxml2mod.so:${PORTSDIR}/textproc/py-libxml2

USE_PYTHON=	yes
USE_GL=		glu
USE_XORG=	glproto x11 xext xxf86vm xdamage xfixes xi xmu dri2proto

do-install:
	cd ${WRKSRC}/src/glut/glx; ${GMAKE} install
		${INSTALL} -C -o ${BINOWN} -g ${BINGRP} -m 444 \
		${WRKSRC}/include/GL/glutf90.h \
		${PREFIX}/include/GL

.include "${.CURDIR}/../../graphics/libGL/bsd.mesalib.mk"
.include <bsd.port.mk>
