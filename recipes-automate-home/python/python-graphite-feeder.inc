SUMMARY = "Graphite integration for the automate-home"
HOMEPAGE = "https://github.com/majamassarini/automate-graphite-feeder"

LICENSE = "MIT"

SRC_URI = "file://graphite-feeder.sh"

FILES_${PN}_append = " /var/*"
FILES_${PN}_append = " /volatile/*"

RDEPENDS_${PN} = "${PYTHON_PN}-home"

INITSCRIPT_NAME = "graphite-feeder.sh"
INITSCRIPT_PARAMS = "defaults 97"

inherit update-rc.d

do_install_append() {
        install -d ${D}/${sysconfdir}/init.d
        install -d ${D}/${PROJECT_DIR}
        install -m 0755 ${WORKDIR}/graphite-feeder.sh ${D}/${sysconfdir}/init.d/

        install -d ${D}/var/
        install -d ${D}/var/log
        install -d ${D}/var/log/automate-home
}

do_install_append_qemuall() {
        install -d ${D}/volatile
        install -d ${D}/volatile/log
        install -d ${D}/volatile/log/automate-home
}


