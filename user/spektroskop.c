#include QMK_KEYBOARD_H
#include "spektroskop.h"

bool gui_tab_active = false;
bool alt_tab_active = false;
bool ctl_tab_active = false;
bool sym_hold = false;

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case FUN_Z:
    case FUN_SLS:
    case LT_LSFT:
    case LT_RSFT:
      return false;
    default:
        return true;
    }
}

bool is_release(keyrecord_t *record) {
  return !record->event.pressed;
}

bool is_press(keyrecord_t *record) {
  return record->event.pressed;
}

void activate_ctl_tab(void) {
    ctl_tab_active = true;
    register_code(KC_LCTL);
    tap_code(KC_TAB);
}

void deactivate_ctl_tab(void) {
    ctl_tab_active = false;
    unregister_code(KC_LCTL);
}

void activate_alt_tab(void) {
    alt_tab_active = true;
    register_code(KC_LALT);
    tap_code(KC_TAB);
}

void deactivate_alt_tab(void) {
    alt_tab_active = false;
    unregister_code(KC_LALT);
}

void activate_gui_tab(void) {
    gui_tab_active = true;
    register_code(KC_LGUI);
    tap_code(KC_TAB);
}

void deactivate_gui_tab(void) {
    gui_tab_active = false;
    unregister_code(KC_LGUI);
}

void deactivate_tabs(keyrecord_t *record) {
  if (is_release(record)) {
    if (alt_tab_active) deactivate_alt_tab();
    if (ctl_tab_active) deactivate_ctl_tab();
    if (gui_tab_active) deactivate_gui_tab();
  }
}

void activate_tabs(uint16_t keycode, keyrecord_t *record) {
  if (is_press(record)) {
    if (keycode == GUI_TAB) {
      if (ctl_tab_active) {
          deactivate_ctl_tab();
          activate_gui_tab();
      } else if (alt_tab_active) {
          deactivate_alt_tab();
          activate_gui_tab();
      } else if (gui_tab_active) {
          tap_code(KC_TAB);
      } else {
          activate_gui_tab();
      }
    } else if (keycode == ALT_TAB)  {
      if (ctl_tab_active) {
          deactivate_ctl_tab();
          activate_alt_tab();
      } else if (gui_tab_active) {
          deactivate_gui_tab();
          activate_alt_tab();
      } else if (alt_tab_active) {
          tap_code(KC_TAB);
      } else {
          activate_alt_tab();
      }
    } else if (keycode == CTL_TAB) {
      if (alt_tab_active) {
          deactivate_alt_tab();
          activate_ctl_tab();
      } else if (gui_tab_active) {
          deactivate_gui_tab();
          activate_ctl_tab();
      } else if (ctl_tab_active) {
          tap_code(KC_TAB);
      } else {
          activate_ctl_tab();
      }
    }
  }
}

void handle_sft_sym(uint16_t keycode, keyrecord_t *record) {
  if (keycode == TT_LSYM || keycode == TT_RSYM) {
    sym_hold = record->event.pressed;
  } else if (keycode == LT_LSFT || keycode == LT_RSFT) {
    if (is_release(record) && !sym_hold) {
      layer_off(_LSYM);
      layer_off(_RSYM);
    }
  }
}

bool clear_oneshots(keyrecord_t *record) {
  bool r = true;
  uint8_t mods = 0;
  if ((mods = get_oneshot_mods()) && !has_oneshot_mods_timed_out()) {
    clear_oneshot_mods();
    unregister_mods(mods);
    r = false;
  }

  if ((mods = get_oneshot_locked_mods())) {
    clear_oneshot_locked_mods();
    unregister_mods(mods);
    r = false;
  }

  if (is_oneshot_layer_active()) {
    layer_clear();
    r = false;
  }

  return r;
}
