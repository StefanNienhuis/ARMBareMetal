#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

struct uart_registers {
    /* All registers are 32 bits wide */
   
    uint32_t DR;            /* 0x000 - Data register - Data */
    uint32_t RSR_ECR;           /* 0x004 - Receive status / error clear register */
    uint32_t _reserved0[4];     /* 0x008 - 0x014 - Reserved */
    uint32_t FR;                /* 0x018 - Flag register */
    uint32_t _reserved1;        /* 0x01C - Reserved */
    uint32_t ILPR;              /* 0x020 - IrDA low-power counter register */
    uint32_t IBRD;              /* 0x024 - Integer bau rate register */
    uint32_t FBRD;              /* 0x028 - Fractional baud rate register */
    uint32_t LCR_H;             /* 0x02C - Line control register */
    uint32_t CR;                /* 0x030 - Control register */
    uint32_t IFLS;              /* 0x034 - Interrupt FIFO level select register */
    uint32_t IMSC;              /* 0x038 - Interrupt mask set/clear register */
    uint32_t RIS;               /* 0x03C - Raw interrupt status register */
    uint32_t MIS;               /* 0x040 - Masked interrupt status register */
    uint32_t ICR;               /* 0x044 - Interrupt clear register */
    uint32_t DMACR;             /* 0x048 - DMA control register */
    /* 0x04C - 0xFDC - Reserved */
    /* 0xFE0 - 0xFEC - Peripheral identification registers */
    /* 0xFF0 - 0xFFC - PrimeCell identification registers */
} __attribute__((__packed__));

size_t strlen(const char str[]);
void uart_transmit(uint8_t byte);
void uart_transmit_string(const char str[]);
uint8_t uart_receive();
const char* uart_receive_string(char* str);