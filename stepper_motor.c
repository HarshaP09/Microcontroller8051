 #include <reg51.h>

sbit start = P1^0;
sbit rev = P1^1;
sbit inc = P1^2;
sbit dec = P1^3;
sbit stop = P1^4;

sbit EN1 = P2^0;
sbit EN2 = P2^1;
sbit IN1 = P2^4;
sbit IN2 = P2^5;
sbit IN3 = P2^6;
sbit IN4 = P2^7;

unsigned int speed = 300;    
bit dir = 0;          
bit motor_on = 0;            

void delay(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 100; j++);
}

void forward() {
    IN1 =1; IN2 =0; IN3= 0; IN4=0;
   delay(speed);
    IN1=0;IN2 =1; IN3=0; IN4= 0;
    delay(speed);
    IN1 =0; IN2=0; IN3=1; IN4=0;
    delay(speed);
    IN1=0; IN2 =0; IN3=0; IN4= 1;
    delay(speed);
}

void reverse() {
    IN1=0; IN2 =0; IN3=0; IN4= 1;
    delay(speed);
   IN1=0; IN2=0; IN3=1; IN4=0;
    delay(speed);
    IN1=0; IN2=1; IN3=0; IN4 = 0;
   delay(speed);
    IN1 =1; IN2=0; IN3=0; IN4 =0;
     delay(speed);
}

void main() {
EN1 = 1;    
EN2 = 1;

    while (1) {
    if (start == 0)  
  motor_on = 1;
		

    if (stop == 0)
    motor_on = 0;

    if (rev == 0)
   dir = ~dir;

   if (inc == 0 && speed > 50)
    speed -= 100;

     if (dec == 0 && speed < 1000)
     speed += 100;

        if (motor_on) {
         if (dir == 0)
         forward();
        else
         reverse();
        } else {
         IN1=IN2=IN3=IN4=0;  
        }
      delay(10); 
}
}



