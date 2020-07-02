#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _LSFT, _RSFT,
    _LSYM, _RSYM,
    _NAV,
};

enum {
    SELECT = SAFE_RANGE,
    ALT_TAB,
    GUI_TAB,
    CTL_TAB,
};

#define ___z___ _______

#define OS_LCTL OSM(MOD_LCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_LGUI OSM(MOD_LGUI)
#define OS_LSFT OSM(MOD_LSFT)

#define S_ENT S(KC_ENT)
#define S_TAB S(KC_TAB)
#define S_INS S(KC_INS)

#define GUI_1 LGUI(KC_1)
#define GUI_2 LGUI(KC_2)
#define GUI_3 LGUI(KC_3)

#include "make_combos.h"

void process_combo_event(uint8_t combo_index, bool pressed) {
    switch(combo_index) {
    case RESET_COMBO:
        if (pressed) {
            reset_keyboard();
        }

        break;
  }
}


#define CTL_A LCTL_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define GUI_D LGUI_T(KC_D)

#define GUI_K LGUI_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define CTL_QUOT LCTL_T(KC_QUOT)

#define NAV_Z LT(_NAV, KC_Z)
#define CTL_X LCTL_T(KC_X)
#define ALT_C LALT_T(KC_C)
#define GUI_V LGUI_T(KC_V)

#define GUI_M LGUI_T(KC_M)
#define ALT_COM LALT_T(KC_COMM)
#define CTL_DOT LCTL_T(KC_DOT)
#define NAV_SLS LT(_NAV, KC_SLSH)

#define OS_LALT OSM(MOD_LALT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_LGUI OSM(MOD_LGUI)
#define OS_RGUI OSM(MOD_RGUI)

#define SFT_ENT LT(_LSFT, KC_ENT)
#define SFT_BSP LT(_LSFT, KC_BSPC)
#define OS_RSYM OSL(_RSYM)

#define OS_LSYM OSL(_LSYM)
#define SFT_SPC LT(_RSFT, KC_SPC)

