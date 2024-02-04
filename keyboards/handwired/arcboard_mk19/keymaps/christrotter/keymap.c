// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#if defined(CONSOLE_ENABLE)
    #include "print.h"
    void keyboard_post_init_user(void) {
        // Customise these values to desired behaviour
        debug_enable=true;
        debug_matrix=true;
        debug_keyboard=true;
        // debug_mouse=true;
    }
#endif
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,KC_1,KC_2,KC_3,KC_4,KC_5,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                KC_6,KC_7,KC_8,KC_9,KC_0,KC_EQUAL,          KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
        KC_TAB , KC_Q,LT(0,KC_W),KC_H, LT(0,KC_R),LT(0,KC_T),KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,           KC_U,LT(0,KC_I), KC_O,   KC_P,   KC_MINUS,   KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
        KC_LSFT, LT(0,KC_A),  KC_S,  KC_D,  KC_F , KC_G,   KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,             KC_H, KC_J, KC_K, KC_L, KC_QUOT, KC_SCLN,   KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
        KC_D,LT(0,KC_Z),LT(0,KC_X),LT(0,KC_C),LT(0,KC_V),LT(0,KC_B),KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,    LT(0,KC_N), KC_M, KC_COMM, KC_DOT, KC_SLASH, KC_1,   KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
        KC_A,  KC_B,    KC_C,    KC_D,    KC_E,   KC_F,   KC_G,   KC_H,  KC_I, KC_J, KC_K, KC_L, KC_M, KC_N, KC_O, KC_P, KC_A,  KC_B,    KC_C,    KC_D,    KC_E,   KC_F,   KC_G,   KC_H,  KC_I, KC_J, KC_K, KC_L, KC_M, KC_N, KC_O, KC_P,
        KC_A,  KC_B,    KC_C,    KC_D,    KC_E,   KC_F,   KC_G,   KC_H,  KC_I, KC_J, KC_K, KC_L, KC_M, KC_N, KC_O, KC_P, KC_A,  KC_B,    KC_C,    KC_D,    KC_E,   KC_F,   KC_G,   KC_H,  KC_I, KC_J, KC_K, KC_L, KC_M, KC_N, KC_O, KC_P,
        KC_A,  KC_B,    KC_C,    KC_D,    KC_E,   KC_F,   KC_G,   KC_H,  KC_I, KC_J, KC_K, KC_L, KC_M, KC_N, KC_O, KC_P, KC_A,  KC_B,    KC_C,    KC_D,    KC_E,   KC_F,   KC_G,   KC_H,  KC_I, KC_J, KC_K, KC_L, KC_M, KC_N, KC_O, KC_P,
        KC_A,  KC_B,    KC_C,    KC_D,    KC_E,   KC_F,   KC_G,   KC_H,  KC_I, KC_J, KC_K, KC_L, KC_M, KC_N, KC_O, KC_P, KC_A,  KC_B,    KC_C,    KC_D,    KC_E,   KC_F,   KC_G,   KC_H,  KC_I, KC_J, KC_K, KC_L, KC_M, KC_N, KC_O, KC_P,
        KC_A,  KC_B,    KC_C,    KC_D,    KC_E,   KC_F,   KC_G,   KC_H,  KC_I, KC_J, KC_K, KC_L, KC_M, KC_N, KC_O, KC_P, KC_A,  KC_B,    KC_C,    KC_D,    KC_E,   KC_F,   KC_G,   KC_H,  KC_I, KC_J, KC_K, KC_L, KC_M, KC_N, KC_O, KC_P,
        KC_A,  KC_B,    KC_C,    KC_D,    KC_E,   KC_F,   KC_G,   KC_H,  KC_I, KC_J, KC_K, KC_L, KC_M, KC_N, KC_O, KC_P, KC_A,  KC_B,    KC_C,    KC_D,    KC_E,   KC_F,   KC_G,   KC_H,  KC_I, KC_J, KC_K, KC_L, KC_M, KC_N, KC_O, KC_P
    )
};
