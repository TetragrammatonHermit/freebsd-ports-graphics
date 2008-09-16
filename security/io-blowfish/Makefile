# New ports collection makefile for:	io-blowfish
# Date created:		2008-09-15
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	blowfish
PORTVERSION=	${IOVERSION}
CATEGORIES=	security
MASTER_SITES=	#
PKGNAMEPREFIX=	io-
DISTNAME=	io-${PORTVERSION}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Blowfish addon for lang/io

USE_BZIP2=	yes
USE_GMAKE=	yes
DEFAULT_ADDONS=	Blowfish

.include "${.CURDIR}/../../lang/io/files/bsd.ioaddons.mk"
.include <bsd.port.mk>
