#include "pinMap.h"
#include "matrix.h"
#include "charakter.h"

uint8_t a;
int c;// unötig
byte b = -1;// für die spalten 
byte d;// für die bustaben 
int counter;
byte* hallo[5]= {
  H,A,L,L,O
};
void setup() {
  // Setup code to run once
  DDRC = 0xff;  // Set PORTC as output
  DDRA = 0xff;  // Set PORTA as output
  Serial.begin(9600);  // Initialize serial communication
  pinMode(F_0,0);
 
}



void loop() {
  
  // Loop through the different bits of PORTA
   
     for (int i = 0; i <= 4; i++) {
    a = (1 << i);  // Bit-shift directly

    a = a & 0b00011111;  // Beschränkung auf 5 Bits
    a = ~a & 0b00011111;  // Invertiere und beschränke auf 5 Bits
    
    
    b = b+1;
    // Set PORTC according to the inverted value of PORTA
    if (b >= 5) {        // Wenn alle Spalten durchlaufen sind, wieder von vorne beginnen
        b = 0;
    }
    
    matrix(a,hallo[d][i]);
    delay(1);
    counter++;
    
    if (counter >= analogRead(F_0)) {   // Ändere die Zahl, um die Geschwindigkeit der Bewegung anzupassen
      counter = 0;
      c= c+1;
       b = b+1;
      if (c >= 5){
        c = 0;
       
        d = d + 1;// Wechsle zum nächsten muster
        if (d >=5){
          d = 0;
        }
      }
      if (b >= 5) {        // Wenn alle Spalten durchlaufen sind, wieder von vorne beginnen
        b = 0;
      }
      
    }
    
    }
    
  }
