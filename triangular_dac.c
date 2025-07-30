
// SQUARE WAVE 

#include <reg51.h>

void delay (unsigned int time)
{
 unsigned int i,j;
	for(i=0;i<time;i++)
	for(j=0;j<10;j++);
	
}

void main(){
 while(1){
  
	 P2=0xFF;
	 delay(50);
	 P2=0x00;
	 delay(50);
 }
  
}


 /*
//TRIANGULAR WAVE 

#include <reg51.h>

void delay(unsigned int time){
 unsigned int i,j;
	for(i=0;i<time;i++)
	for(j=0;j<1000;j++);

}

void main(){
unsigned int i,j;
	
	while(1){
	
		for(i=0;i<256;i++)
		P2 = i;
		for(j=255;j>0;j--)
		P2=j;
	
	}

}

*/



/*

//SAWTOOTH WAVE 

#include <reg51.h>

void delay(unsigned int time){
	
unsigned int i,j ;
	
	for(i=0;i<time;i++)
		for(j=0;j<1000;j++);
}

void main(){
unsigned int i;
	while(1){
	for(i=0;i<256;i++)
	P2=i;

}}


*/


/*

// 3 STEP STAIRCASE WAVE 

#include <reg51.h>

void delay(unsigned int time)
{
 unsigned int i,j ;

for(i=0;i<time;i++)
for(j=0;j<1000;j++);	
}

void main()
{
int i,j;
while(1){

    for(i=0;i<=255;i=i+85)
    {
      P2=i;
     delay(500);
     }
    for(j=254;j>=0;j=j-85)
   {
   P2=j;
   delay(500);
}
}
}

*/



/*
// 5 STEP STAIRCASE WAVE 
#include <reg51.h>

void delay(unsigned int time)
{
 unsigned int i,j ;

for(i=0;i<time;i++)
for(j=0;j<10;j++);	
}

void main()
{
  int i,j;
  while(1){

  for(i=0;i<=255;i=i+51)
    {
      P2=i;
     delay(10);
     }
   for(j=255;j>=0;j=j-51)
{
   P2=j;
   delay(10);
  }
  
 }
}
*/

/*
//SINE WAVE 

#include <reg51.h>

unsigned char sine_table[32] = {128, 152, 176, 198, 218, 234, 245, 252,255, 252, 245, 234, 218, 198, 
	176, 152,128, 104, 80,  58,  38,  22,  11,   4, 0,   4, 11,  22,  38,  58,  80, 104
};

void delay(unsigned int time) {
  unsigned int i, j;
  for(i = 0; i < time; i++)
    for(j = 0; j < 100; j++);
}

void main() {
  int i;
  while(1) {
    for(i = 0; i < 32; i++) {
      P2 = sine_table[i];  
      delay(1);            
    }
  }
}

*/