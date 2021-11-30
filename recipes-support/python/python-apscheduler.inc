SUMMARY = "Advanced python scheduler"
HOMEPAGE = "https://github.com/agronholm/apscheduler"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE.txt;md5=f0e423eea5c91e7aa21bdb70184b3e53"

SRC_URI[md5sum] = "18c2050f24bad3dd82e17dd4b5f182df"

PYPI_PACKAGE = "APScheduler"

inherit pypi

DEPENDS += "${PYTHON_PN}-setuptools-scm-native"

RDEPENDS_${PN} += " \
    ${PYTHON_PN}-six \
    ${PYTHON_PN}-pytz \
    ${PYTHON_PN}-tzlocal \
    ${PYTHON_PN}-setuptools \
"

