#include "gstepper.h"

esp_err_t gstepper_init(gstepper_t stepper)
{
    return ESP_OK;
}

float convert_to_gstepper_angle(int target_angle, float step_resolution)
{
    uint8_t mod = target_angle % 9;
    float error = (mod > 5) ? -error[mod] : error[9 - mod];
    return target_angle + error
}

float gstepper_angle_steps_required(float converted_gstepper_angle, float step_resolution)
{
    return (float)(((uint16_t)((converted_gstepper_angle / step_resolution) * 10)) / 10);
}