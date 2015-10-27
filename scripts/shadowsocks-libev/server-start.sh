#!/bin/bash
PWD=$(cd `dirname "$0"` && pwd)

source "$PWD/utils.sh"

SS_START_SCRIPT="$HOME/bin/ssstart"
OBFS_START_SCRIPT="$HOME/bin/obfs"
DISTRO=$(get_distro)

bash $OBFS_START_SCRIPT
if [[ "$DISTRO" == "fedora" ]]; then
    bash $SS_START_SCRIPT
elif [[ "$DISTRO" == "ubuntu" ]]; then
    sudo systemctl restart shadowsocks-libev-server@1
fi
