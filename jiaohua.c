#include<reg51.h>
#include<intrins.H>
#define uchar unsigned char
#define uint unsigned int 



void delayNs(n)
{
int i;
for(i = 0;i < 100; i++);
}

void delayDay(minus)
{
long n;
n = 86400 - minus;
delayNs(n);
}

// water program
int water1(i)
{
int minus = 60;
P3 = 0x00;
delayNs(minus);
P3 = 0xff;
return minus;
}

int water2(i)
{
int minus = 0;
if (i % 2 != 0)
return 0;
else
{
minus = 60;
P3 = 0x01;
delayNs(minus);
P3 = 0xff;
return minus;
}
}

int water3(i)
{
int minus = 0;
if (i % 3 != 0)
return 0;
else
{
minus = 60;
P3 = 0x02;
delayNs(minus);
P3 = 0xff;
return minus;
}
}

int water7(i)
{
int minus = 0;
if (i % 7 != 0)
return 0;
else
{
minus = 60;
P3 = 0x03;
delayNs(minus);
P3 = 0xff;
return minus;
}
}

int water15(i)
{
int minus;
if (i % 15 != 0)
return 0;
else
{
minus = 60;
P3 = 0x04;
delayNs(minus);
P3 = 0xff;
return minus;
}
}

int water30(i)
{
int minus = 0;
if (i % 30 != 0)
return 0;
else
{
minus = 60;
P3 = 0x05;
delayNs(minus);
P3 = 0xff;
return minus;
}
}
////////////////////////////////////////main
void main()// minus is the seconds  which is used to water the flower last day
{
uchar i=1;
uint minus = 0;
P3=0xff;

while(1)
{
delayDay(minus);
minus = 0;
minus += water1(i);
minus += water2(i);
minus += water3(i);
minus += water7(i);
minus += water15(i);
minus += water30(i);
i++;
if(i == 211)
i = 0;
}
}
