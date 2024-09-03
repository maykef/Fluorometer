const int LED_PIN = 13;  // Built-in LED on most Arduinos

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void pulse(int duration) {
  digitalWrite(LED_PIN, HIGH);
  delayMicroseconds(duration);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  // First pulse
  pulse(100);  // 100 microsecond pulse

  delayMicroseconds(300);  // 300 microsecond delay

  // Second pulse
  pulse(100);  // 100 microsecond pulse

  delay(1000);  // 1 second delay before next cycle
}
