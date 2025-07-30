//LED blinking


// PATTERN 1- ALL LEDs ON/OFF

#include <reg51.h>

void delay(unsigned int time)
{
    unsigned int i, j;
    for(i = 0; i < time; i++)       
    {
        for(j = 0; j<40000; j++);  
    }
}


void main()
{
    while(1){
      P0 = 0xFF;  
     delay(1);  
     P0 = 0x00;  
      delay(1);
    }
}


/*
// PATTERN 2- ALTERNATE LEDs ON/OFF

#include<reg51.h> void delay
(unsigned int time)
{
unsigned int i ; for(i=0 ;
i<time ; i++);
}
void main()
{ while(1)
{

P0 = 0x55 ; // EVEN LEDs ON
delay(20000) ; 
P0 =0xAA ; //ODD LEDs ON 
	delay(20000);
}
}

//PATTERN 3- UPPER NIBBLE-LOWER NIBBLE LEDs ON/OFF

#include<reg51.h> void delay
(unsigned int time)
{ unsigned int i ; for(i=0 ;
i<time ; i++);

}
void main()
{ while(1)
{
P0 = 0xF0 ;  //UPPER NIBBLE ON
delay(20000) ; // FOR TIME DELAY 
	P0 =0x0F ;  //FOR LOWER NIBBLE ON 
	delay(20000);
}



// INCREASING COUNT FROM 00-FF
#include <reg51.h>

void delay(unsigned int t) {
    unsigned int i;
    for (i = 0; i < t; i++);
}

void main() {
    int i;
    for (i = 0x00; i <= 0xFF; i++) {
        P0 = i;
        delay(50000); 
    }
}

*/