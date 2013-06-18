# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dri
PORTVERSION=	${MESAVERSION}
PORTREVISION=	3
PORTEPOCH=	2
CATEGORIES=	graphics

COMMENT=	OpenGL hardware acceleration drivers for the DRI

LIB_DEPENDS=	drm:${PORTSDIR}/graphics/libdrm \
		expat:${PORTSDIR}/textproc/expat2

USES=		pkgconfig
USE_XORG=	glproto x11 xext xxf86vm xdamage xfixes dri2proto

.include <bsd.port.options.mk>

.if ${ARCH} == "ia64"
BROKEN=		does not install on ia64
.endif

.if ! defined(WITH_NEW_XORG)
ALL_DRI_DRIVERS+=I810 MACH64 MGA R128 R300 R600 SAVAGE SIS TDFX UNICHROME
.else
ALL_DRI_DRIVERS=I915 I965 R200 RADEON SWRAST
.endif

.include "${.CURDIR}/../../graphics/libGL/bsd.mesalib.mk"

.if ${ARCH} == "amd64" || ${ARCH} == "i386"
DRI_DRIVERS=	${ALL_DRI_DRIVERS}
.endif

.if defined(WITH_NEW_XORG)
.if ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
DRI_DRIVERS=	RADEON SWRAST
.endif
.else # !defined(WITH_NEW_XORG)
.if ${ARCH} == "powerpc"
DRI_DRIVERS=	MACH64 RADEON SWRAST TDFX
.elif ${ARCH} == "sparc64"
DRI_DRIVERS=	MACH64 RADEON SWRAST
.endif
.endif # defined(WITH_NEW_XORG)

.for _d in ${ALL_DRI_DRIVERS}
.if ${DRI_DRIVERS:M${_d}}
PLIST_SUB+=	${_d}_DRIVER=""
.else
PLIST_SUB+=	${_d}_DRIVER="@comment "
.endif
.endfor

.if !(${ARCH} == "amd64" || ${ARCH} == "i386")
CONFIGURE_ARGS+=--disable-gallium-intel
.endif
CONFIGURE_ARGS+=--with-dri-drivers="${DRI_DRIVERS:L}"

do-install:
	cd ${WRKSRC}/src/mesa; ${GMAKE} install-dri

.include <bsd.port.mk>
