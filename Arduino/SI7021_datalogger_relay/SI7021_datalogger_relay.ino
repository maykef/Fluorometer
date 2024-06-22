#include "SPI.h"
#include "SD.h"
#include "Adafruit_Si7021.h"
#include "RTClib.h"

Adafruit_Si7021 sensor = Adafruit_Si7021();

const int chipSelect = 10;  // used for Arduino
const int relayPin = 8;
RTC_PCF8523 rtc;

unsigned long previousMillis = 0;
unsigned long relayMillis = 0;
const long interval = 1000;  // 1 second
const long relayOnTime = 10000;  // 10 seconds

bool relayState = false;

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);
  Serial.begin(115200);
  
  while (!Serial) {
    delay(100);
  }

  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (!sensor.begin()) {
    Serial.println("Did not find Si7021 sensor!");
    while (true);
  }

  if (!rtc.isrunning()) {
    Serial.println("RTC lost power, let's set the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  if (!SD.begin(chipSelect)) {
    Serial.println("Initialization failed!");
    while (1);
  }
}

void loop() {
  unsigned long currentMillis = millis();

  // Log data every second
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    float h = sensor.readHumidity();
    float t = sensor.readTemperature();

    DateTime now = rtc.now();

    String dataString = "";
    dataString += String(h);
    dataString += ",";
    dataString += String(t);
    
    File dataFile = SD.open("datalog.txt", FILE_WRITE);

    if (dataFile) {
      dataFile.println(dataString);
      dataFile.close();
      Serial.println(dataString);
    } else {
      Serial.println("error opening datalog.txt");
    }

    // Control the relay based on humidity
    if (h > 82 && !relayState) {
      digitalWrite(relayPin, HIGH);
      relayState = true;
      relayMillis = currentMillis;
    }
  }

  // Turn off the relay after 10 seconds
  if (relayState && currentMillis - relayMillis >= relayOnTime) {
    digitalWrite(relayPin, LOW);
    relayState = false;
  }
}
