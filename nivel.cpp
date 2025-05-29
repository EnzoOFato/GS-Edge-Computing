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
    digitalWrite(7, HIGH);
    delay(1000);
    digitalWrite(7, LOW);
  }
  else if(distancia <= 200 && distancia > 80){
    digitalWrite(6, HIGH);
    delay(1000);
    digitalWrite(6, LOW);
  }
  else if(distancia <= 80 && distancia >15){
    digitalWrite(5, HIGH);
    delay(1000);
    digitalWrite(5, LOW);
  }
  else{
    digitalWrite(5, HIGH);
    digitalWrite(buzzPin, HIGH);
    delay(1000);
    digitalWrite(buzzPin, LOW);
  }

  delay(3000);
}