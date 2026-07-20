#pragma once
#include <Arduino.h>

class AudioEngine {
public:
    bool begin();
    void update();

    void setVolume(uint8_t percent);
    uint8_t volume() const;

    void playTone(uint16_t frequencyHz, uint32_t durationMs);
    void stop();

    bool isPlaying() const;

private:
    static constexpr uint8_t DAC_CHANNEL = 0;
    static constexpr uint32_t SAMPLE_RATE = 22050;

    uint8_t volumePercent_ = 50;
    bool playing_ = false;
    uint32_t stopAtMs_ = 0;
};
