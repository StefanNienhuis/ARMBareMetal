# ARM Bare Metal

An experiment with bare metal C on ARM processors. Emulated using QEMU on the Cortex A72.

This repository is just some sample code and scripts (and some details on macOS/M1 support). See the sources below for actual guides.

## Details

Cross compiling GCC and binutils is required. See https://wiki.osdev.org for details.

`hello-world/` is a very basic kernel implementation.

`uart/` is a very basic UART driver implementation.

**Warning:** This is likely the worst C code you will ever see (especially in the UART driver). C is not my area of expertise and especially not at this low level.

## macOS

This was all done in macOS on an M1 Mac, which required some workarounds and different arguments.

For starters, I had to apply some patches to GCC to make it all work on my M1 Mac. See https://github.com/richfelker/musl-cross-make/issues/116#issuecomment-823612404.

`gmp`, `mpc`, `mpfr` and `libiconv` had to be installed (through something like Homebrew), either because they were not included or were very outdated.

`binutils` configure options:
```sh
--target=$TARGET --prefix=$PREFIX --enable-interwork --enable-multilib --disable-nls --disable-werror
```

`gcc` configure options:
```sh
--target=$TARGET --prefix=$PREFIX --disable-nls --enable-languages=c,c++ --without-headers --enable-interwork --enable-multilib --with-gmp=/opt/homebrew --with-mpc=/opt/homebrew --with-mpfr=/opt/homebrew --with-libiconv-prefix=/opt/homebrew/opt/libiconv
```

## Sources

 - https://wiki.osdev.org/, specifically
    - https://wiki.osdev.org/User:Zesterer/Bare_Bones
    - https://wiki.osdev.org/Bare_Bones
    - https://wiki.osdev.org/GCC_Cross-Compiler
 - https://github.com/freedomtan/aarch64-bare-metal-qemu (boot assembly)
 - https://developer.arm.com/documentation/ddi0183/ (UART specification)
 - https://github.com/qemu/qemu/blob/master/hw/arm/virt.c (UART memory mapping)
 - https://github.com/richfelker/musl-cross-make/issues/116#issuecomment-823612404 (M1 GCC patches)