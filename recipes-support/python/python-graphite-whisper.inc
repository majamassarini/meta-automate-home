SUMMARY = "The Whisper time-series database library"
HOMEPAGE = "https://github.com/graphite-project/whisper.git"

LICENSE = "BSD"

GRAPHITE_ROOT = "/opt/graphite"
FILES_${PN}_append = " ${GRAPHITE_ROOT}"

DISTUTILS_INSTALL_ARGS = "--root=${D} \
 --prefix=${GRAPHITE_ROOT} --install-lib=${GRAPHITE_ROOT}/lib"

do_install_append() {
         for i in ${D}${GRAPHITE_ROOT}/bin/* ${D}${GRAPHITE_ROOT}/sbin/*; do
            if [ -f "$i" ]; then
                sed -i -e s:${PYTHON}:${USRBINPATH}/env\ ${DISTUTILS_PYTHON}:g $i
                sed -i -e s:${STAGING_BINDIR_NATIVE}:${bindir}:g $i
            fi
        done
}
