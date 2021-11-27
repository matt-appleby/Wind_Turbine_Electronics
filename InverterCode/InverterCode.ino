
int frequency=1;  //Hz
float period=1/frequency; //s
float switchingPeriod=0.05; //s
float LineHigh[]={0.0, 0.05, 0.1, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4, 0.45};
float LineOneLow[]={0.0, 0.065, 0.129, 0.19, 0.248, 0.3, 0.348, 0.39, 0.429, 0.466};
float LineTwoLow[]={0.043, 0.084, 0.12, 0.155, 0.19, 0.225, 0.263, 0.304, 0.35, 0.401};
float LineThreeLow[]={0.043, 0.099, 0.15, 0.196, 0.237, 0.275, 0.31, 0.355, 0.42, 0.483};
int Transistors[3]={1,2,3};

void setup() {
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
}

void PWMCycleOrder(int PWMHigh, int PWMOneLow,int PWMTwoLow, int PWMThreeLow, int Phase1Trans, int Phase2Trans,int Phase3Trans){
    //sort the turn off of the three lines into chronological order per switching cycle
    if(PWMOneLow < PWMTwoLow && PWMTwoLow < PWMThreeLow){ //1, 2, 3
        pinMode(Phase1Trans, HIGH);
        pinMode(Phase2Trans, HIGH);
        pinMode(Phase3Trans, HIGH);
        
        delay(PWMHigh-PWMOneLow);
        pinMode(Phase1Trans, LOW);
      
        delay(PWMOneLow-PWMTwoLow);
        pinMode(Phase2Trans, LOW);

        delay(PWMTwoLow-PWMThreeLow);
        pinMode(Phase3Trans, LOW);
        
        delay(PWMThreeLow-switchingPeriod);
        }
      
    else if(PWMOneLow < PWMThreeLow && PWMThreeLow < PWMTwoLow){ //1, 3, 2
        pinMode(Phase1Trans, HIGH);
        pinMode(Phase2Trans, HIGH);
        pinMode(Phase3Trans, HIGH);
        delay(PWMHigh-PWMOneLow-PWMTwoLow);
        pinMode(Phase2Trans, LOW);

        delay(PWMHigh-PWMLow1-PWMLow2-PWMLow3);
        pinMode(Phase3Trans, LOW);
        
        delay(PWMThreeLow-switchingPeriod);
    }
    else if(PWMOneLow < PWMThreeLow && PWMThreeLow < PWMTwoLow){ //1, 3, 2
        pinMode(Phase1Trans, HIGH);
        pinMode(Phase2Trans, HIGH);
        pinMode(Phase3Trans, HIGH);
        //PWM one low
        delay(PWMHigh-PWMOneLow);
        pinMode(Phase1Trans, LOW);
        //PWM three low
        delay(PWMOneLow-PWMTwoLow);
        pinMode(Phase3Trans, LOW);
        //PWM two low
        delay(PWMTwoLow-PWMThreeLow);
        pinMode(Phase2Trans, LOW);
        //delay for rest of switching period
        delay(PWMTwoLow-switchingPeriod);
    }
    else if(PWMTwoLow < PWMOneLow && PWMOneLow < PWMThreeLow){ //2, 1, 3
        pinMode(Phase1Trans, HIGH);
        pinMode(Phase2Trans, HIGH);
        pinMode(Phase3Trans, HIGH);
        //PWM two low
        delay(PWMHigh-PWMOneLow);
        pinMode(Phase2Trans, LOW);
        //print("PWM one low")
        delay(PWMOneLow-PWMTwoLow);
        pinMode(Phase1Trans, LOW);
        //PWM three low
        delay(PWMTwoLow-PWMThreeLow);
        pinMode(Phase3Trans, LOW);
        //delay for rest of period
        delay(PWMThreeLow-switchingPeriod);
    }
      
    else if(PWMTwoLow < PWMThreeLow && PWMThreeLow < PWMOneLow){ // 2, 3, 1
        //need to finish off doing these delays
        pinMode(Phase1Trans, HIGH);
        pinMode(Phase2Trans, HIGH);
        pinMode(Phase3Trans, HIGH);
        
        delay(PWMHigh-PWMOneLow);
        pinMode(Phase2Trans, LOW);

        delay(PWMOneLow-PWMTwoLow);
        pinMode(Phase3Trans, LOW);

        delay(PWMTwoLow-PWMThreeLow);
        pinMode(Phase1Trans, LOW);
        
        delay(PWMOneLow-switchingPeriod);
    }
        
    else if(PWMThreeLow < PWMOneLow and PWMOneLow < PWMTwoLow){ // 3, 1, 2
        
        pinMode(Phase1Trans, HIGH);
        pinMode(Phase2Trans, HIGH);
        pinMode(Phase3Trans, HIGH);
        
        delay(PWMHigh-PWMOneLow);
        pinMode(Phase3Trans, LOW);

        delay(PWMOneLow-PWMTwoLow);
        pinMode(Phase1Trans, LOW);

        delay(PWMTwoLow-PWMThreeLow);
        pinMode(Phase2Trans, LOW);
        
        delay(PWMTwoLow-switchingPeriod);
    }
    else if(PWMThreeLow < PWMTwoLow and PWMTwoLow < PWMOneLow){ // 3, 2, 1
        
        pinMode(Phase1Trans, HIGH);
        pinMode(Phase2Trans, HIGH);
        pinMode(Phase3Trans, HIGH);
        
        delay(PWMHigh-PWMOneLow);
        pinMode(Phase3Trans, LOW);

        delay(PWMOneLow-PWMTwoLow);
        pinMode(Phase2Trans, LOW);

        delay(PWMTwoLow-PWMThreeLow);
        pinMode(Phase1Trans, LOW);

        delay(PWMOneLow-switchingPeriod);
    }
    else if(PWMTwoLow < PWMThreeLow && PWMThreeLow < PWMOneLow){ // 2, 3, 1

        pinMode(Phase1Trans, HIGH);
        pinMode(Phase2Trans, HIGH);
        pinMode(Phase3Trans, HIGH);

        delay(PWMHigh-PWMOneLow);
        pinMode(Phase2Trans, LOW);

        delay(PWMOneLow-PWMTwoLow);
        pinMode(Phase3Trans, LOW);

        delay(PWMTwoLow-PWMThreeLow);
        pinMode(Phase1Trans, LOW);

        delay(PWMHigh-PWMOneLow-PWMTwoLow-PWMThreeLow);
    }
    else if(PWMThreeLow < PWMOneLow and PWMOneLow < PWMTwoLow) { //3, 1, 2
        pinMode(Phase1Trans, HIGH);
        pinMode(Phase2Trans, HIGH);
        pinMode(Phase3Trans, HIGH);

        delay(PWMHigh-PWMOneLow);
        pinMode(Phase3Trans, LOW);

        delay(PWMOneLow-PWMTwoLow);
        pinMode(Phase1Trans, LOW);

        delay(PWMTwoLow-PWMThreeLow);
        pinMode(Phase2Trans, LOW);

        delay(PWMHigh-PWMOneLow-PWMTwoLow-PWMThreeLow);
    }
    else if(PWMThreeLow < PWMTwoLow and PWMTwoLow < PWMOneLow) {  //3, 2, 1

        pinMode(Phase1Trans, HIGH);
        pinMode(Phase2Trans, HIGH);
        pinMode(Phase3Trans, HIGH);

        delay(PWMHigh-PWMOneLow);
        pinMode(Phase3Trans, LOW);

        delay(PWMOneLow-PWMTwoLow);
        pinMode(Phase2Trans, LOW);

        delay(PWMTwoLow-PWMThreeLow);
        pinMode(Phase1Trans, LOW);

        delay(PWMHigh-PWMOneLow-PWMTwoLow-PWMThreeLow);
    }
  }

