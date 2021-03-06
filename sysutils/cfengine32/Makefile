# Created by: jrhett@netconsonance.com
# $FreeBSD$

PORTNAME=	cfengine
PORTVERSION=	3.2.3
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://s3.amazonaws.com/cfengine.package-repos/tarballs/
PKGNAMESUFFIX=	32

MAINTAINER=	cy@FreeBSD.org
#		gjb@FreeBSD.org is an alternate committer for this port
COMMENT=	Systems administration tool for networks

LATEST_LINK=	cfengine32
FETCH_BEFORE_ARGS=	-o ${DISTDIR}/${DISTFILES}

CONFLICTS=	cfengine-[2]* cfengine-3.[345]* cfengine-devel-*

USE_RC_SUBR=	cf-execd cf-serverd

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

USES=		libtool
USE_BDB=	48+
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
# EXAMPLESDIR=	${PREFIX}/share/examples/cfengine3
DOCSDIR=	${PREFIX}/share/doc/cfengine3
CONFIGURE_ARGS=	--docdir=${DOCSDIR} \
		--htmldir=${DOCSDIR}/html \
		--with-berkeleydb=${LOCALBASE} \
		--with-pcre=${LOCALBASE}

CONFIGURE_ENV+=	BERKELEY_DB_CFLAGS=-I${BDB_INCLUDE_DIR} \
		BERKELEY_DB_LDFLAGS=-L${BDB_LIB_DIR} \
		BERKELEY_DB_LIB=-l${BDB_LIB_NAME}

post-patch:
		@${REINPLACE_CMD} -e '/^htmldir/s!=.*!= @htmldir@!'\
				  ${WRKSRC}/docs/Makefile.in

.include <bsd.port.mk>
