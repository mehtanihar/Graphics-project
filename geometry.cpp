#include<iostream>
#include<math.h>
#include<conio.h>
#include<stdlib.h>
#include<algorithm>
#include<graphics.h>
using namespace std;

class Point
    {
        public:
        Point(float a,float b); //constructor
        float distance(void);


        float x;
        float y;

    };

Point::Point(float a,float b)
    {
        x=a;
        y=b;

    }

float Point::distance(void){

    return sqrt(x*x+y*y);

}
float distancelinepoint(Point p, Point q){
    return sqrt((p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y))  ;
}




int main()
    {
        int gdriver=DETECT,gmode;
        initgraph(&gdriver,&gmode,"C:\\tc\\bgi");
        initwindow(400,500);
        line(1,2,3);

   /* Point pt1(0,0);
    Point pt2(1,1);
    //cout<<distancelinepoint(pt1,pt2)<<endl;

  cout<<"kkjsnckajs"<<endl;
*/


    }
