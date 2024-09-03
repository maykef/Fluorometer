const int LED_PIN = 13;  // Built-in LED on most Arduinos

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);  // Initialize serial communication
}

void loop() {
  // First pulse
  digitalWrite(LED_PIN, HIGH);
  delay(500);  // 500ms on
  digitalWrite(LED_PIN, LOW);
  
  delay(500);  // 500ms off
  
  // Second pulse
  digitalWrite(LED_PIN, HIGH);
  delay(500);  // 500ms on
  digitalWrite(LED_PIN, LOW);
  
  delay(1000);  // 1 second off before repeating

  Serial.println("Cycle complete");  // Debug message
}
