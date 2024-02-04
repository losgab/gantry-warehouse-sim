#include "gstepper.h"

esp_err_t gstepper_init(gstepper_t stepper, gpio_num_t step_pin, gpio_num_t dir_pin, float step_resolution)
{
    stepper = malloc(sizeof(gstepper));

    stepper->step_pin = step_pin;
    stepper->dir_pin = dir_pin;
    stepper->step_resolution = 0.9;
    stepper->curr_pos = 0;
    stepper->target_pos = 0;
    stepper->pos_error = 0;
    return ESP_OK;
}

float convert_to_gstepper_angle(int target_angle, float step_resolution)
{
    return (target_angle + error[target_angle % 9]);
}

float gstepper_angle_steps_required(float converted_gstepper_angle, float step_resolution)
{
    return (unsigned int)(converted_gstepper_angle / step_resolution);
}