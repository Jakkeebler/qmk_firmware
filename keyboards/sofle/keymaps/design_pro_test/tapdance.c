
enum sofle_layers {
    _QWERTY,
    _ILSTR,
    _LFTHND,
    _FUNCPAD,
};

#include "tapdance.h"

#include QMK_KEYBOARD_H

// Tap Dance Declaration
enum {
    DANCE_ESC,
    DANCE_MINS,
    DANCE_EQL,
    DANCE_LBRC,
    DANCE_RBRC,
    DANCE_0,
    DANCE_1,
    DANCE_2,
    DANCE_3,
    DANCE_5,
    DANCE_7,
    DANCE_8,
    DANCE_A,
    DANCE_B,
    DANCE_C,
    DANCE_D,
    DANCE_E,
    DANCE_F,
    DANCE_G,
    DANCE_H,
    DANCE_I,
    DANCE_J,
    DANCE_K,
    DANCE_L,
    DANCE_N,
    DANCE_O,
    DANCE_P,
    DANCE_Q,
    DANCE_R,
    DANCE_S,
    DANCE_T,
    DANCE_V,
    DANCE_W,
    DANCE_X,
    DANCE_Y,
    DANCE_Z,
    TAP_DANCE_COUNT
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP,
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD,
    TD_MORE_TAPS
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

static td_state_t dance_state[TAP_DANCE_COUNT];

td_state_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    } else if (state->count == 3) {
        if (state->pressed) return TD_TRIPLE_HOLD;
        else return TD_TRIPLE_TAP;
    }
    return TD_MORE_TAPS;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Dance Functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Dance Escape
void on_dance_ESC(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_ESC_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_ESC] = dance_step(state);
    switch (dance_state[DANCE_ESC]) {
        case TD_SINGLE_TAP: register_code16(KC_ESC); break;
        case TD_SINGLE_HOLD:
            layer_on(_LFTHND);
            break;
        case TD_DOUBLE_TAP:
            layer_off(_ILSTR);
            layer_on(_QWERTY);
            break;
        default: break;
    }
}

void dance_ESC_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_ESC]) {
        case TD_SINGLE_TAP: unregister_code16(KC_ESC); break;
        case TD_SINGLE_HOLD:
            layer_off(_LFTHND);
            break;
        default: break;
    }
    dance_state[DANCE_ESC] = 0;
}

// Dance Minus
void on_dance_MINS(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_MINS_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_MINS] = dance_step(state);
    switch (dance_state[DANCE_MINS]) {
        case TD_SINGLE_TAP: register_code16(KC_MINS); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_MINS);
            break;
        default: break;
    }
}

void dance_MINS_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_MINS]) {
        case TD_SINGLE_TAP: unregister_code16(KC_MINS); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_MINS);
            unregister_code(KC_LCTL);
            break;
        default: break;
    }
    dance_state[DANCE_MINS] = 0;
}


// Dance Equals
void on_dance_EQL(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_EQL_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_EQL] = dance_step(state);
    switch (dance_state[DANCE_EQL]) {
        case TD_SINGLE_TAP: register_code16(KC_EQL); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_EQL);
            break;
        default: break;
    }
}

void dance_EQL_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_EQL]) {
        case TD_SINGLE_TAP: unregister_code16(KC_EQL); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_EQL);
            unregister_code(KC_LCTL);
            break;
        default: break;
    }
    dance_state[DANCE_EQL] = 0;
}

// Dance Left Bracket
void on_dance_LBRC(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_LBRC_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_LBRC] = dance_step(state);
    switch (dance_state[DANCE_LBRC]) {
        case TD_SINGLE_TAP: register_code16(KC_LBRC); break;
        case TD_SINGLE_HOLD:
            register_code(KC_LCTL);
            register_code(KC_LSFT);
            register_code(KC_LBRC);
            break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_LBRC);
            break;
        default: break;
    }
}

void dance_LBRC_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_LBRC]) {
        case TD_SINGLE_TAP: unregister_code16(KC_LBRC); break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LBRC);
            unregister_code(KC_LSFT);
            unregister_code(KC_LCTL);
            break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_LBRC);
            unregister_code(KC_LCTL);
            break;
        default: break;
    }
    dance_state[DANCE_LBRC] = 0;
}

