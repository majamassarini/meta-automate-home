SUMMARY = "C daemon for knx protocol"
HOMEPAGE = "https://github.com/majamassarini/knx-stack"

LICENSE = "CLOSED"

SRCREV = "${AUTOREV}"
SRC_URI = "git://git@github.com/majamassarini/knx-stack.git;protocol=ssh"
SRC_URI += "file://knxstack-usbhid-daemon.sh"

S = "${WORKDIR}/git/daemon"

FILES_${PN} += "/usr/bin/knxstack-usbhid-daemon"

inherit update-rc.d

INITSCRIPT_NAME="knxstack-usbhid-daemon.sh"
INITSCRIPT_PARAMS="defaults 90"

do_compile() {
        ${CC} ${CFLAGS} ${LDFLAGS} ${S}/usbhid.c -o knxstack-usbhid-daemon
}

do_install() {
        install -d  ${D}${bindir}
        install -m 0755 ${S}/knxstack-usbhid-daemon ${D}${bindir}
        install -d ${D}/${sysconfdir}/init.d
        install -m 0755 ${WORKDIR}/knxstack-usbhid-daemon.sh ${D}/${sysconfdir}/init.d/
}
