// Copyright 2021 Mikael Manukyan <arm.localhost@gmail.com>
// Copyright 2023 Chris Trotter (@christrotter)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "rgb_ledmaps.h"
#include "arcboard_mk19_fx.h"

bool process_record_user_rgb_matrix(uint16_t keycode, keyrecord_t *record) { return true; }

void set_rgb_ledmap(uint16_t first_led, uint16_t last_led, int val, int layer) {
    const ledmap *l = &(ledmaps[layer]);
    for (int i = first_led; i <= last_led; i++) {
        // RGB_TOT_IND_L is 'how many right indicator leds between left and right key ranges, in the context of the led-flag section of g_led_config'
        // cuz, ledmaps doesn't think there are any indicator leds, it believes you only have l.key-range + r.key-range = total addressable leds
        if (!(is_keyboard_left())) {
            i = i - RGB_TOT_IND_L;
        }
        HSV hsv = {
            .h = (*l)[i][0],
            .s = (*l)[i][1],
            .v = val,
        };
        if (!(is_keyboard_left())) {
            i = i + RGB_TOT_IND_L;
        } // revert i to fit the 'in reality' led sequence
        if (hsv.h || hsv.s) {
            RGB rgb = hsv_to_rgb(hsv);
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    }
}

// set_rgb_range(RGB_FAL1_MIN, RGB_FAL1_MAX, FAL1_L0);
void set_rgb_range(uint16_t first_led, uint16_t last_led, int hue, int sat, int val) {
    for (int i = first_led; i <= last_led; i++) {
        HSV hsv = {
            .h = hue,
            .s = sat,
            .v = 75,
        };
        if (hsv.h || hsv.s) {
            RGB rgb = hsv_to_rgb(hsv);
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    }
}

bool rgb_matrix_indicators_user() {
    if (is_keyboard_left()) {
        // set LEFT per-key leds by ledmap
        set_rgb_range(0, 41, HSV_CYAN);
    } else {
        // set RIGHT per-key leds by ledmap
        set_rgb_range(0, 41, HSV_CYAN);
    }
    return true; // rgb_matrix_indicators_keymap(led_min, led_max);
}
