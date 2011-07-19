#-*- mode: Fundamental; tab-width: 4; -*-
# ex:ts=4
#
# bsd.mesa.mk - an attempt to refactor MesaLib ports.
#
# Created by: Florent Thoumie <flz@FreeBSD.org>
#
# !!! Here be dragons !!! (they seem to be everywhere these days)
#
# Remember to upgrade the following ports everytime you bump MESAVERSION:
#
#    - graphics/libGL
#    - graphics/libGLU
#    - graphics/libGLw
#    - graphics/libglut
#    - graphics/dri
#
# $FreeBSD: ports/graphics/libGL/bsd.mesalib.mk,v 1.17 2011/02/25 16:52:06 miwi Exp $
#

MESAVERSION=	${MESABASEVERSION}${MESASUBVERSION:C/^(.)/.\1/}
MESADISTVERSION=${MESABASEVERSION}${MESASUBVERSION:C/^(.)/-\1/}

MESABASEVERSION=	7.10.3
MESASUBVERSION=

MASTER_SITES=	ftp://ftp.freedesktop.org/pub/mesa/${MESABASEVERSION}/:mesa,glut
MASTER_SITES=	LOCAL/kwm:mesa,glut
DISTFILES=	MesaLib-${MESADISTVERSION}${EXTRACT_SUFX}:mesa
MAINTAINER?=	x11@FreeBSD.org

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=		LDFLAGS=-L${LOCALBASE}/lib
CONFIGURE_ARGS=		--disable-gallium

ALL_TARGET=		default

PATCHDIR=		${.CURDIR}/../../graphics/libGL/files
WRKSRC=			${WRKDIR}/Mesa-${MESABASEVERSION}

.if !defined(ARCH)
ARCH!=			uname -p
.endif

COMPONENT=		${PORTNAME:L:C/^lib//:C/mesa-//}

.if ${COMPONENT:Mglut} == ""
. if ${COMPONENT:Mglu} == ""
CONFIGURE_ARGS+=	--disable-glu --disable-glut
. else
CONFIGURE_ARGS+=	--disable-glut
. endif
.else
DISTFILES+=		MesaGLUT-${MESADISTVERSION}${EXTRACT_SUFX}:glut
.endif

.if ${COMPONENT:Mglw} == ""
CONFIGURE_ARGS+=	--disable-glw
.else
CONFIGURE_ARGS+=	--enable-motif
.endif

CONFIGURE_ARGS+=	--with-demos=no

.if ${COMPONENT:Mdri} == ""
CONFIGURE_ARGS+=	--with-dri-drivers=no
.endif

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
.if ${COMPONENT:Mglut} != ""
	@${REINPLACE_CMD} -e 's|[$$](INSTALL_LIB_DIR)/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/src/glut/glx/Makefile
.endif
