// Copyright 2023 christrotter (@christrotter)
// SPDX-License-Identifier: GPL-2.0-or-later

// Copyright 2023 Chris Trotter (@christrotter)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"
#include "arcpedals_mk2.h"
#include "keymap.h"

#if defined(RGB_MATRIX_LEDMAPS_ENABLED)
    #include "rgb_ledmaps.h"
#endif

#if defined(POINTING_DEVICE_ENABLE)
    #include "pointing.c"
#endif

#if defined(CONSOLE_ENABLE)
    #include "print.h"
    void keyboard_post_init_user(void) {
        // Customise these values to desired behaviour
        debug_enable=true;
        // debug_matrix=true;
        // debug_keyboard=true;
        // debug_mouse=true;
    }
#endif

#if defined(TAP_DANCE_ENABLE)
// Tap Dance definitions
enum {
    TD_SHIFT
};
tap_dance_action_t tap_dance_actions[] = {
    // we want to tap for oneshot, double tap to hold on, double tap to hold off
    // so tap= oneshot shift, doubletap= toggle shift on
    [TD_SHIFT] = ACTION_TAP_DANCE_DOUBLE(OSM(MOD_LSFT), KC_CAPS),
};
#endif

enum keycodes {
  KC_CYCLE_LAYERS = QK_USER,
};
// 1st layer on the cycle
#define LAYER_CYCLE_START 0
// Last layer on the cycle
#define LAYER_CYCLE_END   3

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }
__attribute__((weak)) void post_process_record_keymap(uint16_t keycode, keyrecord_t *record) {}
void                       post_process_record_user(uint16_t keycode, keyrecord_t *record) { post_process_record_keymap(keycode, record); }

// clang-format off
/*
    left                                      right
    side-left, toe, ball, side-right          side-right, toe, ball, side-left
    n/a, n/a, n/a, n/a                        falcon-button
*/
// clang-format on
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_SCROLL] = LAYOUT(
    // physical layout is:
    // left, toe, ball, right  -  right, toe, ball, left (wat)
    LGUI(KC_MS_BTN3), KC_MS_WH_UP, KC_N, KC_MS_WH_LEFT,         KC_MS_BTN3, KC_MS_WH_DOWN, KC_CHRMCYC, KC_MS_WH_RIGHT
    // KC_A, KC_B, KC_C, KC_D,     KC_RIGHT, KC_UP, KC_DOWN, KC_LEFT
),
[_MOUSE] = LAYOUT(
    KC_A, KC_B, KC_C, KC_D,     KC_MS_BTN1, KC_MS_BTN3, KC_N, KC_MS_BTN2
),
[_FUSION] = LAYOUT(
    KC_A, KC_B, KC_C, KC_D,     LGUI(KC_MS_BTN3), KC_MS_BTN3, KC_S, KC_MS_BTN2
),
[_MGMT] = LAYOUT(
    KC_A, KC_B, KC_C, KC_D,     KC_N, EE_CLR, QK_BOOT, KC_N
)
};

#if defined(RGB_MATRIX_LEDMAPS_ENABLED)
// the indicator LEDs are mapped using the flags and for loop.
// Right thumb: KC_MULTILNE, OSM(MOD_LSFT), MO(_SYMBOLS), KC_ENTER, KC_SPACE, MAGIPLAY,
const ledmap ledmaps[] = {
    [_SCROLL]   = LEDMAP(
      PURPLE, RED, WHITE, ORANGE, BG, BG, BG, BG,                   SPRING, GREEN, CYAN, PINK, BG, BG, BG, BG
   ),
   [_MOUSE]     = LEDMAP(
      WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,       RED, PINK, WHITE, PURPLE, CYAN, CYAN, CYAN, CYAN
   ),
    [_FUSION]   = LEDMAP(
      WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,       ORANGE, PINK, CYAN, PURPLE, CYAN, CYAN, CYAN, CYAN
   ),
   [_MGMT]     = LEDMAP(
      WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,       WHITE, RED, RED, WHITE, CYAN, CYAN, CYAN, CYAN
   )
};
#endif // RGB_MATRIX_LEDMAPS_ENABLED


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!(process_record_keymap(keycode, record)
        #if defined(RGB_MATRIX_LEDMAPS_ENABLED)
            && process_record_user_rgb_matrix(keycode, record)
        #endif
        #if defined(CUSTOM_POINTING_DEVICE)
            && process_record_pointing(keycode, record)
        #endif
          && true)) {
        return false;
    }

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
                return true;             // Return true for normal processing of tap keycode
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
                // a bunch of these are commented out cuz homerow mods in play
//                case LT(0,KC_S):
//                if (!record->tap.count && record->event.pressed) {
//                    tap_code16(LCMD(KC_S)); // hold for command+letter
//                    return false;
//                }
//                return true;             // Return true for normal processing of tap keycode
                case LT(0,KC_Z):
                if (!record->tap.count && record->event.pressed) {
                    tap_code16(LCMD(KC_Z)); // hold for command+letter
                    return false;
                }
                return true;             // Return true for normal processing of tap keycode
                case LT(0,KC_X):
                if (!record->tap.count && record->event.pressed) {
                    tap_code16(LCMD(KC_X)); // hold for command+letter
                    return false;
                }
                return true;             // Return true for normal processing of tap keycode
                case LT(0,KC_C):
                if (!record->tap.count && record->event.pressed) {
                    tap_code16(LCMD(KC_C)); // hold for command+letter
                    return false;
                }
                return true;             // Return true for normal processing of tap keycode
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
//                case LT(0,KC_K):
//                if (!record->tap.count && record->event.pressed) {
//                    tap_code16(LCMD(KC_K)); // hold for command+letter
//                    return false;
//                }
//                return true;
//                case LT(0,KC_L):
//                if (!record->tap.count && record->event.pressed) {
//                    tap_code16(LCMD(KC_L)); // hold for command+letter
//                    return false;
//                }
//                return true;
                case LT(0,KC_T):
                if (!record->tap.count && record->event.pressed) {
                    tap_code16(LCMD(KC_T)); // hold for command+letter
                    return false;
                }
                return true;
//                case LT(0,KC_F):
//                if (!record->tap.count && record->event.pressed) {
//                    tap_code16(LCMD(KC_F)); // hold for command+letter
//                    return false;
//                }
//                return true;
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
                case KC_CYCLE_LAYERS:
                  // Our logic will happen on presses, nothing is done on releases
                  if (!record->event.pressed) {
                    // We've already handled the keycode (doing nothing), let QMK know so no further code is run unnecessarily
                    return false;
                  }

                  uint8_t current_layer = get_highest_layer(layer_state);

                  // Check if we are within the range, if not quit
                  if (current_layer > LAYER_CYCLE_END || current_layer < LAYER_CYCLE_START) {
                    return false;
                  }

                  uint8_t next_layer = current_layer + 1;
                  if (next_layer > LAYER_CYCLE_END) {
                      next_layer = LAYER_CYCLE_START;
                  }
                  layer_move(next_layer);
                  return false;
    }
    #endif // end CUSTOM_KEYCODES (for troubleshooting)
    return true;
}
