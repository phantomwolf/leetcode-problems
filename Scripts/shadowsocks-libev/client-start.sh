#!/bin/bash
# Get distro name. Supported: ubuntu, fedora
function get_distro()
{
    which dnf &> /dev/null
    if [[ $? -eq 0 ]]; then
        echo "fedora"
        return 0
    fi
    which apt &> /dev/null
    if [[ $? -eq 0 ]]; then
        echo "ubuntu"
        return 0
    fi
    grep -i 'ubuntu' /etc/issue &> /dev/null
    if [[ $? -eq 0 ]]; then
        echo "ubuntu"
        return 0
    fi
    exit 255
}

SS_START_SCRIPT="$HOME/bin/ssstart"
OBFS_START_SCRIPT="$HOME/bin/obfs"
DISTRO=$(get_distro)

bash $OBFS_START_SCRIPT
if [[ "$DISTRO" == "fedora" ]]; then
    bash $SS_START_SCRIPT
elif [[ "$DISTRO" == "ubuntu" ]]; then
    sudo systemctl restart shadowsocks-libev-local@1
fi
