SUMMARY = "CFFI-based drop-in replacement for Pycairo"
HOMEPAGE = "https://cairocffi.readthedocs.io/en/stable/"

LICENSE = "BSD"
SRC_URI[sha256sum] = "9a979b500c64c8179fec286f337e8fe644eca2f2cd05860ce0b62d25f22ea140"
SRC_URI += "file://setup.cfg.patch;patch=1;pnum=0"

PYPI_PACKAGE = "cairocffi"

DEPENDS_append = " ${PYTHON_PN}-cffi ${PYTHON_PN}-cffi-native cairo" 
RDEPENDS_${PN}_append = " cairo ${PYTHON_PN}-cffi"

do_install_append() {
	${STAGING_BINDIR_NATIVE}/${PYTHON_PN}-native/${PYTHON_PN} cairocffi/ffi_build.py
}

inherit pypi

