#include QMK_KEYBOARD_H

#include "keymap_norwegian.h"

enum { _BASE, _TYPE, _RAISE, _TOP, _FUN, _SYM };

#define OS_CTL OSM(MOD_LCTL)
#define OS_ALT OSM(MOD_LALT)
#define OS_SFT OSM(MOD_LSFT)

#define SFT_Z MT(MOD_LSFT, KC_Z)
#define CTL_X MT(MOD_LCTL, KC_X)
#define CTL_DOT MT(MOD_RCTL, KC_DOT)
#define SFT_SLSH MT(MOD_RSFT, KC_SLSH)

#define GUI_1 LGUI(KC_1)
#define GUI_2 LGUI(KC_2)
#define GUI_3 LGUI(KC_3)
#define SFT_V LSFT(KC_V)
#define LANG LGUI(KC_SPACE)

#define MO_RSE MO(_RAISE)
#define MO_TOP MO(_TOP)
#define TT_FUN TT(_FUN)
#define MO_SYM MO(_SYM)
#define DF_BASE DF(_BASE)
#define DF_TYPE DF(_TYPE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_mit(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_TAB,  XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
    SFT_Z,   CTL_X,   KC_C,    KC_V,    KC_B,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    KC_COMM, CTL_DOT, SFT_SLSH,
    TT_FUN,  KC_LGUI, OS_ALT,  KC_ENT,  MO_RSE,  KC_ESC,           MO_TOP,  KC_SPC,  KC_BSPC, KC_QUOT, MO_SYM
  ),

  [_TYPE] = LAYOUT_planck_mit(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_TAB,  KC_ESC,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    OS_CTL,  OS_SFT,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    TT_FUN,  KC_LGUI, OS_ALT,  KC_ENT,  MO_TOP,  KC_ESC,           MO_RSE,  KC_SPC,  KC_BSPC, KC_QUOT, MO_SYM
  ),

  [_RAISE] = LAYOUT_planck_mit(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
    XXXXXXX, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, KC_LCBR, KC_RCBR, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, SFT_V,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS,
    XXXXXXX, _______, _______, _______, _______, _______,          _______, _______, _______, KC_GRV,  XXXXXXX
  ),

  [_TOP] = LAYOUT_planck_mit(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS,
    XXXXXXX, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, KC_LCBR, KC_RCBR, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, SFT_V,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PIPE,
    XXXXXXX, _______, _______, _______, _______, _______,          _______, _______, _______, KC_TILD, XXXXXXX
  ),

  [_FUN] = LAYOUT_planck_mit(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   XXXXXXX, KC_PAST, KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, KC_PSLS, KC_P4,   KC_P5,   KC_P6,   KC_PMNS,
    GUI_1,   GUI_2,   GUI_3,   KC_HOME, KC_PGUP, KC_END,  XXXXXXX, KC_COLN, KC_P1,   KC_P2,   KC_P3,   KC_PEQL,
    _______, DF_BASE, DF_TYPE, _______, KC_PGDN, RESET,            _______, _______, KC_P0,   KC_PDOT, XXXXXXX
  ),

  [_SYM] = LAYOUT_planck_mit(
    _______, _______, NO_AE,   _______, _______, XXXXXXX, XXXXXXX, _______, _______, _______, NO_OSTR, _______,
    NO_ARNG, _______, _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______,
    XXXXXXX, _______, _______, _______, XXXXXXX, LANG,             XXXXXXX, _______, _______, _______, _______
  ),
};

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
    ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, CYA, CYA,
    ___, PIN, PIN, PIN, PIN, CYA, CYA, PIN, PIN, PIN, PIN, ___,
    ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, CYA,
    ___, ___, ___, ___, ___, ___,      ___, ___, ___, CYA, ___
  },

  [_TOP] = {
    ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, PIN, PIN,
    ___, CYA, CYA, CYA, CYA, PIN, PIN, CYA, CYA, CYA, CYA, ___,
    ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, PIN,
    ___, ___, ___, ___, ___, ___,      ___, ___, ___, PIN, ___
  },

  [_FUN] = {
    ___, ___, ___, ___, ___, ___, ___, ___, PIN, PIN, PIN, ___,
    ___, ___, ___, ___, PIN, ___, ___, ___, PIN, PIN, PIN, ___,
    ___, ___, ___, ___, ___, ___, ___, ___, PIN, PIN, PIN, ___,
    ___, CYA, CYA, ___, ___, CYA,      ___, ___, PIN, ___, ___
  },

  [_SYM] = {
    ___, ___, CYA, ___, ___, ___, ___, ___, ___, ___, CYA, ___,
    CYA, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___,      ___, ___, ___, ___, ___
  },
};

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
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
  uint8_t mods = get_mods();
  uint8_t osm = get_oneshot_mods();
  uint8_t locked_osm = get_oneshot_locked_mods();

  switch (biton32(layer_state)) {
    case _BASE:
      set_layer_color(_BASE);
      planck_ez_right_led_level(0);
      planck_ez_left_led_level(0);
      break;

    case _RAISE:
      set_layer_color(_RAISE);
      planck_ez_right_led_level(32);
      planck_ez_left_led_level(32);
      break;

    case _TOP:
      set_layer_color(_TOP);
      planck_ez_right_led_level(32);
      planck_ez_left_led_level(32);
      break;

    case _FUN:
      set_layer_color(_FUN);
      planck_ez_left_led_level(32);
      break;

    case _SYM:
      set_layer_color(_SYM);
      planck_ez_right_led_level(32);
      break;

   default:
      rgb_matrix_set_color_all(0, 0, 0);
      planck_ez_right_led_level(0);
      planck_ez_left_led_level(0);
    break;
  }

  if (locked_osm & MOD_MASK_SHIFT) {
    rgb_matrix_set_color(30, 238, 67, 67);
    rgb_matrix_set_color(24, 238, 67, 67); // KC_Z
    rgb_matrix_set_color(35, 238, 67, 67); // KC_SLSH
  } else if (osm & MOD_MASK_SHIFT) {
    rgb_matrix_set_color(30, 255, 255, 255);
    rgb_matrix_set_color(24, 255, 255, 255); // KC_Z
    rgb_matrix_set_color(35, 255, 255, 255); // KC_SLSH
  }

  if (locked_osm & MOD_MASK_CTRL) {
    rgb_matrix_set_color(29, 238, 67, 67);
    rgb_matrix_set_color(25, 238, 67, 67); // KC_X
    rgb_matrix_set_color(34, 238, 67, 67); // KC_DOT
  } else if (osm & MOD_MASK_CTRL) {
    rgb_matrix_set_color(29, 255, 255, 255);
    rgb_matrix_set_color(25, 255, 255, 255); // KC_X
    rgb_matrix_set_color(34, 255, 255, 255); // KC_DOT
  }

  if (locked_osm & MOD_MASK_ALT) {
    rgb_matrix_set_color(38, 238, 67, 67);
  } else if (osm & MOD_MASK_ALT) {
    rgb_matrix_set_color(38, 255, 255, 255);
  }

  if (locked_osm & MOD_MASK_GUI) {
    rgb_matrix_set_color(37, 238, 67, 67);
  } else if (osm & MOD_MASK_GUI) {
    rgb_matrix_set_color(37, 255, 255, 255);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool rc = true;
  uint8_t mods;

  if (record->event.pressed) {
    switch (keycode) {
      case KC_ESC:
        if ((mods = get_oneshot_mods()) && !has_oneshot_mods_timed_out()) {
          clear_oneshot_mods();
          unregister_mods(mods);
          rc = false;
        }

        if ((mods = get_oneshot_locked_mods())) {
          clear_oneshot_locked_mods();
          unregister_mods(mods);
          rc = false;
        }

        if (is_oneshot_layer_active()) {
          layer_clear();
          rc = false;
        }

        break;
    }
  }

  return rc;
}

