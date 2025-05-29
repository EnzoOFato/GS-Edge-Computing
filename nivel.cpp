#include <LiquidCrystal_I2C.h>;
#define LCDADDR 0x27
#define LCDColunas 16
#define LCDFileiras 2
LiquidCrystal_I2C lcd(LCDADDR, LCDColunas, LCDFileiras);

#define buzzPin 9
#define trigPin 3
#define echoPin 2

long tempo;
double distancia;

void setup() {
  for(int i = 7; i>= 5; i--){
    pinMode(i, OUTPUT);
  }
  pinMode(buzzPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.init();
  lcd.backlight();
}

void loop() {
  digitalWrite(5, LOW);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);

  tempo = pulseIn(echoPin, HIGH);
  distancia = tempo/58;
  Serial.println(distancia);

  if(distancia > 200){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Baixo Risco");
    lcd.setCursor(0,1);
    lcd.print("de Desastre");
    digitalWrite(7, HIGH);
    delay(4000);
    digitalWrite(7, LOW);
  }
  else if(distancia <= 200 && distancia > 80){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Medio Risco");
    lcd.setCursor(0,1);
    lcd.print("de Desastre");
    digitalWrite(6, HIGH);
    delay(4000);
    digitalWrite(6, LOW);
  }
  else if(distancia <= 80 && distancia >15){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Alto Risco");
    lcd.setCursor(0,1);
    lcd.print("de Desastre");
    digitalWrite(5, HIGH);
    delay(4000);
    digitalWrite(5, LOW);
  }
  else{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Risco iminente");
    delay(2000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Autoridades");
    lcd.setCursor(0,1);
    lcd.print("Contatadas");
    digitalWrite(5, HIGH);
    digitalWrite(buzzPin, HIGH);
    delay(2000);
    digitalWrite(buzzPin, LOW);
  }
}