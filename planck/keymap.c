#include QMK_KEYBOARD_H

#include "keymap_norwegian.h"

enum layers { 
  _BASE, 
  _TYPE,
  _RAISE, 
  _LOWER, 
  _ADJUST, 
  _NUM, 
  _SYM1, 
  _SYM2 
};

enum keycodes {
  ___ARNG = SAFE_RANGE,
  ___AE,
  ___OSTR
};

// ONE SHOT MODS

#define OS_CTL OSM(MOD_LCTL)
#define OS_ALT OSM(MOD_LALT)
#define OS_SFT OSM(MOD_LSFT)

// HOME ROW MODS

#define SFT_A LSFT_T(KC_A)
#define CTL_S LCTL_T(KC_S)
#define ALT_D LALT_T(KC_D)
#define GUI_F LGUI_T(KC_F)

#define GUI_J RGUI_T(KC_J)
#define ALT_K RALT_T(KC_K)
#define CTL_L RCTL_T(KC_L)
#define SFT_SCL RSFT_T(KC_SCLN)
#define SFT_0 RSFT_T(KC_0)

// SHORTCUTS

#define DSK_1 LGUI(KC_1)
#define DSK_2 LGUI(KC_2)
#define DSK_3 LGUI(KC_3)
#define DSK_4 LGUI(KC_4)
#define SFT_V LSFT(KC_V)
#define LANG LGUI(KC_SPACE)

// LAYERS

#define MO_SYM1 MO(_SYM1)
#define MO_SYM2 MO(_SYM2)
#define DF_BASE DF(_BASE)
#define DF_TYPE DF(_TYPE)

#define LT_ENT LT(_LOWER, KC_ENT)
#define LT_SPC LT(_RAISE, KC_SPC)
#define LT_TAB LT(_LOWER, KC_TAB)
#define LT_BSPC LT(_RAISE, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_grid(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    SFT_A,   CTL_S,   ALT_D,   GUI_F,   KC_G,    _______, _______, KC_H,    GUI_J,   ALT_K,   CTL_L,   SFT_SCL,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    MO_SYM1, _______, _______, LT_ENT,  KC_TAB,  KC_ESC,  KC_ESC,  KC_BSPC, LT_SPC,  _______, _______, MO_SYM2 
  ),

  [_TYPE] = LAYOUT_planck_grid(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______, _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    MO_SYM1, _______, _______, LT_ENT,  KC_TAB,  KC_ESC,  KC_ESC,  KC_BSPC, LT_SPC,  _______, KC_QUOT, MO_SYM2 
  ),

  // [_RAISE] = LAYOUT_planck_grid(
  //   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS, KC_EQL,
  //   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  //   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_BSLS,
  //   XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_GRV,  XXXXXXX
  // ),

  // [_LOWER] = LAYOUT_planck_grid(
  //   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX, XXXXXXX, KC_UNDS, KC_PLUS,
  //   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX, XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  //   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_PIPE,
  //   XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_TILD, XXXXXXX
  // ),

  [_RAISE] = LAYOUT_planck_grid(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    SFT_0,
    KC_GRV,  KC_QUOT, KC_BSLS, KC_MINS, KC_EQL,  _______, _______, XXXXXXX, _______, _______, _______, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_LOWER] = LAYOUT_planck_grid(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_GRV,  KC_QUOT, KC_BSLS, KC_MINS, KC_EQL,  _______, _______, XXXXXXX, XXXXXXX, _______, _______, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_ADJUST] = LAYOUT_planck_grid(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, DSK_1,   DSK_2,   XXXXXXX, XXXXXXX, DSK_3,   DSK_4,   XXXXXXX, XXXXXXX, XXXXXXX,
    DF_BASE, XXXXXXX, XXXXXXX, XXXXXXX, KC_INS,  RESET,   RESET,   KC_DEL,  XXXXXXX, XXXXXXX, XXXXXXX, DF_TYPE
  ),

  [_SYM1] = LAYOUT_planck_grid(
    _______, _______, NO_AE,   _______, _______, _______, _______, _______, _______, _______, NO_OSTR, _______,
    NO_ARNG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, LANG,    LANG,    _______, _______, _______, _______, _______
  ),

  [_SYM2] = LAYOUT_planck_grid(
    _______, _______, ___AE,   _______, _______, _______, _______, _______, _______, _______, ___OSTR, _______,
    ___ARNG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
};

