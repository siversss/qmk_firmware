#pragma once
#include QMK_KEYBOARD_H

enum userspace_layers {
	_QWERTY = 0,
	_NAV,
	_SYM,
	_SYST,
	_RGB_LAYER
};

#define KC_SYM_A LT(_SYM, KC_SCLN)  // tap to ; | hold for sym layer
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
#define KC_RGUI_F14 RGUI_T(KC_F14)
#define KC_TURN_RGB MO(_RGB_LAYER)
#define KC_LSFT_S LSFT_T(KC_S) // tap for S, hold for left shift
#define KC_RSFT_L RSFT_T(KC_L) // tap for L, hold for right shift

#define _____QWERTY_L1_____          KC_ESC,    KC_1,      KC_2,      KC_3,    KC_4,    KC_5
#define _____QWERTY_L2_____          KC_TAB,    KC_Q,      KC_W,      KC_E,    KC_R,    KC_T
#define _____QWERTY_L3_____          KC_HYPR,   KC_NAV_A,  KC_LSFT_S, KC_D,    KC_LA_F, KC_G
#define _____QWERTY_L4_____          KC_EQL,    KC_LG_Z,   KC_X,      KC_C,    KC_V,    KC_B

#define _____QWERTY_R1_____          KC_6, KC_7    , KC_8    , KC_9      , KC_0       , KC_BSPC
#define _____QWERTY_R2_____          KC_Y, KC_U    , KC_I    , KC_O      , KC_P       , KC_QUOT
#define _____QWERTY_R3_____          KC_H, KC_LA_J , KC_K    , KC_RSFT_L , KC_SYM_A   , KC_HYPR
#define _____QWERTY_R4_____          KC_N, KC_M    , KC_COMM , KC_DOT    , KC_LG_SLSH , KC_MINS

#define _____QWERTY_L_THUMB_____     KC_RGUI_F13 , KC_LC_OR_SPC , KC_NO
#define _____QWERTY_R_THUMB_____     KC_NO       , KC_RC_OR_ENT , KC_RGUI_F14

#define _____NAV_L1_____ KC_NO , KC_F1 , KC_F2   , KC_F3 , KC_F4   , KC_F5 
#define _____NAV_L2_____ KC_NO , KC_NO , KC_NO   , KC_NO , KC_NO   , KC_NO 
#define _____NAV_L3_____ KC_NO , KC_NO , KC_LSFT , KC_NO , KC_LALT , KC_NO 
#define _____NAV_L4_____ KC_NO , KC_NO , KC_NO   , KC_NO , KC_NO   , KC_NO 

#define _____NAV_R1_____ KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10 , KC_F11
#define _____NAV_R2_____ KC_HOME , KC_PGUP , KC_UP   , KC_PGDN , KC_NO  , KC_F12
#define _____NAV_R3_____ KC_END  , KC_LEFT , KC_DOWN , KC_RGHT , KC_NO  , KC_NO 
#define _____NAV_R4_____ KC_NO   , KC_F16  , KC_F17  , KC_F18  , KC_NO  , KC_NO 

#define _____NAV_L_THUMB_____ KC_NO , KC_LCTL, KC_NO
#define _____NAV_R_THUMB_____ KC_NO , KC_RCTL, KC_NO

#define _____SYM_L1_____ KC_TLANG , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5
#define _____SYM_L2_____ KC_NO    , KC_NO   , KC_NO   , KC_NO   , KC_LBRC , KC_RBRC
#define _____SYM_L3_____ KC_NO    , KC_PIPE , KC_BSLS , KC_TILD , KC_LPRN , KC_RPRN
#define _____SYM_L4_____ KC_NO    , KC_NO   , KC_NO   , KC_GRV  , KC_LCBR , KC_RCBR

#define _____SYM_R1_____ KC_NO , KC_NO   , KC_NO , KC_NO   , KC_NO , KC_NO
#define _____SYM_R2_____ KC_NO , KC_NO   , KC_NO , KC_NO   , KC_NO , KC_NO
#define _____SYM_R3_____ KC_NO , KC_LALT , KC_NO , KC_RSFT , KC_NO , KC_NO
#define _____SYM_R4_____ KC_NO , KC_NO   , KC_NO , KC_NO   , KC_NO , KC_NO

#define _____SYM_L_THUMB_____ KC_NO , KC_LCTL , KC_NO
#define _____SYM_R_THUMB_____ KC_NO , KC_RCTL , KC_NO

#define _____6_NO_____ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO

#define _____SYST_L1_____ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_EEP_RST
#define _____SYST_L2_____ _____6_NO_____
#define _____SYST_L3_____ _____6_NO_____
#define _____SYST_L4_____ _____6_NO_____
		   
#define _____SYST_R1_____ _____6_NO_____
#define _____SYST_R2_____ _____6_NO_____
#define _____SYST_R3_____ KC_NO, KC_NO, KC_NO, KC_LOCK, KC_NO, KC_NO
#define _____SYST_R4_____ _____6_NO_____

#define _____SYST_L_THUMB_____ KC_NO , KC_NO, KC_NO
#define _____SYST_R_THUMB_____ KC_NO , KC_NO, KC_NO

#define _____RGB_L1_____ _____6_NO_____
#define _____RGB_L2_____ _____6_NO_____
#define _____RGB_L3_____ KC_NO, RGB_VAI, RGB_SAI, RGB_HUI, RGB_TOG, KC_NO
#define _____RGB_L4_____ KC_NO, RGB_VAD, RGB_SAD, RGB_HUD, RGB_MOD , KC_NO
		   
#define _____RGB_R1_____ _____6_NO_____
#define _____RGB_R2_____ _____6_NO_____
#define _____RGB_R3_____ _____6_NO_____
#define _____RGB_R4_____ _____6_NO_____

#define _____RGB_L_THUMB_____ KC_NO , KC_NO, KC_NO
#define _____RGB_R_THUMB_____ KC_NO , KC_NO, KC_NO

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)
