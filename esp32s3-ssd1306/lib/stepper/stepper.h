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

#define FULL_STEP 1.8
#define HALF_STEP 0.9
#define QTER_STEP 0.45

typedef struct gstepper_config {
    uint16_t step_pin;
    uint8_t dir_pin;
    float step_resolution;
    float curr_pos;
    float target_pos;
    float pos_error;
} gstepper_config;
typedef gstepper_config* gstepper_t;

/**
 * Initialize the stepper driver.
 * 
 * @param stepper Pointer to the configuration structure
 * 
 * @return ESP_OK on success, ESP_FAIL on failure.
*/
static esp_err_t esp_gstepper_init(gstepper_t stepper);

/**
 * Converts the target angle to the closest stepper angle that can be reached with current resolution config
 * 
 * @param target_angle Target angle (degrees)
 * @param step_resolution Step Resolution
 *
 * @return Converted gstepper angle
*/
static float convert_to_gstepper_angle(float target_angle, float step_resolution);

/**
 * Calculates the number of steps required to reach the converted gstepper angle
 * 
 * @param converted_gstepper_angle Converted gstepper angle
 * @param step_resolution Step Resolution
 * 
 * @return Number of steps required to reach the converted gstepper angle
*/
static float gstepper_angle_steps_required(float converted_gstepper_angle, float step_resolution);