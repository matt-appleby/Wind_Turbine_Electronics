void setup() {
  // put your setup code here, to run once:
<<<<<<< Updated upstream
<<<<<<< Updated upstream
  
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  
  int frequency=1;  //Hz
  float period=1/frequency; //s
  float switchingPeriod=0.05; //s
  float LineHigh={0.0, 0.05, 0.1, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4, 0.45};
  float LineOneLow={0.0, 0.065, 0.129, 0.19, 0.248, 0.3, 0.348, 0.39, 0.429, 0.466};
  float LineTwoLow={0.043, 0.084, 0.12, 0.155, 0.19, 0.225, 0.263, 0.304, 0.35, 0.401};
  float LineThreeLow={-0.043, 0.001, 0.05, 0.104, 0.163, 0.225, 0.289, 0.355, 0.42, 0.483};
}

void PWMCycleOrder(PWMHigh,PWMOneLow,PWMTwoLow,PWMThreeLow,Phase1Trans,Phase2Trans,Phase3Trans){
    //sort the turn off of the three lines into chronological order per switching cycle
    if (PWMOneLow < PWMTwoLow && PWMTwoLow < PWMThreeLow){//1, 2 , 3
        pinMode(Phase1Trans, HIGH);
        pinMode(Phase2Trans, HIGH);
        pinMode(Phase3Trans, HIGH);
        
        delay(PWMHigh-PWMOneLow);
        pinMode(Phase1Trans, LOW);
      
        delay(PWMOneLow-PWMTwoLow);
        pinMode(Phase2Trans, LOW);

        delay(PWMTwoLow-PWMThreeLow);
        pinMode(Phase3Trans, LOW);
        
        delay(PWMHigh-PWMLow1-PWMLow2-PWMLow3-switchingPeriod);
        }
      
    if (PWMOneLow < PWMThreeLow && PWMThreeLow < PWMTwoLow){// 1, 3, 2
    
        delay(PWMHigh-PWMOneLow-PWMTwoLow);
        pinMode(Phase2Trans, LOW);

        delay(PWMHigh-PWMLow1-PWMLow2-PWMLow3);
        pinMode(Phase3Trans, LOW);
        
        delay(PWMHigh-PWMLow1-PWMLow2-PWMLow3-switchingPeriod);
    }
    if (PWMOneLow < PWMThreeLow && PWMThreeLow < PWMTwoLow){// 1, 3, 2
        pinMode(Phase1Trans, HIGH);
        pinMode(Phase2Trans, HIGH);
        pinMode(Phase3Trans, HIGH);
        //PWM one low
        delay(PWMHigh-PWMOneLow);
        pinMode(Phase1Trans, LOW);
        //PWM three low
        delay(PWMOneLow-PWMThreeLow);
        pinMode(Phase3Trans, LOW);
        //PWM two low
        delay(PWMTwoLow-PWMThreeLow);
        pinMode(Phase2Trans, LOW);
        //delay for rest of switching period
        delay(PWMHigh-PWMLow1-PWMLow2-PWMLow3-switchingPeriod);
        }
    if(PWMTwoLow < PWMOneLow && PWMOneLow < PWMThreeLow){//2, 1, 3
        pinMode(Phase1Trans, HIGH);
        pinMode(Phase2Trans, HIGH);
        pinMode(Phase3Trans, HIGH);
        //PWM two low
        delay(PWMHigh-PWMTwoLow);
        pinMode(Phase2Trans, LOW);
        //print("PWM one low")
        delay(PWMOneLow-PWMTwoLow);
        pinMode(Phase1Trans, LOW);
        //PWM three low
        delay(PWMTwoLow-PWMThreeLow);
        pinMode(Phase3Trans, LOW);
        //delay for rest of period
        delay(PWMHigh-PWMLow1-PWMLow2-PWMLow3-switchingPeriod);
        }
      
    if(PWMTwoLow < PWMThreeLow && PWMThreeLow < PWMOneLow){//:# 2, 3, 1
        //need to finish off doing these delays
        pinMode(Phase1Trans, HIGH);
        pinMode(Phase2Trans, HIGH);
        pinMode(Phase3Trans, HIGH);
        
        delay(PWMHigh-PWMOneLow);
        pinMode(Phase2Trans, LOW);

        delay(PWMOneLow-PWMTwoLow);
        pinMode(Phase3Trans, LOW);

        delay(PWMLow2-PWMLow3);
        pinMode(Phase1Trans, LOW);
        
        delay(PWMHigh-PWMLow1-PWMLow2-PWMLow3-switchingPeriod);
        }
        
    if PWMThreeLow < PWMOneLow and PWMOneLow < PWMTwoLow){ // 3, 1, 2
        
        pinMode(Phase1Trans, HIGH);
        pinMode(Phase2Trans, HIGH);
        pinMode(Phase3Trans, HIGH);
        
        delay(PWMHigh-PWMLow1);
        pinMode(Phase3Trans, LOW);

        delay(PWMLow1-PWMLow2);
        pinMode(Phase1Trans, LOW);

        delay(PWMLow2-PWMLow3);
        pinMode(Phase2Trans, LOW);
        
        delay(PWMHigh-PWMLow1-PWMLow2-PWMLow3-switchingPeriod);
        }
    if (PWMThreeLow < PWMTwoLow and PWMTwoLow < PWMOneLow){ // 3, 2, 1
        
        pinMode(Phase1Trans, HIGH);
        pinMode(Phase2Trans, HIGH);
        pinMode(Phase3Trans, HIGH);
        
        delay(PWMHigh-PWMLow1);
        pinMode(Phase3Trans, LOW);

        delay(PWMLow1-PWMLow2);
        pinMode(Phase2Trans, LOW);

        delay(PWMLow2-PWMLow3);
        pinMode(Phase1Trans, LOW);

        delay(PWMHigh-PWMOneLow-PWMTwoLow-PWMThreeLow);
    }
    if(PWMTwoLow < PWMThreeLow && PWMThreeLow < PWMOneLow){//:# 2, 3, 1
        //need to finish off doing these delays

        pinMode(Phase1Trans, HIGH);
        pinMode(Phase2Trans, HIGH);
        pinMode(Phase3Trans, HIGH);

        print("PWM two low")
        print("wait PWMHigh-PWM low 1")
        print("PWM one low")
        print("wait PWMHigh-PWMLow1-PWMLow2")
        print("PWM three low")
        print("wait PWMHigh-PWMLow1-PWMLow2-PWMLow3")
    elif PWMThreeLow < PWMOneLow and PWMOneLow < PWMTwoLow:# 3, 1, 2
        print("PWM three low")
        print("wait PWMHigh-PWM low 1")
        print("PWM one low")
        print("wait PWMHigh-PWMLow1-PWMLow2")
        print("PWM two low")
        print("wait PWMHigh-PWMLow1-PWMLow2-PWMLow3")
    else:#elif PWMThreeLow < PWMTwoLow and PWMTwoLow < PWMOneLow# 3, 2, 1
        print("PWM one low")
        print("wait PWMHigh-PWM low 1")
        print("PWM two low")
        print("wait PWMHigh-PWMLow1-PWMLow2")
        print("PWM three low")
        print("wait PWMHigh-PWMLow1-PWMLow2-PWMLow3")
=======

  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  int frequency = 1; //Hz
  float period = 1 / frequency; //s
  float switchingPeriod = 0.05; //s
  float LineHigh = {0.0, 0.05, 0.1, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4, 0.45};
  float LineOneLow = {0.0, 0.065, 0.129, 0.19, 0.248, 0.3, 0.348, 0.39, 0.429, 0.466};
  float LineTwoLow = {0.043, 0.084, 0.12, 0.155, 0.19, 0.225, 0.263, 0.304, 0.35, 0.401};
  float LineThreeLow = { -0.043, 0.001, 0.05, 0.104, 0.163, 0.225, 0.289, 0.355, 0.42, 0.483};
}

