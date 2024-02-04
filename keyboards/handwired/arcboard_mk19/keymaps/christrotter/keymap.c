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
/*
row0 = 8 keys in thumb row, but two are disconnected/useless, just leds in chain
row1 = fkeys 0-5, dpad 6-10 (4 arrows, 1 center push)
row2 = num keys 0-5, extra falcon keys or misc
row3 = letters1 0-5, macro1 6-9
row4 = letters2 0-5, macro2 6-9
row5 = letters3 0-5

info.json helper
row0,  row1   => 8 (0-7)
row2,  row3   => 11 (0-10)
row4,  row5   => 8 (0-7)
row6,  row7   => 10 (0-9)
row8,  row9   => 10 (0-9)
row10, row11  => 6 (0-5)
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_BSPC,     KC_L,       KC_NO,     KC_DEL,    KC_ESC,    KC_LSFT,  KC_TAB,     KC_NO,                                       KC_SPACE,  KC_ENTER,  KC_NO,     KC_L,      KC_L,       KC_LSFT,   KC_M,      KC_NO, 
        KC_ESC,      KC_1,       KC_2,      KC_3,      KC_4,      KC_5,      KC_UP,     KC_RIGHT,  KC_DOWN,   KC_LEFT,   KC_P,       KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_EQUAL,  KC_UP,     KC_RIGHT,  KC_DOWN,   KC_LEFT,   KC_P,
        KC_TILD,     KC_1,       KC_2,      KC_3,      KC_4,      KC_5,      KC_P,      KC_P,                                        KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_EQUAL,  KC_P,      KC_P,
        KC_TAB,      KC_Q,       LT(0,KC_W),KC_H,      LT(0,KC_R),LT(0,KC_T),KC_1,      KC_2,      KC_3,      KC_4,                  KC_Y,      KC_U,      LT(0,KC_I),KC_O,      KC_P,      KC_MINUS,  KC_1,      KC_2,      KC_3,      KC_4,
        KC_LSFT,     LT(0,KC_A), KC_S,      KC_D,      KC_F,      KC_G,      KC_5,      KC_6,      KC_7,      KC_8,                  KC_H,      KC_J,      KC_K,      KC_L,      KC_QUOT,   KC_SCLN,   KC_5,      KC_6,      KC_7,      KC_8,
        KC_D,        LT(0,KC_Z), LT(0,KC_X),LT(0,KC_C),LT(0,KC_V),LT(0,KC_B),                                                        LT(0,KC_N),KC_M,      KC_COMM,   KC_DOT,    KC_SLASH,  KC_1
    )
};
