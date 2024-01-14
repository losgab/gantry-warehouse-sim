#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/queue.h>
#include <freertos/timers.h>
#include <driver/uart.h>
#include <driver/i2c.h>
#include <driver/gpio.h>
#include <stdio.h>
#include "ssd1306.h"

#define SYS_DELAY(x) vTaskDelay(pdMS_TO_TICKS(x))

#define I2C_MASTER_PORT I2C_NUM_0
#define I2C_SDA 5
#define I2C_SCL 6
#define I2C_MASTER_FREQ 100000
#define SSD1306_ADDRESS 0x3C

#define BUF_SIZE 2048

// I2C Config
i2c_config_t config = {
    .mode = I2C_MODE_MASTER,
    .sda_io_num = I2C_SDA, // select GPIO specific to your project
    .sda_pullup_en = GPIO_PULLUP_ENABLE,
    .scl_io_num = I2C_SCL, // select GPIO specific to your project
    .scl_pullup_en = GPIO_PULLUP_ENABLE,
    .master.clk_speed = I2C_MASTER_FREQ, // select frequency specific to your project
    // .clk_flags = 0,          /*!< Optional, you can use I2C_SCLK_SRC_FLAG_* flags to choose i2c source clock here. */
};

// SSD1306
static ssd1306_handle_t screen = NULL;

void app_main()
{
    i2c_param_config(I2C_MASTER_PORT, &config);
    i2c_driver_install(I2C_MASTER_PORT, config.mode, BUF_SIZE, BUF_SIZE, 0);

    screen = ssd1306_create(I2C_MASTER_PORT, SSD1306_ADDRESS);
    ssd1306_refresh_gram(screen);
    ssd1306_clear_screen(screen, 0x00);

    char data_str[10] = {0};
    sprintf(data_str, "C STR");
    ssd1306_draw_string(screen, 70, 16, (const uint8_t *)data_str, 16, 1);
    ssd1306_refresh_gram(screen);
}