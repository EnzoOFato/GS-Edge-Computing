#include <LiquidCrystal_I2C.h>;
#define LCDADDR 0x27
#define LCDColunas 16
#define LCDFileiras 2
LiquidCrystal_I2C lcd(LCDADDR, LCDColunas, LCDFileiras);

#include <DHT.h>;
#define dhtPin 7
#define dhtTipo DHT22
DHT dht(dhtPin, dhtTipo);

float umidade;
float temp;

void setup () {
    Serial.begin(115200);
    dht.begin();
    lcd.begin(16,2);
    lcd.init();
    lcd.backlight();
}
void loop () {
  umidade = dht.readHumidity();
  temp = dht.readTemperature();

  if(umidade > 80){
    lcd.clear();
    delay(500);
    lcd.setCursor(5,0);
    lcd.print("Alerta");
    lcd.setCursor(1,1);
    lcd.print("Chuva eminente");
    delay(3000);
    lcd.clear();
    delay(500);
  }
  else if (umidade > 50 && umidade <= 79){
    lcd.clear();
    delay(500);
    lcd.setCursor(5,0);
    lcd.print("Médio");
    lcd.setCursor(1,1);
    lcd.print("Risco de chuva");
    delay(3000);
    lcd.clear();
    delay(500);
  }
  else {
    lcd.clear();
    delay(500);
    lcd.setCursor(5,0);
    lcd.print("Baixo");
    lcd.setCursor(1,1);
    lcd.print("Risco de chuva");
    delay(3000);
    lcd.clear();
    delay(500);
  }

  lcd.setCursor(0, 0);
  lcd.print("Temp: "+(String)temp+"C");
  lcd.setCursor(0, 1);
  lcd.print("Umidade: "+(String)umidade+"%");

  Serial.println("Temperatura: "+ (String)temp+"C°");
  delay(1000);
  Serial.println("Umidade do ar: "+ (String)umidade+"%");
  delay(2000);
}

