#ifdef LAYER_LED_ENABLE

#include QMK_KEYBOARD_H

static const uint8_t my_layer_colors[] = {234, 17,170, 85}; // ピンク、黄、青、緑

static uint8_t my_latest_val = 0;
static uint8_t my_latest_hue = 0;
static bool    layer_led     = false;

// レイヤーごとにLED色変更
void change_layer_led_color(uint8_t layer_no) {
    if (!layer_led) {
        return;
    }

    if (layer_no == 0) {
        my_latest_val = rgblight_get_val();
        rgblight_sethsv(rgblight_get_hue(), rgblight_get_sat(), 0); 
    } else {
        rgblight_sethsv(my_layer_colors[layer_no-1], rgblight_get_sat(), my_latest_val);
    }
}

// 機能の有効・無効を切り替え
void toggle_layer_led(bool pressed) {
    if (!pressed) {
        return;
    }

    layer_led = !layer_led;
    if (layer_led) {
        my_latest_hue = rgblight_get_hue();
    } else {
        rgblight_sethsv(my_latest_hue, rgblight_get_sat(), rgblight_get_val());
    }
}

#endif