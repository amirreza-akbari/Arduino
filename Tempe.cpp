#include <DHT.h>


#define DHTPIN 2
#define DHTTYPE DHT21


#define RELAY_PIN 4

const float FAN_ON_TEMP = 40;
const float FAN_OFF_TEMP = 29.50;

DHT dht(DHTPIN, DHTTYPE);

bool fanStatus = false;

void setup()
{
  Serial.begin(9600);

  pinMode(RELAY_PIN, OUTPUT);


  digitalWrite(RELAY_PIN, HIGH);

  dht.begin();

  Serial.println("Temperature Control System Started");
}

void loop()
{
  float temperature = dht.readTemperature();


  if (isnan(temperature))
  {
    Serial.println("Failed to read from DHT21 sensor!");
    delay(2000);
    return;
  }


  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.println(" C");


  if (temperature >= FAN_ON_TEMP && !fanStatus)
  {
    digitalWrite(RELAY_PIN, LOW);
    fanStatus = true;

    Serial.println("Fan turned ON");
  }


  if (temperature <= FAN_OFF_TEMP && fanStatus)
  {
    digitalWrite(RELAY_PIN, HIGH);
    fanStatus = false;

    Serial.println("Fan turned OFF");
  }

  delay(2000);
}
