#include QMK_KEYBOARD_H

#include "precision.h"

static const uint16_t PROGMEM down_cpi = 4;

static uint16_t latest_cpi = 1;
static bool     cpi_state  = false;

void precision_toggle(bool pressed) {
    if (!pressed) {
        return;
    }
    
    uint16_t current_cpi = keyball_get_cpi();
    if (cpi_state) {
        keyball_set_cpi(down_cpi != current_cpi ? current_cpi : latest_cpi);
    } else {
        latest_cpi = current_cpi;
        keyball_set_cpi(down_cpi);
    }
    cpi_state = !cpi_state;
}

void precision_switch(bool pressed) {
    if (pressed) {
        latest_cpi = keyball_get_cpi();
        keyball_set_cpi(down_cpi);
    } else {
        keyball_set_cpi(latest_cpi);
    }
}