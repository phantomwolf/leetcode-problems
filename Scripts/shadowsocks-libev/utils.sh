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

# Update metadata
function repo_refresh()
{
    if [[ "$DISTRO" == "fedora" ]]; then
        sudo dnf update -y
    elif [[ "$DISTRO" == "ubuntu" ]]; then
        sudo apt update
    fi
}

# 1 - packages to install
function package_install()
{
    if [[ "$DISTRO" == "fedora" ]]; then
        sudo dnf install -y $1
    elif [[ "$DISTRO" == "ubuntu" ]]; then
        sudo apt install -y $1
    fi
    if [[ $? -ne 0 ]]; then
        exit 1
    fi
}
