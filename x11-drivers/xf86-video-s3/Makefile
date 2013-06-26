# $FreeBSD$

PORTNAME=	xf86-video-s3
PORTVERSION=	0.6.5
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org s3 display driver

.include <bsd.port.options.mk>

.if defined(WITH_NEW_XORG)
EXTRA_PATCHES+=	${PATCHDIR}/extra-mibstore
.endif

XORG_CAT=	driver
MAN4=		s3.4x

.include <bsd.port.mk>
