#pragma once
#include "reductist.h"

enum custom_keycodes {
  // Secret Macros
  S_XXX1 = SAFE_RANGE,
  S_XXX2,
  S_XXX3,
  S_XXX4,
  S_XXX5,
};

bool process_record_secrets(uint16_t keycode, keyrecord_t *record);
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
#ifdef OLED_ENABLE
bool process_record_oled(uint16_t keycode, keyrecord_t *record);
#endif
