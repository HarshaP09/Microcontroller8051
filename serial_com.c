

#include<reg51.h> void
main(void)

{
unsigned char a=0 ,s[25]= "HARSHA PANDHARE";
TMOD = 0x20;
TH1 = 0xFD;
SCON = 0x50;
TR1 = 1;
while(1)
{ while(s[a]!='\0')
{
SBUF = s[a];
while(TI==0);
TI=0; a++;
}
}
}


/*
#include<reg51.h> void
main(void)

{
unsigned char a=0,serial_data;
TMOD=0x20;
TH1=0xFD;
SCON=0x50;
TR1=1;
while(1)

{ while(!RI);
serial_data=SBUF;
RI=0;
SBUF=serial_data;
while(TI==0); TI=0;
}
}*/