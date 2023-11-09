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
// #    define RGBLIGHT_EFFECT_BREATHING
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

#define OLED_TIMEOUT 30000                // OLED������������
#define TAPPING_TERM 180                  // �L�[����������
#define DYNAMIC_KEYMAP_LAYER_COUNT 5      // ���C���[��
#define KEYBALL_CPI_DEFAULT 1100          // �}�E�X���x
#define KEYBALL_SCROLL_DIV_DEFAULT 5      // �X�N���[�����x
#define COMBO_TERM 80                     // �R���{���莞��
#define COMBO_ONLY_FROM_LAYER 0           // ���C���[�Ɉˑ����Ȃ��R���{(���C���[0�̃L�[�}�b�v�̂ݔ��f)
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE // Automatic Mouse Layer �L����
#define AUTO_MOUSE_DEFAULT_LAYER 2        // Automatic Mouse Layer �Ő؂�ւ��郌�C���[�ԍ�
#define AUTO_MOUSE_TIME 500               // Automatic Mouse Layer �Ō��̃��C���[�ɖ߂�܂ł̎���

// �J�X�^����`
#define LAYER_LED_ENABLE                  // ���C���[LED �L����
#define PRECISION_ENABLE                  // �v���V�W�������[�h �L����
#define PRECISION_CPI 4                   // �v���V�W�������[�h �ŕύX����CPI (1/100�̒l���w��)
