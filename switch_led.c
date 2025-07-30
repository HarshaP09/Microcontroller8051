#include <reg51.h>

void delay(unsigned int time) {
    unsigned int i, j;
    for(i = 0; i < time; i++)
        for(j = 0; j < 1000; j++);
}

void main() {
    unsigned char switches, leds;

    P1 = 0xFF;   
    P2 = 0x00;   

    while(1) {
        switches = P1;      
        leds = 0x00;

        if(switches != 0xFF) {
            leds = switches;    
            P2 = leds;         
        } else {
            P2 = 0x00;          
        }

        delay(10);
    }
}
