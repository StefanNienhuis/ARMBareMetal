#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#include "uart.h"

void kernel_main() {
    uart_transmit_string("What's your name?\n> ");

    char msg[32];
    uart_receive_string(msg);

    uart_transmit_string("Hello, ");

    for (size_t i; i < strlen(msg); i++) {
        uart_transmit(msg[i]);
    }

    uart_transmit('\n');

    while (true) {}
}