#include "myheader.h"

static const int pinLED {4};
char input = {};

void blink_setup() {
    pinMode(pinLED, OUTPUT);
    Serial.println("\n*** Blink Mode ***");
    Serial.println("LED is blinking. Type 'm' or 'M' + Enter to return to mode menu");
}

void blink_loop() {
    digitalWrite(pinLED, HIGH);
    delay(1000);
    digitalWrite(pinLED, LOW);
    delay(1000);

    if (Serial.available() > 0) {
        input = Serial.read();
        
        if (input == '\n' || input == '\r') {
            return;
        }

        switch(input) {
            case 'm': 
            case 'M': {
                currentMode = MENU;
                modeInitialized[0] = false;
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