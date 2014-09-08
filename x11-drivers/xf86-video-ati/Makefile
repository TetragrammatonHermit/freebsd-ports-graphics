# $FreeBSD: head/x11-drivers/xf86-video-ati/Makefile 355734 2014-05-29 19:32:08Z kwm $

PORTNAME=	xf86-video-ati
PORTVERSION=	${ATI_VERSION}
PORTREVISION=	${ATI_REVISION}
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org ati display driver

USE_GL=		gl
XORG_CAT=	driver
USE_XORG=	xf86driproto xineramaproto xf86miscproto glproto

.include <bsd.port.options.mk>

# 902510 = vt(9) merged into 9.2-stable
.if ((${OSVERSION} >= 902510 && ${OSVERSION} < 1000000) || \
      ${OSVERSION} > 1000051) && (${ARCH} == i386 || ${ARCH} == amd64)
NEW_ATI_DRIVER=	yes
.else
NEW_ATI_DRIVER=	no
.endif

.if ${NEW_ATI_DRIVER} == no && !defined(WITH_NEW_XORG)
ATI_VERSION=	6.14.6
ATI_REVISION=	3
CONFIGURE_ARGS+=--disable-kms
PLIST_SUB+=	OLD=""
.else
ATI_VERSION=	7.2.0
ATI_REVISION=	3
CONFIGURE_ARGS+=--disable-udev
CONFIGURE_ARGS+=--disable-glamor
EXTRA_PATCHES+=	${FILESDIR}/extra-src__radeon_kms.c
PLIST_SUB+=	OLD="@comment "
.endif

.include <bsd.port.mk>
