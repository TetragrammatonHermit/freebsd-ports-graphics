#
#
#
#
#
# $FreeBSD$

IOVERSION?=	20080904

IO_BIN=		${LOCALBASE}/bin/io
IO_PORT=	${PORTSDIR}/lang/io

BUILD_DEPENDS+=	${IO_BIN}:${IO_PORT}

WRKSRC?=		${WRKDIR}/io
DEFAULT_ADDONS?=	${PORTNAME}
ADDON_DIR= 	${PREFIX}/lib/io/addons/${DEFAULT_ADDONS}
BUILD_DIR= 	${WRKSRC}/addons/${DEFAULT_ADDONS}
HEADER_PATHS=	append("${PREFIX}/include/io")


post-patch:
	cd ${WRKSRC}/addons && for addon in *; do \
	if ! ${ECHO_CMD} ${DEFAULT_ADDONS} | ${GREP} $$addon > /dev/null; then \
	                              ${RM} -fr $$addon; \
	fi; \
	done
	@${REINPLACE_CMD} -e '/headerSearchPaths := List clone/s|$$| ${HEADER_PATHS}|' \
		    -e 's|/usr/X11R6|${LOCALBASE}|g' \
		${WRKSRC}/build/AddonBuilder.io
	@${REINPLACE_CMD} -e 's|CFLAGS = $$(OPTIMIZE)|CFLAGS +=|' \
	    ${WRKSRC}/Makefile.lib

do-build:
	cd ${WRKSRC}; ${SETENV} ${LOCALBASE}/bin/io build.io -a ${DEFAULT_ADDONS}

do-install:
	${MKDIR} ${ADDON_DIR}
	${MKDIR} ${ADDON_DIR}/_build
	if [ -d  ${BUILD_DIR}/_build/dll ]; then \
		${CP} -rf ${BUILD_DIR}/_build/dll ${ADDON_DIR}/_build/; \
	fi
	if [ -d ${BUILD_DIR}/_build/lib ]; then \
		${CP} -rf ${BUILD_DIR}/_build/lib ${ADDON_DIR}/_build/; \
	fi
	if [ -d ${BUILD_DIR}/_build/objs ]; then \
		${CP} -rf ${BUILD_DIR}/_build/objs ${ADDON_DIR}/_build/; \
	fi
	if [ -d ${BUILD_DIR}/_build/headers ]; then \
		${CP} -rf ${BUILD_DIR}/_build/headers ${ADDON_DIR}/_build/; \
	fi
	if [ -d ${BUILD_DIR}/io ]; then \
		${CP} -rf ${BUILD_DIR}/io ${ADDON_DIR}/; \
	fi
	if [ -d ${BUILD_DIR}/depends ]; then \
		${CP} -rf ${BUILD_DIR}/depends ${ADDON_DIR}/; \
	fi
	if [ -d ${BUILD_DIR}/protos ]; then \
		${CP} -rf ${BUILD_DIR}/protos ${ADDON_DIR}/; \
	fi
	if [ -e ${BUILD_DIR}/build.io ]; then \
		${CP} -f ${BUILD_DIR}/build.io ${ADDON_DIR}/; \
	fi

