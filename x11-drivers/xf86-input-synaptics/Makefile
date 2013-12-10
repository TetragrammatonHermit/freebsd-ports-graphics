# $FreeBSD$

PORTNAME=	xf86-input-synaptics
PORTVERSION=	1.7.1
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org synaptics input driver

CONFLICTS=	synaptics-[0-9]*

OPTIONS_DEFINE=	HAL
OPTIONS_DEFAULT=HAL

USES=		pathfix
USE_XORG=	x11
XORG_CAT=	driver

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHAL}
PLIST_SUB+=	HAL=""
LIB_DEPENDS+=	hal.1:${PORTSDIR}/sysutils/hal
.else
PLIST_SUB+=	HAL="@comment "
.endif

post-install:
.if ${PORT_OPTIONS:MHAL}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/hal/fdi/policy/10osvendor
	${INSTALL_DATA} ${WRKSRC}/conf/11-x11-synaptics.fdi \
		${STAGEDIR}${PREFIX}/share/hal/fdi/policy/10osvendor/
.endif

.include <bsd.port.mk>