void PWMCycleOrder(PWMHigh; PWMOneLow; PWMTwoLow; PWMThreeLow; Phase1Trans; Phase2Trans; Phase3Trans) {
  //sort the turn off of the three lines into chronological order per switching cycle
  if (PWMOneLow < PWMTwoLow && PWMTwoLow < PWMThreeLow) { //1, 2 , 3
    pinMode(Phase1Trans, HIGH);
    pinMode(Phase2Trans, HIGH);
    pinMode(Phase3Trans, HIGH);

    delay(PWMHigh - PWMOneLow);
    pinMode(Phase1Trans, LOW);

    delay(PWMOneLow - PWMTwoLow);
    pinMode(Phase2Trans, LOW);

    delay(PWMTwoLow - PWMThreeLow);
    pinMode(Phase3Trans, LOW);

    delay(PWMHigh - PWMLow1 - PWMLow2 - PWMLow3 - switchingPeriod);
  }

  if (PWMOneLow < PWMThreeLow && PWMThreeLow < PWMTwoLow) { // 1, 3, 2

    pinMode(Phase1Trans, HIGH);
    pinMode(Phase2Trans, HIGH);
    pinMode(Phase3Trans, HIGH);
    //PWM one low
    delay(PWMHigh - PWMOneLow);
    pinMode(Phase1Trans, LOW);

    //PWM three low
    delay(PWMOneLow - PWMThreeLow);
    pinMode(Phase3Trans, LOW);
    //PWM two low
    delay(PWMTwoLow - PWMThreeLow);
    pinMode(Phase2Trans, LOW);

    delay(PWMHigh - PWMLow1 - PWMLow2 - PWMLow3 - switchingPeriod);
  }

  if (PWMTwoLow < PWMOneLow && PWMOneLow < PWMThreeLow) { //2, 1, 3
    pinMode(Phase1Trans, HIGH);
    pinMode(Phase2Trans, HIGH);
    pinMode(Phase3Trans, HIGH);
    //PWM two low
    delay(PWMHigh - PWMTwoLow);
    pinMode(Phase2Trans, LOW);

    //print("PWM one low")
    delay(PWMOneLow - PWMTwoLow);
    pinMode(Phase1Trans, LOW);

    //PWM three low
    delay(PWMTwoLow - PWMThreeLow);
    pinMode(Phase3Trans, LOW);

    delay(PWMHigh - PWMLow1 - PWMLow2 - PWMLow3 - switchingPeriod);
  }

  if (PWMTwoLow < PWMThreeLow && PWMThreeLow < PWMOneLow) { //:# 2, 3, 1
    //need to finish off doing these delays
    pinMode(Phase1Trans, HIGH);
    pinMode(Phase2Trans, HIGH);
    pinMode(Phase3Trans, HIGH);

    delay(PWMHigh - PWMOneLow);
    pinMode(Phase2Trans, LOW);

    delay(PWMOneLow - PWMTwoLow);
    pinMode(Phase3Trans, LOW);

    delay(PWMLow2 - PWMLow3);
    pinMode(Phase1Trans, LOW);

    delay(PWMHigh - PWMLow1 - PWMLow2 - PWMLow3 - switchingPeriod);


    //print("PWM two low")
    //print("wait PWMHigh-PWM low 1")
    //print("PWM one low")
    //print("wait PWMHigh-PWMLow1-PWMLow2")
    //print("PWM three low")
    //print("wait PWMHigh-PWMLow1-PWMLow2-PWMLow3")

  }

  else if PWMThreeLow < PWMOneLow and PWMOneLow < PWMTwoLow) { // 3, 1, 2

  pinMode(Phase1Trans, HIGH);
    pinMode(Phase2Trans, HIGH);
    pinMode(Phase3Trans, HIGH);

    delay(PWMHigh - PWMLow1);
    pinMode(Phase3Trans, LOW);

    delay(PWMLow1 - PWMLow2);
    pinMode(Phase1Trans, LOW);

    delay(PWMLow2 - PWMLow3);
    pinMode(Phase2Trans, LOW);

    delay(PWMHigh - PWMLow1 - PWMLow2 - PWMLow3 - switchingPeriod);


    //print("PWM three low")
    //print("wait PWMHigh-PWM low 1")
    //print("PWM one low")
    //print("wait PWMHigh-PWMLow1-PWMLow2")
    //print("PWM two low")
    //print("wait PWMHigh-PWMLow1-PWMLow2-PWMLow3")
>>>>>>> Stashed changes
  }
  else (PWMThreeLow < PWMTwoLow and PWMTwoLow < PWMOneLow) { // 3, 2, 1

    pinMode(Phase1Trans, HIGH);
    pinMode(Phase2Trans, HIGH);
    pinMode(Phase3Trans, HIGH);

<<<<<<< Updated upstream
void Switchingcycle(degrees){ 
    //Function evaluates which MOSFETs should be driven in 60 degree increments

    if (degrees < 60:#0-60) {
        //print("1 high, 2 low, 3 high")
        //MOSFETS
        PhaseOneTransistor = 1;
        PhaseTwoTransistor = 5;
        PhaseThreeTransistor = 3;
    }
    else if (degrees < 120:#60-120) 
        //print("1 high, 2 low, 3 low")
        PhaseOneTransistor = 1;
        PhaseTwoTransistor = 5;
        PhaseThreeTransistor = 6;
    }
    else if (degrees < 180:#120-180) 
        //print("1 high, 2 high, 3 low")
        PhaseOneTransistor = 1;
        PhaseTwoTransistor = 2; 
        PhaseThreeTransistor = 6;
    }
   
    else if (degrees < 240:#180-240) 
        //print("1 low, 2 high, 3 high")
        PhaseOneTransistor = 4;
        PhaseTwoTransistor = 2; 
        PhaseThreeTransistor = 3;
    }
    else //(degrees      240-360)
        //print("1 low, 2 low, 3 high")
        PhaseOneTransistor = 4;
        PhaseTwoTransistor = 5; 
        PhaseThreeTransistor = 3;
=======
    delay(PWMHigh - PWMLow1);
    pinMode(Phase3Trans, LOW);

    delay(PWMLow1 - PWMLow2);
    pinMode(Phase2Trans, LOW);

    delay(PWMLow2 - PWMLow3);
    pinMode(Phase1Trans, LOW);

    delay(PWMHigh - PWMLow1 - PWMLow2 - PWMLow3 - switchingPeriod);

    //print("PWM one low")
    //print("wait PWMHigh-PWM low 1")
    //print("PWM two low")
    //print("wait PWMHigh-PWMLow1-PWMLow2")
    //print("PWM three low")
    //print("wait PWMHigh-PWMLow1-PWMLow2-PWMLow3")}
  }

  void Switchingcycle(degrees) {
    //Function envaluates which MOSFETs should be driven in 60 degree increments
    if (degrees < 60) { //0-60) 
      print("1 high, 2 low, 3 high")
      //MOSFETS
      PhaseOneTransistor = 1;
      PhaseTwoTransistor = 5;
      PhaseThreeTransistor = 3;
    }
    else if (degrees < 120) { //60-120
      print("1 high, 2 low, 3 low")
      PhaseOneTransistor = 1;
      PhaseTwoTransistor = 5;
      PhaseThreeTransistor = 6;
    }
    else if (degrees < 180) { //120-180
      print("1 high, 2 high, 3 low")
      PhaseOneTransistor = 1;
      PhaseTwoTransistor = 2;
      PhaseThreeTransistor = 6;
    }

    else if (degrees < 240) { //180-240
      print("1 low, 2 high, 3 high")
      PhaseOneTransistor = 4;
      PhaseTwoTransistor = 2;
      PhaseThreeTransistor = 3;
    }
    else {//(degrees      240-360)
      print("1 low, 2 low, 3 high")
      PhaseOneTransistor = 4;
      PhaseTwoTransistor = 5;
      PhaseThreeTransistor = 3;
>>>>>>> Stashed changes
    }
}

return PhaseOneTransistor, PhaseTwoTransistor, PhaseThreeTransistor
}
void loop() {
  for (int x = 0; x < 6; ++x) {
    p1mos, p2mos, p3mos = Switchingcycle(x * 10)
                          cycles = int(period / (switchingPeriod * 6)) //    #number of cycles in 60 degrees
    for (int y = 0; y < (cycles - 1); ++y ) {
      counter = cycles * x + y
                PWMCycleOrder(LineOneHigh[counter], LineOneLow[counter], LineTwoLow[counter], LineThreeLow[counter])//#takes in timing arguments
    }
  }
<<<<<<< Updated upstream
}    
  
  //for x in range(6):
  //  p1mos, p2mos, p3mos = Switchingcycle(x*10)
   // cycles= int(period/(switchingPeriod*6))//    #number of cycles in 60 degrees
   // for y in range(cycles-1):
     //   counter=cycles*x+y
     //   PWMCycleOrder(LineOneHigh[counter], LineOneLow[counter], LineTwoLow[counter], LineThreeLow[counter])//#takes in timing 
