# $FreeBSD$

PORTNAME=	uTox
DISTVERSION=	0.1.8.git20141012
CATEGORIES=	net-im net-p2p

MAINTAINER=	fidaj@ukr.net
COMMENT=	Lightweight Tox client

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libtoxcore.a:${PORTSDIR}/net-im/tox \
		${LOCALBASE}/include/linux/videodev2.h:${PORTSDIR}/multimedia/v4l_compat
LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2 \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig \
		libv4lconvert.so:${PORTSDIR}/multimedia/libv4l \
		libvpx.so:${PORTSDIR}/multimedia/libvpx
RUN_DEPENDS=	${LOCALBASE}/lib/libtoxcore.a:${PORTSDIR}/net-im/tox

USE_GITHUB=	yes
GH_ACCOUNT=	notsecure
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	265d723

USES=		compiler:c11 desktop-file-utils gmake openal:al pkgconfig
USE_XORG=	x11 xext xrender
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=		DBUS
OPTIONS_DEFAULT=	DBUS

DBUS_LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus
DBUS_MAKE_ARGS_OFF=	DBUS=0

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/utox

.include <bsd.port.mk>
