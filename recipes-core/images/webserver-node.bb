inherit automate-home-image

SUMMARY = "Webserver node"

LICENSE = "GPL-3.0"

DESCRIPTION = "Webserver (automate-ws)"


GLIBC_GENERATE_LOCALES ?= "all"

MACHINE_FEATURES_append = ""

DISTRO_FEATURES_append = ""

IMAGE_FEATURES_append = "\
  automate-home-webserver \
  "
