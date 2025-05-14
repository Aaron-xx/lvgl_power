#ifndef POWER_VIEW_H
#define POWER_VIEW_H

#ifdef __cplusplus
extern "C" {
#endif

#include <lvgl/lvgl.h>
#include "../model/power_model.h"
#include "../view/power_view.h"

typedef enum {
    DISP_SMALL,
    DISP_MEDIUM,
    DISP_LARGE,
} disp_size_t;

typedef struct {
    lv_obj_t* voltage_label;
    lv_obj_t* current_label;
} PowerView;

static disp_size_t disp_size;

static lv_obj_t * tv;
static lv_obj_t * calendar;
static lv_style_t style_text_muted;
static lv_style_t style_title;
static lv_style_t style_icon;
static lv_style_t style_bullet;

static const lv_font_t * font_large;
static const lv_font_t * font_normal;

void power_view_init();
void power_view_create(PowerView* view, lv_obj_t* parent);
void power_view_update(const PowerView* view, const PowerModel* model);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* POWER_VIEW_H */