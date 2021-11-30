inherit setuptools3
require python-knx-stack.inc

SRCREV = "${AUTOREV}"
SRC_URI = "git://git@github.com/majamassarini/knx-stack.git;protocol=ssh"

S = "${WORKDIR}/git"

