#pragma once

#define ONESHOT_TAP_TOGGLE 2
#undef ONESHOT_TIMEOUT
#define ONESHOT_TIMEOUT 1000

#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD_PER_KEY
#define TAPPING_FORCE_HOLD

#undef TAPPING_TERM
#define TAPPING_TERM 175

#define COMBO_VARIABLE_LEN
#undef COMBO_TERM
#define COMBO_TERM 20

#define TAPPING_TOGGLE 1
