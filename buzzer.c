#include <reg51.h>

sbit buzzer = P1^1;
sbit button_buzzer = P1^3;

void delay(unsigned int time){
unsigned int i,j ;
	for(i=0 ; i<time ; i++)
	for(j=0 ;j<120 ; j++);
}

void main(){
		bit state = 0;
 buzzer = 1;
	button_buzzer = 1;
	

	
	while(1){
	if(button_buzzer ==0){
	 delay(20);
		
		if(button_buzzer ==0){
		state = !state;
			buzzer = !state;
		while(button_buzzer==0);
			delay(20);
	}
	
	}
	}
	
}
