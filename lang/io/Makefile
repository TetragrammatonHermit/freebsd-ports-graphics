# New ports collection makefile for:	io
# Date created:		4 Nov 2005
# Whom:			Hye-Shik Chang
#
# $FreeBSD: ports/lang/io/Makefile,v 1.20 2008/08/14 05:27:52 perky Exp $
#

PORTNAME=	io
PORTVERSION=	20080904
CATEGORIES=	lang
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Small prototype-based programming language

USE_BZIP2=	yes
USE_GMAKE=	yes
CFLAGS+=	-fPIC
USE_LDCONFIG=	yes

DEFAULT_ADDONS=	#empty

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_ENV=	INSTALL_PREFIX="${PREFIX}"

PORTDOCS=	*
PORTEXAMPLES=	*

post-patch:
	@cd ${WRKSRC}/addons && for addon in *; do \
       if ! ${ECHO_CMD} ${DEFAULT_ADDONS} | ${GREP} $$addon > /dev/null; then \
       ${RM} -fr $$addon; \
       fi; \
done
	@${REINPLACE_CMD} -e 's|CFLAGS = $$(OPTIMIZE)|CFLAGS +=|' \
		${WRKSRC}/Makefile.lib
	@${REINPLACE_CMD} -e '/CC = gcc/ d' \
		${WRKSRC}/libs/basekit/source/simd_cph/test/Makefile

post-install:
	${MKDIR} ${PREFIX}/include/io
	${INSTALL_DATA} ${WRKSRC}/_build/headers/* ${PREFIX}/include/io

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/samples && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
