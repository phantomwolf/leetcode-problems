#!/bin/bash
PWD=$(cd `dirname "$0"` && pwd)

if [[ $# -ne 4 ]]; then
    echo "Usage: $0 REMOTE_PORT SS_METHOD SS_PASSWORD OBFS_PASSWORD"
    exit 255
fi

source "$PWD/utils.sh"

DISTRO=$(get_distro)
REMOTE_PORT="$1"
SS_METHOD="$2"
SS_PASSWORD="$3"
OBFS_PASSWORD="$4"

bash "$PWD/install-ss.sh"
bash "$PWD/setup-ss-server.sh" "$SS_METHOD" "$SS_PASSWORD"
bash "$PWD/setup-obfs-server.sh" "$REMOTE_PORT" "$OBFS_PASSWORD"
bash "$PWD/server-start.sh"
mkdir -p "$HOME/bin/"
ln -s "$PWD/server-start.sh" "$HOME/bin/server-start.sh"
