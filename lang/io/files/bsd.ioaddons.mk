#
# 
#
#
#
# $FreeBSD$

IOVERSION?=	20080904


WRKSRC?=		${WRKDIR}/io
DEFAULT_ADDONS?=	${PORTNAME}
TARGET_DIR= 	${PREFIX}/lib/io/addons/${DEFAULT_ADDONS}
SRC_DIR= 	${WRKSRC}/addons/${DEFAULT_ADDONS}

post-patch:
	cd ${WRKSRC}/addons && for addon in *; do \
	if ! ${ECHO_CMD} ${DEFAULT_ADDONS} | ${GREP} $$addon > /dev/null; then \
	                              ${RM} -fr $$addon; \
	fi; \
 done

do-build:
	cd ${WRKSRC}; ${SETENV} ${LOCALBASE}/bin/io build.io -a ${DEFAULT_ADDONS}

do-install:
	${MKDIR} ${TARGET_DIR}
	${MKDIR} ${TARGET_DIR}/_build
	if [ -d  ${SRC_DIR}/_build/dll ]; then \
		${CP} -rf ${SRC_DIR}/_build/dll ${TARGET_DIR}/_build/; \
	fi
	if [ -d ${SRC_DIR}/_build/lib ]; then \
		${CP} -rf ${SRC_DIR}/_build/lib ${TARGET_DIR}/_build/; \
	fi
	if [ -d ${SRC_DIR}/_build/objs ]; then \
		${CP} -rf ${SRC_DIR}/_build/objs ${TARGET_DIR}/_build/; \
	fi
	if [ -d ${SRC_DIR}/_build/headers ]; then \
		${CP} -rf ${SRC_DIR}/_build/headers ${TARGET_DIR}/_build/; \
	fi
	if [ -d ${SRC_DIR}/io ]; then \
		${CP} -rf ${SRC_DIR}/io ${TARGET_DIR}/; \
	fi
	if [ -e ${SRC_DIR}/build.io ]; then \
		${CP} -f ${SRC_DIR}/build.io ${TARGET_DIR}/; \
	fi

