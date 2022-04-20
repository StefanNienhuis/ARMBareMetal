#!/bin/zsh

if [ -z $1 ]; then
    echo "Missing kernel"
    exit 1
fi

qemu-system-aarch64 --machine virt --cpu cortex-a72 -nographic -kernel $1