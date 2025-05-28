#include <DHT.h>;

#define dhtPin 7
#define dhtTipo DHT22
DHT dht(dhtPin, dhtTipo);

float umidade;
float temp;

void setup () {
    Serial.begin(115200);
    dht.begin();
}
void loop () {
  delay(2000);
  umidade = dht.readHumidity();
  temp = dht.readTemperature();
  Serial.println("Temperatura: "+ (String)temp+"C°");
  delay(2000);
  Serial.println("Umidade do ar: "+ (String)umidade+"%");
  delay(2000);
}

