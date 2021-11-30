SUMMARY = "Converts and manipulates common color representation (RGB, HSL, web...)"
HOMEPAGE = "http://github.com/vaab/colour"

LICENSE = "BSD"

PYPI_PACKAGE = "colour"

SRC_URI += "file://setup.patch;patch=1;pnum=0"
SRC_URI[sha256sum] = "af20120fefd2afede8b001fbef2ea9da70ad7d49fafdb6489025dae8745c3aee"

inherit pypi

