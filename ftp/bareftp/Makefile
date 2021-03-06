# Created by: Chris Petrik (chris@officialunix.com)
# $FreeBSD$

PORTNAME=	bareftp
PORTVERSION=	0.3.10
PORTREVISION=	1
CATEGORIES=	ftp
MASTER_SITES=	http://www.bareftp.org/release/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FTP client made in C sharp

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datarootdir="${PREFIX}/share" \
		--libdir="${PREFIX}/lib" \
		--localedir="${PREFIX}/share/locale" \
		--includedir="${LOCALBASE}/include"

INSTALLS_ICONS=	yes
USES=		gettext gmake libtool pkgconfig
USE_GNOME=	gtksharp20 gnomesharp20

USE_LDCONFIG=	yes

OPTIONS_DEFINE=	GNOMEKEYRING NLS
OPTIONS_DEFAULT=GNOMEKEYRING

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNOMEKEYRING}
KEYRING_DETECT=	${LOCALBASE}/libdata/pkgconfig/gnome-keyring-sharp-1.0.pc
BUILD_DEPENDS+=	${KEYRING_DETECT}:${PORTSDIR}/security/gnome-keyring-sharp
RUN_DEPENDS+=	${KEYRING_DETECT}:${PORTSDIR}/security/gnome-keyring-sharp
.else
CONFIGURE_ARGS+=	--without-gnomekeyring
.endif

.if ${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

# TODO
# Ugly way but configure ignore "--localedir=" fu* ;/
pre-build:
	@${REINPLACE_CMD} -e 's|$$(prefix)/$$(DATADIRNAME)|${PREFIX}/share|g' \
		${WRKSRC}/po/Makefile

.include <bsd.port.mk>
