OpenEmbedded/Yocto distro layer for automate-home
=================================================

This layer provides support for building [automate-home](https://github.com/majamassarini/automate-home) Linux images.

## Dependencies

This layer depends on:

  URI: [https://git.yoctoproject.org/poky](https://git.yoctoproject.org/poky)
  
      branch: dunfell

  URI: [https://github.com/openembedded/meta-openembedded.git](https://github.com/openembedded/meta-openembedded.git)
  
      branch: dunfell
  

## Build Yocto image using repo

```shell
curl -o /usr/local/bin/repo https://storage.googleapis.com/git-repo-downloads/repo && chmod a+x /usr/local/bin/repo
repo init -u https://github.com/majamassarini/repo.git -b master
repo sync
TEMPLATECONF=../meta-automate-home/conf source poky/oe-init-build-env ~/automate-home-build
bitbake complete-node
```
Cleanup image
```shell
bitbake -c cleansstate complete-node
```

## Build Yocto image using kas

```shell
git clone git@github.com:siemens/kas.git
cd kas
pip3 install .

cd ~
git clone git@github.com:majamassarini/meta-automate-home.git
~/kas/kas-container --ssh-dir ~/.ssh build ~/meta-automate-home/kas.yaml
KAS_MACHINE=qemux86-64 ~/kas/kas-container --ssh-dir ~/.ssh build ~/meta-automate-home/kas.yaml
```
Specify a different image
```shell
KAS_MACHINE=qemux86-64 KAS_TARGET=complete-node-no-daemons ~/kas/kas-container --ssh-dir ~/.ssh build ~/meta-automate-home/kas.yaml
```
Cleanup image
```shell
KAS_MACHINE=qemux86-64 ~/git/kas/kas-container --ssh-dir ~/.ssh_new shell ~/meta-automate-home/kas.yaml -c 'bitbake -c cleansstate complete-node'
```
  
Import Yocto rootfs as a new Docker image
=========================================

```shell
docker import "~/automate-home-build/tmp/deploy/images/$KAS_MACHINE/$KAS_TARGET"-"$KAS_MACHINE".tar.xz \
    majamassarini/automate-home:latest \
    --change "EXPOSE 8181" \
    --change "EXPOSE 81" \
    --change "EXPOSE 2003" \
    --change "VOLUME [\"/etc/automate-home\"]" \
    --change "VOLUME [\"/var/lib/redis\"]" \
    --change "VOLUME [\"/opt/graphite/storage\"]" \
    --change "CMD /usr/bin/entrypoint"
```

### Run the docker image

```shell
docker run -v ~/project-configuration:/etc/automate-home -v redis:/var/lib/redis -v graphite:/opt/graphite/storage --name="automate-home" -d -p 8181:8181 -p 81:81 -p 2003:2003 majamassarini/automate-home:latest
docker attach automate-home
```
