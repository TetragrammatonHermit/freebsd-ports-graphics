# Created by: buganini@gmail.com
# $FreeBSD$

PORTNAME=	gbsdconv
PORTVERSION=	11.1
CATEGORIES=	converters python
DISTNAME=	${GH_ACCOUNT}-${GH_PROJECT}-${PORTVERSION}-0-g${GH_COMMIT}

MAINTAINER=	buganini@gmail.com
COMMENT=	GUI for bsdconv

LICENSE=	BSD

LIB_DEPENDS=	libtag.so:${PORTSDIR}/audio/taglib
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bsdconv>=8.0:${PORTSDIR}/converters/py-bsdconv

USE_GITHUB=	yes
GH_ACCOUNT=	buganini
GH_COMMIT=	0a9ad34

USES=		python
USE_GNOME=	gtk30 introspection:run

USE_LDCONFIG=	yes

PLIST_FILES=	bin/gbsdconv \
		lib/gbsdconv_taglib.so \
		%%DATADIR%%/gbsdconv.png \
		%%DATADIR%%/gbsdconv.xml \
		%%DATADIR%%/gbsdconv2.png
PLIST_DIRS=	%%DATADIR%%

.include <bsd.port.mk>
