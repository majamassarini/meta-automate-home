SUMMARY = "A Django-based web application that renders graphs and dashboards"
HOMEPAGE = "https://github.com/graphite-project/graphite-web.git"

LICENSE = "Apache-2.0"

GRAPHITE_ROOT = "/opt/graphite"
FILES_${PN}_append = " ${GRAPHITE_ROOT}"
FILES_${PN}_append_qemuall = " /volatile"

DISTUTILS_INSTALL_ARGS = "--root=${D} \
 --prefix=${GRAPHITE_ROOT}"

RDEPENDS_${PN}_append = " ${PYTHON_PN}-pyparsing"

SRC_URI = " \
 file://graphite-uwsgi.ini \
 file://graphite-uwsgi.py \
 file://graphite.conf \
 file://graphite.db \
 file://graphite-web.sh \
 file://local_settings.py \
"

INITSCRIPT_NAME = "graphite-web.sh"
INITSCRIPT_PARAMS = "defaults 89"

inherit update-rc.d

do_install_append () {
        install -d ${D}/${sysconfdir}/init.d
        install -d ${D}/${sysconfdir}/nginx/
        install -d ${D}/${sysconfdir}/nginx/sites-available/
        install -d ${D}/${sysconfdir}/nginx/sites-enabled/
        install -d ${D}/${GRAPHITE_ROOT}/
        install -d ${D}/${GRAPHITE_ROOT}/conf
        install -d ${D}/${GRAPHITE_ROOT}/storage
        install ${WORKDIR}/graphite.conf ${D}/${sysconfdir}/nginx/sites-available/
	lnr ${D}/${sysconfdir}/nginx/sites-available/graphite.conf ${D}/${sysconfdir}/nginx/sites-enabled/graphite.conf
        install ${WORKDIR}/graphite-uwsgi.py ${D}/${GRAPHITE_ROOT}/conf/graphite-uwsgi.py
        install ${WORKDIR}/graphite-uwsgi.ini ${D}/${GRAPHITE_ROOT}/conf/graphite-uwsgi.ini
	#install ${WORKDIR}/local_settings.py ${D}/${GRAPHITE_ROOT}/webapp/graphite/local_settings.py
        install ${WORKDIR}/graphite.db ${D}/${GRAPHITE_ROOT}/storage/graphite.db

        install -m 0755 ${WORKDIR}/graphite-web.sh ${D}/${sysconfdir}/init.d/

        for i in ${D}${GRAPHITE_ROOT}/bin/* ${D}${GRAPHITE_ROOT}/sbin/*; do
            if [ -f "$i" ]; then
                sed -i -e s:${PYTHON}:${USRBINPATH}/env\ ${DISTUTILS_PYTHON}:g $i
                sed -i -e s:${STAGING_BINDIR_NATIVE}:${bindir}:g $i
            fi
        done
}
