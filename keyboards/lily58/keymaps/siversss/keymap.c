
#include "siversss.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_wrapper(
		_____QWERTY_L1_____ ,                                           _____QWERTY_R1_____ ,
		_____QWERTY_L2_____ ,                                           _____QWERTY_R2_____ ,
		_____QWERTY_L3_____ ,                                           _____QWERTY_R3_____ ,
		_____QWERTY_L4_____ , KC_MUTE,             KC_MEDIA_PLAY_PAUSE, _____QWERTY_R4_____ ,
    KC_TURN_RGB, _____QWERTY_L_THUMB_____,    _____QWERTY_R_THUMB_____, KC_NO
  ),

  [_NAV] = LAYOUT_wrapper(
    _____NAV_L1_____ ,                                 _____NAV_R1_____ ,
		_____NAV_L2_____ ,                                 _____NAV_R2_____ ,
		_____NAV_L3_____ ,                                 _____NAV_R3_____ ,
		_____NAV_L4_____ , KC_NO,                   KC_NO, _____NAV_R4_____ ,
		       KC_NO, _____NAV_L_THUMB_____,   _____NAV_R_THUMB_____, KC_NO
  ),

  [_SYM] = LAYOUT_wrapper(
    _____SYM_L1_____ ,                                 _____SYM_R1_____ ,
		_____SYM_L2_____ ,                                 _____SYM_R2_____ ,
		_____SYM_L3_____ ,                                 _____SYM_R3_____ ,
		_____SYM_L4_____ , KC_NO,                   KC_NO, _____SYM_R4_____ ,
		       KC_NO, _____SYM_L_THUMB_____,   _____SYM_R_THUMB_____, KC_NO
	),

  [_SYST] = LAYOUT_wrapper(
    _____SYST_L1_____ ,                                 _____SYST_R1_____ ,
		_____SYST_L2_____ ,                                 _____SYST_R2_____ ,
		_____SYST_L3_____ ,                                 _____SYST_R3_____ ,
		_____SYST_L4_____ , KC_NO,                   KC_NO, _____SYST_R4_____ ,
		      KC_TRNS, _____SYST_L_THUMB_____,  _____SYST_R_THUMB_____, KC_RESET
	),

	[_RGB_LAYER] = LAYOUT_wrapper(
    _____RGB_L1_____ ,                                 _____RGB_R1_____ ,
		_____RGB_L2_____ ,                                 _____RGB_R2_____ ,
		_____RGB_L3_____ ,                                 _____RGB_R3_____ ,
		_____RGB_L4_____ , KC_NO,                   KC_NO, _____RGB_R4_____ ,
		      KC_NO, _____RGB_L_THUMB_____,  _____RGB_R_THUMB_____, KC_NO
	),

	[_HYPR_LAYER] = LAYOUT_wrapper(
    _____HYPR_L1_____ ,                                 _____HYPR_R1_____ ,
		_____HYPR_L2_____ ,                                 _____HYPR_R2_____ ,
		_____HYPR_L3_____ ,                                 _____HYPR_R3_____ ,
		_____HYPR_L4_____ , KC_NO,                   KC_NO, _____HYPR_R4_____ ,
		      KC_NO, _____HYPR_L_THUMB_____,  _____HYPR_R_THUMB_____, KC_NO
  )
};

#define DISABLE_SIVERSSS_LIGHT

void keyboard_post_init_user(void) {
#ifndef DISABLE_SIVERSSS_LIGHT
	rgblight_enable_noeeprom();
	rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
	rgblight_sethsv_noeeprom(0, 0, 0);
#endif
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifndef DISABLE_SIVERSSS_LIGHT
	if (keycode == KC_D) {
		if (record->event.pressed)
			/* rgblight_sethsv_at(50, 50, 50, 7); */
			rgblight_sethsv_range(50, 50, 50, 6, RGBLED_NUM - 1);
		else
			rgblight_sethsv_range(0,0,0, 6, RGBLED_NUM - 1);
		rgblight_set();
	}
#endif
	return true;
}

#ifdef OLED_DRIVER_ENABLE

const char *read_logo(void);

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

void oled_task_user(void) {
	if (is_keyboard_master()) {
		oled_write(read_logo(), false);
	} else {
		oled_write(read_logo(), false);
	}
}

#endif // OLED_DRIVER_ENABLE

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
					tap_code16(RSFT(RALT(KC_VOLU)));
        } else {
					tap_code16(RSFT(RALT(KC_VOLD)));
        }
    }
    else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_BRIGHTNESS_UP);
        } else {
            tap_code(KC_BRIGHTNESS_DOWN);
        }
    }
}
#endif
