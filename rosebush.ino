/*
Project is going to consist of an array of RGB LEDs that will promote plant growth
A moisture sensor to measure water content in the soil for the plant
Another LED either RGB or just a single color as a signal that the soil is below optimal moisture content and requires watering
Sensor reading is between 200 (dry) and 2000 (wet)
*/

//starting with the RGB LEDs that I know how to code up.
int R_Pin = 9;
int G_Pin = 10;
int B_Pin = 11;

//setting up a second set of RGB LEDs 
int R2_Pin = 3;
int G2_Pin = 5;
int B2_Pin = 6;

//the codes above might work for RGB LED strips as well

//initializing different ints for brightness

int redBrightness;
int greenBrightness;
int blueBrightness;

int redBrightness2;
int greenBrightness2;
int blueBrightnes2;

// intialize a single LED for signal LED for when the moisture content is low
int Signal_LED = 13;
int soilSensorValue = 0;
int thresholdUp = 400;
int thresholdDown = 250;

void setup() {
  //set the LED pins as OUTPUTS for plant growth.
  pinMode(R_Pin, OUTPUT);
  pinMode(G_Pin, OUTPUT);
  pinMode(B_Pin, OUTPUT);

  pinMode(R2_Pin, OUTPUT);
  pinMode(G2_Pin, OUTPUT);
  pinMode(B2_Pin, OUTPUT);
  pinMode(Signal_LED, OUTPUT);
  
  //set up and start the moisture sensor
  Serial.begin(9600);

}

void loop(){
  RGB_color(255, 0, 0); //Setting first set of LEDs to Red
  RGB_color2(0, 0, 255); //Setting second set of LEDs to Blue
  
 soilSensorValue = analogRead(A0);
  soilSensorValue = map(soilSensorValue,0,1023,0,500); //map
  Serial.println(soilSensorValue);
  if (soilSensorValue >= thresholdDown){
    Serial.println("Dry Water it!");
    digitalWrite(Signal_LED, HIGH);
    delay(1000);
  }
  else if (soilSensorValue <= thresholdUp){
    Serial.println("Wet Leave it!");
    digitalWrite(Signal_LED, LOW);
    delay(1000);
  }
}

void RGB_color(int R_Value, int G_Value, int B_Value)
 {
  //set the value to be written to the corresponding Pin
  analogWrite(R_Pin, redBrightness);
  analogWrite(G_Pin, greenBrightness);
  analogWrite(B_Pin, blueBrightness);
  /*found out my LEDs are using a common anode (+) for the long pin of the LED
  Because I am using the common anode (+) RGB LEDs the 255 is off and 0 is on for the RGB LED so the next set of code is required to get the LEDs to work properly.
  I also changed the R_Value above to correspond with the following code
  */

  redBrightness = 255 - R_Value;
  greenBrightness = 255 - G_Value;
  blueBrightnes = 255 - B_Value;
}

void RGB_color2(int R2_Value, int G2_Value, int B2_Value)
 {
  //set the value to be written to the corresponding Pin
   analogWrite(R2_Pin, redBrightness2);
  analogWrite(G2_Pin, greenBrightness2);
  analogWrite(B2_Pin, blueBrightnes2);

  redBrightness2 = 255 - R2_Value;
  greenBrightness2 = 255 - G2_Value;
  blueBrightnes2 = 255 - B2_Value;
}
