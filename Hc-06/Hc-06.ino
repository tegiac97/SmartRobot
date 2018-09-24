#include<SoftwareSerial.h>
char junk;
char inputString =' ';

SoftwareSerial BT(0, 1);        //init bluetooth

void setup()                    // run once, when the sketch starts
{
  BT.begin(9600);            // set the baud rate to 9600, same should be of your Serial Monitor
  Serial.begin(9600);
}

void loop()
{
  if (BT.available()) {
    inputString = BT.read();
    Serial.print(inputString);
  }
}
