SUMMARY = "The KNX plugin for the automate-home project."
HOMEPAGE = "https://github.com/majamassarini/automate-knx-plugin"

LICENSE = "MIT"

FILES_${PN} += "/usr/share"

RDEPENDS_${PN} += "${PYTHON_PN}-knx-stack"

