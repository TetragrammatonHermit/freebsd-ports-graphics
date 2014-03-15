# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libGL
PORTVERSION=	${MESAVERSION}
PORTREVISION=	${LIBGLREVISION}
CATEGORIES=	graphics

COMMENT=	OpenGL library that renders using GLX or DRI

LIB_DEPENDS+=	libdrm.so:${PORTSDIR}/graphics/libdrm \
		libglapi.so:${PORTSDIR}/graphics/libglapi \
		libexpat.so:${PORTSDIR}/textproc/expat2

USE_XORG=	glproto x11 xext xxf86vm xdamage xfixes dri2proto:both \
		dri3proto presentproto xshmfence

SUB_FILES=	pkg-install pkg-deinstall

.include <bsd.port.options.mk>

.if defined(WITH_NEW_MESA)
LIBGLREVISION=	0
.else
LIBGLREVISION=	0
.endif

.include "${.CURDIR}/bsd.mesalib.mk"

.if !(${ARCH} == "amd64" || ${ARCH} == "i386")
CONFIGURE_ARGS+=--disable-gallium-intel
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/.libGL
	@${MV} ${STAGEDIR}${PREFIX}/lib/libGL* \
		${STAGEDIR}${PREFIX}/lib/.libGL/
# kill off to be poudriere -t safe, that unless we can pkg-plist.ignore it.
	@${RM} -rf ${STAGEDIR}${PREFIX}/include/GL/internal
.if defined(WITH_NEW_MESA)
	@${CHMOD} +w ${STAGEDIR}${PREFIX}/etc/drirc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/dri.pc
	@${RM} ${STAGEDIR}${PREFIX}/etc/drirc
.else
	@${CHMOD} +w ${STAGEDIR}${PREFIX}/libdata/pkgconfig/dri.pc
.endif
	@${RM} ${STAGEDIR}${PREFIX}/lib/libglapi.* \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/dri.pc

.include <bsd.port.mk>