void Switchingcycle(int degrees){ 
    //Function evaluates which MOSFETs should be driven in 60 degree increments
    int PhaseOneTransistor = 0;
    int PhaseTwoTransistor = 0;
    int PhaseThreeTransistor = 0;
    
    if (degrees < 60) { //0-60
        //print("1 high, 2 low, 3 high")
        //MOSFETS
        PhaseOneTransistor = 1;
        PhaseTwoTransistor = 5;
        PhaseThreeTransistor = 3;
    }
    else if (degrees < 120) { //60-120)
        //print("1 high, 2 low, 3 low")
        PhaseOneTransistor = 1;
        PhaseTwoTransistor = 5;
        PhaseThreeTransistor = 6;
    }
    else if (degrees < 180) {//120-180
        //print("1 high, 2 high, 3 low")
        PhaseOneTransistor = 1;
        PhaseTwoTransistor = 2; 
        PhaseThreeTransistor = 6;
    }
    else if (degrees < 240){ //180-240 
        //print("1 low, 2 high, 3 high")
        
        PhaseOneTransistor = 4;
        PhaseTwoTransistor = 2; 
        PhaseThreeTransistor = 3;
    }
    else {                  //(degrees  240-360) ??
        //print("1 low, 2 low, 3 high")
        PhaseOneTransistor = 4;
        PhaseTwoTransistor = 5; 
        PhaseThreeTransistor = 3;
    }
    int Transistors[3]={PhaseOneTransistor, PhaseTwoTransistor, PhaseThreeTransistor};
}
void loop() {
  for (int x = 0; x < 6; ++x) {
    Switchingcycle(x*10);
    int p1mos = Transistor[0];
    int p2mos = Transistors[1];
    int p3mos = Transistors[2];
    int cycles= int(period/(switchingPeriod*6));//    #number of cycles in 60 degrees
    for (int y = 0; y < (cycles-1); ++y ) {
        int counter=cycles*x+y
        PWMCycleOrder(LineOneHigh[counter], LineOneLow[counter], LineTwoLow[counter], LineThreeLow[counter]);//#takes in timing arguments
    }
  }
}
