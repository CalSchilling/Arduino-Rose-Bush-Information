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
  pinMode(Signal_LED, OUTPUT);
  
  //set up and start the moisture sensor
  Serial.begin(9600);

}

void loop(){
  RGB_color(255, 0, 255); //Setting the LED color to Purple a mix of red and blue to help stimulate growth according to a couple articles I read

  
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
  analogWrite(R_Pin, R_Value);
  analogWrite(G_Pin, G_Value);
  analogWrite(B_Pin, B_Value);
}
