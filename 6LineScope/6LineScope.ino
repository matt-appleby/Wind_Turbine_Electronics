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
  int pin2 = digitalRead(2);
  int pin3 = digitalRead(3);
  int pin4 = digitalRead(4);
  int pin5 = digitalRead(5);
  int pin6 = digitalRead(6);
  int pin7 = digitalRead(7);
  delay(10);
  Serial.print(pin2);
  Serial.print(" ");
  Serial.print(pin3+2);
  Serial.print(" ");
  Serial.print(pin4+4);
  Serial.print(" ");
  Serial.print(pin5+6);
  Serial.print(" ");
  Serial.print(pin6+8);
  Serial.print(" ");
  Serial.println(pin7+10);
  delay(20);
  }
