#!/bin/sh
set -e

export ROOTDIR="`pwd`"
export VERSION="0.1.0"

read -p "Enter target architecture: " ARCH &&
    [[ $ARCH == [x][8][6][_][6][4] ||
        $ARCH == [a][r][m][7] ]] || (echo -e "Invalid architecture $ARCH" && exit 1)

read -p "Enter gcc target triple: " CC
