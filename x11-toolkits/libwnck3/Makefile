# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11-toolkits/libwnck3/Makefile 19752 2014-06-24 20:41:33Z kwm $

PORTNAME=	libwnck
PORTVERSION=	3.4.7
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	3
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library used for writing pagers and taskslists

USES=		tar:xz

.if !defined(REFERENCE_PORT)

USES+=		bison gettext gmake libtool:keepla pathfix pkgconfig
USE_GNOME=	gtk30 intlhack introspection:build referencehack
USE_XORG=	xres x11
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-tools
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	STARTUP
OPTIONS_DEFAULT=STARTUP
STARTUP_DESC=	Startup notification support
STARTUP_LIB_DEPENDS=	libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification
STARTUP_CONFIGURE_ENABLE=	startup-notification

.include <bsd.port.mk>

.endif
