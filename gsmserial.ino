/*

 Receives from the hardware serial, sends to software serial.
 Receives from software serial, sends to hardware serial.

 The circuit:
 * RX is digital pin 2 (connect to TX of other device)
 * TX is digital pin 3 (connect to RX of other device)

 */
#include <SoftwareSerial.h>

SoftwareSerial gsmSerial(2, 3); // RX, TX

void setup() 
{
  Serial.begin(9600);
  Serial.println("hi, serial setup is completed...");
  gsmSerial.begin(9600);
  Serial.println("hi, gsm serial setup is completed...");
}

void loop() 
{
  if (gsmSerial.available()) {
    Serial.write(gsmSerial.read());
  }
  if (Serial.available()) {
    gsmSerial.write(Serial.read());
  }
}

