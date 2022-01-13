#include QMK_KEYBOARD_H
#include "haryoiro_color.h"

/*---------------------
 * COMBO KEYS
  ---------------------*/
#ifdef COMBO_ENABLE
enum combos
{
  CB_LEFT,
  CB_DOWN,
  CB_UP,
  CB_RIGHT,
  CB_CIRC,
     // JP配列にて通常 <"~"チルダ> Shift押下時 <"^"ハット>が入力されるコンボキー
};

const uint16_t PROGMEM cr_left_combo[] = {KC_LCTL, KC_LEFT, COMBO_END};
const uint16_t PROGMEM cr_down_combo[] = {KC_LCTL, KC_DOWN, COMBO_END};
const uint16_t PROGMEM cr_up_combo[]   = {KC_LCTL, KC_UP,   COMBO_END};
const uint16_t PROGMEM cr_rght_combo[] = {KC_LCTL, KC_RGHT, COMBO_END};
const uint16_t PROGMEM circtil_combo[] = {KC_LSFT, KC_CIRC, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [CB_LEFT ]  = COMBO(cr_left_combo,  KC_HOME),
    [CB_DOWN ]  = COMBO(cr_down_combo,  KC_PGDN),
    [CB_UP   ]  = COMBO(cr_up_combo,    KC_PGUP),
    [CB_RIGHT]  = COMBO(cr_rght_combo,  KC_END),
    [CB_CIRC ]  = COMBO(circtil_combo,  KC_TILD),
};
#endif

/*---------------------
 * LAYER DEFINITIONS
  ---------------------*/
enum layer_number {
    _DEFAULT = 0,       // Windows向け配列。
    _MAC,           // Mac向け配列
    _FUNCTION,      // Functionキー
    _ALLOW,         // VIMLIKE移動キー
    _SYMBOL,        // 記号
    _TRANSPARENT,   // なにもないレイヤー。レイアウト参考用
};


#define DEFAULT  MO(_DEFAULT)
#define MAC      MO(_MAC)
#define FUNCTION MO(_FUNCTION)
#define ALLOW    MO(_ALLOW)
#define SYMBOL   MO(_SYMBOL)


/*---------------------
 * CUSTOM KEYS
  ---------------------*/
enum custom_keys {
  WINMAC,
};

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
    * DEFAULT // JIS配列デフォルトキーマップ
    */
    [_DEFAULT] = LAYOUT(
        KC_LGUI,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                         KC_6,     KC_7,     KC_8,    KC_MINS,  KC_CIRC,    KC_GRV,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                         KC_Y,     KC_U,     KC_I,    KC_O,     KC_P,      KC_RO,
        KC_LSFT,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                         KC_H,     KC_J,     KC_K,    KC_L,     KC_LBRC,   KC_RBRC,
        KC_LCTL,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     XXXXXXX,  XXXXXXX,  KC_N,     KC_M,     KC_COMM, KC_DOT,   KC_SLSH,   KC_QUOT,
                                      KC_LALT,  KC_ESC,   SYMBOL,   KC_SPC,   KC_ENT,   ALLOW,    KC_BSPC,  FUNCTION),

    /*
    * MAC // Macのみに適用されるレイヤー
    */
    [_MAC] = LAYOUT(
        KC_ESC,   _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,    _______,
        _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,   KC_LBRC,
        KC_LSFT,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  KC_RBRC,   KC_NUHS,
        KC_LGUI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_NUHS,   KC_SLSH,
                                      _______,  KC_LCTL,  _______,  _______,  _______,  _______,  _______,  _______),
        // KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                         KC_6,     KC_7,     KC_8,    KC_MINS,  KC_CIRC,    KC_GRV,
        // KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                         KC_Y,     KC_U,     KC_I,    KC_O,     KC_P,      KC_LBRC,
        // KC_LSFT,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                         KC_H,     KC_J,     KC_K,    KC_L,     KC_RBRC,   KC_NUHS,
        // KC_LGUI,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     XXXXXXX,  XXXXXXX,  KC_N,     KC_M,     KC_COMM, KC_DOT,   KC_NUHS,   KC_SLSH,
        //                               KC_LOPT,  KC_LCTL,  SYMBOL,   KC_SPC,   KC_ENT,   ALLOW,    KC_BSPC,  FUNCTION),

    /*
    * FUNCTION
    */
    [_FUNCTION] = LAYOUT(
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  RGB_TOG,                      RGB_TOG,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  RESET,                        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  DEBUG,                        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  EEP_RST,   WINMAC,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______),

    [_ALLOW] = LAYOUT(
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   XXXXXXX,  XXXXXXX,
        KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,                        KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  XXXXXXX,  XXXXXXX,
        KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                      _______,  _______,  _______,  _______,  _______,  _______, _______, _______),

    [_SYMBOL] = LAYOUT(
        _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_MINS,  KC_RO,    KC_JYEN,
        _______,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                         KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_QUOT,
        _______,  KC_EXLM,  KC_DQUO,  KC_HASH,  KC_DLR,   KC_PERC,                      KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_SCLN,
        _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_RBRC,  KC_NUHS,  KC_LBRC,  KC_SLSH,
                                      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______),

    /*
    * TRANSPARENT //
    */
    [_TRANSPARENT] = LAYOUT(
        _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
                                      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______)

};

