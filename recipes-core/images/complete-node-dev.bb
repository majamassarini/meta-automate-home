include recipes-core/images/complete-node.bb

IMAGE_FEATURES_append = "\
  dev-pkgs \
  debug-tweaks \
  "

IMAGE_INSTALL_append = "\
  python3-debugger \
  "
