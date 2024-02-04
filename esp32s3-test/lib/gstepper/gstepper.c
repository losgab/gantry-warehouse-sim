#include "gstepper.h"

esp_err_t gstepper_init(gstepper_t stepper, gpio_num_t step_pin, gpio_num_t dir_pin, uint8_t step_resolution)
{
    stepper = malloc(sizeof(gstepper));

    stepper->step_pin = step_pin;
    stepper->dir_pin = dir_pin;
    stepper->step_resolution = step_resolution;
    stepper->curr_pos = 0;
    stepper->target_pos = 0;
    stepper->pos_error = 0;
    return ESP_OK;
}

float convert_to_gstepper_angle(int target_angle, uint8_t step_resolution)
{
    return (target_angle + error[step_resolution][target_angle % 9]);
}

float gstepper_angle_steps_required(float converted_gstepper_angle, uint8_t step_resolution)
{
    return (unsigned int)(converted_gstepper_angle / step_resolution);
}