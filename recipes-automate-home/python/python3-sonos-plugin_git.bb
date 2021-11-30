inherit setuptools3
require python-sonos-plugin.inc

SRCREV = "${AUTOREV}"
SRCBRANCH = "main"
SRC_URI = "git://git@github.com/majamassarini/automate-sonos-plugin.git;protocol=ssh;branch=${SRCBRANCH}"

S = "${WORKDIR}/git"
