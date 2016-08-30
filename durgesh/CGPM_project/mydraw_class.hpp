# include <cmath>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <GL/glut.h>
#ifndef _MYDRAW_CLASS_HPP_
#define _MYDRAW_CLASS_HPP_




//Define all classes like the color class, adding appropriate methods and data members.
//Implementation of the methods go into the corresponding cpp file

//------------------------
//color_t class c
//int win_width = 512;
//Window height
//int win_height = 512;



class color_t {
private:
  float r,g,b;
public:
  color_t();
  color_t(const float _r, const float _g, const float _b);

  void set(const float _r, const float _g, const float _b);
  float R(void);
  float G(void);
  float B(void);
};

//------------------------



//point_t class
class point_t {
public:
	int x,y;
	color_t c;
	point_t();
	point_t(int x,int y);
	//point_t(int x,int y, color_t c);

	void operator=(point_t p);
	bool operator==(point_t p);

	void draw(int size);
	~point_t();
};

class triangle_t
{
public:
	point_t p1,p2,p3;
	color_t border_color,fill_color;


	triangle_t();
	triangle_t(point_t p1,point_t p2, point_t p3);
	triangle_t(point_t p1,point_t p2, point_t p3, color_t bor,color_t fill);
	void triangle_draw();

	void fill(color_t c);

	~triangle_t();

};

class canvas_t
{
public:

	//float* screen= &screen_array;

	int width;
	int height;
	color_t bkgnd;
	float*  screen_array;
	canvas_t();
	void setpix(point_t* p);
	void clear(void);
	//screen_array = new float[win_width*win_height*3];

	~canvas_t();

};

class pen_t
{
public:
	color_t c;
	int size;
	int penstate; // 0 for neutral ; 1: draw; 2 erase
	pen_t();
	void setcolor(void){
		c.set(c.R(),c.G(),c.B());
	}


	~pen_t();

};
class line_t
{
public:
	point_t p1,p2;
	line_t(point_t w1, point_t w2);
	void bres();
	line_t();
	~line_t();

};

class fill_t
{
public:
	color_t fill_color;
	bool filling(point_t f,point_t p1,point_t p2,point_t p3);
	void fill_triangle(point_t p1,point_t p2,point_t p3);

	fill_t();
	~fill_t();

};

//------------------------


#endif

