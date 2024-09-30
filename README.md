# ButtonWithRGB Library 
## for Pressure Button with RGB Lighting

## Overview

The **ButtonWithRGB library** allows easy control of a button with an integrated RGB LED. It provides functions for **debouncing the button** and **controlling the RGB LED colors**.

![Alt-Text](./RGB_button%201.PNG)

## Functions

- **Push-button control**: Debouncing the push-button for reliable detection.
- **RGB LED control**: Setting the LED color and pulsing with adjustable speed.
- **Gamma correction**: Adjusting the brightness of the RGB LED for linear perception.
- **Adjustable debounce time**: Adjustment of the debounce time for the push-button.

## Important notes:

 1. the RGB LED pins are controlled negatively! Make sure that you use a button that has a permanent positive connection and is controlled with ground. This is usually labelled C+ for the positive supply and R, G, B for the negative side of the LED diode.
 2. The library uses the internal pull-up resistor, so it must be connected to ground. This means that the switch must be connected to GND on one terminal and to the pin used on the other terminal. In the following example, this is pin 2.

## Installation

1. Download the `ButtonWithRGB` library or clone the repository.
2. Copy the `ButtonWithRGB` folder into the `libraries` folder of your Arduino sketchbook folder.
3. Restart the Arduino IDE.

## Usage
#### Create object
```cpp
ButtonWithRGB button(2, 9, 10, 11);
```

Example for creating a button object with the pin assignment:
- Button pin: 2 
- LED pin Red: 9
- LED pin Green: 10
- LED pin Blue: 11
![Alt-Text](./RGB_button%202.PNG)
note: make sure that you use a pin that is PWM compatible.

more information about PWM: https://support.arduino.cc/hc/en-us/articles/9350537961500-Use-PWM-output-with-Arduino

#### Initialize object
```cpp
button.begin();
```

Starts the previously created object.

#### Update object
```cpp
button.update();
```

- This function must be called regularly in the code, 
- otherwise the library will not work. 
- However, it offers a high level of compatibility as it does not use interrupts.

#### Query button
```cpp
bool status = button.getButtonState();
```

Returns the status of the debounced button as true or false.

#### Set RGB color
```cpp
button.setRGB(0, 255, 0);
```

Set the RGB color (0-255).

#### Set RGB pulse color
```cpp
button.pulseRGB(255, 0, 0);
```
Set the pulse RGB color (0-255). The LED pulses in the set color. However, care must be taken not to use any process-blocking codes such as `delay();`. Otherwise, the pulsing may be irregular or may not work at all.

#### Set RGB pulse speed
```cpp
button.setPulseSpeed(50);
```
Sets the pulse speed in ms. If the function is not called, the default value is 30 ms.

#### Set Button debounced time
```cpp
button.setDebounceDelay(100);
```

Sets the debounced time in ms. If the function is not called, the default value is 50 ms.



### Simple example application

```cpp
#include "ButtonWithRGB.h"

ButtonWithRGB button(2, 9, 10, 11); // Button pin 2, RGB-LED on pins 9, 10, 11

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
    button.setRGB(0, 255, 0); // The button will glow green
    Serial.println("Button is pressed");
  } else {
    button.pulseRGB(255, 0, 0); // The button pulses red. The luminosity is increased or decreased with the default value of 30ms.
    Serial.println("Button is not pressed");
  }
}
```
