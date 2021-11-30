inherit automate-home-image

SUMMARY = "Complete node but daemons"

LICENSE = "GPL-3.0"

DESCRIPTION = "Core process (automate-home), redis instance, webserver (automate-ws), graphite app (whisper + carbon + webapp)"


GLIBC_GENERATE_LOCALES ?= "all"

MACHINE_FEATURES_append = " usbhost"

DISTRO_FEATURES_append = " usbhost"

IMAGE_FEATURES_append = "\
  automate-home-core \
  automate-home-webserver \
  automate-home-graphiteapp \
  package-management \
"

IMAGE_INSTALL_append = "\
  redis \
  "

REDISHOST = "127.0.0.1"
KNXREMOTEHOST = "127.0.0.1"
