void setup() {
  // put your setup code here, to run once:
  
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  
  frequency=1;  //Hz
  period=1/frequency; //s
  switchingPeriod=0.05 //s
  float LineOneHigh={0.0, 0.05, 0.1, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4, 0.45};
  float LineOneLow={0.0, 0.065, 0.129, 0.19, 0.248, 0.3, 0.348, 0.39, 0.429, 0.466};
  //LineTwoHigh=[]
  //LineTwoLow=[]
  //LineThreeHigh=[]
  //LineThreeLow=[]
}

void loop() {
  for (int i = 0; i <= period/switchingPeriod; i++) {
    pinMode(1,HIGH);
    float wait = LineOneLow[i]-LineOneHigh[i];
    delay(wait);//millis
    pinMode(1,LOW);
    delay(switchingPeriod-wait)
  }
  }
