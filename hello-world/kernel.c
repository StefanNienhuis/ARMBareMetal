#include <stddef.h>
#include <stdint.h>

volatile uint64_t* const UART = (uint64_t*) 0x09000000;

void print_uart(const char *string) {
    while (*string != '\0') {
        *UART = (uint64_t) *string;
        string++;
    }
}

void kernel_main() {
    print_uart("Hello World!\n\nIncluding new lines!\n");
}