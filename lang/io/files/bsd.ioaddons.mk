#
# 
#
#
#
# $FreeBSD$

IOVERSION?=	20080904

_USE_IO= 	blowfish


blowfish_RUN_DEPENDS=	${PREFIX}/lib/io/addons/Blowfish/io/Blowfish.io${PORTSDIR}/security/io-blowfish

WRKSRC=			${WRKDIR}/io

TARGET_DIR= ${PREFIX}/lib/io/addons/${ADDON_NAME}
SRC_DIR= ${WRKSRC}/addons/${ADDON_NAME}

HEADER_PATHS=	append("${PREFIX}/include/io")
LIB_PATHS=
.for i in ${ADDON_DEPENDS_ON_ADDONS}
HEADER_PATHS+=	append("${PREFIX}/include/io/${i}")
LIB_PATHS+=	append("${PREFIX}/lib/io/addons/${i}/_build/dll")
.endfor


do-build:
	cd ${WRKSRC} && ${PREFIX}/bin/io build.io -a ${ADDON_NAME}

do-install:
	${INSTALL_DATA_DIR} ${TARGET_DIR}
		${INSTALL_DATA_DIR} ${TARGET_DIR}/_build
	if [ -d  ${SRC_DIR}/_build/dll ]; then \
		${CP} -rf ${SRC_DIR}/_build/dll ${TARGET_DIR}/_build/; \
	fi
	if [ -d ${SRC_DIR}/_build/lib ]; then \
		${CP} -rf ${SRC_DIR}/_build/lib ${TARGET_DIR}/_build/; \
	fi
	if [ -d ${SRC_DIR}/io ]; then \
		${CP} -rf ${SRC_DIR}/io ${TARGET_DIR}/; \
	fi
	if [ -e ${SRC_DIR}/depends ]; then \
		${CP} -f ${SRC_DIR}/depends ${TARGET_DIR}/; \
	fi
	if [ -e ${SRC_DIR}/protos ]; then \
		${CP} -f ${SRC_DIR}/protos ${TARGET_DIR}/; \
	fi
	if [ -e ${SRC_DIR}/build.io ]; then \
		${CP} -f ${SRC_DIR}/build.io ${TARGET_DIR}/; \
	fi
	if [ ! -z "${ADDON_INSTALL_HEADERS}" ]; then \
		${INSTALL_DATA_DIR} ${PREFIX}/include/io/${ADDON_NAME}; \
		${CP} -f ${SRC_DIR}/source/*.h ${PREFIX}/include/io/${ADDON_NAME
	fi

