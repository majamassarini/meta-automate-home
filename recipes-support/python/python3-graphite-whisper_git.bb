inherit setuptools3
require python-graphite-whisper.inc

SRCREV = "${AUTOREV}"
SRCBRANCH = "master"
SRC_URI = "git://git@github.com/graphite-project/whisper.git;protocol=ssh;branch=${SRCBRANCH}"
SRC_URI[sha256sum] = "e4066965faef232bc1890d38352231c8acd00ddc9cd4cd930968fe0d09b8b0ba"

S = "${WORKDIR}/git"

