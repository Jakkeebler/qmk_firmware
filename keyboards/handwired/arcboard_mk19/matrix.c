// Copyright 2018-2022 Nick Brassel (@tzarc)
// Copyright 2020-2023 alin m elena (@alinelena, @drFaustroll)
// Copyright 2023 Stefan Kerkmann (@karlk90)
// Copyright 2023 (@burkfers)
// SPDX-License-Identifier: GPL-3.0-or-later

#include "quantum.h"
#include "spi_master.h"
#if defined(CONSOLE_ENABLE)
    #include "print.h"
#endif
// todo remove rows_count here, too
static const uint16_t row_values[ROWS_COUNT] = ROWS;

void matrix_init_custom(void) {
    setPinOutput(SPI_MATRIX_CHIP_SELECT_PIN_COLS);
    writePinHigh(SPI_MATRIX_CHIP_SELECT_PIN_COLS);
    setPinOutput(SPI_MATRIX_CHIP_SELECT_PIN_ROWS);
    writePinHigh(SPI_MATRIX_CHIP_SELECT_PIN_ROWS);
    if (!(is_keyboard_left())) {
        setPinOutput(PMW33XX_CS_PIN);
        writePinHigh(PMW33XX_CS_PIN);
    }
    spi_init();
}

static inline void write_to_rows(uint16_t value) {
    uint8_t message[2] = {(uint8_t)(value & 0xFF), (value >> 8) & 0xFF}; // cut 0xABCD into {0xAB, 0xCD}
    spi_start(SPI_MATRIX_CHIP_SELECT_PIN_ROWS, true, SPI_MODE, SPI_MATRIX_DIVISOR);
    spi_transmit(message, 2);
    spi_stop();
}

// removed this, not sure what it was getting us - matrix still works
// no perf improvement
// static inline void set_row_high(uint16_t row) {
//     write_to_rows(row_values[row]);
// }

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    // TODO replace ROWS_COUNT with a sizeof or array_size or something
    static matrix_row_t temp_matrix[ROWS_COUNT] = {0};
    
    for (uint8_t row = 0; row < (ROWS_COUNT); row++) {
        uint8_t temp_col_receive[MATRIX_COLS_SHIFT_REGISTER_COUNT] = {0};
        uint16_t temp_col_state;

        // set_row_high(row);
        write_to_rows(row_values[row]);

        spi_start(SPI_MATRIX_CHIP_SELECT_PIN_COLS, true, SPI_MODE, SPI_MATRIX_DIVISOR);
        spi_stop();
        spi_start(SPI_MATRIX_CHIP_SELECT_PIN_COLS, true, SPI_MODE, SPI_MATRIX_DIVISOR);
        spi_receive((uint8_t*)temp_col_receive, MATRIX_COLS_SHIFT_REGISTER_COUNT);
        spi_stop();

        temp_col_state = temp_col_receive[0] | (temp_col_receive[1] << 8);
        // if (temp_col_state != 0) {
        //     printf("row/row_val/col: [ %u / %u / %u ] \n", row, row_values[row], temp_col_state);
        // }
        temp_matrix[row] = temp_col_state;
    }
    bool matrix_has_changed = memcmp(current_matrix, temp_matrix, sizeof(temp_matrix)) != 0;
    if (matrix_has_changed) {
        memcpy(current_matrix, temp_matrix, sizeof(temp_matrix));
    }
    return matrix_has_changed;
}
