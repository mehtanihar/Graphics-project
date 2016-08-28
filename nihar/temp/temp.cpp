
#include<iostream>
#include<graphics.h>
using namespace std;

void create_beam(int x1, int y1, int x2, int y2){
bar(x1,y1,x2,y2);
}
void create_force(int x1, int y1){
line(x1,y1-50,x1,y1);
line(x1-10,y1-10,x1,y1);
line(x1+10,y1-10,x1,y1);
}


void move_force(){
int x1,y1;
//    x1=100; y1=100;
//line(x1,y1-50,x1,y1);
//line(x1-10,y1-10,x1,y1);
//line(x1+10,y1-10,x1,y1);
int num=0;
while(!ismouseclick(WM_LBUTTONDOWN))
{

}
while(ismouseclick(WM_LBUTTONDOWN) && !ismouseclick(WM_LBUTTONUP)){

x1=mousex(); y1=mousey();
if((num==0 && x1>380 && x1<420 && y1>240 && y1<300)|| num>0)
{


cleardevice();
create_beam(200,300,600,350);
create_force(x1,y1);
delay(100);
cout<<num<<endl;num++;
}
cout<<x1<<" "<<y1<<endl;create_beam(200,300,600,350);
}
}





int main(){

int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"C:\\tc\\bgi");
create_beam(200,300,600,350);

create_force(400,300);

/*
cout<<"Enter values for the beam:"<<endl;
int x1,y1,x2,y2;
cin>>x1>>y1>>x2>>y2;
create_beam(x1,y1,x2,y2);
*/
cout<<"Enter values for the force:"<<endl;
int x3,y3;
/*
while(!ismouseclick(WM_LBUTTONDOWN)){}
getmouseclick(WM_LBUTTONDOWN,x3,y3);

create_force(x3,y3);
*/
move_force();

        getch();




}
