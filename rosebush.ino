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


/*starting with the RGB LEDs that I know how to code up
so I am using 2 RGB LEDs to create a blue and red light but the LEDs only need to be activated on one of the 4 legs that the LED has so.... theoretically if I just add 5v
to that leg of the LED wont the LED just turn whatever color that leg is?! Nope does not work that way... but... if I only use one pin to do 255 for the leg of the LED 
I want active I just have to attach one wire from the arduino to the LED on the leg I want. */
int R_Pin = 9;
int G_Pin = 5;
int B_Pin = 3;

//the codes above might work for RGB LED strips as well

// intialize a single LED for signal LED for when the moisture content is low
int Signal_LED = 13;

void setup() {
  //set the LED pins as OUTPUTS for plant growth.
  pinMode(R_Pin, OUTPUT);
  pinMode(G_Pin, OUTPUT);
  pinMode(B_Pin, OUTPUT);
  pinMode(Signal_LED, OUTPUT);
  
  //set up and start the moisture sensor
  Serial.begin(9600);
  Serial.println("Initializing");

}

void loop(){

  float tempF = sht1x.readTemperatureF();
  float humidity = sht1x.readHumidity();

  RGB_color(0, 0, 255); //Setting the leg of the LED to 255 so that I can 

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
  analogWrite(R_Pin, R_Value);
  analogWrite(G_Pin, G_Value);
  analogWrite(B_Pin, B_Value);

}
