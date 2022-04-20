#!/bin/zsh

rm -f kernel.elf
./build.sh
../start.sh kernel.elf