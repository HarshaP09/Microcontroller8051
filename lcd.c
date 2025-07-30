#include <reg51.h>

#define lcd_data P1
#define keypad   P0

sbit RS = P2^0;
sbit RW = P2^1;
sbit EN = P2^2;

char key_map[4][4] = {
  {'0','1','2','3'},
  {'4','5','6','7'},
  {'8','9','A','B'},
  {'C','D','E','F'}
};

void delay(unsigned int ms) {
  unsigned int i, j;
  for(i = 0; i < ms; i++)
    for(j = 0; j < 1275; j++);
}

void lcd_cmd(unsigned char cmd) {
  RS = 0; RW = 0;
  lcd_data = cmd;
  EN = 1; delay(2); EN = 0;
}

void lcd_char(unsigned char val) {
  RS = 1; RW = 0;
  lcd_data = val;
  EN = 1; delay(2); EN = 0;
}

void lcd_string(char *s) {
  while(*s) {
    lcd_char(*s++);
  }
}

void lcd_init() {
  lcd_cmd(0x38);
  lcd_cmd(0x0C);
  lcd_cmd(0x01);
  lcd_cmd(0x80);
}

char get_key() {
  unsigned char row, col;
  for(row = 0; row < 4; row++) {
    keypad = 0xFF;
    keypad &= ~(1 << row);
    delay(1);
    for(col = 0; col < 4; col++) {
      if(!(keypad & (1 << (4 + col)))) {
        delay(20);
        while(!(keypad & (1 << (4 + col))));
        return key_map[row][col];
      }
    }
  }
  return 0;
}

void main() {
  char key;
  lcd_init();
  lcd_cmd(0x80);
  lcd_string("pressed value is:");
  while(1) {
    key = get_key();
    if(key) {
      lcd_cmd(0xC0);   
      lcd_char(key);
      delay(500);
    }
  }
}
