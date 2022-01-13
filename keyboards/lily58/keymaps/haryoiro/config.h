/*
This is the c configuration file for the keymap
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
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

// @see https://github.com/samhocevar-forks/qmk-firmware/blob/master/docs/ja/config_options.md
#pragma once

#include "ws2812.h"
#include "config_common.h"

/* Select hand configuration */
#define SPLIT_USB_DETECT
#define MASTER_RIGHT
// #define MASTER_LEFT
// #define EE_HANDS

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 100

#ifdef COMBO_ENABLE

#   define COMBO_COUNT 5
#   define COMBO_TERM 500

#endif

#ifdef RGBLIGHT_ENABLE

#   define RGBLIGHT_LAYERS
#   undef RGBLED_NUM
#   define RGBLED_NUM 58 // 左右含めたLEDの数
#   define RGBLED_SPLIT { 29, 29 } // 左右それぞれに接続されているLEDnの数。
#   define RGBLIGHT_MAX_LAYERS 5
#   define RGBLIGHT_ANIMATIONS
#   define RGBLIGHT_HUE_STEP 10
#   define RGBLIGHT_SAT_STEP 17
#   define RGBLIGHT_VAL_STEP 17
#   define RGBLIGHT_DEFAULT_HUE 0
#   define RGBLIGHT_DEFAULT_SAT 255
#   undef RGBLIGHT_LIMIT_VAL
#   define RGBLIGHT_LIMIT_VAL 60 // 単体の場合
#   define RGBLIGHT_EFFECT_BREATHE_MAX 60

#   define RGB_DI_PIN D3
#define LED_LAYOUT( \
	L00, L01, L02,  L03, L04, L05,           R00, R01, R02, R03, R04, R05, \
	L10, L11, L12,  L13, L14, L15,       	 R10, R11, R12, R13, R14, R15, \
	L20, L21, L22,  L23, L24, L25,           R20, R21, R22, R23, R24, R25, \
	L30, L31, L32,  L33, L34, L35, L45, R30, R31, R32, R33, R34, R35, R45, \
                    L41, L42, L43, L44, R41, R42, R43, R44 \
	) \
	{ \
        /*LeftHand*/ \
		L00, L01, L02, L03, L04, L05, \
        L15, L14, L13, L12, L11, L10, \
		L20, L21, L22, L23, L24, L25, \
        L35, L34, L33, L32, L31, L30, \
        L41, L42, L43, L44, L45 , \
        /*RightHand*/ \
        R00, R01, R02, R03, R04, R05, \
        R15, R14, R13, R12, R11, R10, \
        R20, R21, R22, R23, R24, R25, \
        R35, R34, R33, R32, R31, R30, \
        R41, R42, R43, R44, R45  \
	}

    #define RGBLIGHT_LED_MAP LED_LAYOUT( \
            0, 	1,  2,  3,  4,  5,       	29, 30, 31, 32, 33, 34, \
            6, 	7,  8,  9,  10, 11,      	35, 36, 37, 38, 39, 40, \
            12, 13, 14, 15, 16, 17,     	41, 42, 43, 44, 45, 46, \
            18, 19, 20, 21, 22, 23, 28, 47, 48, 49, 50, 51, 52, 57, \
                        24, 25, 26, 27, 53, 54, 55, 56 \
    )

#endif