// clang-format on

bool MAC_MODE = true;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case WINMAC:
            if (record->event.pressed) {
                MAC_MODE = !MAC_MODE;
                if (!MAC_MODE) {
                    layer_off(_MAC);
                }
            }
            return false;
            break;
    }
  return true;
}

uint32_t layer_state_set_keymap (uint32_t state) {
  return state;
}

/*---------------------
 * RGB LED
  ---------------------*/

// void matrix_init_user(void) {
// }
#ifdef RGBLIGHT_ENABLE
// { start, length, color }
const rgblight_segment_t PROGMEM default_layer[]  = RGBLIGHT_LAYER_SEGMENTS(
  // left
  // { 29,  6, GRAD_TEAL_0 },
  // { 35,  6, GRAD_TEAL_1 },
  // { 41,  6, GRAD_TEAL_2 },
  // { 47,  6, GRAD_TEAL_3 },
  // { 53,  6, GRAD_TEAL_4 }
  { 0, 58, HSV_TEAL }
);
const rgblight_segment_t PROGMEM mac_layer[]      = RGBLIGHT_LAYER_SEGMENTS(  { 0, 58, HSV_TEAL } );
const rgblight_segment_t PROGMEM function_layer[] = RGBLIGHT_LAYER_SEGMENTS(  { 0, 58, HSV_RED  } );
const rgblight_segment_t PROGMEM allow_layer[]    = RGBLIGHT_LAYER_SEGMENTS(  { 0, 58, HSV_CYAN } );
const rgblight_segment_t PROGMEM symbol_layer[]   = RGBLIGHT_LAYER_SEGMENTS(  { 0, 58, HSV_TEAL } );

const rgblight_segment_t* const PROGMEM _rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    default_layer,
    mac_layer,
    allow_layer,
    function_layer,
    symbol_layer
);
// -> keyboard_post_init_user

#endif

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _DEFAULT));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_ENABLE
    rgblight_set_layer_state(0, layer_state_cmp(state, _DEFAULT ));
    rgblight_set_layer_state(1, layer_state_cmp(state, _MAC     ));
    rgblight_set_layer_state(2, layer_state_cmp(state, _FUNCTION));
    rgblight_set_layer_state(3, layer_state_cmp(state, _ALLOW   ));
    rgblight_set_layer_state(4, layer_state_cmp(state, _SYMBOL  ));
#endif
  return state;
}

void keyboard_post_init_user(void) {
  rgblight_layers = _rgb_layers;
  #if defined(RGBLIGHT_ENABLE)
  rgblight_setrgb_range(RGB_TEAL, 0, 58);
  rgblight_set();
  #endif
}