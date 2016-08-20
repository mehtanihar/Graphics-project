#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

class Point
    {
        public:
        Point(float a,float b); //constructor
        float distance(void);

        private:
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





int main()
    {

    Point pt(2,3);
    cout<<pt.distance()<<endl;



    }
