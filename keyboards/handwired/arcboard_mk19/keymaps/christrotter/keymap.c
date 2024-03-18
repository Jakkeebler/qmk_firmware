// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "arcboard_mk19.h"
#include "keymap.h"

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

#if defined(POINTING_DEVICE_ENABLE)
    #include "pointing.c"
#endif

#if defined(RGB_MATRIX_LEDMAPS_ENABLED)
    #include "rgb_ledmaps.h"
#endif

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }
__attribute__((weak)) void post_process_record_keymap(uint16_t keycode, keyrecord_t *record) {}
void                       post_process_record_user(uint16_t keycode, keyrecord_t *record) { post_process_record_keymap(keycode, record); }

/*
row0 = 8 keys in thumb row, but two are disconnected/useless, just leds in chain
row1 = fkeys 0-5, dpad 6-10 (4 arrows, 1 center push)
row2 = num keys 0-5, extra falcon keys or misc
row3 = letters1 0-5, macro1 6-9
row4 = letters2 0-5, macro2 6-9
row5 = letters3 0-5

info.json helper 
old                             new
row0,  row1  => 8 (0-7)         row10,  row11   => 6 (0-5)
row2,  row3  => 11 (0-10)       row2,  row3   => 10 (0-9)
row4,  row5  => 8 (0-7)         row4,  row5   => 10 (0-9)
row6,  row7  => 10 (0-9)        row4,  row5   => 8 (0-7)
row8,  row9  => 10 (0-9)        row2,  row3   => 11 (0-10)
row10, row11 => 6 (0-5)         row0, row1  => 8 (0-7)

row5,  row11 => 11 (0-10)  
row4,  row10 => 8 (0-7)
row3,  row9  => 10 (0-9)   
row2,  row8  => 10 (0-9)  
row1,  row7  => 6 (0-5)  
row0,  row6  => 8 (0-7)

*/
// will we be keeping the same col count? i.e. macropad is 4x2
// 11 x 6 matrix
// and what does this mean for the ledmaps?
// this is not correct - woo good catch here - the schematic says row8/9, but there _is_ no row8/9!
// so we need to 
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        EE_CLR,      QK_BOOT,       KC_2,      KC_3,      KC_4,      KC_5,      KC_UP,     KC_RIGHT,  KC_DOWN,   KC_LEFT,   KC_P,       EE_CLR,      QK_BOOT,      KC_8,      KC_9,      KC_0,      KC_EQUAL,  KC_UP,     KC_RIGHT,  KC_DOWN,   KC_LEFT,   KC_P,
        KC_TILD,     KC_1,       KC_2,      KC_3,      KC_4,      KC_5,      KC_P,      KC_P,                                        KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_EQUAL,  KC_P,      KC_P,
        KC_TAB,      KC_Q,       LT(0,KC_W),KC_E,      LT(0,KC_R),LT(0,KC_T),KC_1,      KC_2,      KC_3,      KC_4,                  KC_Y,      KC_U,      LT(0,KC_I),KC_O,      KC_P,      KC_MINUS,  KC_1,      KC_2,      KC_3,      KC_4,
        KC_LSFT,     LT(0,KC_A), KC_S,      KC_D,      KC_F,      KC_G,      KC_5,      KC_6,      KC_7,      KC_8,                  KC_H,      KC_J,      KC_K,      KC_L,      KC_QUOT,   KC_SCLN,   KC_5,      KC_6,      KC_7,      KC_8,
        DRAG_SCROLL,        LT(0,KC_Z), LT(0,KC_X),LT(0,KC_C),LT(0,KC_V),LT(0,KC_B),                                                        LT(0,KC_N),KC_M,      KC_COMM,   KC_DOT,    KC_SLASH,  KC_1,
        KC_BSPC,     MO(_NAV),   KC_DEL,    KC_ESC,    KC_LSFT,   KC_TAB,                                         KC_SPACE,  KC_ENTER,   MO(_SYMBOLS), MO(_NAV), KC_LSFT,   KC_M
    ),
    [_MOUSE] = LAYOUT(
        EE_CLR,  _______, _______, _______, _______, _______,      KC_UP,     KC_RIGHT,  KC_DOWN,   KC_LEFT,   KC_P,       EE_CLR,  _______, _______, _______, _______, _______,  KC_UP,     KC_RIGHT,  KC_DOWN,   KC_LEFT,   KC_P,
        _______, _______, _______, _______, _______, _______,      KC_P,      KC_P,                                        _______, _______, _______, _______, _______, _______,  KC_P,      KC_P,
        _______, _______, _______, _______, _______, _______,      KC_1,      KC_2,      KC_3,      KC_4,                  _______, _______, _______, _______, _______, _______,  KC_1,      KC_2,      KC_3,      KC_4,
        _______, _______, _______, _______, _______, _______,      KC_5,      KC_6,      KC_7,      KC_8,                  _______, _______, _______, _______, _______, _______,  KC_5,      KC_6,      KC_7,      KC_8,
        _______, _______, _______, _______, _______, _______,                                                              _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                                              _______, _______, _______, _______, _______, _______
    ),
    [_SYMBOLS] = LAYOUT(
        _______,  _______, _______, _______, _______, _______,     KC_UP,     KC_RIGHT,  KC_DOWN,   KC_LEFT,   KC_P,       _______, _______, _______, _______, _______, _______,  KC_UP,     KC_RIGHT,  KC_DOWN,   KC_LEFT,   KC_P,
        _______, _______, _______, _______, _______, _______,      KC_P,      KC_P,                                        KC_MACSHOT, MAGIPLAY,    _______,    _______,    _______, _______,  KC_P,      KC_P,
        _______, KC_EXLM, KC_AT,   KC_LPRN, KC_RPRN, KC_AMPR,      KC_1,      KC_2,      KC_3,      KC_4,                  KC_PPLS, KC_1,    KC_2,    KC_3,    KC_PMNS, KC_EQUAL,   KC_1,      KC_2,      KC_3,      KC_4,
        _______, KC_HASH, KC_DLR,  KC_LCBR, KC_RCBR, KC_GRV,      KC_5,      KC_6,      KC_7,      KC_8,                   KC_PAST, KC_4,    KC_5,    KC_6,    KC_0,    KC_COMM,    KC_5,      KC_6,      KC_7,      KC_8,
        _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_PIPE,                                                              KC_DOT,  KC_7,    KC_8,    KC_9,    KC_BSLS, _______,
        _______, _______, _______, _______, _______, KC_MACLOCK,                                                           _______, _______, _______, _______, _______, _______
    ),
    [_NAV] = LAYOUT(
        EE_CLR,  _______, _______, _______, _______, _______,      KC_UP,     KC_RIGHT,  KC_DOWN,   KC_LEFT,   KC_P,       EE_CLR,  _______, _______, _______, _______, _______,            KC_UP,     KC_RIGHT,  KC_DOWN,   KC_LEFT,   KC_P,
        _______, _______, _______, _______, _______, _______,      KC_P,      KC_P,                                        _______, _______, KC_SFTARROW_U, _______, _______, _______,      KC_P,      KC_P,
        _______, _______, _______, LGUI(KC_TILD), _______, LT(0,KC_YAY),  KC_1,      KC_2,      KC_3,      KC_4,          KC_HOME, KC_ITRMSPCE_L, KC_UP, KC_ITRMSPCE_R, KC_END, _______,       KC_1,      KC_2,      KC_3,      KC_4,
        _______, KC_TAB_L, KC_TAB_R, KC_SPCLEFT, KC_SPCRGHT,_______,      KC_5,      KC_6,      KC_7,      KC_8,           KC_ALTARROW_L, KC_LEFT, KC_DOWN, KC_RIGHT, KC_ALTARROW_R,  _______,  KC_5,      KC_6,      KC_7,      KC_8,
        _______, _______, _______, _______, _______, _______,                                                              KC_SFTGUIARROW_L, KC_SFTALTARROW_L, KC_SFTARROW_D, KC_SFTALTARROW_R, KC_SFTGUIARROW_R, _______,
        _______, _______, _______, _______, _______, _______,                                                              _______, _______, _______, _______, _______, _______
    ),
};

