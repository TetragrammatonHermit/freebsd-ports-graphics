# New ports collection makefile for:    mesa-demos
# Date created:         7 Nov 2003
# Whom:                 anholt@FreeBSD.org
#
# $FreeBSD: ports/graphics/mesa-demos/Makefile,v 1.35 2011/03/02 23:59:52 linimon Exp $
#

PORTNAME=	mesa-demos
PORTVERSION=	7.6.1
CATEGORIES=	graphics
MASTER_SITES=	CRITICAL/mesa3d:mesa,glut,demos
DISTFILES=	MesaLib-${PORTVERSION}${EXTRACT_SUFX}:mesa \
		MesaDemos-${PORTVERSION}${EXTRACT_SUFX}:demos

MAINTAINER=	x11@FreeBSD.org
COMMENT=	OpenGL demos distributed with Mesa

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
USE_GL=		glu glut
USE_XORG=	glproto x11 xext xxf86vm xdamage xfixes dri2proto
CPPFLAGS=	-I${LOCALBASE}/include
CONFIGURE_ENV=	LDFLAGS=-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-gallium --with-demos=demos,xdemos

#ALL_TARGET=	yes

#PATCHDIR=	${.CURDIR}/../../graphics/libGL/files
WRKSRC=		${WRKDIR}/Mesa-${PORTVERSION}/

DATADIR=	${PREFIX}/share/${PKGNAMEPREFIX}${PORTNAME}

OPTIONS=	NVIDIA_GL	"Use NVIDIA's libraries"	off

#EXTRA_PATCHES+=	${FILESDIR}/patch-progs-xdemos-glxpixmap.c \
#		${FILESDIR}/patch-progs-xdemos-yuvrect_client.c

.if defined(WITHOUT_XCB)
CONFIGURE_ARGS+=	--disable-xcb
.else
CONFIGURE_ARGS+=	--enable-xcb
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-ffast-math|${FAST_MATH}|' -e 's|x86_64|amd64|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|[$$](INSTALL_LIB_DIR)/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/src/glu/Makefile \
		${WRKSRC}/src/glw/Makefile \
		${WRKSRC}/src/mesa/Makefile \
		${WRKSRC}/src/mesa/drivers/dri/Makefile
	@${REINPLACE_CMD} -e 's|../images/|${DATADIR}/images/|g' \
		-e 's|geartrain.dat|${DATADIR}/data/geartrain.dat|g' \
		-e 's|terrain.dat|${DATADIR}/data/terrain.dat|g' \
		-e 's|isosurf.dat|${DATADIR}/data/isosurf.dat|g' \
			${WRKSRC}/progs/demos/*.c ${WRKSRC}/progs/xdemos/*.c

do-install:
	@for i in demos xdemos; do \
		cd ${WRKSRC}/progs/$$i; \
		for j in `${MAKE} -V PROGS`; do \
			${ECHO_CMD} ${INSTALL_PROGRAM} $$j ${PREFIX}/bin; \
			${INSTALL_PROGRAM} $$j ${PREFIX}/bin; \
		done; \
	done
	${MKDIR} ${DATADIR}/images ${DATADIR}/data
	@cd ${WRKSRC}/progs/images; \
		for i in `ls *.rgb*`; do \
			${ECHO_CMD} ${INSTALL_DATA} $$i ${DATADIR}/images; \
			${INSTALL_DATA} $$i ${DATADIR}/images; \
		done
	@cd ${WRKSRC}/progs/demos; \
		for i in `ls *.dat`; do \
			${ECHO_CMD} ${INSTALL_DATA} $$i ${DATADIR}/data; \
			${INSTALL_DATA} $$i ${DATADIR}/data; \
		done

.include <bsd.port.pre.mk>
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${PTHREAD_LIBS} -L${LOCALBASE}/lib"

.if defined(WITH_NVIDIA_GL)
CFLAGS+=	-DWITH_NVIDIA_GL=1
.endif

.if !defined(ARCH)
ARCH!=		uname -p
.endif

.include <bsd.port.post.mk>
