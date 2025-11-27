#include "myheader.h"
#include <Arduino.h>

const int pinLED{10};
const int potReadPin{4};
static int potValue{};
static int brightness{};
static char input{};

void dimLED_setup() {
    pinMode(pinLED, OUTPUT); 
    Serial.println("\n*** Basic Dimmer Mode ***");
    Serial.println("LED is ready to be controlled by potentiometer. Type 'm' or 'M' + Enter to return to mode menu");
}

void dimLED_loop() {
    potValue = analogRead(potReadPin);
    brightness = potValue / 16;
    analogWrite(pinLED, brightness);

    if (Serial.available() > 0) {
        input = Serial.read();
        
        if (input == '\n' || input == '\r') {
            return;
        }

        switch(input) {
            case 'm': 
            case 'M': {
                currentMode = MENU;
                modeSetup[1] = false;
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