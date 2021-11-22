// Control the LED brightness by sending value throw Serial monitor in Arduino Ide
// AnalogWrite() reference: https://www.arduino.cc/en/Reference/AnalogWrite

// Select the ride pin which support PWM mode for analogWrite()
// Pinout Arduino Nano: https://goo.gl/Dffq8f (the pins with oscillation symbol - PWM pin in legend)
int LED_PIN_Blue = 5;

// Next step - use Serial.parseInt() for control brightness 
// ParseInt() reference: https://www.arduino.cc/en/Serial/ParseInt
// Example end of this file

// Intensity Blue - White - Red (Driver levels all down):
//     200 = 197  - 88    - 
//     190 = 259  - 118
//     180 = 338  - 157
//     170 = 416  - 203
//     160 = 493  - 260
//     150 = 565  - 325
//     140 = 640  - 390
//     130 = 715  - 453
//     120 = 790  - 516
//     110 = 865  - 577
//     100 = 940  - 638
//     90 = 1015  - 698


void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN_Blue,OUTPUT);
  //analogWrite(pin, value); 
  //pin: 3, 5, 6, 9, 10, 11
  //value: 0 (always off) - 255 (always on)
  analogWrite(LED_PIN_Blue, 127); // middle value
  Serial.println("Control the pulse brightness and length by Serial monitor");
  Serial.println("Click 1 to initiate pulse");
}

void loop() {
  if (Serial.available() > 0) {
    char led_brightness = Serial.read();

    //Serial.print("You send: ");
    Serial.print(led_brightness);
    Serial.println();

    switch(led_brightness) {
      case '1':                     // Press 1
        analogWrite(LED_PIN_Blue, 200);  // Light On at 
        delay(600);                 // length of pulse in ms
        analogWrite(LED_PIN_Blue, 250);  // Ligh off
        Serial.print("The pulse has an intensity of 197 umoles");
        break;
      case '2':
        analogWrite(LED_PIN_Blue, 190);  // Light On at 
        delay(600);                 // length of pulse in ms
        analogWrite(LED_PIN_Blue, 250);  // Ligh off
        Serial.print("The pulse has an intensity of 259 umoles");
        break;
      case '3':
        analogWrite(LED_PIN_Blue, 180);  // Light On at 
        delay(600);                 // length of pulse in ms
        analogWrite(LED_PIN_Blue, 250);  // Ligh off
        Serial.print("The pulse has an intensity of 338 umoles");
        break;
      case '4':
        analogWrite(LED_PIN_Blue, 170);  // Light On at 
        delay(600);                 // length of pulse in ms
        analogWrite(LED_PIN_Blue, 250);  // Ligh off
        Serial.print("The pulse has an intensity of 416 umoles");
        break;
      case '5':
        analogWrite(LED_PIN_Blue, 160);  // Light On at 
        delay(600);                 // length of pulse in ms
        analogWrite(LED_PIN_Blue, 250);  // Ligh off
        Serial.print("The pulse has an intensity of 493 umoles");
        break;
      case '6':                     // Press 1
        analogWrite(LED_PIN_Blue, 150);  // Light On at 
        delay(600);                 // length of pulse in ms
        analogWrite(LED_PIN_Blue, 250);  // Ligh off
        Serial.print("The pulse has an intensity of 565 umoles");
        break;
      case '7':
        analogWrite(LED_PIN_Blue, 140);  // Light On at 
        delay(600);                 // length of pulse in ms
        analogWrite(LED_PIN_Blue, 250);  // Ligh off
        Serial.print("The pulse has an intensity of 640 umoles");
        break;
      case '8':
        analogWrite(LED_PIN_Blue, 130);  // Light On at 
        delay(600);                 // length of pulse in ms
        analogWrite(LED_PIN_Blue, 250);  // Ligh off
        Serial.print("The pulse has an intensity of 715 umoles");
        break;
      case '9':
        analogWrite(LED_PIN_Blue, 120);  // Light On at 
        delay(600);                 // length of pulse in ms
        analogWrite(LED_PIN_Blue, 250);  // Ligh off
        Serial.print("The pulse has an intensity of 790 umoles");
        break;
      case 'a':
        analogWrite(LED_PIN_Blue, 110);  // Light On at 
        delay(600);                 // length of pulse in ms
        analogWrite(LED_PIN_Blue, 250);  // Ligh off
        Serial.print("The pulse has an intensity of 865 umoles");
        break;
      case 'b':
        analogWrite(LED_PIN_Blue, 100);  // Light On at 
        delay(600);                 // length of pulse in ms
        analogWrite(LED_PIN_Blue, 250);  // Ligh off
        Serial.print("The pulse has an intensity of 940 umoles");
        break;
      case 'c':
        analogWrite(LED_PIN_Blue, 90);  // Light On at 
        delay(600);                 // length of pulse in ms
        analogWrite(LED_PIN_Blue, 250);  // Ligh off
        Serial.print("The pulse has an intensity of 1015 umoles");
        break;
    }
  }
}
