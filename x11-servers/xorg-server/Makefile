# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME?=	xorg-server
PORTVERSION=	1.14.4.901
PORTEPOCH?=	1
CATEGORIES=	x11-servers
MASTER_SITES=	XORG
MASTER_SITE_SUBDIR=	individual/xserver
DISTNAME=	xorg-server-${PORTVERSION}

MAINTAINER=	x11@FreeBSD.org
COMMENT?=	X.Org X server and related programs

LIB_DEPENDS=	libdrm.so:${PORTSDIR}/graphics/libdrm
RUN_DEPENDS=	xkeyboard-config>=2.5:${PORTSDIR}/x11/xkeyboard-config \
		xkbcomp:${PORTSDIR}/x11/xkbcomp

XORG_CAT=	xserver
SLAVE_PORT?=	no

OPTIONS_DEFINE=	AIGLX SUID
OPTIONS_RADIO=	CONF
OPTIONS_RADIO_CONF= HAL DEVD
AIGLX_DESC=	Compile with Accelerated Indirect GLX support
SUID_DESC=	Install the Xorg server with setuid bit set
HAL_DESC=	Compile with HAL config support
DEVD_DESC=	Use devd for autoconfiguration of input devices (experimental)
OPTIONS_DEFAULT=AIGLX SUID DEVD

OPTIONS_EXCLUDE_sparc64=	HAL

.include <bsd.port.options.mk>

USE_BZIP2=	yes
USES=		gmake perl5
USE_PERL5=	build
USE_GL=		gl
USE_XORG?=	xf86driproto glproto xdmcp x11 xkbfile xxf86misc xxf86vm xaw7 \
		xmu xt xpm xext randrproto renderproto fixesproto damageproto \
		dri2proto xcmiscproto xextproto xproto xtrans xf86miscproto \
		xf86vidmodeproto xf86bigfontproto scrnsaverproto bigreqsproto \
		resourceproto fontsproto inputproto xf86dgaproto \
		videoproto compositeproto trapproto recordproto xineramaproto \
		xinerama evieproto xfont fontenc xkbui pixman pciaccess

USE_OPENSSL=	yes
CONFIGURE_ARGS?=--disable-dmx --disable-xvfb --disable-xnest \
		--without-xmlto --disable-docs --disable-devel-docs \
		--localstatedir=/var --without-dtrace --disable-xephyr \
		--enable-record=yes

.if ${SLAVE_PORT} == "no"
SUB_FILES=	pkg-install pkg-deinstall
.else
# for slave ports we need to overwrite PLIST, so it doesn't overwrite
# PLIST_FILES, with the masterport plist.
PLIST=		${.CURDIR}/pkg-plist
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_OPENSSL_BASE)
# The reason why I use this is cause openssl from base doesn't install a .pc file
# and configure will fail trying to find it. Setting both of those variables to
# a *non-empty* value by-passes the pkg-config check.
CONFIGURE_ENV=	SHA1_LIB="-L/usr/lib -lcrypto" SHA1_CFLAGS="-I/usr/include"
.endif

.if ${PORT_OPTIONS:MHAL}
LIB_DEPENDS+=	libhal.so:${PORTSDIR}/sysutils/hal
CONFIGURE_ARGS+=	--enable-config-hal=yes
.else
CONFIGURE_ARGS+=	--enable-config-hal=no
.endif

.if ${PORT_OPTIONS:MDEVD}
EXTRA_PATCHES+=		${FILESDIR}/extra-devd
EXTRA_PATCHES+=	${FILESDIR}/extra-config_devd
.endif

.if ${PORT_OPTIONS:MAIGLX}
CONFIGURE_ARGS+=	--enable-aiglx=yes
.else
CONFIGURE_ARGS+=	--enable-aiglx=no
.endif

# We handle Xorg setuid in the plist. This allows to build xorg-server as 
# a user.
CONFIGURE_ARGS+=--enable-install-setuid=no
.if ${PORT_OPTIONS:MSUID}
PLIST_SUB+=	SUID=""
.else
PLIST_SUB+=	SUID="@comment"
.endif

.if ${ARCH} == i386
EXTRA_PATCHES+=	${FILESDIR}/extra-arch-i386
.endif

.if ${ARCH} == ia64
PLIST_SUB+=	IA64_NA="@comment "
EXTRA_PATCHES=	${.CURDIR}/files/extra-arch-ia64
.else
PLIST_SUB+=	IA64_NA=""
.endif

.if ${ARCH} == powerpc || ${ARCH} == powerpc64
PLIST_SUB+=	PPC_NA="@comment "
EXTRA_PATCHES=	${.CURDIR}/files/extra-arch-powerpc
.else
PLIST_SUB+=	PPC_NA=""
.endif

.if ${ARCH} == sparc64
PLIST_SUB+=	SPARC64=""
PLIST_SUB+=	SPARC64_NA="@comment "
EXTRA_PATCHES+=	${FILESDIR}/extra-arch-sparc64
.else
PLIST_SUB+=	SPARC64="@comment "
PLIST_SUB+=	SPARC64_NA=""
.endif

.if ${ARCH} == amd64 || ${ARCH} == i386 || ${ARCH} == sparc64
PLIST_SUB+=	AMD64_I386_SPARC64=""
.else
PLIST_SUB+=	AMD64_I386_SPARC64="@comment "
.endif

.if ${PORT_OPTIONS:MSUID}
pre-everything::
	@${ECHO_MSG} "By default, the X Server installs as a set-user-id root binary. When run by"
	@${ECHO_MSG} "a normal user, it checks arguments and environment as done in the x11/wrapper"
	@${ECHO_MSG} "port before handling them normally.  If you are concerned about the security"
	@${ECHO_MSG} "of this, but still want to run an X Server (for example using xdm/kdm/gdm,"
	@${ECHO_MSG} "which will still run the server as root), you can cancel the build and set"
	@${ECHO_MSG} "xorg-server_UNSET=SUID in /etc/make.conf."
.endif

post-patch:
	@${REINPLACE_CMD} 's/test.*-traditional.*;/true;/' \
		${WRKSRC}/configure
# build libglx.so but don't install it yet. which is done in pre-install.
	@${REINPLACE_CMD} -e 's|@GLX_TRUE@GLXMODS =|@GLX_BOGUS@GLXMODS =|g' \
		-e 's|^LTLIBRARIES = |LTLIBRARIES = libglx.la |g' \
		${WRKSRC}/hw/xfree86/dixmods/Makefile.in
 
post-configure:
.if ${PORT_OPTIONS:MDEVD}
	@${REINPLACE_CMD} -e 's|config\.c|config.c devd.c|g' \
		-e 's|config\.lo|config.lo devd.lo|g' \
		${WRKSRC}/config/Makefile
	@${REINPLACE_CMD} -e 's|^/\* #undef CONFIG_UDEV \*/|#define CONFIG_DEVD 1|' \
		${WRKSRC}/include/dix-config.h
.endif

.if ${SLAVE_PORT} == "no"
post-install:
# The .xorg dir because else the xorg-server might not load the correct 
# libglx module.
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/xorg/modules/extensions/.xorg
	${INSTALL_LIB} ${WRKSRC}/hw/xfree86/dixmods/.libs/libglx.so \
		${STAGEDIR}${PREFIX}/lib/xorg/modules/extensions/.xorg/
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/xorg/modules/*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/xorg/modules/multimedia/*.so
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/X11/xorg.conf.d
.endif

.include <bsd.port.post.mk>
