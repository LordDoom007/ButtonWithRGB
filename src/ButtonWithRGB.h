#ifndef ButtonWithRGB_h
#define ButtonWithRGB_h

#include <Arduino.h>

class ButtonWithRGB {
  private:
    const int buttonPin;
    const int redPin;
    const int greenPin;
    const int bluePin;
    unsigned long lastDebounceTime;
    unsigned long debounceDelay;
    bool lastButtonState;
    bool buttonState;
    int brightness;
    int fadeAmount;
    unsigned long lastPulseTime;
    unsigned long pulseSpeed;
    float gammaCorrection[256];  // Lookup-Tabelle für Gamma-Korrektur

  public:
    ButtonWithRGB(int buttonPin, int redPin, int greenPin, int bluePin, unsigned long debounceDelay = 50);

    void begin();
    void update();
    bool getButtonState();
    void setRGB(uint8_t red, uint8_t green, uint8_t blue);
    void pulseRGB(uint8_t red, uint8_t green, uint8_t blue);
    void setPulseSpeed(unsigned long speed = 30);
    void setDebounceDelay(unsigned long delay = 50);

  private:
    void applyGammaCorrection(uint8_t &red, uint8_t &green, uint8_t &blue);
    void generateGammaTable(float gamma = 3.8);  // Dynamische Gamma-Tabelle generieren 2.8
};

#endif
