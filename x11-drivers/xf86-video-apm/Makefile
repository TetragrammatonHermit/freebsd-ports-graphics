# $FreeBSD$

PORTNAME=	xf86-video-apm
PORTVERSION=	1.2.5
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org apm display driver

.include <bsd.port.options.mk>

.if defined(WITH_NEW_XORG)
EXTRA_PATCHES+=	${PATCHDIR}/extra-mibstore
.endif

XORG_CAT=	driver
MAN4=		apm.4x

.include <bsd.port.mk>
