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
double sum = 0.0;
int previous = 0;
double n = 1.0;
double x = 2.0;
double k = 0.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //serial port for communication

}
//Light shines -> LDR resistance decreases -> voltage increases -> digital on or 1 value. Assume we start with 0 value and no light.

void loop() { //Would 600 iterations of loop equal a minute?
  // put your main code here, to run repeatedly:
  
  m = m + 1; //counter for 600 iterations
  //Serial.println(m);
  LDRValue = digitalRead(LDRpin); //Read value from LDR
  delay(10);
  if (LDRValue == 0 && previous == 1) {
    sum = sum + 1.0; //counts revolutions
  }
  
  if (m == 200) { //m should be 600 but due to arduino serial plotter issues I used a smaller sample size, this value is inversely related to delay(10)
    Serial.println(sum);
    
  }
  
  if ((m-(200*n)) == 200) { 
    k = sum / x;
    k = k * 30.0;
    Serial.println(k);
    x = x + 1;
    n = n + 1;
    
  }
  
  previous = LDRValue;
   
  //every 1-> 0 is revolution, so count number of 1->0's in 600 iterations (if every iteration takes 100 ms then 10 x 60 = 600) 
  
 
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
