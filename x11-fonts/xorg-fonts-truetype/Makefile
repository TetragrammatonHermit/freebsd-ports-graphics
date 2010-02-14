# New ports collection makefile for:    xorg-fonts-truetype
# Date created:		30 May 2004
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD: ports/x11-fonts/xorg-fonts-truetype/Makefile,v 1.14 2009/01/23 16:28:04 flz Exp $
#

PORTNAME=	xorg-fonts-truetype
PORTVERSION=	7.4
CATEGORIES=	x11-fonts
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org TrueType fonts

RUN_DEPENDS=	${FONTDIR}/TTF/luximb.ttf:${PORTSDIR}/x11-fonts/font-bh-ttf \
		${FONTDIR}/OTF/SyrCOMAdiabene.otf:${PORTSDIR}/x11-fonts/font-misc-meltho \
		${FONTDIR}/TTF/GohaTibebZemen.ttf:${PORTSDIR}/x11-fonts/font-misc-ethiopic \
		${LOCALBASE}/lib/X11/fonts/encodings/encodings.dir:${PORTSDIR}/x11-fonts/encodings \
		${LOCALBASE}/lib/X11/fonts/bitstream-vera/VeraIt.ttf:${PORTSDIR}/x11-fonts/bitstream-vera \

do-install:	# empty

NO_BUILD=	# none
FONTDIR=	${LOCALBASE}/lib/X11/fonts

.include <bsd.port.mk>
