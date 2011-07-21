# New ports collection makefile for:	xf86-input-synaptics
# Date Created:				25 Sep 2008
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD: ports/x11-drivers/xf86-input-synaptics/Makefile,v 1.12 2011/02/25 16:52:31 miwi Exp $
#

PORTNAME=	xf86-input-synaptics
PORTVERSION=	1.4.1
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org synaptics input driver

CONFLICTS=	synaptics-[0-9]*

LIB_DEPENDS+=	hal.1:${PORTSDIR}/sysutils/hal

USE_GNOME=	gnomehack
USE_XORG=	x11
XORG_CAT=	driver

MAN1=		syndaemon.1 \
		synclient.1
MAN4=		synaptics.4x

post-install:
	${MKDIR} ${PREFIX}/share/hal/fdi/policy/10osvendor
	${INSTALL_DATA} ${WRKSRC}/conf/11-x11-synaptics.fdi \
		${PREFIX}/share/hal/fdi/policy/10osvendor/

.include <bsd.port.mk>
