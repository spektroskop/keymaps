#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _LSFT, _RSFT,
    _LSYM, _RSYM,
    _FUN,
    _NOR,
};

enum keycodes {
    SELECT = SAFE_RANGE,
};

#define ___z___ _______
#define ___x___ XXXXXXX

#define CTL_X CTL_T(KC_X)
#define ALT_C ALT_T(KC_C)
#define GUI_V GUI_T(KC_V)

#define ESC_SYM LT(_RSYM, KC_ESC)
#define ESC_FUN LT(_FUN, KC_ESC)
#define ENT_SFT LT(_LSFT, KC_ENT)
#define RSYM TT(_RSYM)
#define TAB_SYM LT(_RSYM, KC_TAB)
#define TAB_FUN LT(_FUN, KC_TAB)
#define S_TAB S(KC_TAB)

#define GUI_M GUI_T(KC_M)
#define ALT_COM ALT_T(KC_COMM)
#define CTL_DOT CTL_T(KC_DOT)

#define BSP_SYM LT(_LSYM, KC_BSPC)
#define BSP_FUN LT(_FUN, KC_BSPC)
#define LSYM TT(_LSYM)
#define SPC_SFT LT(_RSFT, KC_SPC)
#define INS_SYM LT(_LSYM, KC_INS)
#define INS_FUN LT(_FUN, KC_INS)
#define S_INS S(KC_INS)

#define GUI_1 LGUI(KC_1)
#define GUI_2 LGUI(KC_2)
#define GUI_3 LGUI(KC_3)

#include "make_combos.h"

void set_led_levels(int left, int right) {
    planck_ez_left_led_level(left);
    planck_ez_right_led_level(right);
}

