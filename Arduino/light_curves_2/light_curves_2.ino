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
  Serial.println("Press 1 to initiate lights");
}

void loop() {
  if (Serial.available() > 0) {
    char led_brightness = Serial.read();
    //Serial.println("You send: ");
    Serial.println(led_brightness);
    Serial.println();
    switch(led_brightness) {
       case '1':                     // Press 1
        //analogWrite(LED_PIN_Blue_2, 220);  // Light On at 
        analogWrite(LED_PIN_White, 220);
        delay(3000);                 // length of pulse in ms
        //analogWrite(LED_PIN_White_2, 250);  // Ligh off
        analogWrite(LED_PIN_White, 250);
        Serial.println("1");
        delay(3000);  
        //analogWrite(LED_PIN_White_2, 210);  // Light On at 
        analogWrite(LED_PIN_White, 210);
        delay(3000);                 // length of pulse in ms
        //analogWrite(LED_PIN_White_2, 250);  // Ligh off
        analogWrite(LED_PIN_White, 250);
        Serial.println("2");
        delay(3000);
        //analogWrite(LED_PIN_White_2, 200);  // Light On at 
        analogWrite(LED_PIN_White, 200);
        delay(3000);                 // length of pulse in ms
        //analogWrite(LED_PIN_White_2, 250);  // Ligh off
        analogWrite(LED_PIN_White, 250);
        Serial.println("3");
        delay(3000);
        //analogWrite(LED_PIN_White_2, 190);  // Light On at 
        analogWrite(LED_PIN_White, 190);
        delay(3000);                 // length of pulse in ms
        //analogWrite(LED_PIN_White_2, 250);  // Ligh off
        analogWrite(LED_PIN_White, 250);
        Serial.println("4");
        delay(3000);
        //analogWrite(LED_PIN_White_2, 180);  // Light On at 
        analogWrite(LED_PIN_White, 180);
        delay(3000);                 // length of pulse in ms
        //analogWrite(LED_PIN_White_2, 250);  // Ligh off
        analogWrite(LED_PIN_White, 250);
        Serial.println("5");
        delay(3000);
        //analogWrite(LED_PIN_White_2, 170);  // Light On at 
        analogWrite(LED_PIN_White, 170);
        delay(3000);                 // length of pulse in ms
        //analogWrite(LED_PIN_White_2, 250);  // Ligh off
        analogWrite(LED_PIN_White, 250);
        Serial.println("6");
        delay(3000);
        //analogWrite(LED_PIN_White_2, 160);  // Light On at 
        analogWrite(LED_PIN_White, 160);
        delay(3000);                 // length of pulse in ms
        //analogWrite(LED_PIN_White_2, 250);  // Ligh off
        analogWrite(LED_PIN_White, 250);
        Serial.println("7");
        delay(3000);
        //analogWrite(LED_PIN_White_2, 150);  // Light On at 
        analogWrite(LED_PIN_White, 150);
        delay(3000);                 // length of pulse in ms
        //analogWrite(LED_PIN_White_2, 250);  // Ligh off
        analogWrite(LED_PIN_White, 250);
        Serial.println("8");
        delay(3000);
        //analogWrite(LED_PIN_White_2, 140);  // Light On at 
        analogWrite(LED_PIN_White, 140);
        delay(3000);                 // length of pulse in ms
        //analogWrite(LED_PIN_White_2, 250);  // Ligh off
        analogWrite(LED_PIN_White, 250);
        Serial.println("9");
        delay(3000);
        //analogWrite(LED_PIN_White_2, 130);  // Light On at 
        analogWrite(LED_PIN_White, 130);
        delay(3000);                 // length of pulse in ms
        //analogWrite(LED_PIN_White_2, 250);  // Ligh off
        analogWrite(LED_PIN_White, 250);
        Serial.println("10");
        delay(3000);
        //analogWrite(LED_PIN_White_2, 120);  // Light On at 
        analogWrite(LED_PIN_White, 120);
        delay(3000);                 // length of pulse in ms
        //analogWrite(LED_PIN_White_2, 250);  // Ligh off
        analogWrite(LED_PIN_White, 250);
        Serial.println("11");
        delay(3000);
        //analogWrite(LED_PIN_White_2, 110);  // Light On at 
        analogWrite(LED_PIN_White, 110);
        delay(3000);                 // length of pulse in ms
        //analogWrite(LED_PIN_White_2, 250);  // Ligh off
        analogWrite(LED_PIN_White, 250);
        Serial.println("12");
        delay(3000);
        //analogWrite(LED_PIN_White_2, 100);  // Light On at 
        analogWrite(LED_PIN_White, 100);
        delay(3000);                 // length of pulse in ms
        //analogWrite(LED_PIN_White_2, 250);  // Ligh off
        analogWrite(LED_PIN_White, 250);
        Serial.println("13");
        delay(3000);
        //analogWrite(LED_PIN_White_2, 90);  // Light On at 
        analogWrite(LED_PIN_White, 90);
        delay(3000);                 // length of pulse in ms
        //analogWrite(LED_PIN_White_2, 250);  // Ligh off
        analogWrite(LED_PIN_White, 250);
        Serial.println("14");
        delay(3000);
        //analogWrite(LED_PIN_White_2, 80);  // Light On at 
        analogWrite(LED_PIN_White, 80);
        delay(3000);                 // length of pulse in ms
        //analogWrite(LED_PIN_White_2, 250);  // Ligh off
        analogWrite(LED_PIN_White, 250);
        Serial.println("15");
        delay(3000);
        //analogWrite(LED_PIN_White_2, 70);  // Light On at 
        analogWrite(LED_PIN_White, 70);
        delay(3000);                 // length of pulse in ms
        //analogWrite(LED_PIN_White_2, 250);  // Ligh off
        analogWrite(LED_PIN_White, 250);
        Serial.println("16");
        delay(3000);
        //analogWrite(LED_PIN_White_2, 60);  // Light On at 
        analogWrite(LED_PIN_White, 60);
        delay(3000);                 // length of pulse in ms
        //analogWrite(LED_PIN_White_2, 250);  // Ligh off
        analogWrite(LED_PIN_White, 250);
        Serial.println("17");
        delay(3000);
        //analogWrite(LED_PIN_White_2, 50);  // Light On at 
        analogWrite(LED_PIN_White, 50);
        delay(3000);                 // length of pulse in ms
        //analogWrite(LED_PIN_White_2, 250);  // Ligh off
        analogWrite(LED_PIN_White, 250);
        Serial.println("18");
        delay(3000);
        //analogWrite(LED_PIN_White_2, 40);  // Light On at 
        analogWrite(LED_PIN_White, 40);
        delay(3000);                 // length of pulse in ms
        //analogWrite(LED_PIN_White_2, 250);  // Ligh off
        analogWrite(LED_PIN_White, 250);
        Serial.println("19");
        delay(3000);
        //analogWrite(LED_PIN_White_2, 30);  // Light On at 
        analogWrite(LED_PIN_White, 30);
        delay(3000);                 // length of pulse in ms
        //analogWrite(LED_PIN_White_2, 250);  // Ligh off
        analogWrite(LED_PIN_White, 250);
        Serial.println("20");
        delay(3000);
        //analogWrite(LED_PIN_White_2, 20);  // Light On at 
        analogWrite(LED_PIN_White, 20);
        delay(3000);                 // length of pulse in ms
        //analogWrite(LED_PIN_White_2, 250);  // Ligh off
        analogWrite(LED_PIN_White, 250);
        Serial.println("21");
        delay(3000);
        //analogWrite(LED_PIN_White_2, 10);  // Light On at 
        analogWrite(LED_PIN_White, 10);
        delay(3000);                 // length of pulse in ms
        //analogWrite(LED_PIN_White_2, 250);  // Ligh off
        analogWrite(LED_PIN_White, 250);
        Serial.println("22");
        delay(3000);
        //analogWrite(LED_PIN_White_2, 00);  // Light On at 
        analogWrite(LED_PIN_White, 00);
        delay(3000);                 // length of pulse in ms
        //analogWrite(LED_PIN_White_2, 250);  // Ligh off
        analogWrite(LED_PIN_White, 250);
        Serial.println("23 and done!");
        break;
    }
  }
}
