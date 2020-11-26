
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
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }

    return rotation;
}

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // Version information
    oled_write_P(PSTR("Lily58L rev1.0\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
		/*
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }
		*/

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_logo();  // Renders a static logo
        // oled_scroll_left();  // Turns on scrolling
    }
}
#endif

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
