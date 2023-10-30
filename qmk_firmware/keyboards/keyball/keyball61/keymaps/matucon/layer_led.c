#include QMK_KEYBOARD_H

#include "layer_led.h"

static uint8_t my_latest_val = 50;
static bool is_layer_led = false;

void change_layer_led_color(layer_state_t state) {
    if (!is_layer_led) {
        return;
    }

    switch(get_highest_layer(state)) {
        case 0: 
            my_latest_val = rgblight_get_val();
            rgblight_sethsv(rgblight_get_hue(), rgblight_get_sat(), 0); 
            break;
        case 1: rgblight_sethsv(234, rgblight_get_sat(), my_latest_val); break;
        case 2: rgblight_sethsv( 36, rgblight_get_sat(), my_latest_val); break;
        case 3: rgblight_sethsv(170, rgblight_get_sat(), my_latest_val); break;
        case 4: rgblight_sethsv(  0, rgblight_get_sat(), my_latest_val); break;
    }
}

bool toggle_layer_led(bool pressed) {
    if (pressed) {
        is_layer_led = !is_layer_led;
        if (!is_layer_led) {
            rgblight_sethsv(0, 250, 250);
        }
    }
    return true;
}