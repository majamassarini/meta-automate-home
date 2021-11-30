inherit setuptools3
require python-home-assistant-plugin.inc

SRCREV = "${AUTOREV}"
SRCBRANCH = "main"
SRC_URI = "git://git@github.com/majamassarini/automate-home-assistant-plugin.git;protocol=ssh;branch=${SRCBRANCH}"

S = "${WORKDIR}/git"
