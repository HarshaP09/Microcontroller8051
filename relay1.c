#include <reg51.h>

sbit relay = P2^0;
sbit button = P2^2;

void delay(unsigned int time)
{
    unsigned int i, j;
    for (i = 0; i < time; i++)
    for (j = 0; j < 120; j++);
}

void main(void)
{
  bit state = 0;
 relay = 1;      
  button = 1;     

    while (1)
    {
      if (button == 0)  
     {
        delay(20);          
       if (button == 0) {
        state = !state;         
         relay = !state;         
        while (button == 0);    
         delay(20);             
}
}
}
}
