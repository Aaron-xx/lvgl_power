#include "power_controller.h"

void power_controller_init(PowerController* ctrl, lv_obj_t* parent) {
    power_model_init(&ctrl->model);
    power_view_init();
    power_view_create(&ctrl->view, parent);
}

void power_controller_update(PowerController* ctrl) {
    power_model_update(&ctrl->model);
    power_view_update(&ctrl->view, &ctrl->model);
}