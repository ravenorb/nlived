#pragma once
#include <Arduino.h>

class InputManager {
public:
    void begin();
    bool bootPressed();

private:
    bool lastBootState_ = HIGH;
    uint32_t lastDebounceMs_ = 0;
};
