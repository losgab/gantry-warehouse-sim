/**
 * Stepper Driver Library for controlling stepper motors like a servo motor in the ESP-IDF.
 * 
 * Based on the Remote Control functionality of the ESP-IDF as a pulse generator for controlling
 * STEP/DIR control interfaces on stepper drivers such as the A4988, TMC2208, etc.
 * 
 * Goals: 
 * - Provide software-based acceleration and velocity ramp control for stepper motors.
 * - Move stepper motors to a desired angle (roughly).
 * 
 * 
 * @author Gabriel Thien (https://github.com/losgab)
*/
#pragma once

#include <math.h>
#include <esp_err.h>
#include <driver/gpio.h>

#define FULL_STEP_RESOLUTION 1.8
#define HALF_STEP_RESOLUTION 0.9
#define QTER_STEP_RESOLUTION 0.45

typedef struct gstepper {
    uint16_t step_pin;
    uint8_t dir_pin;
    float step_resolution;
    float curr_pos;
    float target_pos;
    float pos_error;
} gstepper;
typedef gstepper* gstepper_t;

// Discrete Target & Stepper Angle Errors
const float error[9] = {0, -0.1, -0.2, -0.3, -0.4, 0.4, 0.3, 0.2, 0.1};

/**
 * Initialize the stepper driver.
 * 
 * @param stepper Pointer to the configuration structure
 * 
 * @return ESP_OK on success, ESP_FAIL on failure.
*/
esp_err_t gstepper_init(gstepper_t stepper, gpio_num_t step_pin, gpio_num_t dir_pin, float step_resolution);

/**
 * Converts the target angle to the closest stepper angle that can be reached with current resolution config
 * 
 * @param target_angle Target angle (degrees)
 * @param step_resolution Step Resolution
 *
 * @return Converted gstepper angle
*/
float convert_to_gstepper_angle(int target_angle, float step_resolution);

/**
 * Calculates the number of steps required to reach the converted gstepper angle
 * 
 * @param converted_gstepper_angle Converted gstepper angle
 * @param step_resolution Step Resolution
 * 
 * @return Number of steps required to reach the converted gstepper angle
*/
float gstepper_angle_steps_required(float converted_gstepper_angle, float step_resolution);