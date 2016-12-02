#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<iostream>
#include<windows.h>
#include<GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <conio.h>//needed for getch
#define GL_GLEXT_PROTOTYPES 1
using namespace std;
#include <string>
#include <sstream>
#include<algorithm>
#include<fstream>


int bar=0; int force=0; int k=0;


std::string float_to_str(float f)
{
    std::stringstream stream;
    stream << f;
    return stream.str();
}

ifstream in1("C:/Users/Nihar/Documents/final/CGPM Project/Graphics-project/src/UI_code/data.txt");


float ballX = -0.3f;
float ballY = 0.0f;
float ballZ = -1.0f;

float t = 1.52;

static int flag=1;

float force_x=0;
float force_y=0;

float  beam_length,beam_width,beam_thickness,force_magnitude,force_location,beam_type,vib_type,force_type;
float width;
/*
void button_1(void) {

    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-0.45f,0.26f,ballZ);
    glColor3f(1.0f, 1.0f, 0.0f);
    glScalef(0.0003f,0.0003f,0.0003f);
    glutStrokeCharacter(GLUT_STROKE_ROMAN , 'b');
    glutStrokeCharacter(GLUT_STROKE_ROMAN , 'a');
    glutStrokeCharacter(GLUT_STROKE_ROMAN , 'r');
    glPopMatrix();

    glLoadIdentity();
    glTranslatef(-0.5f,0.3f,ballZ);

    glColor3f(1.0f, 0.0f, 0.0f);

    glRectf(0.0f,0.0f, 0.05f, -0.05f);



}
*/
void button_2(void) {

    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-0.45f,0.16f,ballZ);
    glColor3f(1.0f, 0.0f, 0.0f);
    glScalef(0.0003f,0.0003f,0.0003f);
    glutStrokeCharacter(GLUT_STROKE_ROMAN , 'f');
    glutStrokeCharacter(GLUT_STROKE_ROMAN , 'o');
    glutStrokeCharacter(GLUT_STROKE_ROMAN , 'r');
    glutStrokeCharacter(GLUT_STROKE_ROMAN , 'c');
    glutStrokeCharacter(GLUT_STROKE_ROMAN , 'e');
    glPopMatrix();

    glColor3f(0.0f, 0.0f, 0.0f);
    glLoadIdentity();
    glTranslatef(-0.5f,0.2f,ballZ);

    glRectf(0.0f,0.0f, 0.05f, -0.05f);


}

