#!/bin/bash

echo "ringOS beta builder for Debian(-based) Linux"
echo "This script will ask you for password using sudo."

sudo apt-get update && echo Repository update successful || echo FAILED to update the repository
sudo apt-get install build-essential mtools && echo build-essential mtools installed successfully || echo FAILED to install build-essential mtools
sudo apt-get install nasm && echo NASM installed successfully || echo FAILED to install nasm
sudo apt-get install qemu-system-x86 && echo Qemu installed successfully || echo FAILED to install Qemu
sudo apt-get install git && echo git installed successfully || echo FAILED to install git
sudo apt-get install lld && echo lld installed successfully || echo FAILED to install lld
sudo apt-get install xorriso && echo xorriso installed successfully || echo FAILED to install xorriso
sudo apt-get install mkisofs && echo mkisofs installed successfully || echo FAILED to install mkisofs
git clone https://github.com/VanGutan/gnu-efi
mv bootloader gnu-efi/bootloader

cd gnu-efi && echo In gnu-efi directory || echo FAILED to enter gnu-efi directory
make bootloader && echo Bootloader successfully created || echo FAILED to create bootloader
cd ../kernel && echo In kernel directory || echo FAILED to enter kernel directory
make kernel && echo Kernel successfully created || echo FAILED to create kernel
make buildimg && echo Buildimg successfully created || echo FAILED to create buildimg
chmod +x ./ISO.sh
./ISO.sh
make run

cd ../
chmod +x ./clean.sh
./clean.sh

