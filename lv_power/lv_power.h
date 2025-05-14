/**
 * @file lv_power.h
 *
 */

#ifndef LV_POWER_H
#define LV_POWER_H

#ifdef __cplusplus
extern "C" {
#endif

/*If "lv_conf.h" is available from here try to use it later.*/
#ifdef __has_include
#  if __has_include("lvgl.h")
#    ifndef LV_LVGL_H_INCLUDE_SIMPLE
#      define LV_LVGL_H_INCLUDE_SIMPLE
#    endif
#  endif
#endif

#ifdef __has_include
#  if __has_include("lv_power_conf.h")
#    ifndef LV_POWER_CONF_INCLUDE_SIMPLE
#      define LV_POWER_CONF_INCLUDE_SIMPLE
#    endif
#  endif
#endif

#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#else
#include "../lvgl/lvgl.h"
#endif

#if defined(LV_POWER_CONF_PATH)
#define __LV_TO_STR_AUX(x) #x
#define __LV_TO_STR(x) __LV_TO_STR_AUX(x)
#include __LV_TO_STR(LV_POWER_CONF_PATH)
#undef __LV_TO_STR_AUX
#undef __LV_TO_STR
#elif defined(LV_POWER_CONF_INCLUDE_SIMPLE)
#include "lv_power_conf.h"
#else
#include "../lv_power_conf.h"
#endif

#include "src/model/power_model.h"
#include "src/view/power_view.h"
#include "src/controller/power_controller.h"

#if LV_VERSION_CHECK(8, 0, 0) == 0
#error "lv_power: Wrong lvgl version"
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LV_POWER_H*/
