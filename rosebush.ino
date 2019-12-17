/*
Project is going to consist of an array of RGB LEDs that will promote plant growth
A moisture sensor to measure water content in the soil for the plant
Another LED either RGB or just a single color as a signal that the soil is below optimal moisture content and requires watering
Sensor reading is between 200 (dry) and 2000 (wet)
*/

//include library for moisture sensor

#include "Adafruit_seesaw.h"

//not sure what this line is for but it is on the adafruit example so I am keeping it until no longer required
Adafruit_seesaw ss;

//starting with the RGB LEDs that I know how to code up.
int R_Pin 9;
int G_Pin 10;
int B_Pin 11;
// intialize a single LED for signal LED for when the moisture content is low
int Signal_LED 1;

void setup() {
  //set the LED pins as OUTPUTS
  pinMode(R_Pin, OUTPUT);
  pinMode(G_Pin, OUTPUT);
  pinMode(B_Pin, OUTPUT);
  pinMode(Signal_LED, OUTPUT);
  
  //set up and start the moisture sensor
  Serial.begin(115200);
  
  Serial.println("seesaw Soil Sensor example!");
  
  if (!ss.begin(0x36)) {
   Serial.println("ERROR! seesaw not found");
   while(1);
   }
  else {
    Serial.print("seesaw started! version: ");
    Serial.println(ss.getVersion(), HEX);
  }
}

void loop(){
  RGB_color(255, 0, 255); //supposed to be the best color for growth
  //RGB_color(255, 0, 0); If growth doesn't improve with the "purple" color then Red and Blue 
  //RGB_color(0, 0, 255);
  
  float tempC = ss.getTemp();
  uint16_t capread = ss.touchRead(0);
  
  Serial.print("Temperature: "); Serial.print(TempC); Serial.println("*C);
  Serial.print("Capacitve: "); Serial.println(capread);
  Delay(1000);
                                  
  // if the moisture in the soil is less than or equal to 300 (200 being dry) set the Signal_LED to high
  if (capread <=300) {
    digitalWrite(Signal_LED, HIGH);
  }
  else {
    digitalWrite(Signal_LED, LOW);
  }
}

void RGB_color(int R_Value, int G_Value, int B_Value)
 {
  //set the value to be written to the corresponding Pin
  analogWrite(R_Pin, R_Value);
  analogWrite(G_Pin, G_Value);
  analogWrite(B_Pin, B_Value);
}
