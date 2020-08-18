#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _NAV 1
#define _SYM 2
#define _SYST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NAV,
  SYM,
  SYST
};

#define KC_SYM_A LT(_SYM, KC_SCLN)  // tap to ;, hold for sym layer
#define KC_NAV_A LT(_NAV, KC_A)     // tap to a, hold for nav layer
#define KC_LC_OR_SPC LCTL_T(KC_SPC) // tap to space, hold for left ctrl
#define KC_RC_OR_ENT RCTL_T(KC_ENT) // tap to enter, hold for right ctrl
#define KC_LG_Z LGUI_T(KC_Z)        // tap for Z, hold for left GUI
#define KC_LG_SLSH LGUI_T(KC_SLSH)  // tap for /, hold for left GUI
#define KC_LA_F LALT_T(KC_F)        // tap for f, hold for left alt
#define KC_LA_J LALT_T(KC_J)        // tap for j, hold for left alt
#define KC_TLANG LGUI(LALT(KC_SPC)) // osx, cycle languages
#define KC_RESET RESET
#define KC_TURN_SYST MO(_SYST)
#define KC_LOCK LGUI(LCTL(KC_Q))
#define KC_EEP_RST EEP_RST
#define KC_RGUI_F13 RGUI_T(KC_F13)

#define KC_LSFT_S LSFT_T(KC_S) // tap for S, hold for left shift
#define KC_RSFT_L RSFT_T(KC_L) // tap for L, hold for right shift

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc(
		//------+-------+---+---+------+----+                           +----+------+------+-----+---------+------+
			 ESC  , 1     , 2 , 3 , 4    , 5  ,                             6  , 7    , 8    , 9   , 0       , BSPC ,
		//------+-------+---+---+------+----+                           +----+------+------+-----+---------+------+
			 TAB  , Q     , W , E , R    , T  ,                             Y  , U    , I    , O   , P       , QUOT ,
		//------+-------+---+---+------+----+                           +----+------+------+-----+---------+------+
			 HYPR , NAV_A , LSFT_S , D , LA_F , G  ,                        H  , LA_J , K    , RSFT_L , SYM_A , HYPR ,
		//------+-------+---+---+------+----+-----------+   +-----------+----+------+------+-----+---------+------+
			 EQL  , LG_Z  , X , C , V    , B  , TURN_SYST ,     NO        , N  , M    , COMM , DOT , LG_SLSH , MINS ,
		//------+-------+---+---+------+-----------+----+   +-----+-----+----+------+------+-----+---------+------+
      					          RGUI_F13 , LC_OR_SPC , NO ,     NO  , RC_OR_ENT , NO
		//                  +----------+-----------+----+   +-----+-----------+-----+
  ),

  [_NAV] = LAYOUT_kc(
		//----+----+----+----+------+----+                 +------+------+------+------+-----+-----+
			 NO , F1 , F2 , F3 , F4   , F5 ,                   F6   , F7   , F8   , F9   , F10 , F11 ,
		//----+----+----+----+------+----+                 +------+------+------+------+-----+-----+
			 NO , NO , NO , NO , NO   , NO ,                   HOME , PGUP , UP   , PGDN , NO  , F12 ,
		//----+----+----+----+------+----+                 +------+------+------+------+-----+-----+
			 NO , NO , LSFT, NO, LALT , NO ,                   END  , LEFT , DOWN , RGHT , NO  , NO  ,
		//----+----+----+----+------+----+------+   +------+------+------+------+------+-----+-----+
			 NO , NO , NO , NO , NO   , NO , NO   ,     NO   , NO   , F16  , F17  , F18  , NO  , NO  ,
		//----+----+----+----+------+----+------+   +------+------+------+------+------+-----+-----+
													 NO   , LCTL, NO ,     NO , RCTL   , NO
		//                   +------+----+------+   +------+------+------+
  ),

  [_SYM] = LAYOUT_kc(
    //-------+------+------+------+------+------+                 +----+------+----+----+----+----+
       TLANG , F1   , F2   , F3   , F4   , F5   ,                   NO , NO   , NO , NO , NO , NO ,
    //-------+------+------+------+------+------+                 +----+------+----+----+----+----+
       NO    , NO   , NO   , NO   , LBRC , RBRC ,                   NO , NO   , NO , NO , NO , NO ,
    //-------+------+------+------+------+------+                 +----+------+----+----+----+----+
       NO    , PIPE , BSLS , TILD , LPRN , RPRN ,                   NO , LALT , NO , RSFT , NO , NO ,
    //-------+------+------+------+------+------+------+   +------+----+------+----+----+----+----+
       NO    , NO   , NO   , GRV  , LCBR , RCBR , NO   ,     NO   , NO , NO   , NO , NO , NO , NO ,
    //-------+------+------+------+------+------+------+   +------+----+------+----+----+----+----+
                                     NO  , LCTL   , NO ,     NO , RCTL , NO
    //                            +------+------+------+   +------+----+------+
	),

  [_SYST] = LAYOUT_kc(
    //----+----+----+----+----+---------+                  +----+----+----+------+----+-----
       NO , NO , NO , NO , NO , EEP_RST ,                    NO , NO , NO , NO   , NO , NO ,
    //----+----+----+----+----+---------+                  +----+----+----+------+----+-----
       NO , NO , NO , NO , NO , NO      ,                    NO , NO , NO , NO   , NO , NO ,
    //----+----+----+----+----+---------+                  +----+----+----+------+----+-----
       NO , NO , NO , NO , NO , NO      ,                    NO , NO , NO , LOCK , NO , NO ,
    //----+----+----+----+----+---------+------+   +-------+----+----+----+------+----+-----
       NO , NO , NO , NO , NO , NO      , TRNS ,     RESET , NO , NO , NO , NO   , NO , NO ,
    //----+----+----+----+----+---------+------+   +-------+----+----+----+------+----+-----
                           NO , NO      , NO   ,     NO    , NO , NO
    //                   +----+---------+------+   +-------+----+----+
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
