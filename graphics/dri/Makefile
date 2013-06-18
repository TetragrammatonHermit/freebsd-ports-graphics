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

ALL_DRI_DRIVERS=RADEON SWRAST

.if !defined(WITH_NEW_XORG)
.if ${ARCH} == i386 || ${ARCH} = amd64
ALL_DRI_DRIVERS+=I810 MACH64 MGA R128 R300 R600 SAVAGE SIS TDFX UNICHROME
.else if ${ARCH} == powerpc
ALL_DRI_DRIVERS+=MACH64 TDFX
.else if ${ARCH} == sparc64
ALL_DRI_DRIVERS=MACH64
.endif
.else # defined(WITH_NEW_XORG)
.if ${ARCH} == i386 || ${ARCH} == amd64
ALL_DRI_DRIVERS+=I915 I965 R200
.endif
.endif # !defined(WITH_NEW_XORG)

.include "${.CURDIR}/../../graphics/libGL/bsd.mesalib.mk"

DRI_DRIVERS=
.for _d in ${ALL_DRI_DRIVERS}
DRI_DRIVERS+=	${_d}
PLIST_SUB+=	${_d}_DRIVER=""
.else
PLIST_SUB+=	${_d}_DRIVER="@comment "
.endfor

.if !(${ARCH} == "amd64" || ${ARCH} == "i386")
CONFIGURE_ARGS+=--disable-gallium-intel
.endif
CONFIGURE_ARGS+=--with-dri-drivers="${DRI_DRIVERS:L}"

do-install:
	cd ${WRKSRC}/src/mesa; ${GMAKE} install-dri

.include <bsd.port.mk>
