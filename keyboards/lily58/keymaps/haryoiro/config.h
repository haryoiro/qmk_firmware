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

#pragma once

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
#   define RGBLIGHT_DEFAULT_HUE 128

#   undef RGBLED_NUM
#   define RGBLED_NUM 59 // 接続されているLEDの数
#   define RGBLIGHT_ANIMATIONS
#   undef RGBLIGHT_LIMIT_VAL
#   define RGBLIGHT_LIMIT_VAL 100
#   define RGBLIGHT_HUE_STEP 10
#   define RGBLIGHT_SAT_STEP 17
#   define RGBLIGHT_VAL_STEP 17

#   define RGB_DI_PIN D3

#endif