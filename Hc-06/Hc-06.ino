
#include<SoftwareSerial.h>
#include<string.h>
#include<avr/interrupt.h>

char inputString;
char fullString[6];
int i = 0;
int sign = 0;

//SoftwareSerial BT(8, 9);        //init bluetooth

void uart_init(signed long rate) {
  UCSR0A = 1 << TXC0 | 0 << U2X0 | 0 << MPCM0;
  UCSR0B = 1 << RXCIE0 | 1 << TXCIE0 | 0 << UDRIE0 | 1 << RXEN0 | 1 << TXEN0 | 0 << UCSZ02 | 0 << TXB80;
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
//if (inputString=1) digitalWrite(13, HIGH);
//else if (inputString==0) digitalWrite(13, LOW);




  
    if (sign == 1 && strcmp("tien", fullString) == 0) {
      digitalWrite(13, HIGH);
      sign = 0;
    }
    else if (sign == 1 && strcmp("lui", fullString) == 0) {
      digitalWrite(13, LOW);
      sign = 0;
    }
    memset(fullString, '\0', strlen(fullString));
}

ISR (USART_RX_vect) {
  inputString = UDR0;
  
  
  //Chuyen cac ki tu rieng le vao chuoi
  if (inputString != 'z') {
    fullString[i] = inputString;
    UDR0=fullString[i];
    i++;
    delayMicroseconds(10);
//    //Neu buffer trong
//    if (RXC0 == 0) {
//      digitalWrite(13, HIGH);
//    }
  }
  else if (inputString == 'z'){
    i = 0;
    sign = 1;
  }
  
}

ISR(USART_TX_vect) {
  
}
