SUMMARY = "Home brain packages"
DESCRIPTION = "My Custom Package Groups"
PR = "r1"

inherit packagegroup

PACKAGES = "\
         packagegroup-automate-home-base \
         packagegroup-automate-home-daemons \
         packagegroup-automate-home-core \
         packagegroup-automate-home-webserver \
         packagegroup-automate-home-graphiteapp \
         "

RDEPENDS_packagegroup-automate-home-base = "\
         ntp \
         tzdata \
         glibc-utils \
         localedef \
         "

RDEPENDS_packagegroup-automate-home-daemons = "\
         mosquitto \
         knxstack-usbhid-daemon \
         "

RDEPENDS_packagegroup-automate-home-core = "\
         python3 \
         python3-modules \
         python3-home \
         python3-knx-plugin \
         python3-sonos-plugin \
         python3-lifx-plugin \
         python3-home-assistant-plugin \
         hiredis \
         "

RDEPENDS_packagegroup-automate-home-webserver = "\
         python3 \
         python3-modules \
         python3-ws \
         python3-graphite-feeder \
         uwsgi \
         nginx \
         "

RDEPENDS_packagegroup-automate-home-graphiteapp = "\
         python3-twisted \
         python3-service-identity \
         python3-django \
         python3-django-tagging \
         python3-cairocffi \
         python3-scandir \
         python3-graphite-whisper \
         python3-graphite-carbon \
         python3-graphite-web \
         fontconfig \
         uwsgi \
         nginx \
         "

