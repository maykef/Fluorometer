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
    //Serial.println("You send: ");
    Serial.println(led_brightness);
    Serial.println();
    switch(led_brightness) {
       case '1': 
       analogWrite(LED_PIN_Blue_2, 70);  // Light On at 
       analogWrite(LED_PIN_Blue, 70);
       delay(800); 
       analogWrite(LED_PIN_Blue_2, 250);  // Ligh off
       analogWrite(LED_PIN_Blue, 250); 
       Serial.println("The lights have an intensity of 114 umoles");
       analogWrite(LED_PIN_White, 210); 
       analogWrite(LED_PIN_Red, 233);
       delay(10000);
       for (int i = 0; i < 1; i++)
       {
         analogWrite(LED_PIN_Blue_2, 70);  // Light On at 
         analogWrite(LED_PIN_Blue, 70);
         delay(800);                 // length of pulse in ms
         analogWrite(LED_PIN_Blue_2, 250);  // Ligh off
         analogWrite(LED_PIN_Blue, 250);
       } 
       Serial.println("The lights have an intensity of 215 umoles");
       analogWrite(LED_PIN_White, 200); 
       analogWrite(LED_PIN_Red, 210);
       delay(10000);
       for (int i = 0; i < 1; i++)
       {
         analogWrite(LED_PIN_Blue_2, 70);  // Light On at 
         analogWrite(LED_PIN_Blue, 70);
         delay(800);                 // length of pulse in ms
         analogWrite(LED_PIN_Blue_2, 250);  // Ligh off
         analogWrite(LED_PIN_Blue, 250);
       } 
       Serial.println("The lights have an intensity of 357 umoles");
       analogWrite(LED_PIN_White, 185); 
       analogWrite(LED_PIN_Red, 185);
       delay(10000);
       for (int i = 0; i < 1; i++)
       {
         analogWrite(LED_PIN_Blue_2, 70);  // Light On at 
         analogWrite(LED_PIN_Blue, 70);
         delay(800);                 // length of pulse in ms
         analogWrite(LED_PIN_Blue_2, 250);  // Ligh off
         analogWrite(LED_PIN_Blue, 250);
       } 
       Serial.println("The lights have an intensity of 600 umoles");
       analogWrite(LED_PIN_White, 157); 
       analogWrite(LED_PIN_Red, 157);
       delay(10000);
       for (int i = 0; i < 1; i++)
       {
         analogWrite(LED_PIN_Blue_2, 70);  // Light On at 
         analogWrite(LED_PIN_Blue, 70);
         delay(800);                 // length of pulse in ms
         analogWrite(LED_PIN_Blue_2, 250);  // Ligh off
         analogWrite(LED_PIN_Blue, 250);
       }
       Serial.println("The lights have an intensity of 801 umoles");
       analogWrite(LED_PIN_White, 138); 
       analogWrite(LED_PIN_Red, 138);
       delay(10000);
       for (int i = 0; i < 1; i++)
       {
         analogWrite(LED_PIN_Blue_2, 70);  // Light On at 
         analogWrite(LED_PIN_Blue, 70);
         delay(800);                 // length of pulse in ms
         analogWrite(LED_PIN_Blue_2, 250);  // Ligh off
         analogWrite(LED_PIN_Blue, 250);
       }   
       Serial.println("The lights have an intensity of 1200 umoles");
       analogWrite(LED_PIN_White, 98); 
       analogWrite(LED_PIN_Red, 99);
       delay(10000);
       for (int i = 0; i < 1; i++)
       {
         analogWrite(LED_PIN_Blue_2, 70);  // Light On at 
         analogWrite(LED_PIN_Blue, 70);
         delay(800);                 // length of pulse in ms
         analogWrite(LED_PIN_Blue_2, 250);  // Ligh off
         analogWrite(LED_PIN_Blue, 250);
       }  
       Serial.println("The lights have an intensity of 1300 umoles");
       analogWrite(LED_PIN_White, 88); 
       analogWrite(LED_PIN_Red, 89);
       delay(10000);
       for (int i = 0; i < 1; i++)
       {
         analogWrite(LED_PIN_Blue_2, 70);  // Light On at 
         analogWrite(LED_PIN_Blue, 70);
         delay(800);                 // length of pulse in ms
         analogWrite(LED_PIN_Blue_2, 250);  // Ligh off
         analogWrite(LED_PIN_Blue, 250);
       } 
       Serial.println("The lights have an intensity of 1500 umoles");
       analogWrite(LED_PIN_White, 68); 
       analogWrite(LED_PIN_Red, 69);
       delay(10000);
       for (int i = 0; i < 1; i++)
       {
         analogWrite(LED_PIN_Blue_2, 70);  // Light On at 
         analogWrite(LED_PIN_Blue, 70);
         delay(800);                 // length of pulse in ms
         analogWrite(LED_PIN_Blue_2, 250);  // Ligh off
         analogWrite(LED_PIN_Blue, 250);
       }  
       analogWrite(LED_PIN_White, 250);  // Light Off
       analogWrite(LED_PIN_Red, 250);  // Light Off 
       Serial.println("The lights are off");
       break;
    }
  }
}
