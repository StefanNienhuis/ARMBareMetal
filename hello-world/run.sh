#!/bin/zsh

rm kernel.elf
./build.sh
../start.sh kernel.elf