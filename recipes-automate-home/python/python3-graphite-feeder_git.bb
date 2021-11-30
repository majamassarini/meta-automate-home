inherit setuptools3
require python-graphite-feeder.inc

SRCREV = "${AUTOREV}"
SRCBRANCH = "main"
SRC_URI_append = " git://git@github.com/majamassarini/automate-graphite-feeder.git;protocol=ssh;branch=${SRCBRANCH}"

S = "${WORKDIR}/git"
