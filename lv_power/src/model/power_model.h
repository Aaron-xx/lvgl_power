#ifndef POWER_MODEL_H
#define POWER_MODEL_H

#ifdef __cplusplus
extern "C" {
#endif

// #include "../../lv_power.h"
#include "../model/power_model.h"

typedef struct {
    float voltage;
    float current;
} PowerModel;

void power_model_init(PowerModel* model);
void power_model_update(PowerModel* model);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* POWER_MODEL_H */