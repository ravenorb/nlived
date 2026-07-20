#pragma once
#include <Arduino.h>
#include <TFT_eSPI.h>

class DisplayUi {
public:
    bool begin();
    void drawHome(uint8_t volume, bool playing);
    void drawStatus(const char* text);

private:
    TFT_eSPI tft_;
};
