#include QMK_KEYBOARD_H

#include "layer_led.h"

#ifdef LAYER_LED_ENABLE
static uint8_t my_latest_val = 50;
static bool    layer_led     = false;
static uint8_t latest_hue    = 0;
#endif

// レイヤーごとにLEDの色を変える
void change_layer_led_color(layer_state_t state) {
#ifdef LAYER_LED_ENABLE
    if (!layer_led) {
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
        case 4: rgblight_sethsv( 85, rgblight_get_sat(), my_latest_val); break;
    }
#endif
}

// レイヤーLEDカラーの有効・無効を切り替える
bool toggle_layer_led(bool pressed) {
#ifdef LAYER_LED_ENABLE
    if (!pressed) {
        return;
    }

    layer_led = !layer_led;
    if (!layer_led) {
        rgblight_sethsv(0, 250, 250);
    } else if (rgblight_get_val() == 0) {
        rgblight_sethsv(rgblight_get_hue(), rgblight_get_sat(), 96);
    }
#endif
    return true;
}

// スクロールモードに合わせて一部のLED色を変更する
void toggle_scroll_led(bool pressed) {
#ifdef LAYER_LED_ENABLE
    if (!pressed) {
        return;
    }

    if (!keyball_get_scroll_mode()) {
        latest_hue = rgblight_get_hue();
        rgblight_sethsv_range(0, rgblight_get_sat(), rgblight_get_val(), 66, 71);
        rgblight_sethsv_range(0, rgblight_get_sat(), rgblight_get_val(), 37, 44);

    } else {
        rgblight_sethsv_range(latest_hue, rgblight_get_sat(), rgblight_get_val(), 66, 71);
        rgblight_sethsv_range(latest_hue, rgblight_get_sat(), rgblight_get_val(), 37, 44);
    }
#endif
}
