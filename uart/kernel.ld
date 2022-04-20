ENTRY(_start)
SECTIONS
{
    . = 0x40000000; /* Start at RAM (from QEMU aarch64 virt platform wiki) */
    .boot . : { boot.o(.text) }
    .text : { *(.text) }
    .data : { *(.data) }
    .bss : { *(.bss COMMON) }
    . = ALIGN(8);
    . = . + 0x1000; /* 4 kB stack memory */
    stack_top = .;
}