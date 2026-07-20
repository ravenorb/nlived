# NIVED

Minimal Arduino/PlatformIO display test for the E32R28T ESP32-WROOM-32E board with a 2.8-inch 240x320 ILI9341 TFT.

## Current behavior

At startup the firmware:

1. Turns on the LCD backlight on GPIO 21.
2. Initializes the LCD SPI bus.
3. Initializes the ILI9341 display.
4. Rotates the screen to 320x240 landscape.
5. Clears the screen to black.
6. Displays `K0 K Center` in white at the center of the screen.

Nothing else runs yet.

## Build and upload with PlatformIO

```bash
pio run
pio run -t upload
pio device monitor
```

Serial monitor speed: `115200`.

## Board display pins

| Function | GPIO |
|---|---:|
| LCD SCLK | 14 |
| LCD MISO | 12 |
| LCD MOSI | 13 |
| LCD CS | 15 |
| LCD DC | 2 |
| LCD reset | ESP32 EN |
| LCD backlight | 21 |
