#pragma once
#include <Arduino.h>

namespace BoardPins {

// LCD, handled by TFT_eSPI build flags.
constexpr gpio_num_t LCD_BACKLIGHT = GPIO_NUM_21;

// XPT2046 resistive touch controller.
constexpr gpio_num_t TOUCH_CS   = GPIO_NUM_33;
constexpr gpio_num_t TOUCH_IRQ  = GPIO_NUM_36;
constexpr gpio_num_t TOUCH_MISO = GPIO_NUM_39;
constexpr gpio_num_t TOUCH_MOSI = GPIO_NUM_32;
constexpr gpio_num_t TOUCH_SCLK = GPIO_NUM_25;

// Audio path on the E32R28T board.
constexpr gpio_num_t AUDIO_DAC = GPIO_NUM_26;
constexpr gpio_num_t AMP_ENABLE = GPIO_NUM_4;

// Board controls.
constexpr gpio_num_t BUTTON_BOOT = GPIO_NUM_0;

// Optional microSD bus.
constexpr gpio_num_t SD_CS   = GPIO_NUM_5;
constexpr gpio_num_t SD_MOSI = GPIO_NUM_23;
constexpr gpio_num_t SD_MISO = GPIO_NUM_19;
constexpr gpio_num_t SD_SCLK = GPIO_NUM_18;

} // namespace BoardPins
