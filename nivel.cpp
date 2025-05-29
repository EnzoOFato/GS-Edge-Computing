#include <LiquidCrystal_I2C.h>;
#define LCDADDR 0x27
#define LCDColunas 16
#define LCDFileiras 2
LiquidCrystal_I2C lcd(LCDADDR, LCDColunas, LCDFileiras); // Importação da biblioteca LiquidCrystal_I2C para a utilização do display LCD como lcd

#define buzzPin 9
#define trigPin 3
#define echoPin 2 // Declaração dos pinos utilizados no sensor ultrassônico e buzzer, leds não foram declarados aqui, pois sua declaraçã se torna mais fácil se for feita pareada a um for loop

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
  lcd.backlight();// Configuração dos pinos do display LCD e do sensor ultrassônico, já declarados acima e inicialização do mesmo, fora a de outos componentes como buzzer, leds, Serial e Ultrassom
}

void loop() {
  digitalWrite(5, LOW);
  digitalWrite(buzzPin, LOW);// Verificando que ambos sempre começem desligados

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);//Emissão do som ultrassônico para medir a distância

  tempo = pulseIn(echoPin, HIGH); // captação do tempo que o som leva para retornar ao sensor
  distancia = tempo/58; // Dividimos o tempo recebido por 58 para obter a distância em cm
  Serial.println(distancia); // Verificação para ter certaza que a distancia está sendo medida corretamente

  if(distancia > 200){ // Condição para verificar se a distância é maior que 200 cm, nesse caso baixo risco de desastre
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Baixo Risco");
    lcd.setCursor(0,1);
    lcd.print("de Desastre");
    digitalWrite(7, HIGH);
    delay(4000);
    digitalWrite(7, LOW);
  }
  else if(distancia <= 200 && distancia > 80){ // Condição para verificar se a distância está entre 80 cm e 200 cm, nesse caso médio risco de desastre
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Medio Risco");
    lcd.setCursor(0,1);
    lcd.print("de Desastre");
    digitalWrite(6, HIGH);
    delay(4000);
    digitalWrite(6, LOW);
  }
  else if(distancia <= 80 && distancia >15){ // Condição para verificar se a distância está entre 15 cm e 80 cm, nesse caso alto risco de desastre
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Alto Risco");
    lcd.setCursor(0,1);
    lcd.print("de Desastre");
    digitalWrite(5, HIGH);
    delay(4000);
    digitalWrite(5, LOW);
  }
  else{ // Condição para verificar se a distância é menor ou igual a 15 cm, nesse caso risco iminente de desastre
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
  }// Aqui temos um código mais longo, pois além do led continuar piscando o buzzer também é acionado, e o display LCD alterna entre duas mensagens, tornando sua manipulação mais delicada
}