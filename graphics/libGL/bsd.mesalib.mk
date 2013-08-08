# bsd.mesalib.mk - shared code between MesaLib ports.
#
# !!! Here be dragons !!! (they seem to be everywhere these days)
#
# Remember to upgrade the following ports everytime you bump MESAVERSION:
#
#    - graphics/libEGL
#    - graphics/libGL
#    - graphics/dri
#
# $FreeBSD$

.MAKE.FreeBSD_UL=	yes

MESAVERSION=	${MESABASEVERSION}${MESASUBVERSION:C/^(.)/.\1/}
MESADISTVERSION=${MESABASEVERSION}${MESASUBVERSION:C/^(.)/-\1/}

.if defined(WITH_NEW_XORG)
MESABASEVERSION=	9.1.6
# if there is a subversion, include the '-' between 7.11-rc2 for example.
MESASUBVERSION=		
PLIST_SUB+=	OLD="@comment " NEW=""
.else
MESABASEVERSION=	7.6.1
MESASUBVERSION=		
PLIST_SUB+=	OLD="" NEW="@comment "
.endif

MASTER_SITES=	ftp://ftp.freedesktop.org/pub/mesa/${MESABASEVERSION}/
DISTFILES=	MesaLib-${MESADISTVERSION}${EXTRACT_SUFX}
MAINTAINER?=	x11@FreeBSD.org

BUILD_DEPENDS+=	makedepend:${PORTSDIR}/devel/makedepend \
		${PYTHON_SITELIBDIR}/libxml2.py:${PORTSDIR}/textproc/py-libxml2

USES=		bison gmake pathfix pkgconfig
USE_PYTHON_BUILD=-2.7
USE_BZIP2=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=--enable-gallium-llvm=no --without-gallium-drivers
#CONFIGURE_ARGS+=--disable-silent-rules
CONFIGURE_ENV+=ac_cv_prog_LEX=${LOCALBASE}/bin/flex

.if defined(WITH_NEW_XORG)
# probably be shared lib, and in it own port.
CONFIGURE_ARGS+=        --enable-shared-glapi=no
EXTRA_PATCHES+=	${PATCHDIR}/extra-configure \
		${PATCHDIR}/extra-m4_libtool \
		${PATCHDIR}/extra-src__gallium__include__pipe__p_config.h \
		${PATCHDIR}/extra-src_gallium_drivers_r300_r300-chipset.c \
		${PATCHDIR}/extra-src_gallium_drivers_r600_r600-asm.c \
		${PATCHDIR}/extra-src_gallium_drivers_r600_r600-shader.c \
		${PATCHDIR}/extra-src_gallium_drivers_r600_r600_state_common.c \
		${PATCHDIR}/extra-src_gallium_drivers_radeonsi_r600-buffer.c \
		${PATCHDIR}/extra-src_gallium_winsys_svga_drm_vmw-screen-ioctl.c \
		${PATCHDIR}/extra-src-glsl_ir_constant_expression.cpp \
		${PATCHDIR}/extra_src_mapi_glapi_gen_gl-gentable.py \
		${PATCHDIR}/extra-src_mesa_main_compiler.h \
		${PATCHDIR}/extra-src_mesa_drivers_dri_common_Makefile.in
# we need to reapply these patches because we doing wierd stuff with autogen
REAPPLY_PATCHES= \
		${PATCHDIR}/extra-src_egl_main_Makefile.in \
		${PATCHDIR}/extra-src_glx_Makefile.in \
		${PATCHDIR}/extra-src_mapi_shared-glapi_Makefile.in \
		${PATCHDIR}/extra-src_mesa_drivers_dri_common_xmlpool_Makefile.in \
		${PATCHDIR}/extra-src_mesa_libdricore_Makefile.in

#               ${PATCHDIR}/extra-src_mesa_drivers_x11_Makefile.in
.else
EXTRA_PATCHES+=	${PATCHDIR}/extra-configure-old \
		${PATCHDIR}/extra-mach64_context.h-old \
		${PATCHDIR}/extra-src__mesa__x86-64__glapi_x86-64.S \
		${PATCHDIR}/extra-src__mesa__x86-64__xform4.S \
		${PATCHDIR}/extra-src__mesa__x86__glapi_x86.S \
		${PATCHDIR}/extra-src__mesa__x86__read_rgba_span_x86.S \
		${PATCHDIR}/extra-src_glx_x11_XF86dri.c
CONFIGURE_ARGS+=--disable-glut --disable-glw --disable-glu

ALL_TARGET=		default
.endif

MASTERDIR=		${.CURDIR}/../../graphics/libGL
PATCHDIR=		${MASTERDIR}/files
DESCR=			${.CURDIR}/pkg-descr
PLIST=			${.CURDIR}/pkg-plist
WRKSRC=			${WRKDIR}/Mesa-${MESADISTVERSION}

COMPONENT=		${PORTNAME:L:C/^lib//:C/mesa-//}

.if ${COMPONENT:Megl} == ""
CONFIGURE_ARGS+=	--disable-egl
.else
CONFIGURE_ARGS+=	--enable-egl
.endif

.if ${COMPONENT:Mdri} == ""
CONFIGURE_ARGS+=	--with-dri-drivers=no
.else
# done in the dri port
.endif

.if !defined(WITH_NEW_XORG)
.if defined(WITHOUT_XCB)
CONFIGURE_ARGS+=	--disable-xcb
.else
CONFIGURE_ARGS+=	--enable-xcb
.endif
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-ffast-math|${FAST_MATH}|' -e 's|x86_64|amd64|' \
		${WRKSRC}/configure
# workaround for stupid rerunning configure in do-build step
# xxx
.if defined(WITH_NEW_XORG)
	cd ${WRKSRC} && env NOCONFIGURE=1 sh autogen.sh
. for file in ${REAPPLY_PATCHES}
	@cd ${WRKSRC} && ${PATCH} --quiet  < ${file}
. endfor
# make sure the pkg-config files are installed in the correct place.
# this was reverted by running autogen.sh
	@${FIND} ${WRKSRC} -name Makefile.in -type f | ${XARGS} ${REINPLACE_CMD} -e \
		's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' ;
.else
	@${REINPLACE_CMD} -e 's|[$$](INSTALL_LIB_DIR)/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/src/glu/Makefile \
		${WRKSRC}/src/mesa/Makefile \
		${WRKSRC}/src/mesa/drivers/dri/Makefile
.endif

