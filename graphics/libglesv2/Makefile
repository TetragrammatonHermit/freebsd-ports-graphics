# Created by: kwm@FreeBSD.org
# $FreeBSD$

PORTNAME=	libglesv2
PORTVERSION=	${MESAVERSION}
CATEGORIES=	graphics

COMMENT=	OpenGL ES 2.x library

LIB_DEPENDS+=	libdrm.so:${PORTSDIR}/graphics/libdrm \
		libexpat.so:${PORTSDIR}/textproc/expat2

#USE_GL=		gl
#USE_XORG=	glproto x11 xext xxf86vm xdamage xfixes dri2proto
BUILD_WKRSRC=	${WRKSRC}/src/mapi/es2api
INSTALL_WRKSRC=	${WRKSRC}/src/mapi/es2api


.if ! defined(WITH_NEW_XORG)
IGNORE=	Needs WITH_NEW_XORG
.endif

.include "${.CURDIR}/../../graphics/libGL/bsd.mesalib.mk"
.include <bsd.port.mk>
