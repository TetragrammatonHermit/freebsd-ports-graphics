# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dri
PORTVERSION=	${MESAVERSION}
PORTREVISION=	${DRIREVISION}
PORTEPOCH=	2
CATEGORIES=	graphics

COMMENT=	OpenGL hardware acceleration drivers for the DRI

LIB_DEPENDS=	libdrm.so:${PORTSDIR}/graphics/libdrm \
		libexpat.so:${PORTSDIR}/textproc/expat2

USES=		pkgconfig
USE_XORG=	glproto x11 xext xxf86vm xdamage xfixes dri2proto xvmc

OPTIONS_DEFINE=	TEXTURE

OPTIONS_DEFINE_i386=	GALLIUM VDPAU
OPTIONS_DEFAULT_i386=	GALLIUM VDPAU
OPTIONS_DEFINE_amd64=	GALLIUM VDPAU
OPTIONS_DEFAULT_amd64=	GALLIUM VDPAU

GALLIUM_DESC=	Gallium (llvm backed) dri drivers
TEXTURE_DESC=	Enable texture-float support (patent encumbered)

PKGHELP=	${.CURDIR}/pkg-help

.include <bsd.port.options.mk>

# gcc from base can't handle some code in mesa 9.1+
# We only care for 9.x and 8.x, not for old pre-clang default current.
# This is for 0b0000 binary which gcc 4.3+ understands and is in the i965 driver.
. if ${OSVERSION} >= 901000 && ${OSVERSION} < 902502 \
		&& (${ARCH} == i386 || ${ARCH} == amd64)
CC=clang
CXX=clang++
CPP=clang-cpp
. elif ${OSVERSION} < 901500
USE_GCC=yes
. endif

.if ${ARCH} == ia64
#BROKEN=		does not install on ia64
.endif

ALL_DRI_DRIVERS=I915 I965 R200 RADEON SWRAST

.include "${.CURDIR}/../../graphics/libGL/bsd.mesalib.mk"

PLIST_SUB+=	VERSION=${MESADISTVERSION}

.if ${ARCH} == amd64 || ${ARCH} == i386
DRI_DRIVERS=	${ALL_DRI_DRIVERS}
.endif

.if defined(WITH_NEW_MESA)
DRIREVISION=	0
.else
DRIREVISION=	4
.endif

.if ${PORT_OPTIONS:MGALLIUM}
. if defined(WITH_NEW_MESA)
BUILD_DEPENDS+=	llvm34>=0:${PORTSDIR}/devel/llvm34
CONFIGURE_ENV+=	LLVM_CONFIG=${LOCALBASE}/bin/llvm-config34
. else
BUILD_DEPENDS+=	llvm33>=0:${PORTSDIR}/devel/llvm33
CONFIGURE_ENV+=	LLVM_CONFIG=${LOCALBASE}/bin/llvm-config33
. endif

CONFIGURE_ARGS+=--enable-gallium-llvm \
		--with-gallium-drivers=r300,r600,radeonsi,svga,swrast
PLIST_SUB+=	GALLIUM=""
.else
CONFIGURE_ARGS+=--enable-gallium-llvm=no --without-gallium-drivers \
		--disable-gallium-egl
PLIST_SUB+=	GALLIUM="@comment "
.endif

.if ${PORT_OPTIONS:MTEXTURE}
CONFIGURE_ARGS+=--enable-texture-float
.endif

.if ${PORT_OPTIONS:MVDPAU}
CONFIGURE_ARGS+=--enable-vdpau
LIB_DEPENDS+=	libvdpau.so:${PORTSDIR}/multimedia/libvdpau
PLIST_SUB+=	VDPAU=""
.else
CONFIGURE_ARGS+=--disable-vdpau
PLIST_SUB+=	VDPAU="@comment "
.endif

.if ${ARCH} == powerpc || ${ARCH} == ia64
DRI_DRIVERS=	RADEON SWRAST
.endif
.if ${ARCH} == sparc64
DRI_DRIVERS=	SWRAST
.endif

.for _d in ${ALL_DRI_DRIVERS}
. if ${DRI_DRIVERS:M${_d}}
PLIST_SUB+=	${_d}_DRIVER=""
. else
PLIST_SUB+=	${_d}_DRIVER="@comment "
. endif
.endfor

.if !(${ARCH} == amd64 || ${ARCH} == i386)
CONFIGURE_ARGS+=--disable-gallium-intel
.endif
CONFIGURE_ARGS+=--with-dri-drivers="${DRI_DRIVERS:L}"

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/dri/*_dri.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so.*
.if defined(WITH_VDPAU)
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/vdpau/libvdpau_*.so.1
.endif
.if !defined(WITH_NEW_MESA)
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libllvmradeon9.1.7.so
.endif

.include <bsd.port.mk>
