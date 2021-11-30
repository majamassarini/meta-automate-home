inherit core-image

FEATURE_PACKAGES_automate-home-base = "packagegroup-automate-home-base"
FEATURE_PACKAGES_automate-home-daemons = "packagegroup-automate-home-daemons"
FEATURE_PACKAGES_automate-home-core = "packagegroup-automate-home-core"
FEATURE_PACKAGES_automate-home-webserver = "packagegroup-automate-home-webserver"
FEATURE_PACKAGES_automate-home-graphiteapp = "packagegroup-automate-home-graphiteapp"


# IMAGE_FEATURES_REPLACES_foo = 'bar1 bar2'
# Including image feature foo would replace the image features bar1 and bar2
IMAGE_FEATURES_REPLACES_ssh-server-openssh = "ssh-server-dropbear"

# IMAGE_FEATURES_CONFLICTS_foo = 'bar1 bar2'
# An error exception would be raised if both image features foo and bar1(or bar2) are included

CORE_IMAGE_EXTRA_INSTALL ?= ""

CORE_IMAGE_BASE_INSTALL = '\
    packagegroup-core-boot \
    packagegroup-automate-home-base \
    ${CORE_IMAGE_EXTRA_INSTALL} \
    '


update_hostname_function() {
  echo ${AUTOMATE_HOME_NODE_TYPE} > ${IMAGE_ROOTFS}/etc/hostname
}

set_smart_home_locale() {
  mkdir -p ${IMAGE_ROOTFS}/etc/profile.d/
  echo "export LC_ALL=${SMART_HOME_LOCALE}" > ${IMAGE_ROOTFS}/etc/profile.d/profile.sh
  echo "export LANG=${SMART_HOME_LOCALE}" >> ${IMAGE_ROOTFS}/etc/profile.d/profile.sh
  echo "export LANGUAGE=${SMART_HOME_LOCALE}" >> ${IMAGE_ROOTFS}/etc/profile.d/profile.sh
}

set_etc_default_home_brain() {
  mkdir -p ${IMAGE_ROOTFS}/etc/default/
  echo "export KNX_DAEMON_ARGS=${KNX_DAEMON_ARGS}" >> ${IMAGE_ROOTFS}/etc/default/automate-home
  echo "export BRAIN_DAEMON_ARGS=${BRAIN_DAEMON_ARGS}" >> ${IMAGE_ROOTFS}/etc/default/automate-home
  echo "export WEBSERVER_DAEMON_ARGS=${WEBSERVER_DAEMON_ARGS}" >> ${IMAGE_ROOTFS}/etc/default/automate-home
  echo "export GRAPHITE_FEEDER_DAEMON_ARGS=${WEBSERVER_DAEMON_ARGS}" >> ${IMAGE_ROOTFS}/etc/default/automate-home
}

def buildhistory_get_metadata_revs(d):
  # copied from buildhistory.bbclass
  # We want an easily machine-readable format here, so get_layers_branch_rev isn't quite what we want
  layers = (d.getVar("BBLAYERS") or "").split()
  medadata_revs = ["%-17s = %s:%s%s" % (os.path.basename(i), \
      base_get_metadata_git_branch(i, None).strip(), \
      base_get_metadata_git_revision(i, None), \
      buildhistory_get_modified(i)) \
          for i in layers]
  return '\n'.join(medadata_revs)

def buildhistory_get_modified(path):
  # copied from get_layer_git_status() in image-buildinfo.bbclass
  import subprocess
  try:
      subprocess.check_output("""cd %s; export PSEUDO_UNLOAD=1; set -e;
                              git diff --quiet --no-ext-diff
                              git diff --quiet --no-ext-diff --cached""" % path,
                              shell=True,
                              stderr=subprocess.STDOUT)
      return ""
  except subprocess.CalledProcessError as ex:
      # Silently treat errors as "modified", without checking for the
      # (expected) return code 1 in a modified git repo. For example, we get
      # output and a 129 return code when a layer isn't a git repo at all.
      return " -- modified"

populate_issue_file() {
  buildhistory-collect-srcrevs >> ${IMAGE_ROOTFS}/etc/issue
  echo "${@buildhistory_get_metadata_revs(d)}" >> ${IMAGE_ROOTFS}/etc/issue
}

populate_entrypoint_file() {
echo "/etc/init.d/redis-server start \
& /etc/init.d/mosquitto start \
& /etc/init.d/graphite-carbon.sh start \
& /etc/init.d/graphite-web.sh start \
& /etc/init.d/nginx start \
& /etc/init.d/brain.sh start \
& /etc/init.d/brain-ws.sh start \
& /etc/init.d/graphite-feeder.sh start \
& /bin/sh;" > ${IMAGE_ROOTFS}/usr/bin/entrypoint
chmod 755 ${IMAGE_ROOTFS}/usr/bin/entrypoint
}

AUTOMATE_HOME_NODE_TYPE = "${MACHINE}-${PN}"
ROOTFS_POSTPROCESS_COMMAND_append = "update_hostname_function; set_smart_home_locale; set_etc_default_home_brain; populate_issue_file; populate_entrypoint_file;"
