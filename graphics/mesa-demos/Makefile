# New ports collection makefile for:    mesa-demos
# Date created:         7 Nov 2003
# Whom:                 anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	mesa-demos
PORTVERSION=	8.0.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.freedesktop.org/pub/mesa/demos/${PORTVERSION}/
DISTFILES=	mesa-demos-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	x11@FreeBSD.org
COMMENT=	OpenGL demos distributed with Mesa

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
USE_GL=		glu glut glew
USE_XORG=	glproto x11 xext xxf86vm xdamage xfixes dri2proto
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

DATADIR=	${PREFIX}/share/${PKGNAMEPREFIX}${PORTNAME}

OPTIONS=	NVIDIA_GL	"Use NVIDIA's libraries"	off

post-patch:
	@${REINPLACE_CMD} -e 's|-ffast-math|${FAST_MATH}|' -e 's|x86_64|amd64|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|../images/|${DATADIR}/images/|g' \
		-e 's|geartrain.dat|${DATADIR}/data/geartrain.dat|g' \
		-e 's|terrain.dat|${DATADIR}/data/terrain.dat|g' \
		-e 's|isosurf.dat|${DATADIR}/data/isosurf.dat|g' \
			${WRKSRC}/src/demos/*.c ${WRKSRC}/src/xdemos/*.c

post-install:
	${MKDIR} ${DATADIR}/images ${DATADIR}/data
	@cd ${WRKSRC}/src/images; \
		for i in `ls *.rgb*`; do \
			${ECHO_CMD} ${INSTALL_DATA} $$i ${DATADIR}/images; \
			${INSTALL_DATA} $$i ${DATADIR}/images; \
		done
	@cd ${WRKSRC}/src/demos; \
		for i in `ls *.dat`; do \
			${ECHO_CMD} ${INSTALL_DATA} $$i ${DATADIR}/data; \
			${INSTALL_DATA} $$i ${DATADIR}/data; \
		done

.include <bsd.port.pre.mk>

.if defined(WITH_NVIDIA_GL)
CFLAGS+=	-DWITH_NVIDIA_GL=1
.endif

.if !defined(ARCH)
ARCH!=		uname -p
.endif

.include <bsd.port.post.mk>
