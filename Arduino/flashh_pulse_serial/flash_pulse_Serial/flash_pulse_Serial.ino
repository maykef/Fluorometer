
int ledPin = 5; // LED connected to digital pin 9
// The setup() method runs once, when the sketch starts

void setup()
{
  // initialize the digital pin as an output:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Input 1 to blink the LED");    
}

// the loop() method runs over and over again,
// as long as the Arduino has power

void loop()                    
{
     if(Serial.available())
     {
      int state =Serial.parseInt();
      if (state == 1)
      {
        digitalWrite(ledPin, LOW);   // set the LED on
        delay(200);                  // wait for a second
        digitalWrite(ledPin, HIGH);  // set the LED off
      }
    }
}
