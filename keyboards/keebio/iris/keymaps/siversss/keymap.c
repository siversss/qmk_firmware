#include "siversss.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_wrapper(
		_____QWERTY_L1_____ ,                                  _____QWERTY_R1_____ ,
		_____QWERTY_L2_____ ,                                  _____QWERTY_R2_____ ,
		_____QWERTY_L3_____ ,                                  _____QWERTY_R3_____ ,
		_____QWERTY_L4_____ , KC_TURN_SYST,             KC_NO, _____QWERTY_R4_____ ,
               _____QWERTY_L_THUMB_____,    _____QWERTY_R_THUMB_____
  ),

  [_NAV] = LAYOUT_wrapper(
    _____NAV_L1_____ ,                                 _____NAV_R1_____ ,
		_____NAV_L2_____ ,                                 _____NAV_R2_____ ,
		_____NAV_L3_____ ,                                 _____NAV_R3_____ ,
		_____NAV_L4_____ , KC_NO,                   KC_NO, _____NAV_R4_____ ,
		            _____NAV_L_THUMB_____,   _____NAV_R_THUMB_____										 
  ),

  [_SYM] = LAYOUT_wrapper(
    _____SYM_L1_____ ,                                 _____SYM_R1_____ ,
		_____SYM_L2_____ ,                                 _____SYM_R2_____ ,
		_____SYM_L3_____ ,                                 _____SYM_R3_____ ,
		_____SYM_L4_____ , KC_NO,                   KC_NO, _____SYM_R4_____ ,
		            _____SYM_L_THUMB_____,   _____SYM_R_THUMB_____
	),

  [_SYST] = LAYOUT_wrapper(
    _____SYST_L1_____ ,                                   _____SYST_R1_____ ,
		_____SYST_L2_____ ,                                   _____SYST_R2_____ ,
		_____SYST_L3_____ ,                                   _____SYST_R3_____ ,
		_____SYST_L4_____ , KC_TRNS,                KC_RESET, _____SYST_R4_____ ,
		             _____SYST_L_THUMB_____,  _____SYST_R_THUMB_____
	)
};

void keyboard_post_init_user(void) {
	/* debug_enable=true; */
  /* debug_matrix=true; */
  /* debug_keyboard=true; */
	
	/* rgblight_sethsv_noeeprom(0, 255, 255); */
	/* rgblight_disable_noeeprom(); */
	//rgblight_disable_noeeprom();
}

uint32_t layer_state_set_user(uint32_t state) {
	switch (biton32(state)) {
		case _SYST:
			/* rgblight_enable_noeeprom(); */
			rgblight_sethsv_noeeprom(0, 255, 255);
			break;
		default:
			//rgblight_disable_noeeprom();
			rgblight_sethsv_noeeprom(128, 255, 0);
			break;
	}
	return state;
};
