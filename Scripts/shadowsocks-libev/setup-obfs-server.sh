#!/bin/bash
PWD=$(cd `dirname "$0"` && pwd)

if [[ $# -ne 2 ]]; then
    echo "Usage: $0 REMOTE_PORT OBFS_PASSWORD"
    exit 255
fi

source "$PWD/utils.sh"

DISTRO=$(get_distro)
REMOTE_PORT="$1"
OBFS_PASSWORD="$2"
OBFS_START_SCRIPT="$HOME/bin/obfs"

# Install obfsproxy
sudo pip install service_identity obfsproxy

# Setup obfsproxy
cmd="killall obfsproxy
nohup obfsproxy --data-dir=/tmp/scramblesuit-server scramblesuit --password="$OBFS_PASSWORD" --dest=127.0.0.1:11257 server 0.0.0.0:$REMOTE_PORT &> /tmp/obfsproxy.log &"
mkdir -p $(dirname "$OBFS_START_SCRIPT")
echo "$cmd" > $OBFS_START_SCRIPT
chmod +x $OBFS_START_SCRIPT