void process_combo_event(uint8_t combo_index, bool pressed) {
    switch(combo_index) {
    case RESET_COMBO:
        if (pressed) {
            set_led_levels(16, 16);
            reset_keyboard();
        }

        break;
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*---------------------------------------------------------------------------------------------*\
    |   q   `   w   ø   e   æ   r       t                       y       u   -   i   =   o   \   p   |  qp = reset
    |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    |   a   å   s  ins  d  esc  f  tab  g                       h  bsp  j   (   k   )   l   ;   '   |
    |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    |   z       x       c       v       b                       n       m       ,       .       /   |
    |          ctl     alt     gui                                     gui     alt     ctl          |
    |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    |                  esc     ent     tab                     bsp     spc     ins                  |
    |                  sym     sft     fun                     fun     sft     sym                  |
    \*---------------------------------------------------------------------------------------------*/

    [_BASE] = LAYOUT_planck_grid(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    ___x___, ___x___, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    ___x___, ___x___, KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT,
        KC_Z,    CTL_X,   ALT_C,   GUI_V,   KC_B,    ___x___, ___x___, KC_N,    GUI_M,   ALT_COM, CTL_DOT, KC_SLSH,
        ___x___, ___x___, ESC_SYM, ENT_SFT, TAB_FUN, ___x___, ___x___, BSP_FUN, SPC_SFT, INS_SYM, ___x___, ___x___
    ),

    /*---------------------------------------------------------------------------------------------*\
    |   Q   ~   W   Ø   E   Æ   R       T                       Y       U   _   I   +   O   |   P   |
    |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    |   A   Å   S s-ins D  esc  F s-tab G                       H  bsp  J   [   K   ]   L   :   "   |
    |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    |   Z       X       C       V       B                       N       M       <       >       ?   |
    |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    |                  esc     sym    s-tab                    bsp     sym    s-ins                 |
    \*---------------------------------------------------------------------------------------------*/

    [_LSFT] = LAYOUT_planck_grid(
        S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T), ___x___, ___x___, S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P),
        S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G), ___x___, ___x___, S(KC_H), S(KC_J), S(KC_K), S(KC_L), KC_DQUO,
        S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B), ___x___, ___x___, S(KC_N), S(KC_M), KC_LT,   KC_GT,   KC_QUES,
        ___x___, ___x___, KC_ESC,  ___z___, S_TAB,   ___x___, ___x___, KC_BSPC, LSYM,    S_INS,   ___x___, ___x___
    ),

    [_RSFT] = LAYOUT_planck_grid(
        S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T), ___x___, ___x___, S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P),
        S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G), ___x___, ___x___, S(KC_H), S(KC_J), S(KC_K), S(KC_L), KC_DQUO,
        S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B), ___x___, ___x___, S(KC_N), S(KC_M), KC_LT,   KC_GT,   KC_QUES,
        ___x___, ___x___, KC_ESC,  RSYM,    S_TAB,   ___x___, ___x___, KC_BSPC, ___z___, S_INS,   ___x___, ___x___
    ),

    /*---------------------------------------------------------------------------------------------*\
    |    !       @      #       $       %                       ^       &       *       {       }   |
    |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    |   1       2  ins  3  esc  4  tab  5                       6  bsp  7       8       9       0   |
    |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    |                                                                           ,       .           |
    |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    |                  esc     sym     tab                     bsp     sym     ins                  |
    \*---------------------------------------------------------------------------------------------*/

    [_LSYM] = LAYOUT_planck_grid(
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, ___x___, ___x___, KC_CIRC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    ___x___, ___x___, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ___x___, ___x___, XXXXXXX, XXXXXXX, KC_COMM, KC_DOT, XXXXXXX,
        ___x___, ___x___, KC_ESC,  ___z___, KC_TAB,  ___x___, ___x___, KC_BSPC, ___z___, KC_INS,  ___x___, ___x___
    ),

    [_RSYM] = LAYOUT_planck_grid(
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, ___x___, ___x___, KC_CIRC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    ___x___, ___x___, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ___x___, ___x___, XXXXXXX, XXXXXXX, KC_COMM, KC_DOT, XXXXXXX,
        ___x___, ___x___, KC_ESC,  ___z___, KC_TAB,  ___x___, ___x___, KC_BSPC, ___z___, KC_INS,  ___x___, ___x___
    ),

    /*---------------------------------------------------------------------------------------------*\
    |  f1      f2      f3      f4      f5                      f6      f7      f8      f9      f10  |
    |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    |  sel    home     pgup    pgdn    end                    left    down     up     right    sel  |
    |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    | gui1    gui2     gui3            f11                     f12            gui1     gui2   gui3  |
    |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    |                                                                                               |
    \*---------------------------------------------------------------------------------------------*/

    [_FUN] = LAYOUT_planck_grid(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   ___x___, ___x___, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        SELECT,  KC_HOME, KC_PGUP, KC_PGDN, KC_END,  ___x___, ___x___, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, SELECT,
        GUI_1,   GUI_2,   GUI_3,   XXXXXXX, KC_F11,  ___x___, ___x___, KC_F12,  XXXXXXX, GUI_1,   GUI_2,   GUI_3,
        ___x___, ___x___, XXXXXXX, XXXXXXX, ___z___, ___x___, ___x___, ___z___, XXXXXXX, XXXXXXX, ___x___, ___x___
    ),
};

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *recor) {
    switch (keycode) {
    default:
        return true;
    }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case BSP_FUN:
    case BSP_SYM:
        return false;
    default:
        return true;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case CTL_X:
    case ALT_C:
    case GUI_V:
    case GUI_M:
    case ALT_COM:
    case CTL_DOT:
        return false;
    default:
        return true;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    default:
        return TAPPING_TERM;
    }
}

void keyboard_post_init_user(void) {
    rgb_matrix_disable();
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _LSYM:
        set_led_levels(0, 16);
        break;

    case _RSYM:
        set_led_levels(16, 0);
        break;

    case _FUN:
        set_led_levels(16, 16);
        break;

    default:
        set_led_levels(0, 0);
    }

    return state;
}

bool select_hold = false;
bool sym_hold = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case RSYM:
    case LSYM:
        sym_hold = record->event.pressed;
        break;

    case ENT_SFT:
    case SPC_SFT:
        if (!sym_hold && !record->event.pressed) {
            if (layer_state_is(_LSYM)) {
                layer_off(_LSYM);
            } else if (layer_state_is(_RSYM)) {
                layer_off(_RSYM);
            }
        }
        break;

    case SELECT:
        if (record->event.pressed) {
            select_hold = true;
            register_code(KC_LGUI);
            tap_code(KC_GRV);
        }
        break;

    case ESC_FUN:
    case INS_FUN:
        if (!record->event.pressed) {
            if (select_hold) {
                select_hold = false;
                unregister_code(KC_LGUI);
            }
        }
        break;
    }

    return true;
}

