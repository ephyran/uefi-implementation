#!/bin/sh
set -e

rm -rf iso

mkdir -p iso
mkdir -p iso/BOOT

cd boot/uefi
. ./init.sh
cd ../../

echo "Target: $ARCH" >> iso/BUILDINFO
echo "GCC Triple: $CC" >> iso/BUILDINFO
echo "Version: $VERSION" >> iso/BUILDINFO
echo "Date: `date +"%r %a %d %h %y"`" >> iso/BUILDINFO

cp boot/uefi/INIT.IMG iso/BOOT
rm boot/uefi/INIT.IMG

xorriso -as mkisofs \
    -R -J \
    -e BOOT/INIT.IMG \
    -no-emul-boot \
    -o jpos.iso iso
