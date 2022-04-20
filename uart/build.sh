#!/bin/zsh

aarch64-none-elf-as -g boot.s -o boot.o
aarch64-none-elf-gcc -ffreestanding -c -g kernel.c -o kernel.o
aarch64-none-elf-gcc -ffreestanding -c -g uart.c -o uart.o
aarch64-none-elf-ld -T kernel.ld kernel.o uart.o boot.o -o kernel.elf

rm boot.o kernel.o uart.o