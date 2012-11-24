# Created by: lesi@FreeBSD.org
# $FreeBSD$

PORTNAME=	libdrm
PORTVERSION=	${LIBDRM_VERSION}
PORTREVISION=	${LIBDRM_REVISION}
CATEGORIES=	graphics x11
MASTER_SITES=	http://dri.freedesktop.org/libdrm/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Userspace interface to kernel Direct Rendering Module services

LIB_DEPENDS=	pciaccess.0:${PORTSDIR}/devel/libpciaccess \
		pthread-stubs.0:${PORTSDIR}/devel/libpthread-stubs

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAKE_JOBS_SAFE=	yes

.if defined(WITH_NEW_XORG)

OPTIONS_DEFINE=	KMS
OPTIONS_DEFAULT=KMS
KMS_DESC=	Enable KMS support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKMS}
CONFIGURE_ARGS+=--enable-libkms
EXTRA_PATCHES+=	${FILESDIR}/extra-xf86drmMode.c \
		${FILESDIR}/extra-intel__intel__bufmgr__gem.c
PLIST_SUB+=	KMS=""
.else
PLIST_SUB+=	KMS="@comment "
.endif

LIBDRM_VERSION=	2.4.37
LIBDRM_REVISION=1
PLIST_SUB+=	OLD="@comment " NEW=""
.else
LIBDRM_VERSION=	2.4.17
LIBDRM_REVISION=0
PLIST_SUB+=	OLD="" NEW="@comment "
.endif

pre-patch:
	@${REINPLACE_CMD} 's|{libdir}/pkgconfig|{prefix}/libdata/pkgconfig|g; \
			   s,i?86|x86_64),i?86|amd64|x86_64),g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
