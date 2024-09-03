const int LED_PIN = 13;  // Built-in LED on most Arduinos

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Generate a 110 microsecond pulse
  digitalWrite(LED_PIN, HIGH);
  delayMicroseconds(110);
  digitalWrite(LED_PIN, LOW);

  // Wait for the remainder of the second
  delay(1000);  // This will actually result in a cycle slightly longer than 1 second
}
