#pragma once

#ifdef RGBLIGHT_ENABLE
  #undef RGBLED_NUM
  #define RGBLED_NUM 12

  #define RGBLIGHT_ANIMATIONS

  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8  
  #define RGBLIGHT_SLEEP //  the RGB lighting will be switched off when the host goes to sleep
#endif

#define MASTER_LEFT

#define NO_DEBUG
#define NO_PRINT

// #define RAW_EABLE

