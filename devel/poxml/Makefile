# $FreeBSD$

PORTNAME=	poxml
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Tools to translate Docbook XML using gettext

BUILD_DEPENDS=	${LOCALBASE}/lib/libantlr.a:${PORTSDIR}/devel/antlr

USE_KDE4=	kdelibs kdeprefix automoc4
USES=		cmake:outsource tar:xz
USE_QT4=	moc_build qmake_build rcc_build uic_build \
		corelib xml

.include <bsd.port.mk>
