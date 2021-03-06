# Created by: alepulver
# $FreeBSD$

PORTNAME=	odamex
PORTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Odamex/${PORTVERSION}
DISTNAME=	odamex-src-${PORTVERSION}

MAINTAINER=	cpm@fbsd.es
COMMENT=	Client/server multiplayer engine for Doom

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_SDL=	sdl mixer
USES=		cmake dos2unix tar:bzip2
DOS2UNIX_FILES=	CMakeLists.txt odalaunch/CMakeLists.txt common/d_main.cpp

OPTIONS_DEFINE=	DOCS LAUNCHER

LAUNCHER_DESC=	Enable GUI launcher program

OPTIONS_SUB=	yes

LAUNCHER_USE=		WX=3.0
LAUNCHER_CMAKE_ON=	-DODALAUNCH_TARGET=on -DNO_AG-ODALAUNCH_TARGET=off -DwxWidgets_CONFIG_EXECUTABLE=${PREFIX}/bin/wxgtk2u-3.0-config
LAUNCHER_CMAKE_OFF=	-DODALAUNCH_TARGET=off

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|%%DMDIR%%|${DMDIR}|; \
		s|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/common/d_main.cpp
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/odalaunch/src/dlg_main.cpp
	@${REINPLACE_CMD} -e 's|%%WX_VER%%|${WX_VERSION}|' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/odalaunch/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|-waddir /usr/share/doom||' \
		${WRKSRC}/installer/arch/odamex.desktop

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/client/odamex ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/server/odasrv ${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MLAUNCHER}
	${INSTALL_PROGRAM} ${WRKSRC}/odalaunch/odalaunch ${STAGEDIR}${PREFIX}/bin
.endif
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/odamex.wad ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${STAGEDIR}${DOCSDIR}
.for f in odamex odasrv
	${INSTALL_DATA} ${WRKSRC}/media/icon_${f}_*.png ${STAGEDIR}${PREFIX}/share/pixmaps
.endfor
.if ${PORT_OPTIONS:MLAUNCHER}
	${INSTALL_DATA} ${WRKSRC}/media/icon_odalaunch_*.png ${STAGEDIR}${PREFIX}/share/pixmaps
.endif
.for f in odamex odasrv
	${INSTALL_DATA} ${WRKSRC}/installer/arch/${f}.desktop ${STAGEDIR}${PREFIX}/share/applications
.endfor
.if ${PORT_OPTIONS:MLAUNCHER}
	${INSTALL_DATA} ${WRKSRC}/installer/arch/odalaunch.desktop ${STAGEDIR}${PREFIX}/share/applications
.endif

.include "${.CURDIR}/../doom-data/Makefile.include"

.include <bsd.port.mk>
