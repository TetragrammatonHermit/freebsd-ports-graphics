# Created by: kwm@FreeBSD.org
# $FreeBSD$

PORTNAME=	libglesv2
PORTVERSION=	${MESAVERSION}
CATEGORIES=	graphics

COMMENT=	OpenGL ES v2 library

LIB_DEPENDS+=	libdrm.so:${PORTSDIR}/graphics/libdrm \
		libexpat.so:${PORTSDIR}/textproc/expat2

# stuff not needed by libglesv2 but configure wants it
USE_XORG+=	glproto dri2proto xext xdamage xfixes

BUILD_WKRSRC=	${WRKSRC}/src/mapi/es2api
INSTALL_WRKSRC=	${WRKSRC}/src/mapi/es2api

.include <bsd.port.options.mk>
.include "${.CURDIR}/../../graphics/libGL/bsd.mesalib.mk"

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libGLESv2.so.2

.include <bsd.port.mk>
