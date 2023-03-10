#include "reductist.h"

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case 0:
            if (clockwise) {
                register_code(KC_LCTL);
                tap_code(KC_LEFT);
                unregister_code(KC_LCTL);
            } else {
                register_code(KC_LCTL);
                tap_code(KC_RIGHT);
                unregister_code(KC_LCTL);
            }
            break;
        case 1:
            if (clockwise) {
                tap_code(KC_PGUP);
            } else {
                tap_code(KC_PGDN);
            }
            break;
        case 2:
            if (clockwise) {
                tap_code(KC_VOLD);
            } else {
                tap_code(KC_VOLU);
            }
            break;
    }
    return false;
}

#endif
