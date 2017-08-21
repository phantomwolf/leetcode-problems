#!/bin/bash
PWD=$(cd `dirname "$0"` && pwd)

if [[ $# -ne 3 ]]; then
    echo "Usage: $0 SERVER_IP REMOTE_PORT OBFS_PASSWORD"
    exit 255
fi

source "$PWD/utils.sh"

DISTRO=$(get_distro)
SERVER_IP="$1"
REMOTE_PORT="$2"
OBFS_PASSWORD="$3"
OBFS_START_SCRIPT="$HOME/bin/obfs"

# Install obfsproxy
sudo pip install service_identity obfsproxy

# Setup obfsproxy
cmd="killall obfsproxy
nohup obfsproxy --data-dir=/tmp/scramblesuit-server scramblesuit --password='$OBFS_PASSWORD' --dest=${SERVER_IP}:${REMOTE_PORT} client 127.0.0.1:11257 &> /tmp/obfsproxy.log &"
mkdir -p $(dirname "$OBFS_START_SCRIPT")
echo "$cmd" > $OBFS_START_SCRIPT
chmod +x $OBFS_START_SCRIPT
