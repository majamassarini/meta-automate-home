SUMMARY = "The Sonos plugin for the automate-home project."
HOMEPAGE = "https://github.com/majamassarini/automate-sonos-plugin"

LICENSE = "MIT"

FILES_${PN} += "/usr/share"

RDEPENDS_${PN} += "${PYTHON_PN}-soco (>= 0.17)"

