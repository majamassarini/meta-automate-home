SUMMARY = "The library provides identity and authorization for aiohttp.web"
HOMEPAGE = "https://aiohttp-security.readthedocs.io/"

LICENSE = "Apache-2.0"

RDEPENDS_${PN} = "${PYTHON_PN}-aiohttp-security"

PYPI_PACKAGE = "aiohttp-security"

inherit pypi
