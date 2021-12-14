//6 line quick and dirty digital osiloscope for testing

void setup() {
  Serial.begin(9600);  
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
}

void loop() {
  Serial.print(digitalRead(2));
  Serial.print(" ");
  Serial.print(digitalRead(3));
  Serial.print(" ");
  Serial.print(digitalRead(4));
  Serial.print(" ");
  Serial.print(digitalRead(5));
  Serial.print(" ");
  Serial.println(digitalRead(6));
  Serial.print(" ");
  Serial.println(digitalRead(7));
  delay(100);
  }
