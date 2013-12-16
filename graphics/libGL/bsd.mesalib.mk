# bsd.mesalib.mk - shared code between MesaLib ports.
#
# !!! Here be dragons !!! (they seem to be everywhere these days)
#
# Remember to upgrade the following ports everytime you bump MESAVERSION:
#
#    - graphics/libEGL
#    - graphics/libGL
#    - grahpics/libglesv2
#    - graphics/dri
#
# $FreeBSD$

.MAKE.FreeBSD_UL=	yes

MESAVERSION=	${MESABASEVERSION}${MESASUBVERSION:C/^(.)/.\1/}
MESADISTVERSION=${MESABASEVERSION}${MESASUBVERSION:C/^(.)/-\1/}

.if defined(WITH_NEW_MESA)
MESABASEVERSION=	10.0.1
# if there is a subversion, don't include the '-' between 7.11-rc2.
MESASUBVERSION=	
MASTER_SITES=	ftp://ftp.freedesktop.org/pub/mesa/${MESABASEVERSION}/
PLIST_SUB+=	OLD="@comment " NEW=""

# work around libarchive bug?
EXTRACT_CMD=${LOCALBASE}/bin/gtar
EXTRACT_DEPENDS+=	gtar:${PORTSDIR}/archivers/gtar
.else
MESABASEVERSION=	9.1.7
MESASUBVERSION=		
MASTER_SITES=	ftp://ftp.freedesktop.org/pub/mesa/${MESABASEVERSION:R}/
PLIST_SUB+=	OLD="" NEW="@comment "
.endif

DISTFILES=	MesaLib-${MESADISTVERSION}${EXTRACT_SUFX}
MAINTAINER?=	x11@FreeBSD.org

BUILD_DEPENDS+=	makedepend:${PORTSDIR}/devel/makedepend \
		python2:${PORTSDIR}/lang/python2 \
		${PYTHON_SITELIBDIR}/libxml2.py:${PORTSDIR}/textproc/py-libxml2

USES+=		bison gmake pathfix pkgconfig shebangfix
USE_PYTHON_BUILD=-2.7
USE_BZIP2=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

CPPFLAGS+=	-isystem${LOCALBASE}/include
LDFLAGS+=	-Wl,-Y${LOCALBASE}/lib

.if ${OSVERSION} < 1000033
BUILD_DEPENDS+=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex
CONFIGURE_ENV+=ac_cv_prog_LEX=${LOCALBASE}/bin/flex
.endif

USE_AUTOTOOLS=	autoconf:env automake:env libtool:env
# probably be shared lib, and in it own port.
CONFIGURE_ARGS+=        --enable-shared-glapi=no
# we need to reapply these patches because we doing wierd stuff with autogen
REAPPLY_PATCHES= \
		${PATCHDIR}/patch-configure \
		${PATCHDIR}/patch-src_egl_main_Makefile.in \
		${PATCHDIR}/patch-src_glx_Makefile.in \
		${PATCHDIR}/patch-src_mapi_es2api_Makefile.in \
		${PATCHDIR}/patch-src_mapi_shared-glapi_Makefile.in \
		${PATCHDIR}/patch-src_mesa_drivers_dri_common_Makefile.in \
		${PATCHDIR}/patch-src_mesa_drivers_dri_common_xmlpool_Makefile.in

.if !defined(WITH_NEW_MESA)
REAPPLY_PATCHES+=	${PATCHDIR}/patch-src_mesa_libdricore_Makefile.in
.endif

python_OLD_CMD=	"/usr/bin/env[[:space:]]python"
python_CMD=	${LOCALBASE}/bin/python2
SHEBANG_FILES=	src/gallium/*/*/*.py src/gallium/tools/trace/*.py \
		src/gallium/drivers/svga/svgadump/svga_dump.py \
		src/glsl/tests/compare_ir src/mapi/glapi/gen/*.py
.if defined(WITH_NEW_MESA)
SHEBANG_FILES+=	src/mapi/mapi_abi.py
.endif

MASTERDIR=		${.CURDIR}/../../graphics/libGL
.if defined(WITH_NEW_MESA)
PATCHDIR=		${MASTERDIR}/files
.else
PATCHDIR=		${MASTERDIR}/files-old
.endif
DESCR=			${.CURDIR}/pkg-descr
PLIST=			${.CURDIR}/pkg-plist
WRKSRC=			${WRKDIR}/Mesa-${MESADISTVERSION}

COMPONENT=		${PORTNAME:L:C/^lib//:C/mesa-//}

.if ${COMPONENT:Mglesv2} == ""
CONFIGURE_ARGS+=	--disable-gles2
.else
CONFIGURE_ARGS+=	--enable-gles2
.endif

.if ${COMPONENT:Megl} == ""
CONFIGURE_ARGS+=	--disable-egl
.else
CONFIGURE_ARGS+=	--enable-egl
.endif

.if ${COMPONENT:Mdri} == ""
CONFIGURE_ARGS+=--with-dri-drivers=no
CONFIGURE_ARGS+=--enable-gallium-llvm=no --without-gallium-drivers
.else
# done in the dri port
.endif

.if ${COMPONENT:Mvdpau} == ""
CONFIGURE_ARGS+=--disable-vdpau
.else
CONFIGURE_ARGS+=--enable-vdpau
.endif

.if defined(WITHOUT_XCB)
CONFIGURE_ARGS+=	--disable-xcb
.else
CONFIGURE_ARGS+=	--enable-xcb
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-ffast-math|${FAST_MATH}|' -e 's|x86_64|amd64|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|g' \
		${WRKSRC}/src/mesa/drivers/dri/common/xmlconfig.c
.if !defined(WITH_NEW_MESA)
	@${REINPLACE_CMD} -e 's|#!/use/bin/python|#!${LOCALBASE}/bin/python2|g' \
		${WRKSRC}/src/mesa/drivers/dri/common/xmlpool/gen_xmlpool.py \
		${WRKSRC}/src/glsl/builtins/tools/*.py
.else
	@${REINPLACE_CMD} -e 's|#!/use/bin/python|#!${LOCALBASE}/bin/python2|g' \
		${WRKSRC}/src/mesa/drivers/dri/common/xmlpool/gen_xmlpool.py
.endif
	@${REINPLACE_CMD} -e 's|!/use/bin/python2|!${LOCALBASE}/bin/python2|g' \
		${WRKSRC}/src/mesa/main/get_hash_generator.py \
		${WRKSRC}/src/mapi/glapi/gen/gl_enums.py \
		${WRKSRC}/src/mapi/glapi/gen/gl_table.py

pre-configure:
# workaround for stupid rerunning configure in do-build step
# xxx
	cd ${WRKSRC} && env NOCONFIGURE=1 sh autogen.sh
. for file in ${REAPPLY_PATCHES}
	@cd ${WRKSRC} && ${PATCH} -p0 --quiet  < ${file}
. endfor
# make sure the pkg-config files are installed in the correct place.
# this was reverted by running autogen.sh
	@${FIND} ${WRKSRC} -name Makefile.in -type f | ${XARGS} ${REINPLACE_CMD} -e \
		's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' ;

