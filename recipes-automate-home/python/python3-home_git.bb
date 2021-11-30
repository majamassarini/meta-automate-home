inherit setuptools3
require python-home.inc

SRCREV = "${AUTOREV}"
SRCBRANCH = "main"
SRC_URI_append = " git://git@github.com/majamassarini/automate-home.git;protocol=ssh;branch=${SRCBRANCH}"

S = "${WORKDIR}/git"

