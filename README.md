# esp32_Light
## A project to mess around with LEDs on a esp32

This code consists of three modes: LED Blink, Basic Dimmer, and RGB Dimmer. Each mode has a different design needed to run. I have attached the sample setups I used for my own design with tinkerCAD, but feel free to use any pin or even change the code to match your need.

#### Mode LED Blink:
A simple LED blinking mode which has the light flicker on and off once every second.

#### Mode Basic Dimmer
This mode uses a potentiometer to control the brightness of the LED from 0% to 100%.

#### Mode RGB Dimmer
This mode is built upon the Basic Dimmer but uses multiple potentiometers with multiple LEDs. I used a RGB Led which has multiple colors in it, but that could be simulated by using a Red, Green and Blue LED next to each other under a lens to simulate multiple colors.

## HOW IT IS RUN
I ran this code on a WeAct Studio esp32c3 board which gave me issues with the serial monitor not working. I fixed the serial monitor issue by ensuring that USB CDC is enabled.

If using the Arduino IDE, ensure the correct board, the WeAct Studio esp32c3 board, is the correct selected one.
If running the script in CLI, it will prompt you for your board's serial port it is connected to, so you need to find it and mention it. The serial port is usually /dev/ttyACM0 or /dev/ttyUSB0 but it could also be different.

#### Find Connected Serial Port
##### On Linux
```bash
ls /dev/tty*
```   

##### With Arduino CLI (recommended method)
```bash
arduino-cli board list
```

#### Run the program in CLI
```bash
./run.sh
```