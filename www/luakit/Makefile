# Created by: gugabsd <gugabsd@mundounix.com.br>
# $FreeBSD$

PORTNAME=	luakit
PORTVERSION=	2012.09.13r1
PORTREVISION=	4
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast, small, webkit based browser framework extensible by Lua

LICENSE=	GPLv3

BUILD_DEPENDS=	help2man:${PORTSDIR}/misc/help2man
LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3 \
		libwebkitgtk-1.0.so:${PORTSDIR}/www/webkit-gtk2 \
		libunique-1.0.so:${PORTSDIR}/x11-toolkits/unique
RUN_DEPENDS=	${LUA_PKGNAMEPREFIX}luafilesystem>=0:${PORTSDIR}/devel/luafilesystem-51

USE_GITHUB=	yes
GH_ACCOUNT=	mason-larobina
GH_PROGECT=	${PORTNAME}
GH_TAGNAME=	${PORTVERSION:C/r/-r/}
GH_COMMIT=	0d5f4ab

USES=		desktop-file-utils gmake lua:51 pkgconfig
USE_GNOME=	glib20 gtk20
MAKE_ARGS+=	USE_UNIQUE=1 NO_JAVASCRIPTCORE=1

OPTIONS_DEFINE=	LUAJIT
LUAJIT_DESC=	Use the Just-In-Time compiler for lua

.include <bsd.port.options.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not install on sparc64
.endif

.if ${PORT_OPTIONS:MLUAJIT}
LIB_DEPENDS+=	libluajit-5.1.so:${PORTSDIR}/lang/luajit
MAKE_ARGS+=	USE_LUAJIT=1
.else
MAKE_ARGS+=	USE_LUAJIT=0
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|(DESTDIR)/usr|(INSTALLDIR)|' \
		-e 's|(DESTDIR)|(INSTALLDIR)|' ${WRKSRC}/Makefile
	@${SED} -I "" 's|/etc/xdg/luakit|${LOCALBASE}&|' \
		${WRKSRC}/lib/lousy/util.lua
	@${REINPLACE_CMD} -e \
		's|share/man|man| ; s|luakit/docs|doc/luakit| ; \
		/MANPREFIX */s|?=|=|' \
		${WRKSRC}/config.mk
	@${REINPLACE_CMD} -e 's|bin/env lua|&${LUA_VER_STR}|' \
		${WRKSRC}/build-utils/gentokens.lua

.include <bsd.port.mk>