// Dance Right Bracket
void on_dance_RBRC(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_RBRC_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_RBRC] = dance_step(state);
    switch (dance_state[DANCE_RBRC]) {
        case TD_SINGLE_TAP: register_code16(KC_RBRC); break;
        case TD_SINGLE_HOLD:
            register_code(KC_LCTL);
            register_code(KC_LSFT);
            register_code(KC_RBRC);
            break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_RBRC);
            break;
        default: break;
    }
}

void dance_RBRC_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_RBRC]) {
        case TD_SINGLE_TAP: unregister_code16(KC_RBRC); break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LCTL);
            unregister_code(KC_LSFT);
            unregister_code(KC_RBRC);
            break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_LCTL);
            unregister_code(KC_RBRC);
            break;
        default: break;
    }
    dance_state[DANCE_RBRC] = 0;
}

// Dance 0
void on_dance_0(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_0] = dance_step(state);
    switch (dance_state[DANCE_0]) {
        case TD_SINGLE_TAP: register_code16(KC_0); break;
        case TD_SINGLE_HOLD:
            register_code(KC_LCTL);
            register_code(KC_LALT);
            register_code(KC_0);
            break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_0);
            break;
        default: break;
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_0]) {
        case TD_SINGLE_TAP: unregister_code16(KC_0); break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LCTL);
            unregister_code(KC_LALT);
            unregister_code(KC_0);
            break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_0);
            unregister_code(KC_LCTL);
            break;
        default: break;
    }
    dance_state[DANCE_0] = 0;
}

// Dance 1
void on_dance_1(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_1] = dance_step(state);
    switch (dance_state[DANCE_1]) {
        case TD_SINGLE_TAP: register_code16(KC_1); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_1);
        default: break;
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_1]) {
        case TD_SINGLE_TAP: unregister_code16(KC_1); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_1);
            unregister_code(KC_LCTL);
        default: break;
    }
    dance_state[DANCE_1] = 0;
}

// Dance 2
void on_dance_2(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_2] = dance_step(state);
    switch (dance_state[DANCE_2]) {
        case TD_SINGLE_TAP: register_code16(KC_2); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_2);
            break;
        case TD_DOUBLE_HOLD:
            register_code(KC_LCTL);
            register_code(KC_LALT);
            register_code(KC_2);
            break;
        default: break;
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_2]) {
        case TD_SINGLE_TAP: unregister_code16(KC_2); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_2);
            unregister_code(KC_LCTL);
            break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_LCTL);
            unregister_code(KC_LALT);
            unregister_code(KC_2);
            break;
        default: break;
    }
    dance_state[DANCE_2] = 0;
}

// Dance 3
void on_dance_3(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_3_finished(tap_dance_state_t *state, void *user_data) {

    dance_state[DANCE_3] = dance_step(state);
    switch (dance_state[DANCE_3]) {
        case TD_SINGLE_TAP: register_code16(KC_3); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_3);
            break;
        case TD_DOUBLE_HOLD:
            register_code(KC_LCTL);
            register_code(KC_LALT);
            register_code(KC_3);
            break;
        default: break;
    }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_3]) {
        case TD_SINGLE_TAP: unregister_code16(KC_3); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_3);
            unregister_code(KC_LCTL);
            break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_3);
            unregister_code(KC_LALT);
            unregister_code(KC_LCTL);
            break;
        default: break;
    }
    dance_state[DANCE_3] = 0;
}

// Dance 5
void on_dance_5(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_5_finished(tap_dance_state_t *state, void *user_data) {

    dance_state[DANCE_5] = dance_step(state);
    switch (dance_state[DANCE_5]) {
        case TD_SINGLE_TAP: register_code16(KC_5); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_5);
            break;
        case TD_TRIPLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_LALT);
            register_code(KC_5);
            break;
        default: break;
    }
}

void dance_5_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_5]) {
        case TD_SINGLE_TAP: unregister_code16(KC_5); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_5);
            unregister_code(KC_LCTL);
            break;
        case TD_TRIPLE_TAP:
            unregister_code(KC_5);
            unregister_code(KC_LALT);
            unregister_code(KC_LCTL);
            break;
        default: break;
    }
    dance_state[DANCE_5] = 0;
}

