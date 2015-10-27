#!/bin/bash
PWD=$(cd `dirname "$0"` && pwd)

source "$PWD/utils.sh"

DISTRO=$(get_distro)

if [[ "$DISTRO" == "fedora" ]]; then
    sudo killall ss-local
elif [[ "$DISTRO" == "ubuntu" ]]; then
    sudo systemctl stop shadowsocks-libev-local@1
fi
sudo killall obfsproxy
