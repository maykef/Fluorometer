
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
//     230 =         OFF      OFF       OFF     54
//     220 =         107      222       OFF     88
//     210 =         153      317       67      125
//     200 =         215      445       92      164
//     190 =         281      596       124     201
//     180 =         347      755       165     239
//     170 =         412      912       217     275
//     160 =         476      1068      277     311
//     150 =         540      1221      348     347
//     140 =         603      1373      422     382
//     130 =         665      1524      495     418
//     120 =         726      1673      566     453
//     110 =         787      1820      636     487
//     100 =         849      1965      706     522
//     90 =          908      2111      775     556
//     80 =          968      2254      843     590
//     70 =          1027     2397      910     624
//     60 =          1086     2538      976     659
//     50 =          1145     2679      1042    691
//     40 =          1203     2818      1107    724
//     30 =          1260     2956      1172    755
//     20 =          1318     3094      1235    791
//     10 =          1375     3231      1299    821
//     00 =          1535     3656      1602    891


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
        analogWrite(LED_PIN_Blue_2, 190);  // Light On at 
        analogWrite(LED_PIN_Blue, 190);
        delay(800);                 // length of pulse in ms
        analogWrite(LED_PIN_Blue_2, 250);  // Ligh off
        analogWrite(LED_PIN_Blue, 250);
        Serial.print("The pulse has an intensity of 1221 umoles");
        break;
      case 'd':
        analogWrite(LED_PIN_Blue, 223);  //  20% or 100 umoles 215
        analogWrite(LED_PIN_White, 210);  // 20% or 100 umoles 190
        analogWrite(LED_PIN_Red, 200);  //   60% or 300 umoles 150
        Serial.print("The lights have an intensity of 302 umoles");
        break;
      case 'y':
        analogWrite(LED_PIN_Blue, 223);  //  20% or 100 umoles 215
        analogWrite(LED_PIN_White, 205);  // 20% or 100 umoles 190
        analogWrite(LED_PIN_Red, 180);  //   60% or 300 umoles 150
        Serial.print("The lights have an intensity of 400 umoles");
        break;
      case 'x':
        analogWrite(LED_PIN_Blue, 220);  //  20% or 100 umoles 215
        analogWrite(LED_PIN_White, 197);  // 20% or 100 umoles 190
        analogWrite(LED_PIN_Red, 160);  //   60% or 300 umoles 150
        Serial.print("The lights have an intensity of 500 umoles");
        break;
      case 'm':
        analogWrite(LED_PIN_Blue, 215);  //  20% or 100 umoles 215
        analogWrite(LED_PIN_White, 191);  // 20% or 100 umoles 190
        analogWrite(LED_PIN_Red, 142);  //   60% or 300 umoles 150
        Serial.print("The lights have an intensity of 601 umoles");
        break;
      case 'n':
        analogWrite(LED_PIN_Blue, 211);  //  20% or 100 umoles 215
        analogWrite(LED_PIN_White, 185);  // 20% or 100 umoles 190
        analogWrite(LED_PIN_Red, 124);  //   60% or 300 umoles 150
        Serial.print("The lights have an intensity of 701 umoles");
        break;
      case '@':
        analogWrite(LED_PIN_Blue, 250);  // Light Off
        analogWrite(LED_PIN_White, 250);  // Light Off
        analogWrite(LED_PIN_Red, 250);  // Light Off 
        Serial.print("The lights are off");
        break;
        case '2': 
        analogWrite(LED_PIN_Blue_2, 210);  // Light On at 
        analogWrite(LED_PIN_Blue, 210);
        delay(800);                 // length of pulse in ms
        analogWrite(LED_PIN_Blue_2, 250);  // Ligh off
        analogWrite(LED_PIN_Blue, 250);
        Serial.println("Initial Pulse");
        delay(100000);
        analogWrite(LED_PIN_Blue, 223);  //  20% or 172 umoles 200
        analogWrite(LED_PIN_White, 210);  // 20% or 139 umoles 180
        analogWrite(LED_PIN_Red, 200);  //   60% or 396 umoles 120
        Serial.println("Actinic Light On @");
        delay(100000);
        for (int i = 0; i < 10; i++)
        {
          analogWrite(LED_PIN_Blue_2, 210);  // Light On at 
          analogWrite(LED_PIN_Blue, 210);
          delay(800);                 // length of pulse in ms
          analogWrite(LED_PIN_Blue_2, 250);  // Ligh off
          analogWrite(LED_PIN_Blue, 250);
          Serial.println("The pulse has an intensity of 3196 umoles");
          delay(120000);
        }
        analogWrite(LED_PIN_Blue, 250);  // Light Off
        analogWrite(LED_PIN_White, 250);  // Light Off
        analogWrite(LED_PIN_Red, 250);  // Light Off 
        Serial.println("The lights are off");
        delay(100000);
        for (int i = 0; i < 10; i++)
        {
          analogWrite(LED_PIN_Blue_2, 210);  // Light On at 
          analogWrite(LED_PIN_Blue, 210);
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