// Dance 7
void on_dance_7(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_7_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_7] = dance_step(state);
    switch (dance_state[DANCE_7]) {
        case TD_SINGLE_TAP: register_code16(KC_7); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_7);
            break;
        case TD_DOUBLE_HOLD:
            register_code(KC_LCTL);
            register_code(KC_LALT);
            register_code(KC_LSFT);
            register_code(KC_7);
            break;
        default: break;
    }
}

void dance_7_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_7]) {
        case TD_SINGLE_TAP: unregister_code16(KC_7); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_7);
            unregister_code(KC_LCTL);
            break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_7);
            unregister_code(KC_LSFT);
            unregister_code(KC_LALT);
            unregister_code(KC_LCTL);
            break;
        default: break;
    }
    dance_state[DANCE_7] = 0;
}

// Dance 8
void on_dance_8(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_8_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_8] = dance_step(state);
    switch (dance_state[DANCE_8]) {
        case TD_SINGLE_TAP: register_code16(KC_8); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_8);
            break;
        case TD_DOUBLE_HOLD:
            register_code(KC_LCTL);
            register_code(KC_LALT);
            register_code(KC_LSFT);
            register_code(KC_8);
            break;
        default: break;
    }
}

void dance_8_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_8]) {
        case TD_SINGLE_TAP: unregister_code16(KC_8); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_8);
            unregister_code(KC_LCTL);
            break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_8);
            unregister_code(KC_LSFT);
            unregister_code(KC_LALT);
            unregister_code(KC_LCTL);
            break;
        default: break;
    }
    dance_state[DANCE_8] = 0;
}

// Dance A
void on_dance_A(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_A_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_A] = dance_step(state);
    switch (dance_state[DANCE_A]) {
        case TD_SINGLE_TAP: register_code16(KC_A); break;
        case TD_SINGLE_HOLD: register_code16(KC_LGUI); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_A);
            break;
        default: break;
    }
}

void dance_A_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_A]) {
        case TD_SINGLE_TAP: unregister_code16(KC_A); break;
        case TD_SINGLE_HOLD: unregister_code16(KC_LGUI); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_A);
            unregister_code(KC_LCTL);
            break;
        default: break;
    }
    dance_state[DANCE_A] = 0;
}

// Dance B
void on_dance_B(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_B_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_B] = dance_step(state);
    switch (dance_state[DANCE_B]) {
        case TD_SINGLE_TAP: register_code16(KC_B); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_B);
            break;
        default: break;
    }
}

void dance_B_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_B]) {
        case TD_SINGLE_TAP: unregister_code16(KC_B); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_B);
            unregister_code(KC_LCTL);
            break;
        default: break;
    }
    dance_state[DANCE_B] = 0;
}

// Dance C
void on_dance_C(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_C_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_C] = dance_step(state);
    switch (dance_state[DANCE_C]) {
        case TD_SINGLE_TAP: register_code16(KC_C); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_C);
            break;
        default: break;
    }
}

void dance_C_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_C]) {
        case TD_SINGLE_TAP: unregister_code16(KC_C); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_C);
            unregister_code(KC_LCTL);
            break;
        default: break;
    }
    dance_state[DANCE_C] = 0;
}

// Dance D
void on_dance_D(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_D_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_D] = dance_step(state);
    switch (dance_state[DANCE_D]) {
        case TD_SINGLE_TAP: register_code16(KC_D); break;
        case TD_SINGLE_HOLD: register_code16(KC_LALT); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_D);
            break;
        default: break;
    }
}

void dance_D_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_D]) {
        case TD_SINGLE_TAP: unregister_code16(KC_D); break;
        case TD_SINGLE_HOLD: unregister_code16(KC_LALT); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_D);
            unregister_code(KC_LCTL);
            break;
        default: break;
    }
    dance_state[DANCE_D] = 0;
}

// Dance E
void on_dance_E(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_E_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_E] = dance_step(state);
    switch (dance_state[DANCE_E]) {
        case TD_SINGLE_TAP: register_code16(KC_E); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_E);
            break;
        default: break;
    }
}

void dance_E_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_E]) {
        case TD_SINGLE_TAP: unregister_code16(KC_E); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_E);
            unregister_code(KC_LCTL);
            break;
        default: break;
    }
    dance_state[DANCE_E] = 0;
}

