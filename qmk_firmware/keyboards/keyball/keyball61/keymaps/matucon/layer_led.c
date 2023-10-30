#include QMK_KEYBOARD_H

#include "layer_led.h"

#ifdef LAYER_LED_ENABLE
static uint8_t my_latest_val = 50;
static bool is_layer_led = false;
#endif

void change_layer_led_color(layer_state_t state) {
#ifdef LAYER_LED_ENABLE
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
#endif
}

bool toggle_layer_led(bool pressed) {
#ifdef LAYER_LED_ENABLE
    if (pressed) {
        is_layer_led = !is_layer_led;
        if (!is_layer_led) {
            rgblight_sethsv(0, 250, 250);
        }
    }
#endif
    return true;
}