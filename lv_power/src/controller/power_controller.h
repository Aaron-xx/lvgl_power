#ifndef POWER_CONTROLLER_H
#define POWER_CONTROLLER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../model/power_model.h"
#include "../view/power_view.h"

typedef struct {
    PowerModel model;
    PowerView view;
} PowerController;

void power_controller_init(PowerController* ctrl, lv_obj_t* parent);
void power_controller_update(PowerController* ctrl);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* POWER_CONTROLLER_H */