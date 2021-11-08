// Control the LED brightness by sending value throw Serial monitor in Arduino Ide
// AnalogWrite() reference: https://www.arduino.cc/en/Reference/AnalogWrite

// Select the ride pin which support PWM mode for analogWrite()
// Pinout Arduino Nano: https://goo.gl/Dffq8f (the pins with oscillation symbol - PWM pin in legend)
int LED_PIN_Blue   =  5;
int LED_PIN_White  =  6;
int LED_PIN_Red    =  9;
int LED_PIN_Blue_2   =  10;

// Next step - use Serial.parseInt() for control brightness 
// ParseInt() reference: https://www.arduino.cc/en/Serial/ParseInt
// Example end of this file

// Intensity Red - White - Red (Driver levels all down):
//     200 = 197  - 88   - 154 
//     190 = 259  - 118  - 189
//     180 = 338  - 157  - 223
//     170 = 416  - 203  - 257
//     160 = 493  - 260  - 291
//     150 = 565  - 325  - 324
//     140 = 640  - 390  - 358
//     130 = 715  - 453  - 391
//     120 = 790  - 516  - 424
//     110 = 865  - 577  - 457
//     100 = 940  - 638  - 487
//     90 = 1015  - 698  - 520


void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN_Blue,OUTPUT);
  pinMode(LED_PIN_White,OUTPUT);
  pinMode(LED_PIN_Red,OUTPUT);
  //analogWrite(pin, value); 
  //pin: 3, 5, 6, 9, 10, 11
  //value: 0 (always off) - 255 (always on)
  analogWrite(LED_PIN_Blue, 250); // middle value
  analogWrite(LED_PIN_White, 250); // middle value
  analogWrite(LED_PIN_Red, 250); // middle value
  Serial.println("Control the brightness by Serial monitor");
  Serial.println("Press d to initiate lights");
}

void loop() {
  if (Serial.available() > 0) {
    char led_brightness = Serial.read();
    //Serial.print("You send: ");
    Serial.print(led_brightness);
    Serial.println();
    switch(led_brightness) {
       case '1':                     // Press 1
        analogWrite(LED_PIN_Blue_2, 75);  // Light On at 
        delay(600);                 // length of pulse in ms
        analogWrite(LED_PIN_Blue_2, 250);  // Ligh off
        Serial.print("The pulse has an intensity of 1015 umoles");
        break;
      case 'd':
        analogWrite(LED_PIN_Blue, 218);  //  20% or 100 umoles
        analogWrite(LED_PIN_White, 191);  // 20% or 100 umoles
        analogWrite(LED_PIN_Red, 145);  //   60% or 300 umoles
        Serial.print("The lights have an intensity of 500 umoles");
        break;
      case '@':
        analogWrite(LED_PIN_Blue, 250);  // Light Off
        analogWrite(LED_PIN_White, 250);  // Light Off
        analogWrite(LED_PIN_Red, 250);  // Light Off 
        Serial.print("The lights are off");
        break;
        case '2': 
        analogWrite(LED_PIN_Blue_2, 75);  // Light On at 
        delay(600);                 // length of pulse in ms
        analogWrite(LED_PIN_Blue_2, 250);  // Ligh off
        Serial.println("Initial Pulse");
        delay(10000);
        analogWrite(LED_PIN_Blue, 218);  //  20% or 100 umoles
        analogWrite(LED_PIN_White, 191);  // 20% or 100 umoles
        analogWrite(LED_PIN_Red, 145);  //   60% or 300 umoles
        Serial.println("Actinic Light On");
        delay(10000);
        for (int i = 0; i < 25; i++)
        {
          analogWrite(LED_PIN_Blue_2, 75);  // Light On at 
          delay(600);                 // length of pulse in ms
          analogWrite(LED_PIN_Blue_2, 250);  // Ligh off
          Serial.println("The pulse has an intensity of 1015 umoles");
          delay(120000);
        }
        analogWrite(LED_PIN_Blue, 250);  // Light Off
        analogWrite(LED_PIN_White, 250);  // Light Off
        analogWrite(LED_PIN_Red, 250);  // Light Off 
        Serial.print("The lights are off");
        break;
    }
  }
}
