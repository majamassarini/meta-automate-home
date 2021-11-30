inherit setuptools3
require python-lifx-lib.inc

SRCREV = "${AUTOREV}"
SRC_URI = "git://git@github.com/majamassarini/lifx-lib.git;protocol=ssh"

S = "${WORKDIR}/git"
