SUMMARY = "jinja2 template renderer for aiohttp.web"
HOMEPAGE = "https://github.com/martinblech/xmltodict"

LICENSE = "Apache-2.0"
#LIC_FILES_CHKSUM = "file://LICENSE.txt;md5=57e0bd61643d81d05683cdce65b11d10"

SRC_URI[md5sum] = "7eb1a9be9e776c94d3bff73330c213d0"

RDEPENDS_${PN} = "${PYTHON_PN}-jinja2"

PYPI_PACKAGE = "aiohttp-jinja2"

inherit pypi
