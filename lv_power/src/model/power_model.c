#include "power_model.h"

void power_model_init(PowerModel* model) {
    model->voltage = 0.0f;
    model->current = 0.0f;
}

void power_model_update(PowerModel* model) {
    model->voltage = 12.0f + (rand() % 100) * 0.1f;
    model->current = 2.0f + (rand() % 50) * 0.1f;
}