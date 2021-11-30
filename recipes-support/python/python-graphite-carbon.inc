SUMMARY = "Carbon is one of three components within the Graphite project."
HOMEPAGE = "https://github.com/graphite-project/carbon.git"

LICENSE = "Apache-2.0"

SRC_URI = "file://carbon.conf \
 file://storage-schemas.conf \
 file://graphite-carbon.sh"

GRAPHITE_ROOT = "/opt/graphite"
FILES_${PN}_append = " ${GRAPHITE_ROOT}"
FILES_${PN}_append_qemuall = " /volatile"

DISTUTILS_INSTALL_ARGS = "--root=${D} \
 --prefix=${GRAPHITE_ROOT}"

INITSCRIPT_NAME = "graphite-carbon.sh"
INITSCRIPT_PARAMS = "defaults 93"

inherit update-rc.d

do_install_append() {
        install -d ${D}/${sysconfdir}/init.d
        install -d ${D}/${GRAPHITE_ROOT}/
        install -d ${D}/${GRAPHITE_ROOT}/conf
        install ${WORKDIR}/carbon.conf ${D}/${GRAPHITE_ROOT}/conf/carbon.conf
        install ${WORKDIR}/storage-schemas.conf ${D}/${GRAPHITE_ROOT}/conf/storage-schemas.conf
        install -m 0755 ${WORKDIR}/graphite-carbon.sh ${D}/${sysconfdir}/init.d/

         for i in ${D}${GRAPHITE_ROOT}/bin/* ${D}${GRAPHITE_ROOT}/sbin/*; do
            if [ -f "$i" ]; then
                sed -i -e s:${PYTHON}:${USRBINPATH}/env\ ${DISTUTILS_PYTHON}:g $i
                sed -i -e s:${STAGING_BINDIR_NATIVE}:${bindir}:g $i
            fi
        done
}

do_install_append_qemuall() {
        install -d ${D}/volatile
}

