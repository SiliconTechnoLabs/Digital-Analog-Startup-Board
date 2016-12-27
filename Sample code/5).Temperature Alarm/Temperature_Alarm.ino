
/*Author:Silicon TechnoLabs
www.silicontechnolabs.in*/
/*
  In this example we are interfacing temperature sensor LM35 & Buzzer, Buzzer will sounds when temperature out of predefine range.  
  
  Temperature Alarm
  Attach the LM35 pin of a Digital & Analog IO Breakout Board to pin A0 of arduino,
  Attach the BUZZER pin of Digital & Analog IO Breakout Board to pin 3 of arduino,
  And the 5v and GND pins to +5V and ground respectively.

 This example code is in the public domain.
 */
 
float tempCelsius;//Decalare variable to store temperature value in Celsius 
 
//Define LM35 pin & Buzzer pin
#define LM35_Outpin A0
#define Buzzer_pin 3 

// the setup routine runs once when you press reset:
void setup() 
{
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // initialize the Buzzer pin as an output.
  pinMode(Buzzer_pin,OUTPUT);
}
// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin A0(LM35_Outpin):
  int sensorValue = analogRead(LM35_Outpin);
  //The voltage output of the LM35 increases 10mV per degree Celsius rise in temperature.
  tempCelsius = ((sensorValue /1024)*5000)/10;
  // print out the value of temperature in Celsius:
  Serial.print("DegreeC=");
  Serial.println(tempCelsius);
  //If measured temperature within 20=<temperature<=50 buzzer will not sound
  if(tempCelsius>=20 && tempCelsius<=50)
  {
    digitalWrite(Buzzer_pin, HIGH);   // turn the BUZZER on (HIGH is the voltage level)
  }
  else
  {
    digitalWrite(Buzzer_pin, LOW);   // turn the BUZZER off (LOW is the voltage level)
  }
  delay(1000); // delay in between reads for stability
}
