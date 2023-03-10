#include "quantum.h"
#include "process_records.h"

#ifdef ENCODER_ENABLE
bool left_encoder_rotated;
bool right_encoder_rotated;
uint16_t encoder_rotated_timer;
#endif

// Layers
#define _QWERTY 0
#define _NAV 1
#define _FNS 2

// Layer keys
#define MO_NAV MO(_NAV)
#define MO_FNS MO(_FNS)

// Shortcut keys
#define M_PSCR LSG(KC_4)
