#include<iostream>
#include<math.h>
#include<algorithm>
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

    Point pt1(0,0);
    Point pt2(1,1);
    //cout<<distancelinepoint(pt1,pt2)<<endl;

  cout<<"kkjsnckajs"<<endl;



    }
