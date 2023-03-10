#pragma once
#include QMK_KEYBOARD_H
#include "reductist.h"

// Custom keycodes and macros
enum userspace_custom_keycodes {
    // USER_MOUSE_JIGGLE_ENABLE
    MS_JIGL,

    // USER_ENABLE_SECRETS
    KC_SECRET_1,
    KC_SECRET_2,
    KC_SECRET_3,
    KC_SECRET_4,

    DYNAMIC_MACRO_RANGE
};
bool process_record_secrets(uint16_t keycode, keyrecord_t *record);
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
bool process_record_user_kb(uint16_t keycode, keyrecord_t *record);
