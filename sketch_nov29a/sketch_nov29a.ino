/* LDR decreases its resistance as light increases
 * Will use digital pin as opposed to analog pin to get on/off state
 * 
 * Doc spec: Input is light shining on light dependent resistor and output produces the RPM of rotations of rotor based on amount of times light has shined on LDR and time delay.
 * LDR has threshold 
*/

int LDRValue = 0;
int count = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  LDRValue = digitalRead(LDRpin);
  Serial.println(LDRValue);
  delay(100)
  count = LDRValue + count;
  Serial.println(count);
  
}