void create_force(float x1, float y1){


    glLineWidth(2.5);

    //glColor3f(1.0, 0.0, 0.0);
    glLoadIdentity();
    glBegin(GL_LINES);
    glVertex3f(x1, y1, ballZ);
    glVertex3f(x1+0.0f, y1+0.05f, ballZ);
    glEnd();



    glLoadIdentity();
    glBegin(GL_LINES);
    glVertex3f(x1, y1, ballZ);
    glVertex3f(x1-0.01f, y1+0.01f, ballZ);
    glEnd();



    float force_position=(x1+0.26)/0.52f;
    string s=float_to_str(force_position);

    string s1=float_to_str(force_magnitude);


    glLoadIdentity();
    glBegin(GL_LINES);
    glVertex3f(x1, y1, ballZ);
    glVertex3f(x1+0.01f, y1+0.01f, ballZ);
    glEnd();

    char k='5';
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(x1-0.05f,y1-0.13f,ballZ);
    glColor3f(1.0f, 0.0f, 0.0f);
    glScalef(0.0003f,0.0003f,0.0003f);

    glutStrokeCharacter(GLUT_STROKE_ROMAN , 'x');
    glutStrokeCharacter(GLUT_STROKE_ROMAN , '=');
    glutStrokeCharacter(GLUT_STROKE_ROMAN , '(');

    for(int i=0;i<s.length();i++){
        glutStrokeCharacter(GLUT_STROKE_ROMAN , s[i]);

    }

    glutStrokeCharacter(GLUT_STROKE_ROMAN , 'L');

    glutStrokeCharacter(GLUT_STROKE_ROMAN , ')');
    glPopMatrix();

    glPushMatrix();
    glLoadIdentity();
    glTranslatef(x1-0.03f,y1+0.06f,ballZ);
   glColor3f(1.0f, 0.0f, 0.0f);
    glScalef(0.0003f,0.0003f,0.0003f);

    for(int i=0;i<s1.length();i++){
        glutStrokeCharacter(GLUT_STROKE_ROMAN , s1[i]);
    }
    glutStrokeCharacter(GLUT_STROKE_ROMAN , '*');
    glutStrokeCharacter(GLUT_STROKE_ROMAN , 's');
    glutStrokeCharacter(GLUT_STROKE_ROMAN , 'i');
    glutStrokeCharacter(GLUT_STROKE_ROMAN , 'n');
    glutStrokeCharacter(GLUT_STROKE_ROMAN , 't');
    glutStrokeCharacter(GLUT_STROKE_ROMAN , ' ');

    glutStrokeCharacter(GLUT_STROKE_ROMAN , 'N');

    glLoadIdentity();
    glTranslatef(-0.2f,0.30f,ballZ);
    glColor3f(1.0f, 0.0f, 0.0f);
    glScalef(0.0005f,0.0005f,0.0005f);
    string str;
    if(beam_type==1){ str="Cantilever";}
    if(beam_type==2){ str="Simply Supported";}

    for(int i=0;i<str.length();i++){
            glutStrokeCharacter(GLUT_STROKE_ROMAN , str[i]);
        }

    glLoadIdentity();
    glTranslatef(-0.6f,0.25f,ballZ);
    glColor3f(1.0f, 0.0f, 0.0f);
    glScalef(0.0003f,0.0003f,0.0003f);
    float E=200;
    float I=beam_thickness*(beam_width)*(beam_width)*beam_width/12;

    if(beam_type==1){


        string eq="Differential Equation:";

         for(int i=0;i<eq.length();i++){
            glutStrokeCharacter(GLUT_STROKE_ROMAN , eq[i]);
        }

        string s2=float_to_str(E*I/1000);
        string s3=float_to_str(force_magnitude);
        string s4=float_to_str(force_magnitude*force_location*beam_length);

        for(int i=0;i<s2.length();i++){
            glutStrokeCharacter(GLUT_STROKE_ROMAN , s2[i]);
        }


        glutStrokeCharacter(GLUT_STROKE_ROMAN , 'd');
        glutStrokeCharacter(GLUT_STROKE_ROMAN , '2');
        glutStrokeCharacter(GLUT_STROKE_ROMAN , 'y');
        glutStrokeCharacter(GLUT_STROKE_ROMAN , '/');
        glutStrokeCharacter(GLUT_STROKE_ROMAN , 'd');
        glutStrokeCharacter(GLUT_STROKE_ROMAN , 'x');
        glutStrokeCharacter(GLUT_STROKE_ROMAN , '2');
        glutStrokeCharacter(GLUT_STROKE_ROMAN , '+');

        for(int i=0;i<s3.length();i++){
            glutStrokeCharacter(GLUT_STROKE_ROMAN , s3[i]);
        }

        glutStrokeCharacter(GLUT_STROKE_ROMAN , 'x');
        glutStrokeCharacter(GLUT_STROKE_ROMAN , '-');

        for(int i=0;i<s4.length();i++){
            glutStrokeCharacter(GLUT_STROKE_ROMAN , s4[i]);
        }
        glutStrokeCharacter(GLUT_STROKE_ROMAN , '=');
        glutStrokeCharacter(GLUT_STROKE_ROMAN , '0');
        string s5="for 0<x<"+ float_to_str(force_location)+"L";
        for(int i=0;i<s5.length();i++){
            glutStrokeCharacter(GLUT_STROKE_ROMAN , s5[i]);
        }





    }


    if(beam_type==2){


        string eq="Differential Equation:";

         for(int i=0;i<eq.length();i++){
            glutStrokeCharacter(GLUT_STROKE_ROMAN , eq[i]);
        }

        string s2=float_to_str(E*I/1000*beam_length);
        string s3=float_to_str(force_magnitude*(1-force_location)*beam_length);
        //string s4=float_to_str(force_magnitude*force_location*beam_length);

        for(int i=0;i<s2.length();i++){
            glutStrokeCharacter(GLUT_STROKE_ROMAN , s2[i]);
        }


        glutStrokeCharacter(GLUT_STROKE_ROMAN , 'd');
        glutStrokeCharacter(GLUT_STROKE_ROMAN , '2');
        glutStrokeCharacter(GLUT_STROKE_ROMAN , 'y');
        glutStrokeCharacter(GLUT_STROKE_ROMAN , '/');
        glutStrokeCharacter(GLUT_STROKE_ROMAN , 'd');
        glutStrokeCharacter(GLUT_STROKE_ROMAN , 'x');
        glutStrokeCharacter(GLUT_STROKE_ROMAN , '2');
        glutStrokeCharacter(GLUT_STROKE_ROMAN , '+');

        for(int i=0;i<s3.length();i++){
            glutStrokeCharacter(GLUT_STROKE_ROMAN , s3[i]);
        }

        glutStrokeCharacter(GLUT_STROKE_ROMAN , 'x');

        glutStrokeCharacter(GLUT_STROKE_ROMAN , '=');
        glutStrokeCharacter(GLUT_STROKE_ROMAN , '0');
        string s5="for 0<x<"+ float_to_str(force_location)+"L";
        for(int i=0;i<s5.length();i++){
            glutStrokeCharacter(GLUT_STROKE_ROMAN , s5[i]);
        }



    }


    glPopMatrix();


}

void DrawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_LINE_LOOP);
    for (int ii = 0; ii < num_segments; ii++)   {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle
        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component
        glVertex2f(x + cx, y + cy);//output vertex
    }
    glEnd();
}

void Draw() {
    //glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 0.0f);
    glLoadIdentity();
    glTranslatef(0.0f,0.0f,ballZ);
    //cout<<ballX<<endl;
    width=beam_width/beam_length*0.52f-0.05f;
    glRectf(-0.26f,width, 0.26f, -0.05f);
if(beam_type==2)
   {
        DrawCircle(.27f,-.085,0.005,100) ;
    DrawCircle(.25f,-.085,0.005,100) ;
    glLoadIdentity();
    glBegin(GL_LINES);              // Fixed Support
    glVertex3f(-0.26f, -.05f, ballZ);
    glVertex3f(-.28f, -0.08f, ballZ);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(-0.26f, -.05f, ballZ);
    glVertex3f(-.24f, -0.08f, ballZ);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(-0.24f, -.08f, ballZ);
    glVertex3f(-.28f, -0.08f, ballZ);
    glEnd();
     glBegin(GL_LINES);              // Roller Support
    glVertex3f(0.26f, -.05f, ballZ);
    glVertex3f(.28f, -0.08f, ballZ);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(0.26f, -.05f, ballZ);
    glVertex3f(.24f, -0.08f, ballZ);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(0.24f, -.08f, ballZ);
    glVertex3f(.28f, -0.08f, ballZ);
    glEnd();
   }
   if(beam_type==1)
   {  glLoadIdentity();
   glBegin(GL_LINES);
    glVertex3f(-0.26f, 0.03f, ballZ);
    glVertex3f(-0.26f, -0.09f, ballZ);
    glEnd();
       glBegin(GL_LINES);
    glVertex3f(-0.26f, .03f, ballZ);
    glVertex3f(-0.28f, 0.02f, ballZ);
    glEnd();
     glBegin(GL_LINES);
    glVertex3f(-0.26f, -.09f, ballZ);
    glVertex3f(-0.28f, -0.1f , ballZ);
    glEnd();
     glBegin(GL_LINES);
    glVertex3f(-0.26f, .01f, ballZ);
    glVertex3f(-0.28f, 0.0f , ballZ);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(-0.26f, -.01f, ballZ);
    glVertex3f(-0.28f, -0.02f , ballZ);
    glEnd();
     glBegin(GL_LINES);
    glVertex3f(-0.26f, -.03f, ballZ);
    glVertex3f(-0.28f, -0.04f , ballZ);
    glEnd();
     glBegin(GL_LINES);
    glVertex3f(-0.26f, -.07f, ballZ);
    glVertex3f(-0.28f, -0.08f , ballZ);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(-0.26f, -.05f, ballZ);
    glVertex3f(-0.28f, -0.06f , ballZ);
    glEnd();
   }
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-0.37f,-0.08f,ballZ);
    glColor3f(1.0f, 0.0f, 0.0f);
    glScalef(0.0003f,0.0003f,0.0003f);
    glutStrokeCharacter(GLUT_STROKE_ROMAN , 'x');
    glutStrokeCharacter(GLUT_STROKE_ROMAN , '=');
    glutStrokeCharacter(GLUT_STROKE_ROMAN , '0');
    glPopMatrix();
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(0.32f,-0.08f,ballZ);
    glColor3f(1.0f, 0.0f, 0.0f);
    glScalef(0.0003f,0.0003f,0.0003f);
    glutStrokeCharacter(GLUT_STROKE_ROMAN , 'x');
    glutStrokeCharacter(GLUT_STROKE_ROMAN , '=');
    glutStrokeCharacter(GLUT_STROKE_ROMAN , 'L');
    glPopMatrix();
    /*glBegin(GL_POLYGON);
    glVertex3f(0.25, 0.25, 0.0);
    glVertex3f(0.75, 0.75, 0.0);
    glVertex3f(1, 1.75, 0.0);
    glVertex3f(2, 2.75, 0.0);
    glEnd();*/
    //glutSwapBuffers();
    //glFlush();
}

