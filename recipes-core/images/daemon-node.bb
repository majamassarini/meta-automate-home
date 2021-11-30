inherit automate-home-image

SUMMARY = "Daemons node"

LICENSE = "GPL-3.0"

DESCRIPTION = "Running all available automate-home daemons"

GLIBC_GENERATE_LOCALES ?= "all"

MACHINE_FEATURES_append = " usbhost"

DISTRO_FEATURES_append = " usbhost"

IMAGE_FEATURES_append = "\
  read-only-rootfs \
  automate-home-daemons \
  package-management \
  "

