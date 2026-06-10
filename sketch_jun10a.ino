#include <DHT.h>

#define DHTPIN 7
#define DHTTYPE DHT21
#define RELAY_PIN 8

DHT dht(DHTPIN, DHTTYPE);

const float tempOn  = 30.50;
const float tempOff = 30.1;

bool relayOn = false;

unsigned long lastTime = 0;
const long readInterval = 2000;

void setup() {
  Serial.begin(9600);

  pinMode(RELAY_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, HIGH);

  dht.begin();
}

void loop() {

  if (millis() - lastTime >= readInterval) {
    lastTime = millis();

    float t = dht.readTemperature();

    if (isnan(t)) {
      Serial.println("Sensor read error");
      return;
    }

    Serial.print("Temperature: ");
    Serial.println(t);

    if (!relayOn && t >= tempOn) {
      relayOn = true;
      digitalWrite(RELAY_PIN, LOW);
      Serial.println("Relay ON");
    }

    else if (relayOn && t <= tempOff) {
      relayOn = false;
      digitalWrite(RELAY_PIN, HIGH);
      Serial.println("Relay OFF");
    }
  }
}
