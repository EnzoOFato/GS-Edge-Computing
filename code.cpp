#include <LiquidCrystal_I2C.h>;
#define LCDADDR 0x27 // Definição do ADDR do display LCD
#define LCDColunas 16  // Definição do número de colunas do display LCD
#define LCDFileiras 2 // Definição do número de fileiras do display LCD
LiquidCrystal_I2C lcd(LCDADDR, LCDColunas, LCDFileiras); // Importação da biblioteca LiquidCrystal_I2C para a utilização do display LCD

#include <DHT.h>;
#define dhtPin 9
#define dhtTipo DHT22
DHT dht(dhtPin, dhtTipo); // Importação da biblioteca DHT para a utilização do sensor de temperatura e umidade

float umidade;
float temp;

void setup () {
    Serial.begin(115200);
    dht.begin();
    lcd.begin(16,2);
    lcd.init();
    lcd.backlight();
    // configuração dos pinos do display LCD e do sensor DHT, já dclarados acima
}
void loop () {
  umidade = dht.readHumidity();
  temp = dht.readTemperature();
  // Ambas informações são lidas do sensor DHT22, onde funções nativas são utilizadas para obter os valores de umidade e temperatura.

  if(umidade > 80){ // Condição para verificar se a umidade é maior que 80%
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
  else if (umidade > 50 && umidade <= 79){ // Condição para verificar se a umidade está entre 50% e 79%
    lcd.clear();
    delay(500);
    lcd.setCursor(5,0);
    lcd.print("Medio");
    lcd.setCursor(1,1);
    lcd.print("Risco de chuva");
    delay(3000);
    lcd.clear();
    delay(500);
  }
  else { // Condição para verificar se a umidade é menor ou igual a 50%
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

  // Para cada caso de umidade, o display LCD é atualizado com a mensagem correspondente e um pequeno atraso que é adicionado para garantir a leitura da mensagem

  // O método setCursor() é utilizado para posicionar o cursor no display LCD, e o método print() é utilizado para exibir as mensagens
  // já o clear() é utilizado para limpar o display antes de exibir uma nova mensagem

  lcd.setCursor(0, 0);
  lcd.print("Temp: "+(String)temp+"C");
  lcd.setCursor(0, 1);
  lcd.print("Umidade: "+(String)umidade+"%");

  // Exibição dos valores de temperatura e umidade no display LCD

  Serial.println("Temperatura: "+ (String)temp+"C°");
  delay(1000);
  Serial.println("Umidade do ar: "+ (String)umidade+"%");
  delay(2000);
}

