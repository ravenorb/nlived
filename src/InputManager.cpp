#include "InputManager.h"
#include "BoardPins.h"

void InputManager::begin() {
    pinMode(BoardPins::BUTTON_BOOT, INPUT_PULLUP);
    lastBootState_ = digitalRead(BoardPins::BUTTON_BOOT);
}

bool InputManager::bootPressed() {
    const bool current = digitalRead(BoardPins::BUTTON_BOOT);
    const uint32_t now = millis();

    bool pressed = false;
    if (lastBootState_ == HIGH && current == LOW && now - lastDebounceMs_ > 40) {
        pressed = true;
        lastDebounceMs_ = now;
    }

    lastBootState_ = current;
    return pressed;
}
