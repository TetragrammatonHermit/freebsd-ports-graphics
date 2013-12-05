# $FreeBSD$

PORTNAME=	libxshmfence
PORTVERSION=	1.1
CATEGORIES=	devel

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Shared memory 'SyncFence' synchronization primitive

LICENSE=	MIT

USE_XORG=	xproto
XORG_CAT=	lib

test:	build
	@cd ${WRKSRC} && ${MAKE} check

.include <bsd.port.mk>
