#!/bin/bash
PWD=$(cd `dirname "$0"` && pwd)

source "$PWD/utils.sh"

DISTRO=$(get_distro)

# Install dependencies
echo "[INFO] Installing dependencies..." 1>&2
repo_refresh
if [[ "$DISTRO" == "fedora" ]]; then
    sudo dnf install -y gettext gcc autoconf libtool automake make asciidoc xmlto udns-devel libev-develgit python2-pip python2-devel zlib-devel openssl-devel asciidoc xmlto
elif [[ "$DISTRO" == "ubuntu" ]]; then
    sudo apt install -y python-pip
fi

# Install shadowsocks-libev
cd /tmp
if [[ "$DISTRO" == "fedora" ]]; then
    echo "[INFO] Installing shadowsocks-libev from git repo..."
    git clone --depth=1 https://github.com/shadowsocks/shadowsocks-libev.git
    cd shadowsocks-libev
    git submodule update --init --recursive
    # Installation of Libsodium
    export LIBSODIUM_VER=1.0.12
    wget https://download.libsodium.org/libsodium/releases/libsodium-$LIBSODIUM_VER.tar.gz
    tar xvf libsodium-$LIBSODIUM_VER.tar.gz
    pushd libsodium-$LIBSODIUM_VER
    ./configure --prefix=/usr && make
    sudo make install
    popd
    sudo ldconfig
    # Installation of MbedTLS
    export MBEDTLS_VER=2.5.1
    wget https://tls.mbed.org/download/mbedtls-$MBEDTLS_VER-gpl.tgz
    tar xvf mbedtls-$MBEDTLS_VER-gpl.tgz
    pushd mbedtls-$MBEDTLS_VER
    make SHARED=1 CFLAGS=-fPIC
    sudo make DESTDIR=/usr install
    popd
    sudo ldconfig
    # Start building
    ./autogen.sh && ./configure && make
    sudo make install
elif [[ "$DISTRO" == "ubuntu" ]]; then
    echo "[INFO] Installing shadowsocks-libev from ppa..." 1>&2
    sudo add-apt-repository -y ppa:max-c-lv/shadowsocks-libev
    sudo apt-get update
    sudo apt install -y shadowsocks-libev
fi
