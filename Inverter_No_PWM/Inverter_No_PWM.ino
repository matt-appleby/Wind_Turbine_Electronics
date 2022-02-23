
int frequency=1;  //Hz
float period=1/frequency; //s
float switchingPeriod=500; //ms
float LineHigh[]={0.0, 500.0, 1000.0, 1500.0, 2000.0, 2500.0, 3000.0, 3500.0, 4000.0, 4500.0};
float LineOneLow[]={0.0, 650.0, 1290.0, 1900.0, 2480.0, 3000.0, 3480.0, 3900.0, 4290.0, 4660.0};
float LineTwoLow[]={431.0, 840.0, 1200.0, 1550.0, 2100.0, 2751.0, 3370.0, 3960.0, 4500.0, 4990.0};
float LineThreeLow[]={430.0, 990.0, 1500.0, 1960.0, 2370.0, 2750.0, 3100.0, 3550.0, 4200.0, 4830.0};
int Transistors[3]={1,2,3};

void setup() {
  pinMode(7,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  Serial.begin(9600);
}

void Switchingcycle(int degrees){ 
    //Function evaluates which MOSFETs should be driven in 60 degree increments
    if (degrees < 60) { //0-60
        //print("1 high, 2 low, 3 high")
        //MOSFETS
        pinMode(7, HIGH);
        pinMode(5, HIGH);
        pinMode(3, HIGH);
        pinMode(2, LOW);
        pinMode(4,LOW);
        pinMode(6,LOW);
        Serial.println("60");
    }
    else if (degrees < 120) { //60-120)
        //print("1 high, 2 low, 3 low")
        //PhaseOneTransistor = 1;
        //PhaseTwoTransistor = 5;
        //PhaseThreeTransistor = 6;

        pinMode(7, HIGH);
        pinMode(5, HIGH);
        pinMode(6, HIGH);
        pinMode(2, LOW);
        pinMode(4,LOW);
        pinMode(5,LOW);
        Serial.println("120");
    }
    else if (degrees < 180) {//120-180
        //print("1 high, 2 high, 3 low")
        //PhaseOneTransistor = 1;
        //PhaseTwoTransistor = 2; 
        //PhaseThreeTransistor = 6;       
        pinMode(7, HIGH);
        pinMode(2, HIGH);
        pinMode(6, HIGH);
        pinMode(3, LOW);
        pinMode(4,LOW);
        pinMode(5,LOW);
    }
    else if (degrees < 240){ //180-240 
        //print("1 low, 2 high, 3 high")
        
        pinMode(4, HIGH);
        pinMode(2, HIGH);
        pinMode(3, HIGH);
        pinMode(7, LOW);
        pinMode(3,LOW);
        pinMode(6,LOW);
        //PhaseOneTransistor = 4;
        //PhaseTwoTransistor = 2; 
        //PhaseThreeTransistor = 3;
    }
    else {                  //(degrees  240-360) ??
        //print("1 low, 2 low, 3 high")
        
        
        pinMode(4, HIGH);
        pinMode(5, HIGH);
        pinMode(3, HIGH);
        pinMode(2, LOW);
        pinMode(7,LOW);
        pinMode(6,LOW);
        //PhaseOneTransistor = 4;
        //PhaseTwoTransistor = 5; 
        //PhaseThreeTransistor = 3;
    }
    //int Transistors[3]={PhaseOneTransistor, PhaseTwoTransistor, PhaseThreeTransistor};
}
void loop() {
  for (int x = 0; x < 12; ++x) {
    //Switchingcycle(x*10);
    //int p1mos = Transistors[0];
    //int p2mos = Transistors[1];
    //int p3mos = Transistors[2];
    //int cycles= int(period/(switchingPeriod*6));//    #number of cycles in 60 degrees
    Switchingcycle(x*30);
    delay(1000);
  }
}
