#include QMK_KEYBOARD_H
#include "reductist.h"

__attribute__ ((weak))
void matrix_scan_user_kb(void) { }

// Runs on every matrix scan. Be careful what goes here - you can really impact the
// responsiveness of your keyboard if you add too much in this function.
void matrix_scan_user(void) {
#ifdef USER_MOUSE_JIGGLE_ENABLE
    matrix_scan_mouse_jiggle();
#endif

    matrix_scan_user_kb();
}
