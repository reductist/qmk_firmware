#include "reductist.h"

__attribute__((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

__attribute__((weak))
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) { return true; }

#ifdef OLED_ENABLE
__attribute__((weak))
bool process_record_oled(uint16_t keycode, keyrecord_t *record) { return true; }
#endif

bool mouse_jiggle_active = false;
uint16_t mouse_timer = false;
uint16_t mouse_interval = 1000; // (1000ms == 1s)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // user macros here
    switch (keycode) {
    case JIGGL:
        if (record->event.pressed) {
            mouse_jiggle_active = !mouse_jiggle_active;
        }
        break;
    }

    //     case BAR:
    //         if (record->event.pressed) {
    //             register_code(KC_LGUI);
    //             register_code(KC_LALT);
    //             register_code(KC_LCTL);
    //         } else {
    //             unregister_code(KC_LGUI);
    //             unregister_code(KC_LALT);
    //             unregister_code(KC_LCTL);
    //         }
    //         break;


    return process_record_keymap(keycode, record) && process_record_secrets(keycode, record)
        #ifdef OLED_ENABLE
        && process_record_oled(keycode, record)
        #endif
        ; // Close return
}

void matrix_scan_user(void) {
    if (mouse_jiggle_active && timer_elapsed(mouse_timer) >= mouse_interval) {
        mouse_timer = timer_read();
        SEND_STRING(SS_DELAY(100));
        tap_code(KC_MS_UP);
        SEND_STRING(SS_DELAY(100));
        tap_code(KC_MS_DOWN);
        SEND_STRING(SS_DELAY(100));
        tap_code(KC_MS_LEFT);
        SEND_STRING(SS_DELAY(100));
        tap_code(KC_MS_RIGHT);
    } else {
    }
}
