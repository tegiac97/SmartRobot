#include<SoftwareSerial.h>
#include<string.h>
//#include<avr/interrupt.h>

char inputString;
char fullString[30];
int i = 0;
int sign = 0;

SoftwareSerial BT(8, 9);        //init bluetooth

void uart_init(signed long rate) {
  UCSR0A = 0 << TXC0 | 0 << U2X0 | 0 << MPCM0;
  UCSR0B = 1 << RXCIE0 | 0 << TXCIE0 | 0 << UDRIE0 | 1 << RXEN0 | 0 << TXEN0 | 0 << UCSZ02 | 0 << TXB80;
  UCSR0C = 0 << UMSEL01 | 0 << UMSEL00 | 0 << UPM01 | 0 << UPM00 | 0 << USBS0 | 1 << UCSZ01 | 1 << UCSZ00 | 0 << UCPOL0;
  UBRR0 = (F_CPU / 16 / rate - 1);
}

void setup()                    // run once, when the sketch starts
{
  cli();
  //BT.begin(9600);            // set the baud rate to 9600, same should be of your Serial Monitor
  //Serial.begin(9600);
  uart_init(9600);
  sei();
}

void loop() {
  if (sign == 1 && strcmp("tien", fullString) == 0) {
    //Serial.println(fullString);
    //Serial.println("fullString");
    digitalWrite(13, HIGH);
    sign = 0;
  }
  else if (sign == 1 && strcmp("lui", fullString) == 0) {
    digitalWrite(13, LOW);
    sign = 0;
  }

  //    if(strcmp("tien",fullString)==0){
  //       Serial.println("rignt command!");
  //      }
  memset(fullString, NULL, strlen(fullString));
}

ISR (USART_RX_vect) {
  inputString = UDR0;
  if (inputString != 'z') {
    fullString[i] = inputString;
    //Serial.print(i);
    //Serial.println(inputString);
    delay(10);
    i++;
  }
  else {
    i = 0;
    //Serial.println(fullString);
    sign = 1;
  }
}