void random(int x)
{
}

int temp=500;

void mousehold(int x, int y)
{
    cout<<"x:"<<x<<"y:"<<y<<endl;
    //temp=x;
    x=x-683.0;
    ballX=float(x)/683.0;
    glLoadIdentity();
    cout<<ballX<<endl;

    if(ballX>-0.26f && ballX<0.26f){
        force_location=(ballX+0.26f)/0.52f;
    }
    else if(ballX>0.26f){
        force_location=1.0f;
    }
    else if(ballX<-0.26f){force_location=0.0f;}




    glutTimerFunc(100,random,5);

    // ballY=y;
    //cout<<ballX<<endl;

    //Draw();



    glutPostRedisplay();

}
/*
float func(float x,float P,float L){

if(x<(L/2)){ return -2*P*sin(t)*x/48*(3*L*L-4*x*x)*5;}
else{return -2*P*sin(t)*(L-x)/48*(3*L*L-4*(L-x)*(L-x))*5;}
}
*/

float func2(float x,float a,float L){

    if(x<a){return -8*force_magnitude*sin(t)*((L-a)/L*x*x*x/6-(L-a)/6/L*(2*L*a-a*a)*x)/25;}
    else{return -8*force_magnitude*sin(t)*((L-a)/L*x*x*x/6-(L-a)/6/L*(2*L*a-a*a)*x-(x-a)*(x-a)*(x-a)/6)/25;}
}




float func(float x,float a,float L){

if(x<a){return 2*force_magnitude*sin(t)/6*(x*x*x - 3*a*x*x)/25 ;}
else{return 2*force_magnitude*sin(t)*a*a/6*(a-3*x)/25 ;}
}

float func3(float x,float a,float L){
int mode=15;
return sin(mode*3.14*x/L)*sin(mode*mode*3.14*3.14*t/10)/100 ;

}

float func4(float x,float a,float L){
float mode=4.694; // second mode
float A=0.98;
return (cos(mode*x/L) - cosh(mode*x/L) + A*(sin(mode*x/L) - sinh(mode*x/L)))*cos(mode*mode*t)/1000 ;

}


void draw_graph(){

float P=1;
float a=0.52/2;
float b=a;


float x, dx = 0.01f;
    glLoadIdentity();
    glTranslatef(-0.26f,-0.05f,ballZ);
	glPushMatrix(); /* GL_MODELVIEW is default */

	glColor3f(0.0, 0.0, 1.0);
	//glTranslatef()
    //glLoadIdentity();

	glBegin(GL_LINE_STRIP);
	glVertex3f(-0.26f, -0.45f+2*width, ballZ);
    glVertex3f(-0.26f, -.55f, ballZ);
	glEnd();

    if(beam_type==2){

	glBegin(GL_LINE_STRIP);


	for(x = 0.0f; x < 0.52f; x += dx)
	{

		 if(vib_type==1){//free
            glVertex2f(x, -0.2f+width+  func3(x,force_location*0.52f,0.52f));
        }
        if(vib_type==2){//forced
            glVertex2f(x, -0.2f+width+  func2(x,force_location*0.52f,0.52f));
        }

	}

	glEnd();
	glBegin(GL_LINE_STRIP);
	for(x = 0.0f; x < 0.52f; x += dx)
	{
        if(vib_type==1){
            glVertex2f(x, -0.25f+  func3(x,force_location*0.52f,0.52f));
        }
        if(vib_type==2){
            glVertex2f(x, -0.25f+  func2(x,force_location*0.52f,0.52f));
        }
	}


	glEnd();


	glBegin(GL_LINE_STRIP);
	glVertex3f(0.78f, -0.45f+2*width , ballZ);
    glVertex3f(0.78f, -0.55f, ballZ);
	glEnd();
	}

	if(beam_type==1){

        glBegin(GL_LINE_STRIP);


	for(x = 0.0f; x < 0.52f; x += dx)
	{

		if(vib_type==1){
            glVertex2f(x, -0.2f+ width+ func4(x,force_location*0.52f,0.52f));
        }
        if(vib_type==2){
            glVertex2f(x, -0.2f+ width+ func(x,force_location*0.52f,0.52f));
        }
	}

	glEnd();
	glBegin(GL_LINE_STRIP);
	for(x = 0.0f; x < 0.52f; x += dx)
	{

		if(vib_type==1){
            glVertex2f(x, -0.25f+  func4(x,force_location*0.52f,0.52f));
        }
        if(vib_type==2){
            glVertex2f(x, -0.25f+  func(x,force_location*0.52f,0.52f));
        }
	}


	glEnd();


   glBegin(GL_LINE_STRIP);
   if(vib_type==1){
            glVertex2f(.52f, -0.2f+width+ func4(.52f,force_location*0.52f,0.52f) );
    glVertex2f(.52f, -0.25f + func4(.52f,force_location*0.52f,0.52f));
        }
        if(vib_type==2){
            glVertex2f(.52f, -0.2f+width+ func(.52f,force_location*0.52f,0.52f) );
    glVertex2f(.52f, -0.25f + func(.52f,force_location*0.52f,0.52f));
        }

	glEnd();

	}
	glPopMatrix();


}



