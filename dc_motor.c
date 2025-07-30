


// CODE-1
//simple dc motor run

#include <reg51.h>


sbit EN1 = P2^0;

sbit IN1 = P2^4;   
sbit IN2 = P2^5;   

void delay(unsigned int time) {
    unsigned int i, j;
    for(i = 0; i < time; i++)
     for(j = 0; j < 1275; j++);
}

void main() {
    
    EN1 = 1;    
    IN1 = 1;   
    IN2 = 0;

    while(1) {
        
    }
}

/*

//CODE-2
//DC MOTOR CONTROLLED BY SWITCHES
#include <reg51.h>

sbit start = P1^0;
sbit stop  = P1^4;
sbit inc   = P1^2;
sbit dec   = P1^3;
sbit rev   = P1^1;

sbit EN1 = P2^0;
sbit ip1 = P2^4;
sbit ip2 = P2^5;

unsigned int duty= 20;  
bit motor_on = 0;
bit direction = 0;

void delay(unsigned int time) {
	unsigned int i;
	while(time--) for(i=0;i<10;i++);
}

void motor() {
	if(motor_on) {
		if(direction == 0) {
			ip1 = 1;
			ip2 = 0;
		} else {
			ip1 = 0;
			ip2 = 1;
		}

		EN1 = 1;
		delay(duty);             
		EN1 = 0;
		delay(100 - duty);     
	} else {
		EN1 = 0;
		ip1 = 0;
		ip2 = 0;
	}
}

void main() {
	P1 = 0xFF;
	P2 = 0x00;

	while(1) {
		if(start == 0) {
			motor_on = 1;
			delay(1000);
		}

		if(stop == 0) {
			motor_on = 0;
			delay(1000);
		}

		if(inc == 0 && duty < 95) {
			duty += 5;
			delay(1000);
		}

		if(dec == 0 && duty > 5) {
			duty -= 5; 
			delay(1000);
		}

		if(rev == 0) {
			direction = ~direction;
			delay(1000);
		}

		motor();  
	}
}
*/