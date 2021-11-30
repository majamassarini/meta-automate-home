SUMMARY = "asyncio (PEP 3156) Redis support"
HOMEPAGE = "https://github.com/aio-libs/aioredis"

PYPI_PACKAGE = "aioredis"

RDEPENDS_${PN} = "${PYTHON_PN}-hiredis \
  ${PYTHON_PN}-async-timeout \
"


LICENSE = "MIT"


inherit pypi

