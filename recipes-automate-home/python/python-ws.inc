SUMMARY = "A simple web interface for the automate-home project."
HOMEPAGE = "https://github.com/majamassarini/automate-ws"

LICENSE = "CLOSED"

SRC_URI = "file://brain-ws.sh"

FILES_${PN}_append = " /usr/share"
FILES_${PN}_append = " /var/*"
FILES_${PN}_append = " /volatile/*"

RDEPENDS_${PN} = "${PYTHON_PN}-xmltodict"
RDEPENDS_${PN} += "${PYTHON_PN}-aioredis"
RDEPENDS_${PN} += "${PYTHON_PN}-aiohttp"
RDEPENDS_${PN} += "${PYTHON_PN}-aiohttp-jinja2"
RDEPENDS_${PN} += "${PYTHON_PN}-aiohttp-security"
RDEPENDS_${PN} += "${PYTHON_PN}-aiohttp-session"
RDEPENDS_${PN} += "${PYTHON_PN}-misc"
RDEPENDS_${PN} += "${PYTHON_PN}-modules"
RDEPENDS_${PN} += "${PYTHON_PN}-home"
RDEPENDS_${PN} += "${PYTHON_PN}-colour"
RDEPENDS_${PN} += "gunicorn"

inherit update-rc.d

INITSCRIPT_NAME = "brain-ws.sh"
INITSCRIPT_PARAMS = "defaults 96"

do_install_append() {
        install -d ${D}/var/
        install -d ${D}/var/log
        install -d ${D}/var/log/automate-home

        install -d ${D}/${sysconfdir}/init.d
        install -d ${D}/${PROJECT_DIR}
        install -m 0755 ${WORKDIR}/brain-ws.sh ${D}/${sysconfdir}/init.d/

        install -d ${D}${sysconfdir}/${PROJECT_DIR}/ws/
        install -d ${S}/ws/templates ${D}${sysconfdir}/${PROJECT_DIR}/ws/
}

do_install_append_qemuall() {
        install -d ${D}/volatile
        install -d ${D}/volatile/log
        install -d ${D}/volatile/log/automate-home
}
