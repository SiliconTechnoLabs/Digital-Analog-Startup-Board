/* Simple test of the functionality of the (LDR) photo resistor

Connect the LDR pin of Digital & Analog Breakoutboard to the pin A0 of ARDUINO.
Connect One LED of Digital & Analog Breakoutboard to the pin 2 of ARDUINO.
And the 5v and GND pins to +5V and ground respectively.

----------------------------------------------------

           PhotoR     10K
 +5    o---/\/\/--.--/\/\/---o GND
                  |
 A0 o-------------

----------------------------------------------------
*/

int LDR_Pin = 0;  //define a pin for Photo resistor
int ledPin=2;     //define a pin for LED

void setup()
{
    Serial.begin(9600);  //Begin serial communcation
    pinMode( ledPin, OUTPUT );
}

void loop()
{
    Serial.println(analogRead(LDR_Pin)); //Write the value of the photoresistor to the serial monitor.
    analogWrite(ledPin, analogRead(LDR_Pin)/4);  //send the value to the ledPin. Depending on value of resistor 
                                                //you have  to divide the value. for example, 
                                                //with a 10k resistor divide the value by 2, for 100k resistor divide by 4.
   delay(10); //short delay for faster response to light.
}
