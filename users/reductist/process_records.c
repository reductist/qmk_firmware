#include "reductist.h"

__attribute__((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

__attribute__((weak))
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) { return true; }

#ifdef OLED_ENABLE
__attribute__((weak))
bool process_record_oled(uint16_t keycode, keyrecord_t *record) { return true; }
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // user macros here
    // switch (keycode) {
    //     case FOO:
    //         if (record->event.pressed) {
    //             SEND_STRING("FOO\n");
    //         }
    //         break;

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
    // }

    return process_record_keymap(keycode, record) && process_record_secrets(keycode, record)
        #ifdef OLED_ENABLE
        && process_record_oled(keycode, record)
        #endif
        ; // Close return
}
