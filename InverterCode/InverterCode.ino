
int frequency=1;  //Hz
float period=1/frequency; //s
float switchingPeriod=500; //ms
float LineHigh[]={0.0, 500.0, 1000.0, 1500.0, 2000.0, 2500.0, 3000.0, 3500.0, 4000.0, 4500.0};
float LineOneLow[]={0.0, 650.0, 1290.0, 1900.0, 2480.0, 3000.0, 3480.0, 3900.0, 4290.0, 4660.0};
float LineTwoLow[]={431.0, 840.0, 1200.0, 1550.0, 2100.0, 2751.0, 3370.0, 3960.0, 4500.0, 4990.0};
float LineThreeLow[]={430.0, 990.0, 1500.0, 1960.0, 2370.0, 2750.0, 3100.0, 3550.0, 4200.0, 4830.0};
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
        
        delay(PWMOneLow-PWMHigh);
        pinMode(Phase1Trans, LOW);
      
        delay(PWMTwoLow-PWMOneLow);
        pinMode(Phase2Trans, LOW);

        delay(PWMThreeLow-PWMTwoLow);
        pinMode(Phase3Trans, LOW);
        
        delay(PWMHigh+switchingPeriod-PWMThreeLow);

        }
      
    else if(PWMOneLow < PWMThreeLow && PWMThreeLow < PWMTwoLow){ //1, 3, 2
        pinMode(Phase1Trans, HIGH);
        pinMode(Phase2Trans, HIGH);
        pinMode(Phase3Trans, HIGH);
        
        delay(PWMOneLow-PWMHigh);
        pinMode(Phase1Trans,LOW);
        
        delay(PWMThreeLow-PWMOneLow);
        pinMode(Phase3Trans, LOW);

        delay(PWMTwoLow-PWMThreeLow);
        pinMode(Phase2Trans, LOW);
        
        delay(PWMHigh+switchingPeriod-PWMThreeLow);
    }
    else if(PWMOneLow < PWMThreeLow && PWMThreeLow < PWMTwoLow){ //1, 3, 2
        pinMode(Phase1Trans, HIGH);
        pinMode(Phase2Trans, HIGH);
        pinMode(Phase3Trans, HIGH);
        //PWM one low
        delay(PWMOneLow-PWMHigh);
        pinMode(Phase1Trans, LOW);
        //PWM three low
        delay(PWMThreeLow-PWMOneLow);
        pinMode(Phase3Trans, LOW);
        //PWM two low
        delay(PWMTwoLow-PWMThreeLow);
        pinMode(Phase2Trans, LOW);
        //delay for rest of switching period
        delay(PWMHigh+switchingPeriod-PWMTwoLow);
    }
    else if(PWMTwoLow < PWMOneLow && PWMOneLow < PWMThreeLow){ //2, 1, 3
        pinMode(Phase1Trans, HIGH);
        pinMode(Phase2Trans, HIGH);
        pinMode(Phase3Trans, HIGH);
        //PWM two low
        delay(PWMTwoLow-PWMHigh);
        pinMode(Phase2Trans, LOW);
        //print("PWM one low")
        delay(PWMOneLow-PWMTwoLow);
        pinMode(Phase1Trans, LOW);
        //PWM three low
        delay(PWMThreeLow-PWMOneLow);
        pinMode(Phase3Trans, LOW);
        //delay for rest of period
        delay(PWMHigh+switchingPeriod-PWMThreeLow);
    }
      
    else if(PWMTwoLow < PWMThreeLow && PWMThreeLow < PWMOneLow){ // 2, 3, 1
        //need to finish off doing these delays
        pinMode(Phase1Trans, HIGH);
        pinMode(Phase2Trans, HIGH);
        pinMode(Phase3Trans, HIGH);
        
        delay(PWMTwoLow-PWMHigh);
        pinMode(Phase2Trans, LOW);

        delay(PWMThreeLow-PWMTwoLow);
        pinMode(Phase3Trans, LOW);

        delay(PWMOneLow-PWMThreeLow);
        pinMode(Phase1Trans, LOW);
        
        delay(PWMHigh+switchingPeriod-PWMOneLow);
    }
        
    else if(PWMThreeLow < PWMOneLow and PWMOneLow < PWMTwoLow){ // 3, 1, 2
        
        pinMode(Phase1Trans, HIGH);
        pinMode(Phase2Trans, HIGH);
        pinMode(Phase3Trans, HIGH);
        
        delay(PWMThreeLow-PWMHigh);
        pinMode(Phase3Trans, LOW);

        delay(PWMOneLow-PWMThreeLow);
        pinMode(Phase1Trans, LOW);

        delay(PWMTwoLow-PWMOneLow);
        pinMode(Phase2Trans, LOW);
        
        delay(PWMHigh+switchingPeriod-PWMTwoLow);
    }
    else if(PWMThreeLow < PWMTwoLow and PWMTwoLow < PWMOneLow){ // 3, 2, 1
        
        pinMode(Phase1Trans, HIGH);
        pinMode(Phase2Trans, HIGH);
        pinMode(Phase3Trans, HIGH);
        
        delay(PWMThreeLow-PWMHigh);
        pinMode(Phase3Trans, LOW);

        delay(PWMTwoLow-PWMThreeLow);
        pinMode(Phase2Trans, LOW);

        delay(PWMOneLow-PWMTwoLow);
        pinMode(Phase1Trans, LOW);

        delay(PWMHigh+switchingPeriod-PWMOneLow);
    }
    else if(PWMTwoLow < PWMThreeLow && PWMThreeLow < PWMOneLow){ // 2, 3, 1

        pinMode(Phase1Trans, HIGH);
        pinMode(Phase2Trans, HIGH);
        pinMode(Phase3Trans, HIGH);

        delay(PWMTwoLow-PWMHigh);
        pinMode(Phase2Trans, LOW);

        delay(PWMThreeLow-PWMTwoLow);
        pinMode(Phase3Trans, LOW);

        delay(PWMOneLow-PWMThreeLow);
        pinMode(Phase1Trans, LOW);

        delay(PWMHigh+switchingPeriod-PWMOneLow);
    }
    else if(PWMThreeLow < PWMOneLow and PWMOneLow < PWMTwoLow) { //3, 1, 2
        pinMode(Phase1Trans, HIGH);
        pinMode(Phase2Trans, HIGH);
        pinMode(Phase3Trans, HIGH);

        delay(PWMThreeLow-PWMHigh);
        pinMode(Phase3Trans, LOW);

        delay(PWMOneLow-PWMThreeLow);
        pinMode(Phase1Trans, LOW);

        delay(PWMTwoLow-PWMOneLow);
        pinMode(Phase2Trans, LOW);

        delay(PWMHigh+switchingPeriod-PWMTwoLow);
    }
    else if(PWMThreeLow < PWMTwoLow and PWMTwoLow < PWMOneLow) {  //3, 2, 1

        pinMode(Phase1Trans, HIGH);
        pinMode(Phase2Trans, HIGH);
        pinMode(Phase3Trans, HIGH);

        delay(PWMThreeLow-PWMHigh);
        pinMode(Phase3Trans, LOW);

        delay(PWMTwoLow-PWMThreeLow);
        pinMode(Phase2Trans, LOW);

        delay(PWMOneLow-PWMTwoLow);
        pinMode(Phase1Trans, LOW);

        delay(PWMHigh+switchingPeriod-PWMOneLow);
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
    int p1mos = Transistors[0];
    int p2mos = Transistors[1];
    int p3mos = Transistors[2];
    int cycles= int(period/(switchingPeriod*6));//    #number of cycles in 60 degrees
    for (int y = 0; y < (cycles-1); ++y ) {
        int counter=cycles*x+y;
        PWMCycleOrder(LineHigh[counter], LineOneLow[counter], LineTwoLow[counter], LineThreeLow[counter], p1mos, p2mos, p3mos);//#takes in timing arguments
    }
  }
}
