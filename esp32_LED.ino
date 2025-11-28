#include "myheader.h"
#include <Arduino.h>

void setup() {
    Serial.begin(115200);
    delay(1000);
}

void loop() {
    switch(currentMode) {
        case MENU: {
            if (!menuDisplayed) {        // while menu is not displayed yet
                showMenu();              // display the menu
                menuDisplayed = true;    // menu is displayed
            }
            getUserInput();              // get user input
            break;
        }
        case BLINK: {
            if (!modeSetup[0]) {        // if the blink mode's setup is not run yet
                blink_setup();          // run the blink setup function
                modeSetup[0] = true;    // let the program know that the setup has been already performed
            }
            blink_loop();               // perform the LED blink function
            break;
        }
        case DIM_BASIC: {
            if (!modeSetup[1]) {       // if the basic dimmer mode's setup is not performed 
                dimLED_setup();        // run the basic dimmer setup function
                modeSetup[1] = true;   // let the program know that the setup has been already performed
            }
            dimLED_loop();             // perform the LED basic dimmer function
            break;
        }
        case DIM_RGB: {
            if (!modeSetup[2]) {      // if the RGB dimmer mode's setup function is not performed 
                dimRGB_setup();       // run the RGB dimmer setup function
                modeSetup[2] = true;  // let the program know that the setup has been already performed
            }
            dimRGB_loop();            // perform the RGB dimmer function
            break;
        }
        default: {
            currentMode = 0;         // set the mode back to menu display
            menuDisplayed = false;   // set the menu displayed validation to false
            break;
        }
    }
}
