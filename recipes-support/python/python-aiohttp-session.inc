SUMMARY = "The library provides sessions for aiohttp.web."
HOMEPAGE = "http://aiohttp-session.readthedocs.io/"

LICENSE = "Apache-2.0"

RDEPENDS_${PN} = "${PYTHON_PN}-aiohttp-session"

PYPI_PACKAGE = "aiohttp-session"

inherit pypi
