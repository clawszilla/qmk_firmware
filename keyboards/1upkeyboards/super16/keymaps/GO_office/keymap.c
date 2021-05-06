#include QMK_KEYBOARD_H

enum layers {
 base,
 zbrush,
 test
};

enum custom_keycodes {
  COPY_SEL = SAFE_RANGE,
  PASTE_SEL,
  GO_ADMIN,
  MOVE_BRUSH,
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
       TO(base), TG(zbrush), TG(test), KC_DELETE,                           //kept for switching layers
       LSFT(KC_F5), LCTL(KC_C), LCTL(KC_V), KC_ENTER,                       //Refresh Page, Copy, Paste, Enter
       LSFT(LCTL(KC_DEL)), GO_ADMIN, LCTL(LSFT(KC_X)), LCTL(KC_S),          //Shfit+CTRL+DEL, ".\go-admin", Remote Paste, Save
       LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), LCTL(KC_T), KC_N                   //Prev Tab, Next Tab, N. Tab, N. Ticket
    ),
  [zbrush] = LAYOUT_ortho_4x4(
       TO(base), TG(zbrush), TG(test), KC_NO,                //kept for switching layers
       MOVE_BRUSH, CLAYB_BRUSH, CLAY_BRUSH, KC_NO,           //macros for brushes
       DAMSTAND_BRUSH, STAND_BRUSH, TRIMDYN_BRUSH, KC_NO,    //extra keys are empty
       HPOLISH_BRUSH, SPOLISH_BRUSH, SNAKEHK_BRUSH, KC_NO    //alt + key for zbrush cmd
    ),
  [test] = LAYOUT_ortho_4x4(
       TO(base), KC_2, KC_3, KC_4,                //kept for switching layers
       KC_A, KC_B, KC_C, KC_D,                    //sends the same key
       KC_E, KC_F, KC_G, KC_H,                    //to test each switch
       KC_I, KC_J, KC_K, KC_L                     //for proper signals
    )
};

/*
LCTL(kc)	Hold Left Control and press kc
LSFT(kc)	Hold Left Shift and press kc
LALT(kc)	Hold Left Alt and press kc
LGUI(kc)	Hold Left GUI and press kc
RCTL(kc)	Hold Right Control and press kc
RSFT(kc)	Hold Right Shift and press kc
RALT(kc)	Hold Right Alt and press kc
RGUI(kc)	Hold Right GUI and press kc
SGUI(kc)	Hold Left Shift and GUI and press kc
LCA(kc)		Hold Left Control and Alt and press kc
LCAG(kc)	Hold Left Control, Alt and GUI and press kc
MEH(kc)		Hold Left Control, Shift and Alt and press kc
HYPR(kc)	Hold Left Control, Shift, Alt and GUI and press kc
KC_MEH		Left Control, Shift and Alt
KC_HYPR		Left Control, Shift, Alt and GUI
*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case COPY_SEL:  //this is the keycode
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("c"));  // preses l_ctrl and then c to copy
            }
            return false;
        case PASTE_SEL:  //this is the keycode
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("v"));  // preses l_ctrl and then v to paste
            }
            return false;
        case GO_ADMIN:  //this is the keycode
            if (record->event.pressed) {
                SEND_STRING("."SS_TAP(X_BSLASH)"go-admin");  // enter local admin username
            }
            return false;
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
