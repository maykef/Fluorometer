// Control the LED brightness by sending value throw Serial monitor in Arduino Ide
// AnalogWrite() reference: https://www.arduino.cc/en/Reference/AnalogWrite

// Select the ride pin which support PWM mode for analogWrite()
// Pinout Arduino Nano: https://goo.gl/Dffq8f (the pins with oscillation symbol - PWM pin in legend)
int LED_PIN = 5;

// Next step - use Serial.parseInt() for control brightness 
// ParseInt() reference: https://www.arduino.cc/en/Serial/ParseInt
// Example end of this file

// Intensity (Driver levels all down):
// 200 = 197
// 190 = 259
// 180 = 338
// 170 = 416
// 160 = 493


void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN,OUTPUT);
  //analogWrite(pin, value); 
  //pin: 3, 5, 6, 9, 10, 11
  //value: 0 (always off) - 255 (always on)
  analogWrite(LED_PIN, 127); // middle value
  Serial.println("Control LED brightness by Serial monitor");
  Serial.println("Click 1 to initiate pulse");
}

void loop() {
  if (Serial.available() > 0) {
    char led_brightness = Serial.read();

    Serial.print("You send: ");
    Serial.print(led_brightness);
    Serial.println();

    switch(led_brightness) {
      case '1':                     // Press 1
        analogWrite(LED_PIN, 90);  // Light On at 
        delay(2000);                 // length of pulse in ms
        analogWrite(LED_PIN, 250);  // Ligh off
    }
  }
}
