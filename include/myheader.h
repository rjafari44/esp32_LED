#pragma once

inline int currentMode{};
inline bool menuDisplayed{false};
inline bool modeSetup[3]{false, false, false};

enum menu { MENU, BLINK, DIM_BASIC, DIM_RGB};

void showMenu();
void getUserInput();

void blink_setup();
void blink_loop();

void dimLED_setup();
void dimLED_loop();

void dimRGB_setup();
void dimRGB_loop();