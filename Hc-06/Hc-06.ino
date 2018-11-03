#include<SoftwareSerial.h>
#include<string.h>


char inputString;
char fullString[30];
int i=0;

SoftwareSerial BT(0, 1);        //init bluetooth

void setup()                    // run once, when the sketch starts
{
  BT.begin(9600);            // set the baud rate to 9600, same should be of your Serial Monitor
  Serial.begin(9600);
}

void loop()
{
  if (BT.available()) {
    while (BT.available()) {
      inputString = BT.read();
      if (inputString != 'z') {
        fullString[i] = inputString;
        //Serial.print(i);  
        //Serial.println(inputString);
        delay(10);
        i++;
      }
      else{
        i = 0;
        Serial.println(fullString);
      }
    }
    
    
    memset(fullString, NULL, strlen(fullString));
  }
  if(strcmp("tien",fullString)==0){
     Serial.println("rignt command!");

    }
}
