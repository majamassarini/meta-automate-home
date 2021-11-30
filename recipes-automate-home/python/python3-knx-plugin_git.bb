inherit setuptools3
require python-knx-plugin.inc

SRCREV = "${AUTOREV}"
SRCBRANCH = "main"
SRC_URI = "git://git@github.com/majamassarini/automate-knx-plugin.git;protocol=ssh;branch=${SRCBRANCH}"

S = "${WORKDIR}/git"