// Dance F
void on_dance_F(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_F_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_F] = dance_step(state);
    switch (dance_state[DANCE_F]) {
        case TD_SINGLE_TAP: register_code16(KC_F); break;
        case TD_SINGLE_HOLD: register_code16(KC_LCTL); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_F);
            break;
        default: break;
    }
}

void dance_F_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_F]) {
        case TD_SINGLE_TAP: unregister_code16(KC_F); break;
        case TD_SINGLE_HOLD: unregister_code16(KC_LCTL); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_F);
            unregister_code(KC_LCTL);
            break;
        default: break;
    }
    dance_state[DANCE_F] = 0;
}

// Dance G
void on_dance_G(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_G_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_G] = dance_step(state);
    switch (dance_state[DANCE_G]) {
        case TD_SINGLE_TAP: register_code16(KC_G); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_G);
            break;
        case TD_DOUBLE_HOLD:
            register_code(KC_LCTL);
            register_code(KC_LSFT);
            register_code(KC_G);
            break;
        default: break;
    }
}

void dance_G_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_G]) {
        case TD_SINGLE_TAP: unregister_code16(KC_G); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_G);
            unregister_code(KC_LCTL);
            break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_G);
            unregister_code(KC_LSFT);
            unregister_code(KC_LCTL);
            break;
        default: break;
    }
    dance_state[DANCE_G] = 0;
}

// Dance H
void on_dance_H(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_H_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_H] = dance_step(state);
    switch (dance_state[DANCE_H]) {
        case TD_SINGLE_TAP: register_code16(KC_H); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_H);
            break;
        default: break;
    }
}

void dance_H_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_H]) {
        case TD_SINGLE_TAP: unregister_code16(KC_H); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_LCTL);
            unregister_code(KC_H);
            break;
        default: break;
    }
    dance_state[DANCE_H] = 0;
}

// Dance I
void on_dance_I(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_I_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_I] = dance_step(state);
    switch (dance_state[DANCE_I]) {
        case TD_SINGLE_TAP: register_code16(KC_I); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_I);
            break;
        case TD_DOUBLE_HOLD:
            layer_on(_ILSTR);
            break;
        case TD_TRIPLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_LSFT);
            register_code(KC_I);
            break;
        default: break;
    }
}

void dance_I_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_I]) {
        case TD_SINGLE_TAP: unregister_code16(KC_I); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_I);
            unregister_code(KC_LCTL);
            break;
        case TD_TRIPLE_TAP:
            unregister_code(KC_I);
            unregister_code(KC_LSFT);
            unregister_code(KC_LCTL);
            break;
        default: break;
    }
    dance_state[DANCE_I] = 0;
}

// Dance J
void on_dance_J(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_J_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_J] = dance_step(state);
    switch (dance_state[DANCE_J]) {
        case TD_SINGLE_TAP: register_code16(KC_J); break;
        case TD_SINGLE_HOLD: register_code16(KC_RCTL); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_J);
            break;
        default: break;
    }
}

void dance_J_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_J]) {
        case TD_SINGLE_TAP: unregister_code16(KC_J); break;
        case TD_SINGLE_HOLD: unregister_code16(KC_RCTL); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_LCTL);
            unregister_code(KC_J);
            break;
        default: break;
    }
    dance_state[DANCE_J] = 0;
}

// Dance K
void on_dance_K(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_K_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_K] = dance_step(state);
    switch (dance_state[DANCE_K]) {
        case TD_SINGLE_TAP: register_code16(KC_K); break;
        case TD_SINGLE_HOLD: register_code16(KC_RALT); break;
        default: break;
    }
}

void dance_K_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_K]) {
        case TD_SINGLE_TAP: unregister_code16(KC_K); break;
        case TD_SINGLE_HOLD: unregister_code16(KC_RALT); break;
        default: break;
    }
    dance_state[DANCE_K] = 0;
}

// Dance L
void on_dance_L(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_L_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_L] = dance_step(state);
    switch (dance_state[DANCE_L]) {
        case TD_SINGLE_TAP: register_code16(KC_L); break;
        case TD_SINGLE_HOLD: register_code16(KC_RGUI); break;
        default: break;
    }
}

