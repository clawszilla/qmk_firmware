#include "triplebox.h"

/*This is where you list any layers you want to be able to switch to with MO() or TG(). 
Then you add the keymap for each below following the same template as the ones existing.
You can have up to 32 differnt layers but they stack up and are influenced by the layer below it as well, 
similar to FN keys. https://docs.qmk.fm/#/keymap will have a detailed explanation of how they work.*/
enum layers {
 base,
 second
 };

/*This is where you define Macro names, which are equale to custom defined keys. 
You much have a case block for each name or the software won't compile, 
so only list the ones you are using right now.*/
enum custom_keycodes {
  PRINT_NAME = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[base] = KEYMAP(
		KC_1, KC_2, KC_3, KC_4,   //Row 1 Keys listed as they appear on the board for easy config.
		KC_Q, KC_W, KC_E, KC_5,   //Row 2
		KC_A, KC_S, KC_D, KC_LSHIFT),  //Row 3
	[second] = KEYMAP(
		KC_1, KC_2, KC_3, KC_4,   //Row 1 This is the keymap for the second layer.
		KC_5, KC_6, KC_7, KC_8,   //Row 2 It is currently unusable because there is no key set to switch layers.
		KC_9, KC_0, KC_1, KC_2),  //Row 3
};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

/*Each "case" below is a macro, called by names defined above  under "custom keycodes",
The content of the macro is within "SEND_STRING" anc an be lot sof different options.
More info and examples are avalible at https://docs.qmk.fm/#/feature_macros */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case PRINT_NAME:  //this is the keycode
            if (record->event.pressed) {
                SEND_STRING("This is for Triple Boxing");  // send text, or keystrokes, can also use combinations
            }
			return false;
	}
	return true;
}

/*This is for configuring the on board LEDs for the controllers, best not to change this. */
void led_set_user(uint8_t usb_led) {
	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
	} else {	}
	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
	} else {	}
	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
	} else {	}
	if (usb_led & (1 << USB_LED_COMPOSE)) {
	} else {	}
	if (usb_led & (1 << USB_LED_KANA)) {
	} else {	}
}
