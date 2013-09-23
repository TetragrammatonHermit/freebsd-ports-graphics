# $FreeBSD$

PORTNAME=	xf86-video-vesa
PORTVERSION=	2.3.3
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org vesa display driver

.include <bsd.port.options.mk>

.if defined(WITH_NEW_XORG)
EXTRA_PATCHES+=	${PATCHDIR}/extra-mibstore
.endif

XORG_CAT=	driver
MAN4=		vesa.4x
NO_STAGE=	yes


.include <bsd.port.mk>