void dance_L_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_L]) {
        case TD_SINGLE_TAP: unregister_code16(KC_L); break;
        case TD_SINGLE_HOLD: unregister_code16(KC_RGUI); break;
        default: break;
    }
    dance_state[DANCE_L] = 0;
}

// Dance N
void on_dance_N(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_N_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_N] = dance_step(state);
    switch (dance_state[DANCE_N]) {
        case TD_SINGLE_TAP: register_code16(KC_N); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_N);
            break;
        case TD_TRIPLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_LSFT);
            register_code(KC_N);
            break;
        default: break;
    }
}

void dance_N_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_N]) {
        case TD_SINGLE_TAP: unregister_code16(KC_N); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_N);
            unregister_code(KC_LCTL);
            break;
        case TD_TRIPLE_TAP:
            unregister_code(KC_N);
            unregister_code(KC_LSFT);
            unregister_code(KC_LCTL);
            break;
        default: break;
    }
    dance_state[DANCE_N] = 0;
}

// Dance O
void on_dance_O(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_O_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_O] = dance_step(state);
    switch (dance_state[DANCE_O]) {
        case TD_SINGLE_TAP: register_code16(KC_O); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_O);
            break;
        case TD_TRIPLE_TAP:
            register_code(KC_LSFT);
            register_code(KC_O);
            break;
        default: break;
    }
}

void dance_O_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_O]) {
        case TD_SINGLE_TAP: unregister_code16(KC_O); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_O);
            unregister_code(KC_LCTL);
            break;
        case TD_TRIPLE_TAP:
            unregister_code(KC_O);
            unregister_code(KC_LSFT);
            break;
        default: break;
    }
    dance_state[DANCE_O] = 0;
}

// Dance P
void on_dance_P(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_P_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_P] = dance_step(state);
    switch (dance_state[DANCE_P]) {
        case TD_SINGLE_TAP: register_code16(KC_P); break;
        default: break;
    }
}

void dance_P_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_P]) {
        case TD_SINGLE_TAP: unregister_code16(KC_P); break;
        default: break;
    }
    dance_state[DANCE_P] = 0;
}

// Dance Q
void on_dance_Q(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_Q_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_Q] = dance_step(state);
    switch (dance_state[DANCE_Q]) {
        case TD_SINGLE_TAP: register_code16(KC_Q); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_Q);
            break;
        default: break;
    }
}

void dance_Q_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_Q]) {
        case TD_SINGLE_TAP: unregister_code16(KC_Q); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_Q);
            unregister_code(KC_LCTL);
            break;
        default: break;
    }
    dance_state[DANCE_Q] = 0;
}

// Dance R
void on_dance_R(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_R_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_R] = dance_step(state);
    switch (dance_state[DANCE_R]) {
        case TD_SINGLE_TAP: register_code16(KC_R); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_R);
        default: break;
    }
}

void dance_R_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_R]) {
        case TD_SINGLE_TAP: unregister_code16(KC_R); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_R);
            unregister_code(KC_LCTL);
        default: break;
    }
    dance_state[DANCE_R] = 0;
}

// Dance S
void on_dance_S(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_S_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_S] = dance_step(state);
    switch (dance_state[DANCE_S]) {
        case TD_SINGLE_TAP: register_code16(KC_S); break;
        case TD_SINGLE_HOLD: register_code16(KC_LSFT); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_S);
            break;
        case TD_DOUBLE_HOLD:
            register_code(KC_LCTL);
            register_code(KC_LALT);
            register_code(KC_S);
            break;
        case TD_TRIPLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_LSFT);
            register_code(KC_S);
            break;
        default: break;
    }
}

void dance_S_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_S]) {
        case TD_SINGLE_TAP: unregister_code16(KC_S); break;
        case TD_SINGLE_HOLD: unregister_code16(KC_LSFT); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_S);
            unregister_code(KC_LCTL);
            break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_S);
            unregister_code(KC_LALT);
            unregister_code(KC_LCTL);
            break;
        case TD_TRIPLE_TAP:
            unregister_code(KC_S);
            unregister_code(KC_LSFT);
            unregister_code(KC_LCTL);
            break;
        default: break;
    }
    dance_state[DANCE_S] = 0;
}

