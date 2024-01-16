#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/queue.h>
#include <freertos/timers.h>
#include <driver/rmt_tx.h>

// Communication Protocols
#include <driver/uart.h>
#include <driver/i2c.h>
#include <driver/gpio.h>

#include "esp_log.h"

#include <stdio.h>

#define SYS_DELAY(x) vTaskDelay(pdMS_TO_TICKS(x))

// Stepper Driver Definitions
#define STEPPER_EN GPIO_NUM_4
#define STEPPER_DIR GPIO_NUM_5
#define STEPPER_STEP GPIO_NUM_6
#define STEPPER_PINS_BITMASK (1ULL << STEPPER_EN | 1ULL << STEPPER_DIR | 1ULL << STEPPER_STEP)
#define STEP_MOTOR_ENABLE_LEVEL 0
#define STEP_MOTOR_SPIN_DIR_CLOCKWISE 0
#define STEP_MOTOR_SPIN_DIR_COUNTERCLOCKWISE !STEP_MOTOR_SPIN_DIR_CLOCKWISE
#define STEP_MOTOR_RESOLUTION_HZ 1000000 // 1 MHz

// GPIO Setup
gpio_config_t stepper_config = {
    .pin_bit_mask = STEPPER_PINS_BITMASK,
    .mode = GPIO_MODE_OUTPUT,
    .pull_up_en = GPIO_PULLUP_DISABLE,
    .pull_down_en = GPIO_PULLDOWN_DISABLE,
    .intr_type = GPIO_INTR_DISABLE,
};

// RMT Channel Create
rmt_channel_handle_t motor_chan = NULL;
rmt_tx_channel_config_t tx_chan_config = {
    .clk_src = RMT_CLK_SRC_DEFAULT, // select clock source
    .gpio_num = STEPPER_STEP,       // set GPIO number
    .mem_block_symbols = 64,
    .resolution_hz = STEP_MOTOR_RESOLUTION_HZ,
    .trans_queue_depth = 10, // set the number of transactions that can be pending in the background
};

static const char *TAG = "Stepper Control";

void app_main()
{
    // ESP_LOGI(TAG, "Initialize EN + DIR GPIO");
    // ESP_ERROR_CHECK(gpio_config(&stepper_config));

    // ESP_LOGI(TAG, "Create RMT TX channel");
    // ESP_ERROR_CHECK(rmt_new_tx_channel(&tx_chan_config, &motor_chan));

    // SP_LOGI(TAG, "Set spin direction");
    // gpio_set_level(STEPPER_DIR, STEP_MOTOR_SPIN_DIR_CLOCKWISE);
    // ESP_LOGI(TAG, "Enable step motor");
    // gpio_set_level(STEPPER_EN, STEP_MOTOR_ENABLE_LEVEL);

    // ESP_LOGI(TAG, "Create motor encoders");
    // stepper_motor_curve_encoder_config_t accel_encoder_config = {
    //     .resolution = STEP_MOTOR_RESOLUTION_HZ,
    //     .sample_points = 500,
    //     .start_freq_hz = 500,
    //     .end_freq_hz = 1500,
    // };
    // rmt_encoder_handle_t accel_motor_encoder = NULL;
    // ESP_ERROR_CHECK(rmt_new_stepper_motor_curve_encoder(&accel_encoder_config, &accel_motor_encoder));

    // stepper_motor_uniform_encoder_config_t uniform_encoder_config = {
    //     .resolution = STEP_MOTOR_RESOLUTION_HZ,
    // };
    // rmt_encoder_handle_t uniform_motor_encoder = NULL;
    // ESP_ERROR_CHECK(rmt_new_stepper_motor_uniform_encoder(&uniform_encoder_config, &uniform_motor_encoder));

    // stepper_motor_curve_encoder_config_t decel_encoder_config = {
    //     .resolution = STEP_MOTOR_RESOLUTION_HZ,
    //     .sample_points = 500,
    //     .start_freq_hz = 1500,
    //     .end_freq_hz = 500,
    // };
    // rmt_encoder_handle_t decel_motor_encoder = NULL;
    // ESP_ERROR_CHECK(rmt_new_stepper_motor_curve_encoder(&decel_encoder_config, &decel_motor_encoder));

    // ESP_LOGI(TAG, "Enable RMT channel");
    // ESP_ERROR_CHECK(rmt_enable(motor_chan));

    // ESP_LOGI(TAG, "Spin motor for 6000 steps: 500 accel + 5000 uniform + 500 decel");
    // rmt_transmit_config_t tx_config = {
    //     .loop_count = 0,
    // };

    // const static uint32_t accel_samples = 500;
    // const static uint32_t uniform_speed_hz = 1500;
    // const static uint32_t decel_samples = 500;
    // gpio_set_level(STEPPER_EN, 0);
    gpio_set_level(STEPPER_DIR, 0);

    while (1)
    {
        printf("HI!\n");
        gpio_set_level(STEPPER_STEP, 0);
        SYS_DELAY(10);
        gpio_set_level(STEPPER_STEP, 1);
        SYS_DELAY(10);
        //     // acceleration phase
        //     tx_config.loop_count = 0;
        //     ESP_ERROR_CHECK(rmt_transmit(motor_chan, accel_motor_encoder, &accel_samples, sizeof(accel_samples), &tx_config));

        //     // uniform phase
        //     tx_config.loop_count = 5000;
        //     ESP_ERROR_CHECK(rmt_transmit(motor_chan, uniform_motor_encoder, &uniform_speed_hz, sizeof(uniform_speed_hz), &tx_config));

        //     // deceleration phase
        //     tx_config.loop_count = 0;
        //     ESP_ERROR_CHECK(rmt_transmit(motor_chan, decel_motor_encoder, &decel_samples, sizeof(decel_samples), &tx_config));
        //     // wait all transactions finished
        //     ESP_ERROR_CHECK(rmt_tx_wait_all_done(motor_chan, -1));

        //     vTaskDelay(pdMS_TO_TICKS(1000));
    }
}