# ButtonWithRGB Library

## Übersicht

Die `ButtonWithRGB`-Bibliothek bietet eine einfache Möglichkeit, einen Taster mit einer RGB-LED zu steuern. Sie unterstützt Funktionen zur Entprellung des Tasters, zur Steuerung der RGB-LED-Farben und zur Anpassung der Pulsfrequenz und Gamma-Korrektur.

## Funktionen

- **Tastersteuerung**: Entprellung des Tasters für eine zuverlässige Erkennung.
- **RGB-LED-Steuerung**: Setzen der LED-Farbe und Pulsieren mit einstellbarer Geschwindigkeit.
- **Gamma-Korrektur**: Anpassung der Helligkeit der RGB-LED für eine lineare Wahrnehmung.
- **Einstellbare Entprellzeit**: Anpassung der Entprellzeit für den Taster.

## Installation

1. Lade die `ButtonWithRGB`-Bibliothek herunter oder klone das Repository.
2. Kopiere den Ordner `ButtonWithRGB` in den `libraries`-Ordner deines Arduino-Sketchbook-Ordners.
3. Starte die Arduino IDE neu.

## Verwendung

### Einfache Beispielanwendung

```cpp
#include "ButtonWithRGB.h"

ButtonWithRGB button(2, 9, 10, 11); // Taster an Pin 2, RGB-LED an Pins 9, 10, 11

void setup() {
  button.begin();
  Serial.begin(9600);
}

void loop() {
  button.update();
  
  // Tasterstatus abfragen
  bool status = button.getButtonState();
  if (status) {
    button.setRGB(0, 255, 0); // Grün, wenn gedrückt
    Serial.println("Button is pressed");
  } else {
    button.pulseRGB(255, 0, 0); // Rot pulsieren, wenn nicht gedrückt
    Serial.println("Button is not pressed");
  }
}
