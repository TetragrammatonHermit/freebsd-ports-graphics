# Created by: kwm@FreeBSD.org
# $FreeBSD$

PORTNAME=	libEGL
PORTVERSION=	${MESAVERSION}
CATEGORIES=	graphics

COMMENT=	OpenEGL library

USE_GL=		gl
USE_XORG=	glproto x11 xext xxf86vm xdamage xfixes dri2proto
BUILD_WKRSRC=	${WRKSRC}/src/egl
INSTALL_WRKSRC=	${WRKSRC}/src/egl


.if ! defined(WITH_NEW_XORG)
IGNORE=	Needs WITH_NEW_XORG
.endif

.include "${.CURDIR}/../../graphics/libGL/bsd.mesalib.mk"
.include <bsd.port.mk>
