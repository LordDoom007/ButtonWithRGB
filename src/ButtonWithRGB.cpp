#include "ButtonWithRGB.h"

ButtonWithRGB::ButtonWithRGB(int buttonPin, int redPin, int greenPin, int bluePin, unsigned long debounceDelay)
  : buttonPin(buttonPin), redPin(redPin), greenPin(greenPin), bluePin(bluePin),
    lastDebounceTime(0), debounceDelay(debounceDelay), lastButtonState(LOW), buttonState(LOW),
    brightness(0), fadeAmount(5), lastPulseTime(0), pulseSpeed(30) {
}

void ButtonWithRGB::begin() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  generateGammaTable();  // Gamma-Tabelle generieren
}

void ButtonWithRGB::update() {
  // Button Entprellen
  bool reading = !digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    buttonState = reading;
  }

  lastButtonState = reading;

  // LED Steuerung basierend auf dem Button-Status
  if (buttonState == HIGH) {
    setRGB(0, 255, 0);  // Grün wenn gedrückt
  } else {
    pulseRGB(255, 0, 0);  // Rot pulsieren wenn nicht gedrückt
  }
}

bool ButtonWithRGB::getButtonState() {
  return buttonState;
}

void ButtonWithRGB::setRGB(uint8_t red, uint8_t green, uint8_t blue) {
  applyGammaCorrection(red, green, blue);  // Gamma-Korrektur anwenden
  analogWrite(redPin, 255 - red);
  analogWrite(greenPin, 255 - green);
  analogWrite(bluePin, 255 - blue);
}

void ButtonWithRGB::pulseRGB(uint8_t red, uint8_t green, uint8_t blue) {
  unsigned long currentTime = millis();
  if (currentTime - lastPulseTime > pulseSpeed) {
    brightness += fadeAmount;
    if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount;
    }
    uint8_t correctedRed = (red * brightness) / 255;
    uint8_t correctedGreen = (green * brightness) / 255;
    uint8_t correctedBlue = (blue * brightness) / 255;

    applyGammaCorrection(correctedRed, correctedGreen, correctedBlue);  // Gamma-Korrektur anwenden
    analogWrite(redPin, 255 - correctedRed);
    analogWrite(greenPin, 255 - correctedGreen);
    analogWrite(bluePin, 255 - correctedBlue);

    lastPulseTime = currentTime;
  }
}

void ButtonWithRGB::setPulseSpeed(unsigned long speed) {
  pulseSpeed = speed;
}

void ButtonWithRGB::setDebounceDelay(unsigned long delay) {
  debounceDelay = delay;
}

void ButtonWithRGB::applyGammaCorrection(uint8_t &red, uint8_t &green, uint8_t &blue) {
  red = gammaCorrection[red];
  green = gammaCorrection[green];
  blue = gammaCorrection[blue];
}

void ButtonWithRGB::generateGammaTable(float gamma) {
  for (int i = 0; i < 256; i++) {
    gammaCorrection[i] = pow((float)i / 255.0, gamma) * 255.0;
  }
}
