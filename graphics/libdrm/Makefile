# New ports collection makefile for:	libdrm
# Date created:				29 Dec 2005
# Whom:					lesi@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libdrm
PORTVERSION=	${LIBDRM_VERSION}
CATEGORIES=	graphics x11
MASTER_SITES=	http://dri.freedesktop.org/libdrm/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Userspace interface to kernel Direct Rendering Module services

BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/pthread-stubs.pc:${PORTSDIR}/devel/libpthread-stubs
LIB_DEPENDS=	pciaccess.0:${PORTSDIR}/devel/libpciaccess
RUN_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/pthread-stubs.pc:${PORTSDIR}/devel/libpthread-stubs

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

LIBDRM_VERSION=	2.4.26
CONFIGURE_ARGS=	--enable-nouveau-experimental-api

MAKE_JOBS_SAFE=	yes

OPTIONS=	KMS "Enable KMS support (very experimental)" off

.include <bsd.port.options.mk>

.if defined(WITH_KMS)
EXTRA_PATCHES+=	${FILESDIR}/extra-configure \
		${FILESDIR}/extra-xf86drmMode.c
.endif

pre-patch:
	@${REINPLACE_CMD} 's|{libdir}/pkgconfig|{prefix}/libdata/pkgconfig|g' \
	    ${WRKSRC}/configure

.include <bsd.port.mk>
