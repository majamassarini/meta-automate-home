SUMMARY = "SoCo (Sonos Controller) is a simple library to control Sonos speakers."
HOMEPAGE = "https://github.com/SoCo/SoCo"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE.rst;md5=07b0e2ca9ac77cd65cd4edf2e13367ea"

RDEPENDS_${PN} += "${PYTHON_PN}-requests \
  ${PYTHON_PN}-xmltodict \
"

BBCLASSEXTEND = "native"

# Make clean requires sphinx which we don't have
CLEANBROKEN = "1"

inherit pypi