// Dance T
void on_dance_T(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_T_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_T] = dance_step(state);
    switch (dance_state[DANCE_T]) {
        case TD_SINGLE_TAP: register_code16(KC_T); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_T);
        default: break;
    }
}

void dance_T_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_T]) {
        case TD_SINGLE_TAP: unregister_code16(KC_T); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_T);
            unregister_code(KC_LCTL);
        default: break;
    }
    dance_state[DANCE_T] = 0;
}

// Dance V
void on_dance_V(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_V_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_V] = dance_step(state);
    switch (dance_state[DANCE_V]) {
        case TD_SINGLE_TAP: register_code16(KC_V); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_V);
            break;
        case TD_DOUBLE_HOLD:
            register_code(KC_LCTL);
            register_code(KC_LSFT);
            register_code(KC_V);
            break;
        case TD_TRIPLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_LALT);
            register_code(KC_LSFT);
            register_code(KC_V);
            break;
        default: break;
    }
}

void dance_V_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_V]) {
        case TD_SINGLE_TAP: unregister_code16(KC_V); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_V);
            unregister_code(KC_LCTL);
            break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_V);
            unregister_code(KC_LSFT);
            unregister_code(KC_LCTL);
            break;
        case TD_TRIPLE_TAP:
            unregister_code(KC_V);
            unregister_code(KC_LSFT);
            unregister_code(KC_LALT);
            unregister_code(KC_LCTL);
            break;
        default: break;
    }
    dance_state[DANCE_V] = 0;
}

// Dance W
void on_dance_W(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_W_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_W] = dance_step(state);
    switch (dance_state[DANCE_W]) {
        case TD_SINGLE_TAP: register_code16(KC_W); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_W);
            break;
        default: break;
    }
}

void dance_W_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_W]) {
        case TD_SINGLE_TAP: unregister_code16(KC_W); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_W);
            unregister_code(KC_LCTL);
            break;
        default: break;
    }
    dance_state[DANCE_W] = 0;
}

// Dance X
void on_dance_X(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_X_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_X] = dance_step(state);
    switch (dance_state[DANCE_X]) {
        case TD_SINGLE_TAP: register_code16(KC_X); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_X);
            break;
        case TD_TRIPLE_TAP:
            register_code(KC_LSFT);
            register_code(KC_X);
        default: break;
    }
}

void dance_X_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_X]) {
        case TD_SINGLE_TAP: unregister_code16(KC_X); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_X);
            unregister_code(KC_LCTL);
            break;
        case TD_TRIPLE_TAP:
            unregister_code(KC_X);
            unregister_code(KC_LSFT);
        default: break;
    }
    dance_state[DANCE_X] = 0;
}

// Dance Y
void on_dance_Y(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_Y_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_Y] = dance_step(state);
    switch (dance_state[DANCE_Y]) {
        case TD_SINGLE_TAP: register_code16(KC_Y); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_Y);
        case TD_TRIPLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_LALT);
            register_code(KC_LSFT);
            register_code(KC_Y);
            break;
        default: break;
    }
}

void dance_Y_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_Y]) {
        case TD_SINGLE_TAP: unregister_code16(KC_Y); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_Y);
            unregister_code(KC_LCTL);
        case TD_TRIPLE_TAP:
            unregister_code(KC_Y);
            unregister_code(KC_LSFT);
            unregister_code(KC_LALT);
            unregister_code(KC_LCTL);
            break;
        default: break;
    }
    dance_state[DANCE_Y] = 0;
}

// Dance Z
void on_dance_Z(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_Z_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_Z] = dance_step(state);
    switch (dance_state[DANCE_Z]) {
        case TD_SINGLE_TAP: register_code16(KC_Z); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_Z);
            break;
        case TD_DOUBLE_HOLD:
            register_code(KC_LCTL);
            register_code(KC_LSFT);
            register_code(KC_Z);
            break;
        default: break;
    }
}

void dance_Z_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_Z]) {
        case TD_SINGLE_TAP: unregister_code16(KC_Z); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_Z);
            unregister_code(KC_LCTL);
            break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_Z);
            unregister_code(KC_LSFT);
            unregister_code(KC_LCTL);
            break;
        default: break;
    }
    dance_state[DANCE_Z] = 0;
}
