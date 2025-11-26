# esp32_Light
A simple project to mess around with LEDs on a esp32

I ran this code on a WeAct Studio esp32c3 board which gave me issues with the serial monitor not working. I fixed the serial monitor issue by ensuring that USB CDC is enabled.

If using the Arduino IDE, ensure the correct board, the WeAct Studio esp32c3 board is the correct selected one. 

If using the Arduino-Cli, compile with this inside the correct directory: Arduino-cli compile --fqbn esp32:esp32:esp32c3:CDCOnBoot=cdc
then upload with arduino-cli upload -p /dev/ttyACM0 --fqbn esp32:esp32:esp32c3
and pull up the serial monitor: arduino-cli monitor -p /dev/ttyACM0 --config baudrate=115200
