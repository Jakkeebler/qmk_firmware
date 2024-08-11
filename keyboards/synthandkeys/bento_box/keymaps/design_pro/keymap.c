// Copyright 2023 Synth-and-Keys (@Synth-and-Keys)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Layers
enum bento_layers {
    _DEFAULT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT(
                                            QK_BOOT,            G(S(KC_S)),
                    KC_HOME,                KC_NO,              KC_NO,
        KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_UP,      KC_NO,      C(KC_T),            C(KC_W),
        KC_LEFT,    KC_DOWN,    KC_RIGHT,   S(C(KC_TAB)),       C(KC_TAB)
    ),
};

    /* LAYER TEMPLATE
    * ------------------------------------
    * |      |      |      |      |      |
    * ------------------------------------
    * |      |      |      |      |      |
    * ------------------------------------
    * |      |      |      |      |      |
    * ------------------------------------
    * |      |      |      |      |      |
    * ------------------------------------
    * |      |      |      |      |      |
    * ------------------------------------
     */
