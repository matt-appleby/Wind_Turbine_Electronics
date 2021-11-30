/* LDR decreases its resistance as light increases
 * Will use digital pin as opposed to analog pin to get on/off state
 * 
 * Doc spec: Input is light shining on light dependent resistor and output produces the RPM of rotations of rotor based on amount of times light has shined on LDR and time delay.
 * LDR has threshold 
*/

#define LDRpin 8 //pin to connect LDR and resistor, will replace LDRpin with 8 before program compiled

int LDRValue = 0; //result of reading analog pin
//int count[600];
int m = 0;
int sum = 0;
int previous = 0;
int total = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //serial port for communication

}
//Light shines -> LDR resistance decreases -> voltage increases -> digital on or 1 value. Assume we start with 0 value and no light.

void loop() { //Would 600 iterations of loop equal a minute?
  // put your main code here, to run repeatedly:
  
  LDRValue = digitalRead(LDRpin); //Read value from LDR
  Serial.println(LDRValue); //Print the value to the serial port
  delay(100); //waits for 100ms
  int current = LDRValue;
  if (current == 0 && previous == 1) {
    sum = sum + 1;
    previous = current;
  }
  m = m + 1; //counter for 600 iterations
  if (m == 600) {
    total = sum;
    Serial.println(total);
   // every 1-> 0 is revolution, so count number of 1->0's in 600 iterations (if every iteration takes 100 ms then 10 x 60 = 600) 
  }
 
  /* Solution using array
  // 1 is when light is shining 
  count[i] = LDRValue;
  m = m + 1;
  //find the number of 1 -> 0 pattern and count how many times this happens.
  if (m == 600) { 
    for(i = 0;i<600;++i){
      sum = count[i] + sum;
    }
    
    Serial.println(sum);
  }
  */
  
  
}