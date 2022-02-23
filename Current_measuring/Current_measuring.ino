/************************************************************************

  Test of Pmod ISNS20 & Pmod SSR

*************************************************************************

  Description: Pmod_ISNS20, Pmod_SSR
  The current through a load will be measured

  Material
  1. Arduino Uno
  2. Pmod ISNS20
  3. Pmod SSR

  Wiring
  ISNS20 <----------> Arduino <----------> SSR
  -         to        5V          to        V
  VCC       to        3V3         to        -
  GND       to        GND         to        G
  CS        to        10          to        -
  DO        to        12(MISO)    to        -
  CLK       to        13(SCK)     to        -
  -         to        2           to        ON

************************************************************************/

#include <SPI.h> // call library

#define CS 10 //chip select pin
#define FILTER true //enable/disable digital filter
#define AVG_NUM 100 //number of readings to average (if filter is on)

float offset = 0; //variable to save measurement offset

float ISNS20_get_mA(bool is_offset = false);  //function prototype

void setup() {
  Serial.begin(9600); //initialize the serial monitor

  SPI.begin(); // initialization of SPI interface
  SPI.setDataMode(SPI_MODE0); // configuration of SPI communication in mode 0
  SPI.setClockDivider(SPI_CLOCK_DIV16); // configuration of clock at 1MHz
  pinMode(CS, OUTPUT);  //set chip select pin as output

  Serial.println("Disconnecting load to measure the offset");
  Serial.println("Measuring offset...");
  offset = ISNS20_get_mA(true);  //measure and save the offset
  Serial.println("Connecting the load");
}

void loop() {
  Serial.print("I = "); //display measured current
  Serial.print(ISNS20_get_mA()/2);//idk this is janky
  Serial.println("mA");

  delay(500); //arbitrary delay, to make the values readable
}

//measure with the sensor (send true as parameter to measure the offset)
float ISNS20_get_mA(bool is_offset) {
  float sum = 0;
  for (int i = 0; i < AVG_NUM; i++) {
    int temporal = 0;
    digitalWrite(CS, LOW);      //begin SPI transfer
    delay(1);
    temporal = SPI.transfer(0x00);   //transfer first byte in
    temporal <<= 8; //shift msb to place
    delay(1);
    temporal |= SPI.transfer(0x00);   //transfer and append second byte in
    delay(1);
    digitalWrite(CS, HIGH);     //end transfer
    delay(1);
    float result = temporal / 4096.0 * (-3.0);  //convert raw value to mA: bit result / 12 bits * 3.0V reference

    //if the measurement isn't for offset, correct the error
    if (!is_offset) {
      result = (result - offset) / 0.066; //correct offset: (result-offset)/(0.066V per Amp ratio)
    }

    //if no filtering is needed, return the result
    if (!FILTER) {
      return result;
    }

    sum += result;  //add partial results for averaging
  }
  sum /= AVG_NUM; //divide sum to get the average
  return sum;
}
