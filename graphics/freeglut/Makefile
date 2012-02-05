# vim:ts=8:sw=8
# New ports collection makefile for:	freeglut
# Date created:		Wed Apr 23 2003
# Whom:			thierry@pompo.net
#
# $FreeBSD: ports/graphics/freeglut/Makefile,v 1.26 2011/09/23 22:23:09 amdmi3 Exp $
#

PORTNAME=	freeglut
PORTVERSION=	2.8.0
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME:L}/${PORTVERSION}

MAINTAINER=	x11@FreeBSD.org
COMMENT=	An alternative to the OpenGL Utility Toolkit (GLUT) library

CONFLICTS=	libglut-[0-9].*

USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_XORG=	ice xi xrandr
USE_GL=		glu
CONFIGURE_ARGS=	--disable-warnings
LDFLAGS+=	-lusbhid -L${LOCALBASE}/lib 
USE_LDCONFIG=	yes

DOCS=	download.html freeglut.html freeglut_logo.png		\
	freeglut_user_interface.html index.html ogl_sm.png	\
	progress.html structure.html
BINS=	CallbackMaker Fractals Fractals_random Lorenz One shapes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800000
EXTRA_PATCHES=	${FILESDIR}/extra-patch-src__freeglut_joystick.c
.endif

pre-configure:
.for fract in Fractals/fractals.c Fractals_random/fractals_random.c
	@${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|g"		\
		${WRKSRC}/progs/demos/${fract}
.endfor

post-build:
	@${MV} ${WRKSRC}/progs/demos/CallbackMaker/.libs/CallbackMaker	\
		${WRKSRC}/progs/demos/CallbackMaker/.libs/callbackmaker

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${FILE} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/progs/demos/Fractals/fractals.dat ${EXAMPLESDIR}
.for prog in ${BINS}
	@${INSTALL_PROGRAM} ${WRKSRC}/progs/demos/${prog}/.libs/${prog:L} ${EXAMPLESDIR}
.endfor
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
.endif
.if ${OSVERSION} >= 800000
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}
.endif

.include <bsd.port.post.mk>
