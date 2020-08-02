/*
Project is going to consist of an array of RGB LEDs that will promote plant growth
A moisture sensor to measure water content in the soil for the plant
Another LED either RGB or just a single color as a signal that the soil is below optimal moisture content and requires watering
Sensor reading is between 200 (dry) and 2000 (wet)
*/

#include <SHT1x.h>
#define dataPin 10
#define clockPin 11
SHT1x sht1x(dataPin, clockPin);


//starting with the RGB LEDs that I know how to code up.
//int R_Pin = 9;
//int G_Pin = 10;
//int B_Pin = 11;

//setting up a second set of RGB LEDs 
int R2_Pin = 3;
int G2_Pin = 5;
int B2_Pin = 6;

//the codes above might work for RGB LED strips as well

// intialize a single LED for signal LED for when the moisture content is low
int Signal_LED = 13;

void setup() {
  //set the LED pins as OUTPUTS for plant growth.
  //pinMode(R_Pin, OUTPUT);
  //pinMode(G_Pin, OUTPUT);
  //pinMode(B_Pin, OUTPUT);

  pinMode(R2_Pin, OUTPUT);
  pinMode(G2_Pin, OUTPUT);
  pinMode(B2_Pin, OUTPUT);
  pinMode(Signal_LED, OUTPUT);
  
  //set up and start the moisture sensor
  Serial.begin(9600);
  Serial.println("Initializing");

}

void loop(){

  float tempF = sht1x.readTemperatureF();
  float humidity = sht1x.readHumidity();

  RGB_color(255, 0, 0); //Setting first set of LEDs to Red
  RGB_color2(0, 0, 255); //Setting second set of LEDs to Blue

  Serial.print ("Temerature: ");
  Serial.print (tempF, DEC);
  Serial.println ("F");
  Serial.print ("Humidity: ");
  Serial.print (humidity);
  Serial.println ("%");
  delay(1000);

  if(humidity <= 20 || humidity == 100){
    digitalWrite(13, HIGH);
  }
  else
    digitalWrite(13, LOW);
}
  
void RGB_color(int R_Value, int G_Value, int B_Value)
 {
  //set the value to be written to the corresponding Pin
  //analogWrite(R_Pin, R_Value);
  //analogWrite(G_Pin, G_Value);
  //analogWrite(B_Pin, B_Value);
}

void RGB_color2(int R2_Value, int G2_Value, int B2_Value)
 {
  //set the value to be written to the corresponding Pin
  analogWrite(R2_Pin, R2_Value);
  analogWrite(G2_Pin, G2_Value);
  analogWrite(B2_Pin, B2_Value);
}
