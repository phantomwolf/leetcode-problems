#!/bin/bash
PWD=$(cd `dirname "$0"` && pwd)

if [[ $# -ne 2 ]]; then
    echo "Usage: $0 SS_METHOD SS_SS_PASSWORD"
    exit 255 
fi

SS_METHOD="$1"
SS_SS_PASSWORD="$2"
CONF_FILE="$PWD/server.json"
SS_START_SCRIPT="$HOME/bin/ssstart"

source "$PWD/utils.sh"

DISTRO=$(get_distro)

# Configuration file
if [[ "$DISTRO" == "fedora" ]]; then
    sed -e "s/<password>/$SS_PASSWORD/g" -e "s/<method>/$SS_METHOD/g" "$CONF_FILE" > $HOME/.shadowsocks-server
    cmd="killall ss-server
nohup ss-server -c ~/.shadowsocks-server &> /tmp/ss-server.log &"
    echo "$cmd" > $SS_START_SCRIPT
    chmod +x $SS_START_SCRIPT
elif [[ "$DISTRO" == "ubuntu" ]]; then
    sudo bash -c "sed -e 's/<password>/$SS_PASSWORD/g' -e 's/<method>/$SS_METHOD/g' '$CONF_FILE' > /etc/shadowsocks-libev/1.json"
    sudo systemctl enable shadowsocks-libev-server@1
fi
