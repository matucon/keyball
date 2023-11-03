/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"
#include "keymap_japanese.h"
#include "layer_led.c"
#include "custom_oled.c"
#include "precision.c"

enum my_keyball_keycodes {
	LAY_TOG = KEYBALL_SAFE_RANGE, // レイヤーLEDトグル
    PRC_TOG,                      // Precision モードトグル
    PRC_SW,                       // Precision モードスイッチ  
    OLED_IN,                      // OLED ページ＋
    OLED_DE,                      // OLED ページ-
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_universal(
    KC_ESC  , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                                  KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_MINS  ,
    KC_TAB  , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                  KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_INT3  ,
    KC_LCTL , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                  KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , S(KC_7)  ,
    KC_LSFT , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     , KC_RBRC  ,              KC_NUHS, KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_RSFT  ,
    MO(1)   , C(KC_Z)  , KC_LALT  , KC_LGUI,LT(4,KC_DELETE),LT(2,KC_SPC),LT(3,KC_GRV),    KC_BSPC,LT(2,KC_ENT),LT(1,KC_LNG2),KC_RGUI, _______ , KC_LALT  , TG(2)
  ),

  [1] = LAYOUT_universal(
    S(KC_ESC)  , S(KC_1)  , KC_LBRC  , S(KC_3)  , S(KC_4)  , S(KC_5)  ,                                  KC_EQL   , S(KC_6)  ,S(KC_QUOT), S(KC_8)  , S(KC_9)   , S(KC_INT1),
    S(KC_TAB)  , S(KC_Q)  , S(KC_W)  , S(KC_E)  , S(KC_R)  , S(KC_T)  ,                                  S(KC_Y)  , S(KC_U)  ,S(KC_I)   , S(KC_O)  , S(KC_P)   , S(KC_INT3),
    S(KC_LCTL) , S(KC_A)  , S(KC_S)  , S(KC_D)  , S(KC_F)  , S(KC_G)  ,                                  S(KC_H)  , S(KC_J)  ,S(KC_K)   , S(KC_L)  , KC_QUOT   , S(KC_2)   ,
    _______    , S(KC_Z)  , S(KC_X)  , S(KC_C)  , S(KC_V)  , S(KC_B)  ,S(KC_RBRC),           S(KC_NUHS), S(KC_N)  , S(KC_M)  ,S(KC_COMM), S(KC_DOT), S(KC_SLSH), S(KC_RSFT),
    _______    ,S(KC_LCTL),S(KC_LALT),S(KC_LGUI), _______  , _______  , _______  ,            KC_DELETE, KC_INSERT, _______  ,S(KC_RGUI), _______  , S(KC_LALT), _______
  ),

  [2] = LAYOUT_universal(
    _______  , KC_F1    , KC_F2    , KC_F3     , KC_F4    , KC_F5   ,                                   KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   ,
    _______  , KC_PSLS  , KC_P7    , KC_P8     , KC_P9    , KC_PMNS ,                                   _______  , KC_LEFT  , KC_UP    , KC_RGHT  , C(KC_W)  , KC_F12   ,
    _______  , KC_PAST  , KC_P4    , KC_P5     , KC_P6    , KC_PPLS ,                                   PRC_TOG  , KC_BTN1  , KC_DOWN  , KC_BTN2  , KC_BTN3  , MO(3)    ,
    _______  , KC_PDOT  , KC_P1    , KC_P2     , KC_P3    , KC_PEQL , S(KC_8)  ,             S(KC_9)  , _______  , KC_BTN4  , SCRL_TO  , KC_BTN5  , _______  , PRC_SW   ,
    KC_NUM   , KC_PCMM  , KC_P0    , KC_PENT   , PRC_SW   , _______ , _______  ,             KC_ESC   , _______  , _______  , _______  , _______  , _______  , KC_TRNS
  ),

  [3] = LAYOUT_universal(
    RGB_TOG  , LAY_TOG  , OLED_DE  , OLED_IN  , _______  , _______  ,                                  RGB_M_P  , RGB_M_B  , RGB_M_R  , RGB_M_SW , RGB_M_SN , RGB_M_K  ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , RGB_SPI  , _______  ,                                  RGB_M_X  , RGB_M_G  , RGB_M_T  , RGB_M_TW , _______  , _______  ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , RGB_SPD  , _______  ,                                  CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE , KBC_RST  ,
    _______  , _______  , SCRL_DVD , SCRL_DVI , SCRL_MO  , SCRL_TO  , EE_CLR  ,              EE_CLR  , KC_HOME  , KC_PGDN  , KC_PGUP  , KC_END   , _______  , _______  ,
    JP_CAPS  , KC_SCRL  , _______  , _______  , _______  , _______  , _______  ,            _______  , KC_BSPC  , _______  , _______  , _______  , _______  , _______
  ),

  [4] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,            _______  , _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , PRC_SW   , _______  , _______  ,            _______  , _______  , _______  , _______  , _______  , _______  , _______
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);

    change_layer_led_color(state);

    switch(get_highest_layer(remove_auto_mouse_layer(state, true))) {
        case 1:
            state = remove_auto_mouse_layer(state, false);
            set_auto_mouse_enable(false);
            break;
        default:
            set_auto_mouse_enable(true);
            break;
    }
    
    return state;
}

#ifdef OLED_ENABLE

#include "lib/oledkit/oledkit.h"

#ifdef CUSTOM_OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
#  ifdef LED_INFO_ENABLE
    return OLED_ROTATION_270;
#  else
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
#  endif
    return rotation;
}
#endif

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oledkit_render_info_user();
    } else {
        oledkit_render_logo_user();
#  ifndef CUSTOM_OLED_ENABLE
        oled_scroll_left();
#  endif
    }
    return true;
}

void oledkit_render_info_user(void) {
#  ifdef CUSTOM_OLED_ENABLE
    keyball_oled_render_mymain();
#  else
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
#  endif
}

#  ifdef LED_INFO_ENABLE
void oledkit_render_logo_user(void) {
    keyball_oled_render_mysub();
}
#  endif

#endif

#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
void pointing_device_init_user(void) {
    set_auto_mouse_enable(true);
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LAY_TOG:
            toggle_layer_led(record->event.pressed);
            return true;
        case SCRL_TO:
            toggle_scroll_led(record->event.pressed);
            return true;
        case PRC_SW:
            precision_switch(record->event.pressed);
            return true;
        case PRC_TOG:
            precision_toggle(record->event.pressed);
            return true;
            
#ifdef OLED_PAGE_ENABLE
        case OLED_IN:
            if (record->event.pressed) {
                change_page(true);
            }
            return true;
        case OLED_DE:
            if (record->event.pressed) {
                change_page(false);
            }
            return true;
#endif
    }
    return true;
}
