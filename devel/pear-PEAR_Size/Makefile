# New ports collection makefile for:	pear-PEAR_Size
# Date created:		2008-09-22
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	PEAR_Size
PORTVERSION=	0.1.7
CATEGORIES=	devel pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Determine and list how much filespace each installed package consumes.

BUILD_DEPENDS+=	${PEARDIR}/HTML/Table.php:${PORTSDIR}/devel/pear-HTML_Table \
		${PEARDIR}/Console/Getargs.php:${PORTSDIR}/devel/pear-Console_Getargs \
		${PEARDIR}/Console/Table.php:${PORTSDIR}/devel/pear-Console_Table
RUN_DEPENDS+=	${PEARDIR}/HTML/Table.php:${PORTSDIR}/devel/pear-HTML_Table \
		${PEARDIR}/Console/Getargs.php:${PORTSDIR}/devel/pear-Console_Getargs \
		${PEARDIR}/Console/Table.php:${PORTSDIR}/devel/pear-Console_Table

CATEGORY=	PEAR
FILES=		Command/Size.php Command/Size.xml Size/Size.php Size/Size_CLI.php \
		Size/Size_Exception.php Size/Size_Factory.php Size/Size_Output_csv.php \
		Size/Size_Output_html.php Size/Size_Output_text.php Size/Size_Output_xml.php
DOCS=		script-usage.txt
SCIRPTS=	pearsize.bat pearsize.php

TESTS=		AllTests.php PEAR_Size_TestSuite_Bugs.php PEAR_Size_TestSuite_CLI.php \
		PEAR_Size_TestSuite_Standard.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
