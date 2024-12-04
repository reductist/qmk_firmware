#include "reductist.h"

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

__attribute__((weak)) bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
    return true;
}

#ifdef OLED_ENABLE
__attribute__((weak)) bool process_record_oled(uint16_t keycode, keyrecord_t *record) {
    return true;
}
#endif

uint32_t idle_timeout   = 60000; // (after 60s)
uint32_t mouse_interval = 20000; // (every 20s)
bool     idle_enabled   = false; // initially disabled

static uint32_t idle_callback(uint32_t trigger_time, void *cb_arg) {
    // now idle
    if (idle_enabled) {
        tap_code16(KC_F15);
    }
    return mouse_interval;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // on every key event start or extend `idle_callback()` deferred execution after IDLE_TIMEOUT_MS
    static deferred_token idle_token = INVALID_DEFERRED_TOKEN;

    if (!extend_deferred_exec(idle_token, idle_timeout) && idle_enabled) {
        idle_token = defer_exec(idle_timeout, idle_callback, NULL);
    }

    // user macros here
    switch (keycode) {
        case JIGGL:
            if (record->event.pressed) {
                idle_enabled = !idle_enabled;
                if (idle_enabled) {
                    rgb_matrix_enable_noeeprom();
                    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
                    rgb_matrix_sethsv_noeeprom(HSV_CORAL);
                } else {
                    rgb_matrix_disable_noeeprom();
                }
            }
            break;
    }

    return process_record_keymap(keycode, record) && process_record_secrets(keycode, record)
#ifdef OLED_ENABLE
           && process_record_oled(keycode, record)
#endif
        ; // close return
}
