# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bonnie++
PORTVERSION=	1.97
PORTREVISION=	3
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.coker.com.au/bonnie++/experimental/

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Performance Test of Filesystem I/O

LICENSE=	GPLv2

GNU_CONFIGURE=	yes

USES=	shebangfix tar:tgz
SHEBANG_FILES=	bon_csv2txt.in

WRKSRC=	${WRKDIR}/${PORTNAME}-1.97.1

PORTDOCS=	readme.html

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} \
		's|/usr/share/|${PREFIX}/share/|g' ${WRKSRC}/bonnie++.8
	@${REINPLACE_CMD} \
		's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
