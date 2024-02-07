// Copyright 2021 Mikael Manukyan <arm.localhost@gmail.com>
// Copyright 2023 Chris Trotter (@christrotter)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"

// the naming here is arbitrary.
// 
#define LEDMAP( \
    L_10, L_11, L_12, L_13, L_14, L_15,     R_10, R_11, R_12, R_13, R_14, R_15, \
    L_20, L_21, L_22, L_23, L_24, L_25,     R_20, R_21, R_22, R_23, R_24, R_25, \
    L_30, L_31, L_32, L_33, L_34, L_35,     R_30, R_31, R_32, R_33, R_34, R_35, \
    L_40, L_41, L_42, L_43, L_44, L_45,     R_40, R_41, R_42, R_43, R_44, R_45, \
    L_50, L_51, L_52, L_53, L_54, L_55,     R_50, R_51, R_52, R_53, R_54, R_55, \
    L_00, L_01, L_02, L_03, L_04, L_05, L_06, L_07,     R_00, R_01, R_02, R_03, R_04, R_05, R_06, R_07 \
) { \
    L_30, L_20, L_10, L_50, L_40, \
    L_31, L_21, L_11, L_51, L_41, \
    L_32, L_22, L_12, L_52, L_42, \
    L_33, L_23, L_13, L_53, L_43, \
    L_34, L_24, L_14, L_54, L_44, \
    L_35, L_25, L_15, L_55, L_45, \
    L_00, L_01, L_02, L_03, L_04, L_05, L_06, L_07, \
    R_30, R_20, R_10, R_50, R_40, \
    R_31, R_21, R_11, R_51, R_41, \
    R_32, R_22, R_12, R_52, R_42, \
    R_33, R_23, R_13, R_53, R_43, \
    R_34, R_24, R_14, R_54, R_44, \
    R_35, R_25, R_15, R_55, R_45, \
    R_00, R_01, R_02, R_03, R_04, R_05, R_06, R_07, \
}

typedef uint8_t ledmap[RGB_MATRIX_LED_COUNT][3];
extern const ledmap ledmaps[];

void set_rgb_ledmap(uint8_t first_led, uint8_t last_led, int val, int layer);
void set_rgb_range(uint8_t first_led, uint8_t last_led, int hue, int sat, int val);

void rgb_matrix_layers_enable(void);     // do we need this?
void rgb_matrix_layers_disable(void);    // do we need this?
