# Created by: Dejan Lesjak <lesi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xextproto
PORTVERSION=	7.2.99.901
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	XExt extension headers

XORG_CAT=	proto
NO_STAGE=	yes

CONFIGURE_ARGS+=--disable-specs

post-patch:
	@${REINPLACE_CMD} '/^SUBDIR/s/specs//' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
