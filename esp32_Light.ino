#include "myheader.h"

void setup() {
    Serial.begin(115200);
    delay(1000);
}

void loop() {
    switch(currentMode) {
        case MENU: {
            if (!menuDisplayed) {
                showMenu();
                menuDisplayed = true;
            }
            getUserInput();
            break;
        }
        case BLINK: {
            if (!modeSetup[0]) {
                blink_setup();
                modeSetup[0] = true;
            }
            blink_loop();
            break;
        }
        case DIM_BASIC: {
            if (!modeSetup[1]) {
                dimLED_setup();
                modeSetup[1] = true;
            }
            dimLED_loop();
            break;
        }
        case DIM_RGB: {
            if (!modeSetup[2]) {
                dimRGB_setup();
                modeSetup[2] = true;
            }
            dimRGB_loop();
            break;
        }
        default: {
            currentMode = 0;
            menuDisplayed = false;
            break;
        }
    }
}
