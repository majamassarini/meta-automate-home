inherit setuptools3
require python-graphite-web.inc

SRCREV = "${AUTOREV}"
SRCBRANCH = "master"
SRC_URI_append = "git://git@github.com/graphite-project/graphite-web.git;protocol=ssh;branch=${SRCBRANCH}"

RDEPENDS_${PN}_append = " bash"

S = "${WORKDIR}/git"
