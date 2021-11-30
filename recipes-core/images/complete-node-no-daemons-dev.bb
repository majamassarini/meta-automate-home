include recipes-core/images/complete-node-no-daemons.bb

IMAGE_FEATURES_append = "\
  dev-pkgs \
  debug-tweaks \
  "
