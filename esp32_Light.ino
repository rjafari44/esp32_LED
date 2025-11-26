// ESP32-C3 minimal Serial + LED test

// Onboard LED pin (usually GPIO 2 on WeAct ESP32-C3)
#define LED_PIN 4

void setup() {
  // Initialize serial at 115200 baud
  Serial.begin(115200);

  // Wait for USB CDC to initialize
  delay(2000);

  Serial.println("=== ESP32-C3 Serial Test ===");
  Serial.println("Serial output is working!");
  
  // Initialize LED pin
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Turn LED on
  digitalWrite(LED_PIN, HIGH);
  Serial.println("LED ON");
  delay(500);

  // Turn LED off
  digitalWrite(LED_PIN, LOW);
  Serial.println("LED OFF brrrrr");
  delay(500);
}
