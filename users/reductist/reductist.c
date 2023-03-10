#include "reductist.h"

layer_state_t layer_state_set_user (layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#ifdef RGBLIGHT_ENABLE
extern rgblight_config_t rgblight_config;
#endif
void keyboard_post_init_user(void) {
  #ifdef RGBLIGHT_ENABLE
     // Cycles through the entire hue wheel and resetting to default color
     uint16_t default_hue = rgblight_config.hue;
     rgblight_enable_noeeprom();
     layer_state_set_user(layer_state);
     rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
     for (uint16_t i = 255; i > 0; i--) {
          rgblight_sethsv_noeeprom((i + default_hue) % 255, rgblight_config.sat, rgblight_config.val);
          matrix_scan();
          wait_ms(10);
     }
  #endif
  layer_state_set_user(layer_state);
}
