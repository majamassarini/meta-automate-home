inherit setuptools3
require python-ws.inc

SRCREV = "${AUTOREV}"
SRCBRANCH = "main"
SRC_URI_append = " git://git@github.com/majamassarini/automate-ws.git;protocol=ssh;branch=${SRCBRANCH}"

S = "${WORKDIR}/git"
