# New ports collection makefile for:    libGLw
# Date created:		7 May 2004
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libGLw
PORTVERSION=	1.0.0
CATEGORIES=	graphics
MASTER_SITES=	LOCAL/kwm
DISTNAME=	glw-${PORTVERSION}
# when offical released. Set PORTEPOCH if needed and remove DIST_SUBDIR
#PORTEPOCH=	1
DIST_SUBDIR=	GL

COMMENT=	OpenGL widgets library

USE_BZIP2=	yes
USE_GNOME=	gnomehack pkgconfig
USE_LDCONFIG=	yes
USE_GL=		gl
USE_MOTIF=	yes
USE_XORG=	x11 xt xext
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static --enable-motif
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
