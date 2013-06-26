# $FreeBSD$

PORTNAME=	xf86-video-newport
PORTVERSION=	0.2.4
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org newport display driver

.include <bsd.port.options.mk>

.if defined(WITH_NEW_XORG)
BROKEN=		Does not build
.endif

XORG_CAT=	driver
MAN4=		newport.4x

post-patch:
		${REINPLACE_CMD} -e 's|values.h|sys/limits.h|' \
				 -e 's|MAXSHORT|SHRT_MAX|g' \
				 ${WRKSRC}/src/newport_accel.c

.include <bsd.port.mk>
