#include "AudioEngine.h"
#include "BoardPins.h"

bool AudioEngine::begin() {
    pinMode(BoardPins::AMP_ENABLE, OUTPUT);

    // This board revision uses LOW to enable the amplifier.
    digitalWrite(BoardPins::AMP_ENABLE, LOW);

    // ESP32 Arduino tone() can generate a basic square wave on GPIO26.
    // Replace this later with I2S/DAC sample playback for WAV or synthesized audio.
    pinMode(BoardPins::AUDIO_DAC, OUTPUT);
    stop();
    return true;
}

void AudioEngine::update() {
    if (playing_ && stopAtMs_ != 0 && millis() >= stopAtMs_) {
        stop();
    }
}

void AudioEngine::setVolume(uint8_t percent) {
    volumePercent_ = constrain(percent, 0, 100);

    // Placeholder: tone() has no amplitude control.
    // Implement software sample scaling when moving to I2S/DAC playback.
}

uint8_t AudioEngine::volume() const {
    return volumePercent_;
}

void AudioEngine::playTone(uint16_t frequencyHz, uint32_t durationMs) {
    if (frequencyHz == 0) {
        stop();
        return;
    }

    tone(BoardPins::AUDIO_DAC, frequencyHz);
    playing_ = true;
    stopAtMs_ = durationMs > 0 ? millis() + durationMs : 0;
}

void AudioEngine::stop() {
    noTone(BoardPins::AUDIO_DAC);
    digitalWrite(BoardPins::AUDIO_DAC, LOW);
    playing_ = false;
    stopAtMs_ = 0;
}

bool AudioEngine::isPlaying() const {
    return playing_;
}
