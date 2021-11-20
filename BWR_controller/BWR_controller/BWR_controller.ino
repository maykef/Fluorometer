// Control the LED brightness by sending value throw Serial monitor in Arduino Ide
// AnalogWrite() reference: https://www.arduino.cc/en/Reference/AnalogWrite

// Select the ride pin which support PWM mode for analogWrite()
// Pinout Arduino Nano: https://goo.gl/Dffq8f (the pins with oscillation symbol - PWM pin in legend)
int LED_PIN_Blue    =  5;
int LED_PIN_White   =  6;
int LED_PIN_Red     =  9;
int LED_PIN_Blue_2  =  10;

// Next step - use Serial.parseInt() for control brightness 
// ParseInt() reference: https://www.arduino.cc/en/Serial/ParseInt
// Example end of this file

// Intensity Blue (single)- (double) - White - Red (Driver levels all down):
//     230 =         OFF      OFF       OFF     49
//     220 =         107      194       OFF     79
//     210 =         153      278       57      114
//     200 =         215      388       78      147
//     190 =         281      520       107     181
//     180 =         347      661       142     215
//     170 =         412      799       185     247
//     160 =         476      936       237     280
//     150 =         540      1071      298     313
//     140 =         603      1204      362     346
//     130 =         665      1336      425     377
//     120 =         726      1467      488     409
//     110 =         787      1597      548     441
//     100 =         849      1725      609     472
//     90 =          908      1852      668     502
//     80 =          968      1979      727     533
//     70 =          1027     2104      785     564
//     60 =          1086     2228      842     594
//     50 =          1145     2351      899     626
//     40 =          1203     2465      955     656
//     30 =          1260     2586      1011    686
//     20 =          1318     2707      1067    713
//     10 =          1375     2826      1122    743
//     00 =          1535     3199      1384    805


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
        analogWrite(LED_PIN_Blue_2, 00);  // Light On at 
        analogWrite(LED_PIN_Blue, 00);
        delay(800);                 // length of pulse in ms
        analogWrite(LED_PIN_Blue_2, 250);  // Ligh off
        analogWrite(LED_PIN_Blue, 250);
        Serial.print("The pulse has an intensity of 1184 umoles");
        break;
      case 'd':
        analogWrite(LED_PIN_Blue, 220);  //  20% or 100 umoles 215
        analogWrite(LED_PIN_White, 200);  // 20% or 100 umoles 190
        analogWrite(LED_PIN_Red, 200);  //   60% or 300 umoles 150
        Serial.print("The lights have an intensity of 305 umoles");
        break;
      case 'y':
        analogWrite(LED_PIN_Blue, 220);  //  20% or 100 umoles 215
        analogWrite(LED_PIN_White, 200);  // 20% or 100 umoles 190
        analogWrite(LED_PIN_Red, 170);  //   60% or 300 umoles 150
        Serial.print("The lights have an intensity of 404 umoles");
        break;
      case 'x':
        analogWrite(LED_PIN_Blue, 219);  //  20% or 100 umoles 215
        analogWrite(LED_PIN_White, 189);  // 20% or 100 umoles 190
        analogWrite(LED_PIN_Red, 150);  //   60% or 300 umoles 150
        Serial.print("The lights have an intensity of 502 umoles");
        break;
      case 'm':
        analogWrite(LED_PIN_Blue, 219);  //  20% or 100 umoles 215
        analogWrite(LED_PIN_White, 190);  // 20% or 100 umoles 190
        analogWrite(LED_PIN_Red, 115);  //   60% or 300 umoles 150
        Serial.print("The lights have an intensity of 604 umoles");
        break;
      case 'n':
        analogWrite(LED_PIN_Blue, 212);  //  20% or 100 umoles 215
        analogWrite(LED_PIN_White, 175);  // 20% or 100 umoles 190
        analogWrite(LED_PIN_Red, 110);  //   60% or 300 umoles 150
        Serial.print("The lights have an intensity of 700 umoles");
        break;
      case '@':
        analogWrite(LED_PIN_Blue, 250);  // Light Off
        analogWrite(LED_PIN_White, 250);  // Light Off
        analogWrite(LED_PIN_Red, 250);  // Light Off 
        Serial.print("The lights are off");
        break;
        case '2': 
        analogWrite(LED_PIN_Blue_2, 00);  // Light On at 
        analogWrite(LED_PIN_Blue, 00);
        delay(800);                 // length of pulse in ms
        analogWrite(LED_PIN_Blue_2, 250);  // Ligh off
        analogWrite(LED_PIN_Blue, 250);
        Serial.println("Initial Pulse");
        delay(100000);
        analogWrite(LED_PIN_Blue, 220);  //  20% or 172 umoles 200
        analogWrite(LED_PIN_White, 200);  // 20% or 139 umoles 180
        analogWrite(LED_PIN_Red, 170);  //   60% or 396 umoles 120
        Serial.println("Actinic Light On");
        delay(100000);
        for (int i = 0; i < 10; i++)
        {
          analogWrite(LED_PIN_Blue_2, 00);  // Light On at 
          analogWrite(LED_PIN_Blue, 00);
          delay(800);                 // length of pulse in ms
          analogWrite(LED_PIN_Blue_2, 250);  // Ligh off
          analogWrite(LED_PIN_Blue, 250);
          Serial.println("The pulse has an intensity of 3196 umoles");
          delay(120000);
        }
        analogWrite(LED_PIN_Blue, 220);  // Light Off
        analogWrite(LED_PIN_White, 200);  // Light Off
        analogWrite(LED_PIN_Red, 170);  // Light Off 
        Serial.println("The lights are off");
        delay(100000);
        for (int i = 0; i < 10; i++)
        {
          analogWrite(LED_PIN_Blue_2, 00);  // Light On at 
          analogWrite(LED_PIN_Blue, 00);
          delay(800);                 // length of pulse in ms
          analogWrite(LED_PIN_Blue_2, 250);  // Ligh off
          analogWrite(LED_PIN_Blue, 250);
          Serial.println("The pulse has an intensity of 3196 umoles");
          delay(120000);
        }
        Serial.println("Done!");
        break;
    }
  }
}
