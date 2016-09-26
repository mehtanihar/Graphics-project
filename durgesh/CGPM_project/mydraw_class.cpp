#include "mydraw_class.hpp"
#include <vector>
//-------------------
//color_t methods
extern canvas_t canvas;
extern pen_t pen;
extern color_t globalcolor;

color_t::color_t():r(0),g(1.0),b(1.0) { }

color_t::color_t(const float _r, const float _g, const float _b)
		 :r(_r),g(_g),b(_b) { }

void color_t::set(const float _r, const float _g, const float _b)
{
  r=_r; g=_g; b=_b;
}

float color_t::R(void) { return r; }
float color_t::G(void) { return g; }
float color_t::B(void) { return b; }

point_t::point_t(){ };
point_t::point_t(int xp,int yp)
{
	x=xp;
	y=yp;
}
void point_t::operator=(point_t p)
{
	x=p.x;
	y=p.y;
	c=p.c;
};
point_t::~point_t(){ };

pen_t::pen_t(){
	penstate=1;
	size = 2; // 0; neutral;  1 for drawing; 2 erase
};//draw_size=3;};
pen_t::~pen_t(){ };


triangle_t::triangle_t(){};
triangle_t::~triangle_t(){};
triangle_t::triangle_t(point_t s1,point_t s2, point_t s3)
{
	p1=s1;
	p2=s2;
	p3=s3;
};
triangle_t::triangle_t(point_t s1,point_t s2, point_t s3, color_t bord,color_t fillu)
{
	p1=s1;
	p2=s2;
	p3=s3;
	border_color= bord;
	fill_color= fillu;
};

void triangle_t::triangle_draw(){
	line_t l1(p1,p2);
	l1.bres();
	line_t l2(p2, p3);
	l2.bres();
	line_t l3(p3, p1);
	l3.bres();
}


canvas_t::canvas_t(){ width=512; height=512; bkgnd.set(.0f,.0f,.0f);
	screen_array = new float[width*height*3];
for(int i=0;i<width*height-40;i=i+1){
	screen_array[3*i]=bkgnd.R();
	screen_array[3*i+1]=bkgnd.G();
	screen_array[3*i+2]=bkgnd.B();
}

};
canvas_t::~canvas_t(){ };

void canvas_t::setpix(point_t* p){
	screen_array[p->x*3 + (width - p->y -1)*height*3]=pen.c.R();
	screen_array[p->x*3 + (width - p->y -1)*height*3 +1]=pen.c.G();
	screen_array[p->x*3 + (width - p->y -1)*height*3 +2]=pen.c.B();
}

void point_t::draw(int size)
	{
		point_t p1;
		for (int i =0;i<2*size-1;i++){
			for (int j=0;j<2*size-1;j++){
				p1 = point_t(x+i-size, y+j-size);
				point_t* abc = &p1;
				canvas.setpix(abc);

			}
		}

	}

line_t::line_t(point_t w1, point_t w2)
{
	p1=w1;
	p2=w2;
};

line_t::line_t(){};
line_t::~line_t(){};

void swap (int &x, int &y)
		{
  		int temp = x;
  		x = y; y = temp;
		}

fill_t::fill_t()
{
	fill_color.set(0.2f,0.5f,0.9f);
}

void fill_t::fill_triangle(point_t p1,point_t p2,point_t p3)
{
	for (int i=0; i<canvas.width; i++)
	{
		for (int j=0; j<canvas.height; j++)
		{
			point_t p0=point_t(i,j); // the point corresponding to a pixel onthe screen is po
			if (filling(p0,p1,p2,p3))
			{
				canvas.setpix(&p0);
			}

		}
	}


	line_t l1(p1,p2);
	l1.bres();
	line_t l2(p2, p3);
	l2.bres();
	line_t l3(p3, p1);
	l3.bres();
}

bool fill_t::filling(point_t f,point_t p1,point_t p2,point_t p3){
//f.x=0;
//f.y=0;
float m1 = (float)(p1.y-p2.y)/(float)(p1.x-p2.x);
float m2 = (float)(p3.y-p2.y)/(float)(p3.x-p2.x);
float m3 = (float)(p1.y-p3.y)/(float)(p1.x-p3.x);
float c1 = (float)p1.y- m1*(float)p1.x;
float c3 = (float)p1.y- m3*(float)p1.x;
float c2 = (float)p2.y- m2*(float)p2.x;
float cenx = (float)(p1.x+p2.x+p3.x)/3.0;
float ceny = (float)(p1.y+p2.y+p3.y)/3.0;
//std::cout<<m1<<" "<<m2<<" "<<m3<<" "<<c1<<" "<<c2<<" "<<c3<<" "<<std::endl;

//std::cout<<(m1*cenx+c1-ceny)<<" "<<(m1*(float)f.x+c1-(float)f.y)<<" "<<std::endl;
//std::cout<<(m2*cenx+c2-ceny)<<" "<<(m2*(float)f.x+c2-(float)f.y)<<" "<<std::endl;
//std::cout<<(m3*cenx+c3-ceny)<<" "<<(m3*(float)f.x+c3-(float)f.y)<<" "<<std::endl;


if((((m1*cenx+c1-ceny)*(m1*(float)f.x+c1-(float)f.y))>0)&&((m2*cenx+c2-ceny)*(m2*(float)f.x+c2-(float)f.y)>0)&&((m3*cenx+c3-ceny)*(m3*(float)f.x+c3-(float)f.y))>0){
return true;
}
else
return false;
}
fill_t::~fill_t(){};



void line_t::bres(){

	if (pen.penstate==1) pen.c=globalcolor;
	else if (pen.penstate==2) pen.c=canvas.bkgnd;

	int x1, x0, y1, y0;
	x1=p1.x;
	y1=p1.y;
	x0=p2.x;
	y0=p2.y;
	bool steep = abs(y1 - y0) > abs(x1 - x0);
  if (steep)
    {
      swap(x0, y0);
      swap(x1, y1);
    }
  if (x0 > x1)
    {
      swap(x0, x1);
      swap(y0, y1);
    }
  int deltax = x1 - x0;
  int deltay = abs(y1 - y0);

  float error = 0.0;
  float deltaerr = (float)deltay / (float)deltax;

  int ystep;
  int y = y0;

  if (y0 < y1) ystep = 1; else ystep = -1;

  //glPointSize(1.0);
  //glColor3f(1.0, 0.6, 0.7);

  //glBegin(GL_POINTS);
  // point_t q;
  for (int x=x0; x < x1; x++)
    {
      if (steep){
      	point_t q(y,x);
      	q.draw(pen.size);
	  //glVertex2f(y, x);
      }
      else {
      	point_t q(x,y);
      	q.draw(pen.size);
      }
	  //glVertex2f(x, y);
      error = error + deltaerr;
      if (error >= 0.5)
	{
	  y = y + ystep;
	  error = error - 1.0;
	}
    }
  //glEnd();
}

//---------------------

