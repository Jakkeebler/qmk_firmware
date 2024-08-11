#include QMK_KEYBOARD_H

// Custom Keycodes Declaration
enum custom_keycodes {
    KC_LAYER = SAFE_RANGE,
    KC_ARTBRD,
    KC_FUNC,
};

// Custom Keycode Functions
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LAYER:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                register_code(KC_LBRC);
            } else {
                unregister_code(KC_LBRC);
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
            }
            return false;
        case KC_ARTBRD:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_0);
            } else {
                unregister_code(KC_0);
                unregister_code(KC_LCTL);
            }
            return false;
        case KC_FUNC:
            if (record->event.pressed) {
                layer_on(_FUNCPAD);
            } else {
                layer_off(_FUNCPAD);
            }
            return false;
    }
    return true;
}
