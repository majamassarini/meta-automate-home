SUMMARY = "Python wrapper for hiredis"
HOMEPAGE = "https://github.com/redis/hiredis-py"

LICENSE = "BSD"
LIC_FILES_CHKSUM = "file://COPYING;md5=9fc8ec18a03409e5aae0a1b95ab0a77f"

SRC_URI[md5sum] = "ad421ea848734c7be5c10689caa2a6f1"
SRC_URI += "file://hiredis_lib.patch;patch=1;pnum=0"

DEPENDS = "hiredis python3-distutils-extra"
PYPI_PACKAGE = "hiredis"

inherit pypi

