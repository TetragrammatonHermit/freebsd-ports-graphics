# $FreeBSD$

PORTNAME=	xf86-video-chips
PORTVERSION=	1.2.5
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org chips display driver

.include <bsd.port.options.mk>

.if defined(WITH_NEW_XORG)
EXTRA_PATCHES+=	${PATCHDIR}/extra-mibstore
.endif

XORG_CAT=	driver
MAN4=		chips.4x

.include <bsd.port.mk>