=======

  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  int frequency = 1; //Hz
  float period = 1 / frequency; //s
  float switchingPeriod = 0.05; //s
  float LineHigh = {0.0, 0.05, 0.1, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4, 0.45};
  float LineOneLow = {0.0, 0.065, 0.129, 0.19, 0.248, 0.3, 0.348, 0.39, 0.429, 0.466};
  float LineTwoLow = {0.043, 0.084, 0.12, 0.155, 0.19, 0.225, 0.263, 0.304, 0.35, 0.401};
  float LineThreeLow = { -0.043, 0.001, 0.05, 0.104, 0.163, 0.225, 0.289, 0.355, 0.42, 0.483};

  // map could replace dictionary with map<int, char> my
}

void PWMCycleOrder(PWMHigh; PWMOneLow; PWMTwoLow; PWMThreeLow; Phase1Trans; Phase2Trans; Phase3Trans) {
  //sort the turn off of the three lines into chronological order per switching cycle
  if (PWMOneLow < PWMTwoLow && PWMTwoLow < PWMThreeLow) { //1, 2 , 3
    pinMode(Phase1Trans, HIGH);
    pinMode(Phase2Trans, HIGH);
    pinMode(Phase3Trans, HIGH);

    delay(PWMHigh - PWMOneLow);
    pinMode(Phase1Trans, LOW);

    delay(PWMOneLow - PWMTwoLow);
    pinMode(Phase2Trans, LOW);

    delay(PWMTwoLow - PWMThreeLow);
    pinMode(Phase3Trans, LOW);

    delay(PWMHigh - PWMLow1 - PWMLow2 - PWMLow3 - switchingPeriod);
  }

  if (PWMOneLow < PWMThreeLow && PWMThreeLow < PWMTwoLow) { // 1, 3, 2

    pinMode(Phase1Trans, HIGH);
    pinMode(Phase2Trans, HIGH);
    pinMode(Phase3Trans, HIGH);
    //PWM one low
    delay(PWMHigh - PWMOneLow);
    pinMode(Phase1Trans, LOW);

    //PWM three low
    delay(PWMOneLow - PWMThreeLow);
    pinMode(Phase3Trans, LOW);
    //PWM two low
    delay(PWMTwoLow - PWMThreeLow);
    pinMode(Phase2Trans, LOW);

    delay(PWMHigh - PWMLow1 - PWMLow2 - PWMLow3 - switchingPeriod);
  }

  if (PWMTwoLow < PWMOneLow && PWMOneLow < PWMThreeLow) { //2, 1, 3
    pinMode(Phase1Trans, HIGH);
    pinMode(Phase2Trans, HIGH);
    pinMode(Phase3Trans, HIGH);
    //PWM two low
    delay(PWMHigh - PWMTwoLow);
    pinMode(Phase2Trans, LOW);

    //print("PWM one low")
    delay(PWMOneLow - PWMTwoLow);
    pinMode(Phase1Trans, LOW);

    //PWM three low
    delay(PWMTwoLow - PWMThreeLow);
    pinMode(Phase3Trans, LOW);

    delay(PWMHigh - PWMLow1 - PWMLow2 - PWMLow3 - switchingPeriod);
  }

  if (PWMTwoLow < PWMThreeLow && PWMThreeLow < PWMOneLow) { //:# 2, 3, 1
    //need to finish off doing these delays
    pinMode(Phase1Trans, HIGH);
    pinMode(Phase2Trans, HIGH);
    pinMode(Phase3Trans, HIGH);

    delay(PWMHigh - PWMOneLow);
    pinMode(Phase2Trans, LOW);

    delay(PWMOneLow - PWMTwoLow);
    pinMode(Phase3Trans, LOW);

    delay(PWMLow2 - PWMLow3);
    pinMode(Phase1Trans, LOW);

    delay(PWMHigh - PWMLow1 - PWMLow2 - PWMLow3 - switchingPeriod);


    //print("PWM two low")
    //print("wait PWMHigh-PWM low 1")
    //print("PWM one low")
    //print("wait PWMHigh-PWMLow1-PWMLow2")
    //print("PWM three low")
    //print("wait PWMHigh-PWMLow1-PWMLow2-PWMLow3")

  }

  else if PWMThreeLow < PWMOneLow and PWMOneLow < PWMTwoLow) { // 3, 1, 2

  pinMode(Phase1Trans, HIGH);
    pinMode(Phase2Trans, HIGH);
    pinMode(Phase3Trans, HIGH);

    delay(PWMHigh - PWMLow1);
    pinMode(Phase3Trans, LOW);

    delay(PWMLow1 - PWMLow2);
    pinMode(Phase1Trans, LOW);

    delay(PWMLow2 - PWMLow3);
    pinMode(Phase2Trans, LOW);

    delay(PWMHigh - PWMLow1 - PWMLow2 - PWMLow3 - switchingPeriod);


    //print("PWM three low")
    //print("wait PWMHigh-PWM low 1")
    //print("PWM one low")
    //print("wait PWMHigh-PWMLow1-PWMLow2")
    //print("PWM two low")
    //print("wait PWMHigh-PWMLow1-PWMLow2-PWMLow3")
  }
  else (PWMThreeLow < PWMTwoLow and PWMTwoLow < PWMOneLow) { // 3, 2, 1

    pinMode(Phase1Trans, HIGH);
    pinMode(Phase2Trans, HIGH);
    pinMode(Phase3Trans, HIGH);

    delay(PWMHigh - PWMLow1);
    pinMode(Phase3Trans, LOW);

    delay(PWMLow1 - PWMLow2);
    pinMode(Phase2Trans, LOW);

    delay(PWMLow2 - PWMLow3);
    pinMode(Phase1Trans, LOW);

    delay(PWMHigh - PWMLow1 - PWMLow2 - PWMLow3 - switchingPeriod);

    //print("PWM one low")
    //print("wait PWMHigh-PWM low 1")
    //print("PWM two low")
    //print("wait PWMHigh-PWMLow1-PWMLow2")
    //print("PWM three low")
    //print("wait PWMHigh-PWMLow1-PWMLow2-PWMLow3")}
  }

  void Switchingcycle(degrees) {
    //Function envaluates which MOSFETs should be driven in 60 degree increments
    if (degrees < 60) { //0-60) 
      print("1 high, 2 low, 3 high")
      //MOSFETS
      PhaseOneTransistor = 1;
      PhaseTwoTransistor = 5;
      PhaseThreeTransistor = 3;
    }
    else if (degrees < 120) { //60-120
      print("1 high, 2 low, 3 low")
      PhaseOneTransistor = 1;
      PhaseTwoTransistor = 5;
      PhaseThreeTransistor = 6;
    }
    else if (degrees < 180) { //120-180
      print("1 high, 2 high, 3 low")
      PhaseOneTransistor = 1;
      PhaseTwoTransistor = 2;
      PhaseThreeTransistor = 6;
    }

    else if (degrees < 240) { //180-240
      print("1 low, 2 high, 3 high")
      PhaseOneTransistor = 4;
      PhaseTwoTransistor = 2;
      PhaseThreeTransistor = 3;
    }
    else {//(degrees      240-360)
      print("1 low, 2 low, 3 high")
      PhaseOneTransistor = 4;
      PhaseTwoTransistor = 5;
      PhaseThreeTransistor = 3;
    }
}

return PhaseOneTransistor, PhaseTwoTransistor, PhaseThreeTransistor
}
void loop() {
  for (int x = 0; x < 6; ++x) {
    p1mos, p2mos, p3mos = Switchingcycle(x * 10)
                          cycles = int(period / (switchingPeriod * 6)) //    #number of cycles in 60 degrees
    for (int y = 0; y < (cycles - 1); ++y ) {
      counter = cycles * x + y
                PWMCycleOrder(LineOneHigh[counter], LineOneLow[counter], LineTwoLow[counter], LineThreeLow[counter])//#takes in timing arguments
    }
  }
=======
>>>>>>> Stashed changes
}

//for x in range(6):
//  p1mos, p2mos, p3mos = Switchingcycle(x*10)
// cycles= int(period/(switchingPeriod*6))//    #number of cycles in 60 degrees
// for y in range(cycles-1):
//   counter=cycles*x+y
//   PWMCycleOrder(LineOneHigh[counter], LineOneLow[counter], LineTwoLow[counter], LineThreeLow[counter])//#takes in timing
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
