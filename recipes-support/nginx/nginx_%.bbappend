FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

SRC_URI_append = " file://nginx.conf"

FILES_${PN}_append = " /var/*"
FILES_${PN}_append = " /run/*"
FILES_${PN}_append = " /volatile/*"

do_install_append() {
        install -d ${D}/var
        install -d ${D}/var/log
        install -d ${D}/var/log/nginx
        install -m 0755 ${WORKDIR}/nginx.conf ${D}/${sysconfdir}/nginx/nginx.conf

        install -d ${D}/run/nginx
}

do_install_append_qemuall() {
        install -d ${D}/volatile
        install -d ${D}/volatile/log
        install -d ${D}/volatile/log/nginx

}
