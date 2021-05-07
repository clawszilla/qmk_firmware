#include QMK_KEYBOARD_H

enum layers {
 base,         // 0
 zbrush,       // 1
 blender,      // 2
 lightrm       // 3
};

enum custom_keycodes {
  MOVE_BRUSH = SAFE_RANGE,
  CLAYB_BRUSH,
  CLAY_BRUSH,
  STAND_BRUSH,
  DAMSTAND_BRUSH,
  HPOLISH_BRUSH,
  SPOLISH_BRUSH,
  TRIMDYN_BRUSH,
  SNAKEHK_BRUSH
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [base] = LAYOUT_ortho_4x4(
       TO(base), TG(zbrush), TG(blender), KC_NO,
       TG(lightrm), LCTL(KC_C), LCTL(KC_V), KC_ENTER,
       KC_NO, KC_LSHIFT, KC_NO, KC_NO,
       KC_LCTRL, KC_LGUI, KC_LALT, KC_DELETE
    ),
/* base
* ,---------------------------------------.
* | BASE    | zbrush  | blender |         |
* |---------+---------+---------+---------|
* | lightrm | copy    | paste   | ENTER   |
* |---------+---------+---------+---------|
* |         | SHIFT   |         |         |
* |---------+---------+---------+---------|
* | CTRL    | WINDOWS | ALT     | DEL     |
* `---------------------------------------'
*/
  [zbrush] = LAYOUT_ortho_4x4(
       TO(base), TG(zbrush), TG(blender), KC_NO,             //base, zbrush, maya, NA
       MOVE_BRUSH, CLAYB_BRUSH, CLAY_BRUSH, KC_NO,           //macros for brushes
       DAMSTAND_BRUSH, STAND_BRUSH, TRIMDYN_BRUSH, KC_NO,    //extra keys are empty
       HPOLISH_BRUSH, SPOLISH_BRUSH, SNAKEHK_BRUSH, KC_NO    //alt + key
    ),
/* zbrush
* ,---------------------------------------.
* | BASE    | Zbrush  | blender |         |
* |---------+---------+---------+---------|
* | Move    | Clay B  | Clay    |         |
* |---------+---------+---------+---------|
* | Dam St  | Stand   | Trim D  |         |
* |---------+---------+---------+---------|
* | H Polish| S Polish| Snake H |         |
* `---------------------------------------'
*/
  [blender] = LAYOUT_ortho_4x4(   //<------ FIX ME!
       TO(base), TG(zbrush), TG(blender), KC_NO,    //base, zbrush, maya, NA
       LSFT(KC_I), LCTL(KC_D), KC_J, KC_G,          //Isolate, Duplicate, Snap, Repeat
       KC_5, KC_4, KC_KP_3, KC_KP_1,                //shaded, wirefram, smooth prv, no smooth prv
       KC_NO, KC_NO, LCTL(KC_S), LCTL(KC_G)         //na, na, save, Group
    ),
/* blender <------ FIX ME!
* ,---------------------------------------.
* | BASE    | Zbrush  | blender |         |
* |---------+---------+---------+---------|
* |         |         |         |         |
* |---------+---------+---------+---------|
* |         |         |         |         |
* |---------+---------+---------+---------|
* |         |         |         |         |
* `---------------------------------------'
*/
  [lightrm] = LAYOUT_ortho_4x4(
       TO(base), TG(zbrush), TG(blender), KC_NO,       //base, zbrush, maya, NA
       KC_P, KC_X, KC_U, KC_NO,                        //pick, reject, unflag, na
       KC_1, KC_3, KC_5, KC_NO,                        //1 str, 3 str, 5 str, na
       KC_NO, KC_NO, KC_NO, KC_NO                      //na, na, na, na
    )
/* lightrm
* ,---------------------------------------.
* | BASE    | Zbrush  | blender |         |
* |---------+---------+---------+---------|
* | Pick    | Reject  | Un Flag |         |
* |---------+---------+---------+---------|
* | 1 Star  | 3 Star  | 5 Star  |         |
* |---------+---------+---------+---------|
* |         |         |         |         |
* `---------------------------------------'
*/
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MOVE_BRUSH:  //this is the keycode
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("m"));  // preses alt + key
            }
            return false;
        case CLAYB_BRUSH:  //this is the keycode
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("b"));  // preses alt + key
            }
            return false;
        case CLAY_BRUSH:  //this is the keycode
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("c"));  // preses alt + key
            }
            return false;
        case STAND_BRUSH:  //this is the keycode
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("s"));  // preses alt + key
            }
            return false;
        case DAMSTAND_BRUSH:  //this is the keycode
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("d"));  // preses alt + key
            }
            return false;
        case HPOLISH_BRUSH:  //this is the keycode
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("h"));  // preses alt + key
            }
            return false;
        case SPOLISH_BRUSH:  //this is the keycode
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("p"));  // preses alt + key
            }
            return false;
        case TRIMDYN_BRUSH:  //this is the keycode
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("t"));  // preses alt + key
            }
            return false;
        case SNAKEHK_BRUSH:  //this is the keycode
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("x"));  // preses alt + key
            }
            return false;
            break;
    }
    return true;
}

/*
SAVED KEYMAPS
 [maya] = LAYOUT_ortho_4x4(
       TO(base), TG(zbrush), TG(maya), KC_DELETE,   //active ground, active zbrush, active maya, delete
       LSFT(KC_I), LCTL(KC_D), KC_J, KC_G,          //Isolate, Duplicate, Snap, Repeat
       KC_5, KC_4, KC_KP_3, KC_KP_1,                //shaded, wirefram, smooth prv, no smooth prv
       KC_NO, KC_NO, LCTL(KC_S), LCTL(KC_G)         //na, na, save, Group
*/
