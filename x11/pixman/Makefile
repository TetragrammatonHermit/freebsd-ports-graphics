# $FreeBSD$

PORTNAME=	pixman
PORTVERSION=	0.32.4
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Low-level pixel manipulation library

USES=		libtool perl5
USE_PERL5=	build
XORG_CAT=	lib
CONFIGURE_ARGS=	--disable-gtk
INSTALL_TARGET=	install-strip

PLIST_SUB+=	LIBVERSION=${PORTVERSION}

.include <bsd.port.mk>
