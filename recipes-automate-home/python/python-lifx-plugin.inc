SUMMARY = "The Lifx plugin for the automate-home project."
HOMEPAGE = "https://github.com/majamassarini/automate-lifx-plugin"

LICENSE = "MIT"

FILES_${PN} += "/usr/share"

RDEPENDS_${PN} += "${PYTHON_PN}-lifx-lib"

