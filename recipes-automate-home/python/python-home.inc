SUMMARY = "Yet another automation project because a smart light is more than just on or off"
HOMEPAGE = "https://github.com/majamassarini/automate-home"

LICENSE = "GPL-3.0"

SRC_URI = "file://brain.sh"

FILES_${PN}_append = " /var/*"
FILES_${PN}_append = " /volatile/*"

RDEPENDS_${PN} = "${PYTHON_PN}-apscheduler"
RDEPENDS_${PN} += "${PYTHON_PN}-pyephem"
RDEPENDS_${PN} += "${PYTHON_PN}-hiredis"
RDEPENDS_${PN} += "${PYTHON_PN}-aioredis"
RDEPENDS_${PN} += "${PYTHON_PN}-pyyaml"

INITSCRIPT_NAME = "brain.sh"
INITSCRIPT_PARAMS = "defaults 95"

inherit update-rc.d

do_install_append() {
        install -d ${D}/${sysconfdir}/init.d
        install -d ${D}/${PROJECT_DIR}
        install -m 0755 ${WORKDIR}/brain.sh ${D}/${sysconfdir}/init.d/

        install -d ${D}/var/
        install -d ${D}/var/log
        install -d ${D}/var/log/automate-home
}

do_install_append_qemuall() {
        install -d ${D}/volatile
        install -d ${D}/volatile/log
        install -d ${D}/volatile/log/automate-home
}
