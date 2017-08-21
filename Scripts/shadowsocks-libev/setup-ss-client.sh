#!/bin/bash
PWD=$(cd `dirname "$0"` && pwd)

if [[ $# -ne 2 ]]; then
    echo "Usage: $0 SS_METHOD SS_PASSWORD"
    exit 255 
fi

source "$PWD/utils.sh"

DISTRO=$(get_distro)
SS_METHOD="$1"
SS_PASSWORD="$2"
CONF_FILE="$PWD/local.json"
SS_START_SCRIPT="$HOME/bin/ssstart"


# Configuration file
if [[ "$DISTRO" == "fedora" ]]; then
    sed -e "s/<password>/$SS_PASSWORD/g" -e "s/<method>/$SS_METHOD/g" "$CONF_FILE" > $HOME/.shadowsocks-local
    cmd="killall ss-local
nohup ss-local -c $HOME/.shadowsocks-local &> /tmp/ss-local.log &"
    echo "$cmd" > $SS_START_SCRIPT
    chmod +x $SS_START_SCRIPT
elif [[ "$DISTRO" == "ubuntu" ]]; then
    sudo bash -c "sed -e 's/<password>/$SS_PASSWORD/g' -e 's/<method>/$SS_METHOD/g' '$CONF_FILE' > /etc/shadowsocks-libev/1.json"
    sudo systemctl enable shadowsocks-libev-local@1
fi
