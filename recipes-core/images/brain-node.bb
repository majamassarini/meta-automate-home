inherit automate-home-image

SUMMARY = "Brain node"

LICENSE = "GPL-3.0"

DESCRIPTION = "Core process (automate-home)"

GLIBC_GENERATE_LOCALES ?= "all"

MACHINE_FEATURES_append = ""

DISTRO_FEATURES_append = ""

IMAGE_FEATURES_append = "\
  automate-home-core \
  package-management \
  "

