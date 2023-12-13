#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/trusos.kernel isodir/boot/trusos.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "trusos" {
	multiboot /boot/trusos.kernel
}
EOF
grub-mkrescue -o trusos.iso isodir
