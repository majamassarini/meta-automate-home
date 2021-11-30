SUMMARY = "scandir() is a directory iteration function like os.listdir(), except that instead of returning a list of bare filenames, it yields DirEntry objects that include file type and stat information along with the name"
HOMEPAGE = "https://github.com/benhoyt/scandir"

SRC_URI[sha256sum] = "4d4631f6062e658e9007ab3149a9b914f3548cb38bfb021c64f39a025ce578ae"
LICENSE = "BSD"

PYPI_PACKAGE = "scandir"

inherit pypi

