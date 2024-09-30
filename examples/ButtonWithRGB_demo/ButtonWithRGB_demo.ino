#include "ButtonWithRGB.h"

// Create a ButtonWithRGB object. The button is connected to pin 2,
// and the RGB LED is connected to pins 9, 10, and 11.
ButtonWithRGB button(2, 9, 10, 11);

void setup() {
  // Initialize the button
  button.begin();
  
  // Start serial communication at a baud rate of 9600
  Serial.begin(9600);

  // Set the speed at which the LED pulses to 50 milliseconds
  button.setPulseSpeed(50);  // 50 ms pulse speed
  
  // Set the debounce delay of the button to 100 milliseconds
  // This helps to avoid false signals due to mechanical noise
  button.setDebounceDelay(100);  // 100 ms debounce delay
}

void loop() {
  // Update the button state
  button.update();
  
  // Read the current state of the button
  bool status = button.getButtonState();
  
  // If the button is pressed
  if (status) {
    // Set the RGB LED to green
    button.setRGB(0, 255, 0);  // Green (R=0, G=255, B=0)
    // Print a message to the serial monitor
    Serial.println("Button is pressed");
  } else {
    // If the button is not pressed, make the RGB LED pulse red
    button.pulseRGB(255, 0, 0);  // Pulse red (R=255, G=0, B=0)
    // Print a message to the serial monitor
    Serial.println("Button is not pressed");
  }
}
