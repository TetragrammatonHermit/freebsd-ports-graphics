# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gmpc-lyricwiki
PORTVERSION=	11.8.16
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://download.sarine.nl/Programs/gmpc/${PORTVERSION}/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Lyricswiki Provider plugin for gmpc

LIB_DEPENDS=	libmpd.so:${PORTSDIR}/audio/libmpd
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gmpc.pc:${PORTSDIR}/audio/gmpc
RUN_DEPENDS=	gmpc:${PORTSDIR}/audio/gmpc

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
USES=		gettext gmake libtool pkgconfig
USE_GNOME=	intltool glib20 gtk20 libxml2

.include <bsd.port.mk>
