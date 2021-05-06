The correct code to run to compile and flash is:

$ cd qmk_firmware //to get into the correct directory

$ make claws_studios/super16:office:avrdude

-----------------------------------------------------
[Setting Up A Macro]

include each new keycode

enum custom_keycodes {
  COPY_SEL = SAFE_RANGE,
  PASTE_SEL
};

then for the actual macro functions follow the standard

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case COPY_SEL:  //this is the keycode for the first macro
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("c"));  // preses l_ctrl and then c to copy
            }
            return false;
        case PASTE_SEL:  //this is the keycode for another macro
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("v"));  // preses l_ctrl and then v to paste
            }
            return false;
            break;
    }
    return true;
}

SAVED FOR POSSIBLE USE:
[rgb] = LAYOUT_ortho_4x4(
       TO(base), TG(zbrush), TG(test), TG(rgb),   //kept for switching layers
       RGB_HUI, RGB_SAI, RGB_VAI, KC_NO,          //hue+, sat+, val+, na
       RGB_HUD, RGB_SAD, RGB_VAD, KC_NO,          //hue-, sat-, val-, na
       RGB_M_P, RGB_M_R, RGB_M_B, KC_NO           //static, rainbow, breathe, na
    )