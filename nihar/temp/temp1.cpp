
#include<iostream>
#include<graphics.h>

int main(){

int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"C:\\tc\\bgi");
line(20,30,30,30);

moveto(200,300);
delay(2000);
lineto(200,300);

getch();
}