#define LSYM TT(_LSYM)
#define RSYM TT(_RSYM)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
    +---------------------------------------+       +---------------------------------------+
    |   q   `   w   ø   e   æ   r       t   |       |   y       u   -   i   =   o   \   p   |  qp = reset
    |-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------|
    |   a   å   s       d       f       g   |       |   h       j   (   k   )   l   ;   '   |
    |-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------|
    |   z       x       c       v       b   |       |   n       m       ,       .       /   |
    |  nav                                  |       |                                  nav  |
    |-------+-------+-------+-------+-------+       |-------+-------+-------+-------+-------|
                    |  esc     sym     ent  |       | spc     sym      bsp  |
                    |                  sft  |       | sft                   |
                    +-----------------------+       +-----------------------+
    */

    [_BASE] = LAYOUT_gergoplex(
        KC_Q,   KC_W,     KC_E,    KC_R,    KC_T,           KC_Y,    KC_U,      KC_I,    KC_O,    KC_P,
        KC_A,   KC_S,     KC_D,    KC_F,    KC_G,           KC_H,    KC_J,      KC_K,    KC_L,    KC_QUOT,
        NAV_Z,  KC_X,     KC_C,    KC_V,    KC_B,           KC_N,    KC_M,      KC_COMM, KC_DOT,  NAV_SLS,
                          OS_LALT, OS_RSYM, SFT_ENT,        SFT_SPC, OS_LSYM,   OS_LCTL
    ),

    [_LSFT] = LAYOUT_gergoplex(
        S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T),        S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P),
        S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G),        S(KC_H), S(KC_J), S(KC_K), S(KC_L), KC_DQUO,
        S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B),        S(KC_N), S(KC_M), KC_LT,   KC_GT,   KC_QUES,
                          OS_LALT, XXXXXXX, ___z___,        KC_BSPC, XXXXXXX, OS_LGUI
    ),

    [_RSFT] = LAYOUT_gergoplex(
        S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T),        S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P),
        S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G),        S(KC_H), S(KC_J), S(KC_K), S(KC_L), KC_DQUO,
        S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B),        S(KC_N), S(KC_M), KC_LT,   KC_GT,   KC_QUES,
                          OS_LGUI, XXXXXXX, KC_TAB,         ___z___, XXXXXXX, OS_LCTL
    ),

    [_LSYM] = LAYOUT_gergoplex(
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,        KC_CIRC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, KC_COMM, KC_DOT, XXXXXXX,
                          KC_ESC,  XXXXXXX, ___z___,        ___z___, XXXXXXX, KC_BSPC
    ),

    [_RSYM] = LAYOUT_gergoplex(
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,        KC_CIRC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, KC_COMM, KC_DOT, XXXXXXX,
                          KC_ESC,  XXXXXXX, ___z___,        ___z___, XXXXXXX, KC_BSPC
    ),

    [_NAV] = LAYOUT_gergoplex(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,          KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN, KC_END,         KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
        ___z___, GUI_1,   GUI_2,   GUI_3,   SELECT,         SELECT,  GUI_TAB, ALT_TAB, CTL_TAB, ___z___,
                          KC_F11,  S_INS,   KC_LSFT,        KC_RSFT, S_INS,   KC_F12
    ),
};

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *recor) {
    switch (keycode) {
    case NAV_Z:
    case NAV_SLS:
        return false;
    default:
        return true;
    }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case SFT_BSP:
        return false;
    default:
        return true;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    default:
        return true;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case SFT_ENT:
    case SFT_BSP:
    case SFT_SPC:
        return 175;
    default:
        return TAPPING_TERM;
    }
}

bool select_hold = false;
bool sym_hold = false;
bool gui_tab = false;
bool alt_tab = false;
bool ctl_tab = false;

void activate_ctl_tab(void) {
    ctl_tab = true;
    register_code(KC_LCTL);
    tap_code(KC_TAB);
}

void deactivate_ctl_tab(void) {
    ctl_tab = false;
    unregister_code(KC_LCTL);
}

void activate_alt_tab(void) {
    alt_tab = true;
    register_code(KC_LALT);
    tap_code(KC_TAB);
}

void deactivate_alt_tab(void) {
    alt_tab = false;
    unregister_code(KC_LALT);
}

void activate_gui_tab(void) {
    gui_tab = true;
    register_code(KC_LGUI);
    tap_code(KC_TAB);
}

void deactivate_gui_tab(void) {
    gui_tab = false;
    unregister_code(KC_LGUI);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case SELECT:
        if (record->event.pressed) {
            select_hold = true;
            register_code(KC_LGUI);
            tap_code(KC_GRV);
        }
        break;


    case ALT_TAB:
        if (record->event.pressed) {
            if (ctl_tab) {
                deactivate_ctl_tab();
                activate_alt_tab();
            } else if (gui_tab) {
                deactivate_gui_tab();
                activate_alt_tab();
            } else if (alt_tab) {
                tap_code(KC_TAB);
            } else {
                activate_alt_tab();
            }
        }
        break;

    case CTL_TAB:
        if (record->event.pressed) {
            if (alt_tab) {
                deactivate_alt_tab();
                activate_ctl_tab();
            } else if (gui_tab) {
                deactivate_gui_tab();
                activate_ctl_tab();
            } else if (ctl_tab) {
                tap_code(KC_TAB);
            } else {
                activate_ctl_tab();
            }
        }
        break;

    case GUI_TAB:
        if (record->event.pressed) {
            if (ctl_tab) {
                deactivate_ctl_tab();
                activate_gui_tab();
            } else if (alt_tab) {
                deactivate_alt_tab();
                activate_gui_tab();
            } else if (gui_tab) {
                tap_code(KC_TAB);
            } else {
                activate_gui_tab();
            }
        }
        break;

    case NAV_Z:
    case NAV_SLS:
        if (!record->event.pressed) {
            if (select_hold) {
                select_hold = false;
                unregister_code(KC_LGUI);
            }

            if (alt_tab) {
                deactivate_alt_tab();
            }

            if (ctl_tab) {
                deactivate_ctl_tab();
            }

            if (gui_tab) {
                deactivate_gui_tab();
            }
        }
        break;

    case RSYM:
    case LSYM:
        sym_hold = record->event.pressed;
        break;

    case SFT_ENT:
    case SFT_BSP:
    case SFT_SPC:
        if (!sym_hold && !record->event.pressed) {
            if (layer_state_is(_LSYM)) {
                layer_off(_LSYM);
            } else if (layer_state_is(_RSYM)) {
                layer_off(_RSYM);
            }
        }
        break;

    case KC_ESC:
        if (record->event.pressed) {
            bool rc = true;
            uint8_t mods = 0;
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

            return rc;
        }
    }

    return true;
}
