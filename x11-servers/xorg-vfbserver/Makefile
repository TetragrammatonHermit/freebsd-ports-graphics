# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD: head/x11-servers/xorg-vfbserver/Makefile 351411 2014-04-16 18:28:47Z zeising $

PORTNAME=	xorg-vfbserver
PORTVERSION=	1.14.7
CATEGORIES=	x11-servers
MASTER_SITES=	XORG
MASTER_SITE_SUBDIR=	individual/xserver
DISTNAME=	xorg-server-${PORTVERSION}

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X virtual framebuffer server from X.Org

USE_XORG=	xau xfont pixman xcmiscproto xtrans bigreqsproto \
		xproto fontsproto resourceproto presentproto \
		fixesproto damageproto randrproto renderproto \
		xextproto inputproto kbproto videoproto \
		compositeproto recordproto xineramaproto \
		xkbfile xdmcp
RUN_DEPENDS=	xkeyboard-config>=2.5:${PORTSDIR}/x11/xkeyboard-config \
		xkbcomp:${PORTSDIR}/x11/xkbcomp

USES=		pkgconfig tar:bzip2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-xwin --disable-xwayland --disable-xephyr \
		--disable-xnest --disable-xorg \
		--enable-xvfb --disable-glx --disable-aiglx \
		--without-xmlto --disable-docs --disable-devel-docs \
		--disable-config-hal --disable-libdrm --disable-glx-tls \
		--disable-dri --disable-pciaccess --disable-screensaver \
		--disable-vbe --disable-vgahw --disable-xfake \
		--disable-xfbdev --without-dtrace

INSTALL_WRKSRC=	${WRKSRC}/hw/vfb
PLIST_FILES=	bin/Xvfb \
		man/man1/Xvfb.1.gz

.include <bsd.port.mk>