void mousePress(int button,int state,int x, int y)
{

    if(state==GLUT_DOWN)
    {

         if(button==GLUT_LEFT_BUTTON)
         {
             cout<<"x:"<<x<<"y:"<<y<<endl;

             if(x>230 && x<280 && y>180 && y<235 && force==0 ){force=1;}



             //x=x-683;

            //cout<<"x"<<x<<endl;

            //ballX=float(x)/683.0;
            //ballX=-1.0f;


            //ballX -=0.05f ;
         }

          if(button==GLUT_RIGHT_BUTTON)
         {
             //ballX+=0.05f;
            //ballX +=0.05f ;
         }

    }


    glutPostRedisplay();
}

void Initialize() {
	glClearColor(255.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void initRendering()
{
    glEnable(GL_DEPTH_TEST);
}

//Called when the window is resized
void handleResize(int w, int h) {
    //Tell OpenGL how to convert from coordinates to pixel values
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective

    //Set the camera perspective
    glLoadIdentity(); //Reset the camera
    gluPerspective(45.0,                  //The camera angle
                   (double)w / (double)h, //The width-to-height ratio
                   1.0,                   //The near z clipping coordinate
                   200.0);                //The far z clipping coordinate
}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glClearColor(255,255,255,0);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    //button_1();
    //button_2();


    //glLoadIdentity();
    Draw();

    if(force_type==2){create_force((force_location-0.5f)*0.52f,width);}
    if(force_type==1){
        button_2();
        if(force==1){create_force(force_location*0.52f-0.26f,width);}
    }
    //drawBall2();
    draw_graph();
    glutSwapBuffers();
}

//float _angle = 30.0f;
void update(int value) {
    if(flag)
    {
    ballX += 0.001f;
       if(ballX>0.3)
       {
           flag=0;

       }
    }
    if (!flag)
    {
        ballX -= 0.001f;
        if(ballX<-0.3)
       {
           flag=1;

       }
    }
    t = t + 0.05 ;

    glutPostRedisplay(); //Tell GLUT that the display has changed

    //Tell GLUT to call update again in 25 milliseconds
    glutTimerFunc(25, update, 0);
}

int main(int argc,char** argv)
{
    string type_of_beam;
    in1>>type_of_beam;
    cout<<"boba"<<endl;

    if(type_of_beam=="cantilever"){beam_type=1;}
    else if(type_of_beam=="simply_supported"){beam_type=2;}

    string type_of_vibrations;
    in1>>type_of_vibrations;

    if(type_of_vibrations=="free"){vib_type=1;}
    else if(type_of_vibrations=="forced"){vib_type=2;}

    if(vib_type==1){
        in1>>beam_length;
        in1>>beam_width;
        in1>>beam_thickness;

    }
    else if(vib_type==2){
        string force_placement;
        in1>>force_placement;
        if(force_placement=="drag_and_drop"){force_type=1;}
        else if(force_placement=="location"){force_type=2;}

        if(force_type==1){
            in1>>beam_length;
            in1>>beam_width;
            in1>>beam_thickness;
            in1>>force_magnitude;


        }

        else if(force_type==2){
            in1>>beam_length;
            in1>>beam_width;
            in1>>beam_thickness;
            in1>>force_magnitude;
            in1>>force_location;

        }


    }

    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);

    glutInitWindowSize(1366,768);

    glutCreateWindow("Moving Rect");

    initRendering();

    glutDisplayFunc(drawScene);
    glutMouseFunc(mousePress);
    glutMotionFunc(mousehold);

    //glutMouseFunc(mousePress); // keyboard function
    glutReshapeFunc(handleResize);
    //autorot();

    glutTimerFunc(25, update, 0);

    glutMainLoop();

    return(0);
}

/*
int main(int iArgc, char** cppArgv) {
	glutInit(&iArgc, cppArgv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("XoaX.net");
	Initialize();
	glutDisplayFunc(Draw);
	glutMainLoop();
	return 0;
}
*/
