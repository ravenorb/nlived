#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>

namespace {
constexpr uint8_t LCD_BACKLIGHT_PIN = 21;
constexpr uint8_t LCD_SCLK_PIN = 14;
constexpr uint8_t LCD_MISO_PIN = 12;
constexpr uint8_t LCD_MOSI_PIN = 13;
constexpr uint8_t LCD_CS_PIN = 15;

TFT_eSPI display;
}

void setup() {
    Serial.begin(115200);
    delay(100);

    pinMode(LCD_BACKLIGHT_PIN, OUTPUT);
    digitalWrite(LCD_BACKLIGHT_PIN, HIGH);

    // Initialize the E32R28T display SPI bus and ILI9341 controller.
    SPI.begin(LCD_SCLK_PIN, LCD_MISO_PIN, LCD_MOSI_PIN, LCD_CS_PIN);
    display.init();
    display.setRotation(3);  // 320 x 240 landscape
    display.fillScreen(TFT_BLACK);

    // Draw the startup text at the exact center of the display.
    display.setTextDatum(MC_DATUM);
    display.setTextColor(TFT_WHITE, TFT_BLACK);
    display.setTextFont(4);
    display.drawString("K0 K Center", display.width() / 2, display.height() / 2);

    Serial.println("Display initialized: K0 K Center");
}

void loop() {
    delay(1000);
}
