#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#include "uart.h"

volatile struct uart_registers* const UART = (struct uart_registers*) 0x09000000;

size_t strlen(const char str[]) {
    size_t len = 0;

    while (str[len]) {
        len++;
    }

    return len;
}

void uart_transmit(uint8_t byte) {
    UART->DR = byte;
}

void uart_transmit_string(const char str[]) {
    for (size_t i = 0; i < strlen(str); i++) {
        uart_transmit(str[i]);
    }
}

uint8_t uart_receive() {
    while (true) {
        uint8_t data = UART->DR;

        if (data > 0) {
            return data;
        }
    }
}

const char* uart_receive_string(char* str) {
    size_t len = 0;

    while (true) {
        uint8_t data = uart_receive();

        if (data == '\r') {
            uart_transmit('\n');

            *str = '\0';
            break;
        } else {
            uart_transmit(data);

            *str = data;
            str++;
            len++;
        }
    }

    return (const char*) str;
}