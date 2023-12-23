#!/bin/sh

echo -e "Creating BOOTX64.EFI..."

for FILE in *.c; do
    echo -e "Compiling $FILE..."
    $ARCH-w64-mingw32-gcc -ffreestanding -mcmodel=large -mno-red-zone -mno-mmx -mno-sse -mno-sse2 -c $FILE -o $FILE.o
done

echo -e "Linking BOOTX64.EFI..."
$ARCH-w64-mingw32-gcc -ffreestanding -nostdlib -Wl,-dll -shared -Wl,--subsystem,10 -e efi_main -o BOOTX64.EFI *.o

rm *.o

echo -e "Creating INIT.IMG..."
dd if=/dev/zero of=INIT.IMG bs=1k count=1440
mformat -i INIT.IMG -f 1440 ::
mmd -i INIT.IMG ::/EFI
mmd -i INIT.IMG ::/EFI/BOOT

echo -e "Copying BOOTX64.EFI..."
mcopy -i INIT.IMG BOOTX64.EFI ::/EFI/BOOT
rm BOOTX64.EFI
