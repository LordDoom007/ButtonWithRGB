# ButtonWithRGB Library

## Overview

The **ButtonWithRGB library** makes it possible to easily control a button with an integrated RGB LED. It offers functions for **debouncing the button** and **controlling the RGB LED colours**.

## Functions

- **Tastersteuerung**: Entprellung des Tasters für eine zuverlässige Erkennung.
- **RGB-LED-Steuerung**: Setzen der LED-Farbe und Pulsieren mit einstellbarer Geschwindigkeit.
- **Gamma-Korrektur**: Anpassung der Helligkeit der RGB-LED für eine lineare Wahrnehmung.
- **Einstellbare Entprellzeit**: Anpassung der Entprellzeit für den Taster.

## Installation

1. download the `ButtonWithRGB` library or clone the repository.
2. copy the `ButtonWithRGB` folder into the `libraries` folder of your Arduino sketchbook folder.
3. restart the Arduino IDE.

## Use

### Simple example application

```cpp
#include "ButtonWithRGB.h"

ButtonWithRGB button(2, 9, 10, 11); // Butten Pin 2, RGB-LED on Pins 9, 10, 11

void setup() {
  button.begin();
  Serial.begin(9600);
}

void loop() {
  button.update(); 
// This function must be called regularly in the code, 
// otherwise the library will not work. 
// However, it offers a high level of compatibility as it does not use interrupts.

  
// Query button status
  bool status = button.getButtonState();
  if (status) {
    button.setRGB(0, 255, 0); //the butten will glow green
    Serial.println("Button is pressed");
  } else {
    button.pulseRGB(255, 0, 0); //the butten pulses red. the luminosity is increased or reduced with the stadart value 30ms.
    Serial.println("Button is not pressed");
  }
}
