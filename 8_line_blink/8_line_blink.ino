//6 line quick and dirty digital osiloscope for testing

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  delay(500);
  digitalWrite(2, LOW);
  delay(500);
  digitalWrite(3, LOW);
  delay(500);
  digitalWrite(4, LOW);
  delay(500);
  digitalWrite(5, LOW);
  delay(500);
  digitalWrite(6, LOW);
  delay(500);
  digitalWrite(7, LOW);
  delay(500);
  digitalWrite(8, LOW);
  delay(500);
  digitalWrite(9, LOW);
  delay(1000);
}
