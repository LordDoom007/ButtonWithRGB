# ButtonWithRGB Library

## Overview

The **ButtonWithRGB library** makes it possible to easily control a button with an integrated RGB LED. It offers functions for **debouncing the button** and **controlling the RGB LED colours**.

## Functions

- **Push-button control**: Debouncing of the push-button for reliable detection.
- **RGB LED control**: Setting the LED colour and pulsing with adjustable speed.
- **Gamma correction**: Adjusting the brightness of the RGB LED for linear perception.
- **Adjustable debounce time**: Adjustment of the debounce time for the push-button.

## Installation

1. download the `ButtonWithRGB` library or clone the repository.
2. copy the `ButtonWithRGB` folder into the `libraries` folder of your Arduino sketchbook folder.
3. restart the Arduino IDE.

## Use
# Create object
```ButtonWithRGB button(2, 9, 10, 11);```

example for creating a butten object with the pin assignment
Buttons pin: 2 
Led pin Red: 9
led pin green: 10
pin blue: 11

Attention
1. the RGB LED pins are controlled negatively!!!
2. the butten uses the internal pulse resistor, so it must be connected to ground.

# Initialise object
```button.begin();```
Start the previously created object



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
