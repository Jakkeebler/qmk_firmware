// Copyright 2023 christrotter (@christrotter)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define DEBOUNCE 10

// SPI configuration
#define SPI_MATRIX_DIVISOR 16
#define SPI_MODE 0
#define SPI_DRIVER SPID1
#define SPI_SCK_PIN  GP10
#define SPI_MOSI_PIN GP11
#define SPI_MISO_PIN GP12

// 74HC595 config
#define SPI_MATRIX_CHIP_SELECT_PIN_ROWS GP9
#define MATRIX_COLS_SHIFT_REGISTER_COUNT 2

// 74HC589 config
#define SPI_MATRIX_CHIP_SELECT_PIN_COLS GP5
#define MATRIX_ROWS_SHIFT_REGISTER_COUNT 2

// custom matrix config
#define ROWS_COUNT 10 // this can be replaced w. array_size or something?
#define ROWS { \
    0b0000000000000001, \
    0b0000000000000010, \
    0b0000000000000100, \
    0b0000000000001000, \
    0b0000000000010000, \
    0b0000000000100000, \
    0b0000000001000000, \
    0b0000000010000000, \
    0b0000000100000000, \
    0b0000001000000000, \
}
 
    // 0b0000010000000000, 
    // 0b0000100000000000, 
    // 0b0001000000000000, 
    // 0b0010000000000000, 
    // 0b0100000000000000, 
    // 0b1000000000000000, 

// #define ROWS (uint16_t[]){0x4000, 0x2000, 0x1000, 0x0800, 0x0400, 0x0200, 0x0100, 0x0080, 0x0040, 0x0020, 0x0010, 0x0008, 0x0004, 0x0002, 0x0001}
// Rows that should be scanned, by their bit position and thus row index.

// this makes sense if they are == PCB-ROW0, like the physical pin location
// #define ROWS { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 }
// #define ROWS { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 }
// #define ROWS { 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 }

// Split settings
#if defined(SPLIT_KEYBOARD)
    #define SPLIT_HAND_PIN GP2                  // validated this works!
    // #define SPLIT_HAND_PIN_LOW_IS_LEFT
    #define SERIAL_USART_FULL_DUPLEX
    #define SERIAL_USART_PIN_SWAP
    #define SERIAL_USART_TX_PIN GP0             // I could never get full-duplex working; this is the only config needed for half-duplex
    #define SERIAL_USART_RX_PIN GP1
    #define SERIAL_PIO_USE_PIO1                 // using PIO0 i get a lot of dropped packets; none using PIO1
    #define SERIAL_USART_SPEED 800000           // this improves scan rate by 200
    #define SPLIT_LAYER_STATE_ENABLE            // docs say use this if you are using split and rgb lighting per layer // this added 20 to scanrate???
#endif

#if defined(RGB_MATRIX_ENABLE) || defined(RGB_MATRIX_LEDMAPS_ENABLED)
    #define RGB_MATRIX_DEFAULT_HUE 5
    #define RGB_MATRIX_DEFAULT_SAT 5
#endif