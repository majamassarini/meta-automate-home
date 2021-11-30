#!/bin/sh

NAME=carbon-cache.py
DAEMON=/opt/graphite/bin/$NAME
PIDFILE=/var/run/$NAME.pid

# Sanity checks
test -f $DAEMON || exit 0

test -f /etc/default/automate-home && source /etc/default/automate-home
DAEMON_ARGS=""

start() {
        printf "Starting $NAME: "
        start-stop-daemon --start --quiet --background --exec $DAEMON \
                -- $DAEMON_ARGS start \
                && echo "OK" || echo "FAIL"
}

stop() {
        printf "Stopping $NAME: "
        start-stop-daemon --stop --quiet --pidfile $PIDFILE \
                && echo "OK" || echo "FAIL"
}

case "$1" in
        start)
                start
                ;;
        stop)
                stop
                ;;
        restart)
                stop
                sleep 1
                start
                ;;
        *)
                echo "Usage: $0 {start|stop|restart}"
                exit 1
esac
