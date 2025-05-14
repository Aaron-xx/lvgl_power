#include "power_view.h"
#include <stdio.h>

void power_view_init() {
    if(LV_HOR_RES <= 320) disp_size = DISP_SMALL;
    else if(LV_HOR_RES < 720) disp_size = DISP_MEDIUM;
    else disp_size = DISP_LARGE;

    font_large = LV_FONT_DEFAULT;
    font_normal = LV_FONT_DEFAULT;

    lv_coord_t tab_h;
    if(disp_size == DISP_LARGE) {
        tab_h = 70;
#if LV_FONT_MONTSERRAT_24
        font_large     =  &lv_font_montserrat_24;
#else
        LV_LOG_WARN("LV_FONT_MONTSERRAT_24 is not enabled for the widgets demo. Using LV_FONT_DEFAULT instead.");
#endif
#if LV_FONT_MONTSERRAT_16
        font_normal    =  &lv_font_montserrat_16;
#else
        LV_LOG_WARN("LV_FONT_MONTSERRAT_16 is not enabled for the widgets demo. Using LV_FONT_DEFAULT instead.");
#endif
    } else if(disp_size == DISP_MEDIUM) {
        tab_h = 45;
#if LV_FONT_MONTSERRAT_20
        font_large     =  &lv_font_montserrat_20;
#else
        LV_LOG_WARN("LV_FONT_MONTSERRAT_20 is not enabled for the widgets demo. Using LV_FONT_DEFAULT instead.");
#endif
#if LV_FONT_MONTSERRAT_14
        font_normal    =  &lv_font_montserrat_14;
#else
        LV_LOG_WARN("LV_FONT_MONTSERRAT_14 is not enabled for the widgets demo. Using LV_FONT_DEFAULT instead.");
#endif
    } else { /* disp_size == DISP_SMALL */
        tab_h = 45;
#if LV_FONT_MONTSERRAT_18
        font_large     =  &lv_font_montserrat_18;
#else
    LV_LOG_WARN("LV_FONT_MONTSERRAT_18 is not enabled for the widgets demo. Using LV_FONT_DEFAULT instead.");
#endif
#if LV_FONT_MONTSERRAT_12
        font_normal    =  &lv_font_montserrat_12;
#else
    LV_LOG_WARN("LV_FONT_MONTSERRAT_12 is not enabled for the widgets demo. Using LV_FONT_DEFAULT instead.");
#endif
    }

#if LV_USE_THEME_DEFAULT
    lv_theme_default_init(NULL, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), LV_THEME_DEFAULT_DARK, font_normal);
#endif
}

void power_view_create(PowerView* view, lv_obj_t* parent) {
    lv_obj_t* cont = lv_obj_create(parent);
    lv_obj_set_size(cont, LV_PCT(100), LV_PCT(100));
    // lv_obj_center(cont);
    lv_obj_set_flex_flow(cont, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(cont, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

    // 电压显示
    lv_obj_t* voltage_cont = lv_obj_create(cont);
    lv_obj_remove_style_all(voltage_cont);
    lv_obj_set_size(voltage_cont, LV_PCT(100), LV_SIZE_CONTENT);
    
    lv_obj_t* icon = lv_label_create(voltage_cont);
    lv_label_set_text(icon, LV_SYMBOL_BATTERY_FULL);
    view->voltage_label = lv_label_create(voltage_cont);
    lv_label_set_text_fmt(view->voltage_label, "%.2f V", 0.0f);
    lv_obj_align_to(view->voltage_label, icon, LV_ALIGN_OUT_RIGHT_MID, 10, 0);

    // 电流显示
    lv_obj_t* current_cont = lv_obj_create(cont);
    lv_obj_remove_style_all(current_cont);
    lv_obj_set_size(current_cont, LV_PCT(100), LV_SIZE_CONTENT);
    
    icon = lv_label_create(current_cont);
    lv_label_set_text(icon, LV_SYMBOL_CHARGE);
    view->current_label = lv_label_create(current_cont);
    lv_label_set_text_fmt(view->current_label, "%.2f A", 0.0f);
    lv_obj_align_to(view->current_label, icon, LV_ALIGN_OUT_RIGHT_MID, 10, 0);
}

void power_view_update(const PowerView* view, const PowerModel* model) {
    lv_label_set_text_fmt(view->voltage_label, "%.2f V", model->voltage);
    lv_label_set_text_fmt(view->current_label, "%.2f A", model->current);
}