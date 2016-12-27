
/*Author:Silicon TechnoLabs
www.silicontechnolabs.in*/
/*
  In this example we are interfacing temperature sensor LM35 and print result in serial monitor.  
  
  Temperature sensor LM35
  Reads an Temperature sensor input on pin A0, prints the result to the serial monitor.
  Attach the LM35 pin of a Digital & Analog IO Breakout Board to pin A0, and the 5v and GND pins to +5V and ground respectively.

 This example code is in the public domain.
 */
 
float tempCelsius;//Decalare variable to store temperature value in Celsius 
float tempFahrenheit;////Decalare variable to store temperature value in Fahrenheit
 
//Define LM35 pin
#define LM35_Outpin A0

// the setup routine runs once when you press reset:
void setup() 
{
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}
// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin A0(LM35_Outpin):
  int sensorValue = analogRead(LM35_Outpin);
  //The voltage output of the LM35 increases 10mV per degree Celsius rise in temperature.
  tempCelsius = ((sensorValue /1024)*5000)/10;//
  // print out the value of temperature in Celsius:
  Serial.print("DegreeC=");
  Serial.println(tempCelsius);
  
  //Convert Celsius to Fahrenheit
  Serial.print("Fahrenheit=");
  tempFahrenheit = (tempCelsius*9)/5 + 32;
  // print out the value of temperature in Fahrenheit:
  Serial.println(tempFahrenheit);
  
  delay(1000); // delay in between reads for stability
}
