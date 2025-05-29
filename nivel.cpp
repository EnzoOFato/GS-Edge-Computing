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
  digitalWrite(buzzPin, HIGH);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);

  tempo = pulseIn(echoPin, HIGH);
  distancia = tempo/58;
  Serial.println(distancia);
  delay(3000);
}