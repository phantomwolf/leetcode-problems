#!/bin/bash
PWD=$(cd `dirname "$0"` && pwd)

if [[ $# -ne 5 ]]; then
    echo "Usage: $0 SERVER_IP REMOTE_PORT SS_METHOD SS_PASSWORD OBFS_PASSWORD"
    exit 255
fi

source "$PWD/utils.sh"

DISTRO=$(get_distro)
SERVER_IP="$1"          # IP of remote server
REMOTE_PORT="$2"        # Remote obfsproxy port
SS_METHOD="$3"          # shadowsocks encryption method
SS_PASSWORD="$4"        # shadowsocks password
OBFS_PASSWORD="$5"      # obfsproxy password

bash "$PWD/install-ss.sh"
bash "$PWD/setup-ss-client.sh" "$SS_METHOD" "$SS_PASSWORD"
bash "$PWD/setup-obfs-client.sh" "$SERVER_IP" "$REMOTE_PORT" "$OBFS_PASSWORD"
bash "$PWD/client-start.sh"
mkdir -p "$HOME/bin/"
ln -s "$PWD/client-start.sh" "$HOME/bin/client-start.sh"
