#include <reg51.h>

#define seg P1       
#define keys P0     


sbit c1 = P2^0;
sbit c2 = P2^1;
sbit c3 = P2^2;
sbit c4 = P2^3;


unsigned char seg_code[16] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0x88, 0x83,0xC6, 0xA1, 0x86, 0x8E };


unsigned char key_map[4][4] = {
  {0x0, 0x1, 0x2, 0x3},
  {0x4, 0x5, 0x6, 0x7},
  {0x8, 0x9, 0xA, 0xB},
  {0xC, 0xD, 0xE, 0xF}
};

void delay(unsigned int ms) {
  unsigned int i, j;
  for(i = 0; i < ms; i++)
    for(j = 0; j < 1275; j++);
}


unsigned char get_key() {
  unsigned char row, col;
  
  for(row = 0; row < 4; row++) {
    keys = 0xFF; 
    keys &= ~(1 << row); 

    delay(2); 

    for(col = 0; col < 4; col++) {
      if((keys & (0x10 << col)) == 0) { 
        delay(20); 
        while((keys & (0x10 << col)) == 0); 
        return key_map[row][col]; 
   }
  }
  }
  
  return 0xFF; 
}


void display(unsigned char val) {
  seg = seg_code[val];

  c1 = c2 = c3 = c4 = 0;  
  delay(5);                           
  c1 = c2 = c3 = c4 = 1; 
}

void main() {
  unsigned char key;

  c1 = c2 = c3 = c4 = 1; 
  seg = 0xFF;                       

  while(1) {
    key = get_key();

    if(key != 0xFF && key < 16) {
      display(key); 
    }
  }
}
