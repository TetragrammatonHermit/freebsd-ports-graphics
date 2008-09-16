# New ports collection makefile for:	io-zlib
# Date created:		2008-09-15
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	zlib
PORTVERSION=	${IOVERSION}
CATEGORIES=	archivers
MASTER_SITES=	#
PKGNAMEPREFIX=	io-
DISTNAME=	io-${PORTVERSION}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Zlib addon for lang/io

USE_BZIP2=	yes
USE_GMAKE=	yes
DEFAULT_ADDONS=	Zlib

.include "${.CURDIR}/../../lang/io/files/bsd.ioaddons.mk"
.include <bsd.port.mk>
