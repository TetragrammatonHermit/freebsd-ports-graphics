# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wkhtmltopdf
PORTVERSION=	0.12.1
CATEGORIES=	converters
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTVERSION}
DISTNAME=	wkhtmltox-${PORTVERSION}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Convert HTML (or live webpages) to PDF or image

LICENSE=	LGPL3
LICENSE_FILE_LGPL3=	${INSTALL_WRKSRC}/COPYING

LIB_DEPENDS+=	libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png


USES=			pkgconfig gmake perl5 iconv tar:bzip2
USE_XORG=		x11 xext xrender
USE_PERL5=		build
USE_LDCONFIG=		yes
HAS_CONFIGURE=		yes

WRKSRC=			${WRKDIR}/wkhtmltox-${PORTVERSION}
PATCH_WRKSRC=		${WRKSRC}/qt	
CONFIGURE_WRKSRC=	${WRKSRC}/build/qt
BUILD_WRKSRC=		${WRKSRC}/build/qt
INSTALL_WRKSRC=		${WRKSRC}/build/app

CONFIGURE_SCRIPT=	../../qt/configure
CONFIGURE_ARGS=	-prefix ${WRKSRC}/build/qt \
	-opensource -confirm-license -fast -release -static \
	-graphicssystem raster -webkit -exceptions -xmlpatterns -system-zlib \
	-system-libpng -system-libjpeg -no-libmng -no-libtiff -no-stl \
	-no-accessibility -no-qt3support -no-phonon -no-phonon-backend \
	-no-opengl -no-declarative -no-script -no-scripttools \
	-no-sql-ibase -no-sql-mysql -no-sql-odbc -no-sql-psql \
	-no-sql-sqlite -no-sql-sqlite2 -no-mmx -no-3dnow -no-sse -no-sse2 \
	-no-multimedia -nomake demos -nomake docs -nomake examples \
	-nomake tools -nomake tests -nomake translations -xrender -largefile \
	-iconv -openssl -no-rpath -no-dbus -no-nis -no-cups -no-pch \
	-no-gtkstyle -no-nas-sound -no-sm -no-xshape -no-xinerama -no-xcursor \
	-no-xfixes -no-xrandr -no-mitshm -no-xinput -no-xkb -no-glib \
	-no-gstreamer -D ENABLE_VIDEO=0 -no-openvg -no-xsync \
	-no-audio-backend -no-sse3 -no-ssse3 -no-sse4.1 -no-sse4.2 -no-avx \
	-no-neon

MAKE_ARGS+=	INSTALL_ROOT="${STAGEDIR}${PREFIX}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
BROKEN=		fails to extract on FreeBSD 7.X
.endif

.if ${ARCH} == "powerpc"
BROKEN=		Does not link on powerpc
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		-e 's|/usr/X11R6/include|${LOCALBASE}/include/X11|g' \
		-e 's|/usr/X11R6/lib|${LOCALBASE}/lib|g' \
		${PATCH_WRKSRC}/mkspecs/freebsd-g++/qmake.conf
	@${REINPLACE_CMD} -e "s|gcc|${CC}|g" -e "s|g++|${CXX}|g" \
		${PATCH_WRKSRC}/mkspecs/common/g++-base.conf
	@${REINPLACE_CMD} -e "s|share/man|man|g" \
		${WRKSRC}/src/image/image.pro \
		${WRKSRC}/src/pdf/pdf.pro
	@${MKDIR} ${WRKSRC}/build/app ${WRKSRC}/build/qt \
		${WRKSRC}/build/wkhtmltox

post-build:
	@cd ${WRKSRC}/build/app && ${SETENV} ${MAKE_ENV} \
		../qt/bin/qmake ../../wkhtmltopdf.pro && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} \
		${_MAKE_JOBS} ${MAKE_ARGS:C,^${DESTDIRNAME}=.*,,g} \
		${ALL_TARGET}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
