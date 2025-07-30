#include <reg51.h>

unsigned char display[10] = {0x3F,0x06, 0x5B, 0x4F,0x66, 0x6D, 0x7D, 0x07,0x7F, 0x6F};


sbit dis1 = P0^0;
sbit dis2 = P0^1;
sbit dis3 = P0^2;
 sbit dis4 = P0^3;

void delay(unsigned int time) {
    unsigned int i, j;
    for(i = 0; i <time; i++)
  for(j = 0; j <1000; j++);
}

void main() {
    unsigned char i;

  dis1 = 0;
 dis2 = 0;
  dis3 = 0;
 dis4 = 0;

    while(1) {
        for(i = 0; i < 10; i++) {
         P2 = ~display[i]; 

    dis1 = 1;
     dis2 = 1;
     dis3 = 1;
       dis4 = 1;

       delay(200);  
 }
 }
}
