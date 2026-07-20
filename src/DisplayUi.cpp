#include "DisplayUi.h"
#include "BoardPins.h"

bool DisplayUi::begin() {
    pinMode(BoardPins::LCD_BACKLIGHT, OUTPUT);
    digitalWrite(BoardPins::LCD_BACKLIGHT, HIGH);

    tft_.init();
    tft_.setRotation(3);
    tft_.fillScreen(TFT_BLACK);
    tft_.setTextDatum(MC_DATUM);
    return true;
}

void DisplayUi::drawHome(uint8_t volume, bool playing) {
    tft_.fillScreen(TFT_BLACK);

    tft_.setTextColor(TFT_CYAN, TFT_BLACK);
    tft_.setTextFont(4);
    tft_.drawString("NIVED", 160, 38);

    tft_.setTextColor(TFT_WHITE, TFT_BLACK);
    tft_.setTextFont(2);
    tft_.drawString("ESP32 Sound App", 160, 78);

    tft_.drawRoundRect(45, 105, 230, 70, 10, TFT_DARKGREY);
    tft_.drawString(playing ? "PLAYING" : "READY", 160, 140);

    char buffer[32];
    snprintf(buffer, sizeof(buffer), "Volume: %u%%", volume);
    tft_.drawString(buffer, 160, 200);

    tft_.setTextColor(TFT_LIGHTGREY, TFT_BLACK);
    tft_.drawString("Press BOOT to play test tone", 160, 225);
}

void DisplayUi::drawStatus(const char* text) {
    tft_.fillRect(40, 100, 240, 80, TFT_BLACK);
    tft_.setTextColor(TFT_YELLOW, TFT_BLACK);
    tft_.setTextFont(2);
    tft_.drawString(text, 160, 140);
}