// LIGHTS

#define ___ {0,0,0}
#define PIN {245, 138, 255}
#define CYA {74, 255, 235}
#define WHI {255, 255, 255}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
  [_BASE] = {
    ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, WHI, ___, ___, ___, ___, WHI, ___, ___, ___,
    ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___,      ___, ___, ___, ___, ___
  },

  [_RAISE] = {
    ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, PIN, ___, ___, ___, ___, PIN, ___, ___, ___,
    ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___,      ___, ___, ___, ___, ___
  },

  [_LOWER] = {
    ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, CYA, ___, ___, ___, ___, CYA, ___, ___, ___,
    ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___,      ___, ___, ___, ___, ___
  },

  [_ADJUST] = {
    ___, ___, ___, CYA, ___, ___, ___, ___, PIN, ___, ___, ___,
    ___, PIN, PIN, PIN, PIN, ___, ___, CYA, CYA, CYA, CYA, ___,
    ___, ___, ___, CYA, CYA, ___, ___, PIN, PIN, ___, ___, ___,
    CYA, ___, ___, ___, ___, PIN,      ___, ___, ___, ___, PIN
  },

  [_SYM1] = {
    ___, ___, CYA, ___, ___, ___, ___, ___, ___, ___, CYA, ___,
    CYA, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___,      ___, ___, ___, ___, ___
  },

  [_SYM2] = {
    ___, ___, CYA, ___, ___, ___, ___, ___, ___, ___, CYA, ___,
    CYA, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___,      ___, ___, ___, ___, ___
  },
};

void keyboard_post_init_user(void) {
  // rgb_matrix_enable();
  rgb_matrix_disable();
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

uint16_t get_tapping_term(uint16_t keycode) {
  switch (keycode) {
    // case LT_SPC:
    // case LT_ENT:
    //   return 150;
    //   break;
    default:
      return TAPPING_TERM;
  }
}

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    RGB rgb = {
      .r = pgm_read_byte(&ledmap[layer][i][0]),
      .g = pgm_read_byte(&ledmap[layer][i][1]),
      .b = pgm_read_byte(&ledmap[layer][i][2]),
    };

    if (!rgb.r && !rgb.g && !rgb.b) {
      rgb_matrix_set_color(i, 0, 0, 0);
    } else {
      rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
  }
}

void rgb_matrix_indicators_user(void) {
  switch (biton32(layer_state)) {
    case _BASE:
    case _TYPE:
      planck_ez_right_led_level(0);
      planck_ez_left_led_level(0);
      break;

    case _RAISE:
      planck_ez_right_led_level(32);
      planck_ez_left_led_level(0);
      break;

    case _LOWER:
      planck_ez_right_led_level(0);
      planck_ez_left_led_level(32);
      break;

    case _ADJUST:
      planck_ez_right_led_level(32);
      planck_ez_left_led_level(32);
      break;

    case _SYM1:
      planck_ez_left_led_level(32);
      planck_ez_left_led_level(0);
      break;

    case _SYM2:
      planck_ez_right_led_level(32);
      planck_ez_left_led_level(0);
      break;

   default:
      planck_ez_right_led_level(0);
      planck_ez_left_led_level(0);
    break;
  }
}

// void rgb_matrix_indicators_user(void) {
//   // uint8_t osm = get_oneshot_mods();
//   // uint8_t locked_osm = get_oneshot_locked_mods();

//   switch (biton32(layer_state)) {
//     case _BASE:
//     case _TYPE:
//       set_layer_color(_BASE);
//       planck_ez_right_led_level(0);
//       planck_ez_left_led_level(0);
//       break;

