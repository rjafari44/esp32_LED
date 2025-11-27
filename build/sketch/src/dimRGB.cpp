#line 1 "/home/GoonKid/GitHub/esp32_Light/src/dimRGB.cpp"
#include "myheader.h"
#include <Arduino.h>

const int pinLED[3]{20, 10, 8};
const int potReadPin[3]{0, 1, 4};

static int potValue[3]{};
static int brightness[3]{};
static char input{};

void dimRGB_setup() {

    for (int i = 0; i < 3; i++) {
        pinMode(pinLED[i], OUTPUT);
    }
    Serial.println("\n*** RGB Dimmer Mode ***");
    Serial.println("LEDs are ready to be controlled by the potentiometers. Type 'm' or 'M' + Enter to return to mode menu");
}

void dimRGB_loop() {
    for (int i = 0; i < 3; i++) {
        potValue[i] = analogRead(potReadPin[i]);

        brightness[i] = potValue[i] / 16;

        analogWrite(pinLED[i], brightness[i]);
    }

    if (Serial.available() > 0) {
        input = Serial.read();
        
        if (input == '\n' || input == '\r') {
            return;
        }

        switch(input) {
            case 'm': 
            case 'M': {
                currentMode = MENU;
                modeSetup[2] = false;
                Serial.println("Returning to mode menu...");
                break;
            }
            default:
            Serial.println("Unknown command. Type 'm' or 'M' to return to main menu.");
            break;
        }

        while (Serial.available() > 0) {
            Serial.read();
        }
    }
}