inherit setuptools3
require python-lifx-plugin.inc

SRCREV = "${AUTOREV}"
SRCBRANCH = "main"
SRC_URI = "git://git@github.com/majamassarini/automate-lifx-plugin.git;protocol=ssh;branch=${SRCBRANCH}"

S = "${WORKDIR}/git"