//     case _RAISE:
//       set_layer_color(_RAISE);
//       planck_ez_right_led_level(0);
//       planck_ez_left_led_level(32);
//       break;

//     case _LOWER:
//       set_layer_color(_LOWER);
//       planck_ez_right_led_level(32);
//       planck_ez_left_led_level(0);
//       break;

//     case _ADJUST:
//       set_layer_color(_ADJUST);
//       planck_ez_right_led_level(32);
//       planck_ez_left_led_level(32);
//       break;

//     case _SYM1:
//       set_layer_color(_SYM1);
//       planck_ez_left_led_level(32);
//       break;

//     case _SYM2:
//       set_layer_color(_SYM2);
//       planck_ez_right_led_level(32);
//       break;

//    default:
//       rgb_matrix_set_color_all(0, 0, 0);
//       planck_ez_right_led_level(0);
//       planck_ez_left_led_level(0);
//     break;
//   }

//   // if (locked_osm & MOD_MASK_SHIFT) {
//   //   rgb_matrix_set_color(30, 238, 67, 67);
//   //   rgb_matrix_set_color(24, 238, 67, 67); // KC_Z
//   //   rgb_matrix_set_color(35, 238, 67, 67); // KC_SLSH
//   // } else if (osm & MOD_MASK_SHIFT) {
//   //   rgb_matrix_set_color(30, 255, 255, 255);
//   //   rgb_matrix_set_color(24, 255, 255, 255); // KC_Z
//   //   rgb_matrix_set_color(35, 255, 255, 255); // KC_SLSH
//   // }

//   // if (locked_osm & MOD_MASK_CTRL) {
//   //   rgb_matrix_set_color(29, 238, 67, 67);
//   //   rgb_matrix_set_color(25, 238, 67, 67); // KC_X
//   //   rgb_matrix_set_color(34, 238, 67, 67); // KC_DOT
//   // } else if (osm & MOD_MASK_CTRL) {
//   //   rgb_matrix_set_color(29, 255, 255, 255);
//   //   rgb_matrix_set_color(25, 255, 255, 255); // KC_X
//   //   rgb_matrix_set_color(34, 255, 255, 255); // KC_DOT
//   // }

//   // if (locked_osm & MOD_MASK_ALT) {
//   //   rgb_matrix_set_color(38, 238, 67, 67);
//   // } else if (osm & MOD_MASK_ALT) {
//   //   rgb_matrix_set_color(38, 255, 255, 255);
//   // }

//   // if (locked_osm & MOD_MASK_GUI) {
//   //   rgb_matrix_set_color(37, 238, 67, 67);
//   // } else if (osm & MOD_MASK_GUI) {
//   //   rgb_matrix_set_color(37, 255, 255, 255);
//   // }
// }

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   uint8_t mods;
//   bool rc = true;

//   switch (keycode) {
//     case ___ARNG: 
//       if (record->event.pressed) {
//         // TODO
//       } else {
//         // TODO
//       }

//       break;

//     case ___AE: 
//       if (record->event.pressed) {
//         // TODO
//       } else {
//         // TODO
//       }

//       break;

//     case ___OSTR: 
//       if (record->event.pressed) {
//         // TODO
//       } else {
//         // TODO
//       }

//       break;

//     case KC_ESC:
//       if (record->event.pressed) {
//         if ((mods = get_oneshot_mods()) && !has_oneshot_mods_timed_out()) {
//           clear_oneshot_mods();
//           unregister_mods(mods);
//           rc = false;
//         }

//         if ((mods = get_oneshot_locked_mods())) {
//           clear_oneshot_locked_mods();
//           unregister_mods(mods);
//           rc = false;
//         }

//         if (is_oneshot_layer_active()) {
//           layer_clear();
//           rc = false;
//         }

//         break;
//       }
//   }


//   return rc;
// }
