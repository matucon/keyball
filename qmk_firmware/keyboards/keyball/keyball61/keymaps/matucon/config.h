/*
This is the c configuration file for the keymap

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

#pragma once

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_EFFECT_BREATHING
// #    define RGBLIGHT_EFFECT_RAINBOW_MOOD
// #    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
// #    define RGBLIGHT_EFFECT_SNAKE
// #    define RGBLIGHT_EFFECT_KNIGHT
// #    define RGBLIGHT_EFFECT_CHRISTMAS
// #    define RGBLIGHT_EFFECT_STATIC_GRADIENT
// #    define RGBLIGHT_EFFECT_RGB_TEST
// #    define RGBLIGHT_EFFECT_ALTERNATING
// #    define RGBLIGHT_EFFECT_TWINKLE
#endif

#define TAP_CODE_DELAY 5

#define DYNAMIC_KEYMAP_LAYER_COUNT 5
#define KEYBALL_CPI_DEFAULT 1100
#define KEYBALL_SCROLL_DIV_DEFAULT 5

#define OLED_TIMEOUT 30000

#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define AUTO_MOUSE_DEFAULT_LAYER 2
#define AUTO_MOUSE_TIME 500

#define TAPPING_TERM 180
#define COMBO_TERM 30

// オリジナル定義
#define LAYER_LED_ENABLE   // レイヤーごとにLED色変更
#define CUSTOM_OLED_ENABLE // オリジナルのOLED表示デザイン
#define LAYER_NUM_DESIGN 1 // レイヤーNoアイコンデザイン (1:肉球の数、2:肉球内に数字、その他:アラビア数字)
#define LED_INFO_ENABLE    // サブ側のOLEDにLED情報を表示
#define OLED_PAGE_ENABLE   // メイン側のOLEDを複数ページ化
#define VER_INFO_ENABLE    // メイン側のOLED 2ページ目にバージョン情報を表示