#if defined(RGB_MATRIX_LEDMAPS_ENABLED)
// the indicator LEDs are mapped using the flags and for loop.
// todo: is there 'skip' logic for the ___n___ items?
// there are no macropad things here...we need the ledmap to also be 11x6? maybe
// added macropad, need to ensure indicators are not included...
const ledmap ledmaps[] = {
//     [_QWERTY]   = LEDMAP(

   [_QWERTY]   = LEDMAP(
     RED, ORANGE, YELLOW, GREEN, CYAN, BLUE,                     RED, ORANGE, YELLOW, GREEN, CYAN, BLUE,
     CYAN, ___n___, ___n___, ___n___, ___n___, ___n___,         ___n___, ___n___, ___n___, ___n___, ___n___,    CYAN,
     GOLD, ___n___, ___n___, HRM_CTL, ___n___, ___n___,         ___n___, ___n___, ___n___, ___n___, ___n___,    CYAN, 
    GREEN, ___n___, HRM_ALT, HRM_GUI, HRM_SFT, ___n___,         ___n___, HRM_SFT, HRM_GUI, HRM_ALT, ___n___, ___n___, 
    ORANGE, ___n___, ___n___, ___n___, ___n___, ___n___,        ___n___, HRM_CTL, ___n___, ___n___, ___n___,     RED,
    DEL, TOG_NAV, DEL,  ESC, SHIFT, ___n___,                    TOG_SYM, ENTER, SPACE, GREEN, CHART, CYAN,
    GREEN, GREEN, GREEN, GREEN, CYAN, CYAN, CYAN, CYAN,         PURPLE, PURPLE, PURPLE, PURPLE, RED, RED, RED, RED
    ),
   [_MOUSE]   = LEDMAP(
     RED, ___n___, ___n___, ___n___, ___n___, ___n___,                                                  RED,     ___n___, ___n___, ___n___, ___n___, ___n___,
     CYAN, ___n___, ___n___, ___n___, ___n___, ___n___,                                                 RED,  YELLOW, ___n___, ___n___,  ___n___, ___n___,
     GOLD, ___n___, ___n___, ___n___, ___n___, ___n___, ___n___, ___n___, ___n___, ___n___,             RED,   GREEN, ___n___, ___n___,  ___n___, ___n___, ___n___, ___n___, ___n___, ___n___, 
    GREEN, ___n___, ___n___, ___n___, ___n___, ___n___, ___n___, ___n___, ___n___, ___n___,             RED,    CYAN,    PINK,    CYAN,  ___n___, ___n___, ___n___, ___n___, ___n___, ___n___,
    ORANGE, ___n___, ___n___, ___n___, ___n___, ___n___,                                                GREEN,    CYAN,    PINK,    CYAN, ___n___, ___n___,
    DEL, TOG_NAV, DEL,  ESC, SHIFT, ___n___,                                                            TOG_SYM, ENTER, SPACE, GREEN, CHART, CYAN
    ),
   [_SYMBOLS]   = LEDMAP(
     RED, ___n___, ___n___, ___n___, ___n___, ___n___,                                                  RED,     ___n___, ___n___, ___n___, ___n___, ___n___,
     CYAN, ___n___, ___n___, ___n___, ___n___, ___n___,                                                 ORANGE, MAGIPLY, ___n___, ___n___, ___n___, ___n___,
     GOLD,     GOLD,   GREEN,  PURPLE,  PURPLE,   GREEN, ___n___, ___n___, ___n___, ___n___,            GREEN,    CYAN,    CYAN,    CYAN, ___n___, ___n___, ___n___, ___n___, ___n___, ___n___,
    GREEN,     CYAN,  YELLOW,  MAGENT,  MAGENT,    BLUE, ___n___, ___n___, ___n___, ___n___,            GREEN,    CYAN,    CYAN,    CYAN,    CYAN, ___n___, ___n___, ___n___, ___n___, ___n___,
    ORANGE,    GOLD,   GREEN,   PINK,     PINK,    CYAN,                                                  RED,    CYAN,    CYAN,    CYAN,    GOLD, ___n___,
    DEL, TOG_NAV, DEL,  ESC, SHIFT, ___n___,                                                            TOG_SYM, ENTER, SPACE, GREEN, CHART, CYAN
    ),
   [_NAV]   = LEDMAP(
     RED, ___n___, ___n___, ___n___, ___n___, ___n___,                                                  RED,     ___n___, ___n___, ___n___, ___n___, ___n___,
     CYAN, ___n___, ___n___, ___n___, ___n___, ___n___,                                                 ___n___, ___n___, ___n___, ___n___, ___n___, ___n___,
     GOLD, ___n___, ___n___, CYAN, ___n___, ___n___, ___n___, ___n___, ___n___, ___n___,                GREEN,    CYAN,   GREEN,    CYAN,     RED, ___n___,  ___n___, ___n___, ___n___, ___n___,
    GREEN, BLUE,  SPRING,    PINK,    CYAN, ___n___, ___n___, ___n___, ___n___, ___n___,                YELLOW,   GREEN,   GREEN,   GREEN,  YELLOW, ___n___, ___n___, ___n___, ___n___, ___n___,
    ORANGE, ___n___, ___n___, ___n___, ___n___, ___n___,                                                PURPLE,  ORANGE,  ORANGE,  ORANGE,  PURPLE, ___n___,
    DEL, TOG_NAV, DEL,  ESC, SHIFT, ___n___,                                                            TOG_SYM, ENTER, SPACE, GREEN, CHART, CYAN
    ),
    
};
#endif // RGB_MATRIX_LEDMAPS_ENABLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!(process_record_keymap(keycode, record) && true)) {
        return false;
    }
    #if defined(DRAGSCROLL_ENABLE)
        if (keycode == DRAG_SCROLL && record->event.pressed) {
            set_scrolling = !set_scrolling;
            return false;
        }
    #endif
    // now we check for specific keycodes...
    #if defined(CUSTOM_KEYCODES)
        switch (keycode) {
                case LT(0,KC_YAY):
                if (record->event.pressed) {
                    SEND_STRING("\\o/");
                    return false;
                }
                return true;
                case LT(0,KC_TILD):
                if (!record->tap.count && record->event.pressed) {
                    tap_code16(LCMD(KC_TILD)); // hold for command+letter
                    return false;
                }
                return true;
                case LT(0,KC_1):
                if (!record->tap.count && record->event.pressed) {
                    tap_code16(LCMD(KC_1)); // hold for command+letter
                    return false;
                }
                return true;
                case LT(0,KC_2):
                if (!record->tap.count && record->event.pressed) {
                    tap_code16(LCMD(KC_2)); // hold for command+letter
                    return false;
                }
                return true;
                case LT(0,KC_3):
                if (!record->tap.count && record->event.pressed) {
                    tap_code16(LCMD(KC_3)); // hold for command+letter
                    return false;
                }
                return true;
                case LT(0,KC_4):
                if (!record->tap.count && record->event.pressed) {
                    tap_code16(LCMD(KC_4)); // hold for command+letter
                    return false;
                }
                return true;
                case LT(0,KC_5):
                if (!record->tap.count && record->event.pressed) {
                    tap_code16(LCMD(KC_5)); // hold for command+letter
                    return false;
                }
                return true;
                case LT(0,KC_6):
                if (!record->tap.count && record->event.pressed) {
                    tap_code16(LCMD(KC_6)); // hold for command+letter
                    return false;
                }
                return true;
                case LT(0,KC_7):
                if (!record->tap.count && record->event.pressed) {
                    tap_code16(LCMD(KC_7)); // hold for command+letter
                    return false;
                }
                return true;
                case LT(0,KC_8):
                if (!record->tap.count && record->event.pressed) {
                    tap_code16(LCMD(KC_8)); // hold for command+letter
                    return false;
                }
                return true;
                case LT(0,KC_9):
                if (!record->tap.count && record->event.pressed) {
                    tap_code16(LCMD(KC_9)); // hold for command+letter
                    return false;
                }
                return true;
                case LT(0,KC_Z):
                if (!record->tap.count && record->event.pressed) {
                    tap_code16(LCMD(KC_Z)); // hold for command+letter
                    return false;
                }
                return true;
                case LT(0,KC_X):
                if (!record->tap.count && record->event.pressed) {
                    tap_code16(LCMD(KC_X)); // hold for command+letter
                    return false;
                }
                return true;
                case LT(0,KC_C):
                if (!record->tap.count && record->event.pressed) {
                    tap_code16(LCMD(KC_C)); // hold for command+letter
                    return false;
                }
                return true;
                case LT(0,KC_V):
                if (!record->tap.count && record->event.pressed) {
                    tap_code16(LCMD(KC_V)); // hold for command+letter
                    return false;
                }
                return true;
                case LT(0,KC_B):
                if (!record->tap.count && record->event.pressed) {
                    tap_code16(LCMD(KC_B)); // hold for command+letter
                    return false;
                }
                return true;
                case LT(0,KC_A):
                if (!record->tap.count && record->event.pressed) {
                    tap_code16(LCMD(KC_A)); // hold for command+letter
                    return false;
                }
                return true;
                case LT(0,KC_R):
                if (!record->tap.count && record->event.pressed) {
                    tap_code16(LCMD(KC_R)); // hold for command+letter
                    return false;
                }
                return true;
                case LT(0,KC_W):
                if (!record->tap.count && record->event.pressed) {
                    tap_code16(LCMD(KC_W)); // hold for command+letter
                    return false;
                }
                return true;
                case LT(0,KC_T):
                if (!record->tap.count && record->event.pressed) {
                    tap_code16(LCMD(KC_T)); // hold for command+letter
                    return false;
                }
                return true;
                case LT(0,KC_N):
                if (!record->tap.count && record->event.pressed) {
                    tap_code16(LCMD(LSFT(KC_N))); // hold for command+letter
                    return false;
                }
                return true;
                case LT(0,KC_I):
                if (!record->tap.count && record->event.pressed) {
                    tap_code16(LCMD(KC_I)); // hold for command+letter
                    return false;
                }
                return true;
                case LT(0,KC_MPLY):
                if (!record->tap.count && record->event.pressed) {
                    tap_code16(KC_MNXT); // hold for command+letter
                    return false;
                }
                return true;
    }
    #endif // end CUSTOM_KEYCODES (for troubleshooting)
    return true;
}
