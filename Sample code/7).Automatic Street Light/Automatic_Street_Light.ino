//street light control using Arduino

/* Simple test of the functionality of the (LDR) photo resistor

Connect the LDR pin of Digital & Analog Breakoutboard to the pin A0 of ARDUINO.
Connect Relay pin of Digital & Analog Breakoutboard to the pin 2 of ARDUINO.
And the 5v and GND pins to +5V and ground respectively.

*/

int LDR_Pin = A0; // select the input pin for the LDR
int Relay_pin = 2; // select the pin for the RELAY
int light_value = 0; // variable to store the value coming from the sensor

void setup()
{
// declare the ledPin as an OUTPUT:
pinMode(Relay_pin, OUTPUT);
}

void loop() 
{
  // read the value from the sensor:
  light_value = analogRead(LDR_Pin);
 
  if(light_value>=100) // SWITCH off the Relay when light level is high
  {
    digitalWrite(Relay_pin, LOW);
    delay(1000);
  }
  else// SWITCH ON the Relay when light level is LOW
  {
    digitalWrite(Relay_pin, HIGH);
    delay(1000);
  }
  delay(500);
}
