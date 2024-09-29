#include "ButtonWithRGB.h"

ButtonWithRGB button(2, 9, 10, 11); // Button an Pin 2, RGB LED an Pins 9, 10, 11

void setup() {
  button.begin();
  Serial.begin(9600);

  // Setze die Puls-Geschwindigkeit und Entprellzeit
  button.setPulseSpeed(50);  // Stelle die Puls-Geschwindigkeit auf 50 ms ein
  button.setDebounceDelay(100);  // Stelle die Entprellzeit auf 100 ms ein
}

void loop() {
  button.update();
  
  // Button-Status auslesen
  bool status = button.getButtonState();
  if (status) {
    button.setRGB(0, 255, 0);  // Grün wenn gedrückt
    Serial.println("Button is pressed");
  } else {
    button.pulseRGB(255, 0, 0);  // Rot pulsieren wenn nicht gedrückt
    Serial.println("Button is not pressed");
  }
}
