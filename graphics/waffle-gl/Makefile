# Created by: Jean-Sébastien Pédron <dumbbell@FreeBSD.org>
# $FreeBSD$

PORTNAME=	waffle-gl
PORTVERSION=	1.3.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.waffle-gl.org/files/release/waffle-${PORTVERSION}/
DISTNAME=	waffle-${PORTVERSION}

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Library that allows to defer selection of an OpenGL API until runtime

LICENSE=	BSD2CLAUSE

USES=		cmake:outsource ninja pkgconfig tar:xz
USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/share/doc/waffle1

OPTIONS_DEFINE=	DOCS

USE_XORG=	x11 xcb
USE_GL=		gl egl

CMAKE_ARGS+=	-Dwaffle_has_glx=ON					\
		-Dwaffle_has_x11_egl=ON

# TODO:		-Dwaffle_has_gbm=ON

.include <bsd.port.pre.mk>

post-install:
.if ! ${PORT_OPTIONS:MDOCS}
	${RM} ${STAGEDIR}${DOCSDIR}/LICENSE.txt
	${RM} ${STAGEDIR}${DOCSDIR}/README.txt
	${RM} ${STAGEDIR}${DOCSDIR}/examples/Makefile.example
	${RM} ${STAGEDIR}${DOCSDIR}/examples/gl_basic.c
	${RM} ${STAGEDIR}${DOCSDIR}/examples/simple-x11-egl.c
	${RM} ${STAGEDIR}${DOCSDIR}/release-notes/waffle-${PORTVERSION}.txt
	${RMDIR} ${STAGEDIR}${DOCSDIR}/examples
	${RMDIR} ${STAGEDIR}${DOCSDIR}/release-notes
	${RMDIR} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.post.mk>
