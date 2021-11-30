inherit setuptools3
require python-graphite-carbon.inc

SRCREV = "${AUTOREV}"
SRCBRANCH = "master"
SRC_URI_append = " git://git@github.com/graphite-project/carbon.git;protocol=ssh;branch=${SRCBRANCH}"

S = "${WORKDIR}/git"

