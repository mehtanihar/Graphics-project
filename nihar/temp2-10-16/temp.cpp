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

float ballX = -0.3f;
float ballY = 0.0f;
float ballZ = -1.0f;

float t = 1.52;

static int flag=1;


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

	 glColor3f(3.0f, 2.0f, 1.0f);

	glRectf(0.0f,0.0f, 0.05f, -0.05f);



}

void button_2(void) {

    glPushMatrix();
     glLoadIdentity();
	 glTranslatef(-0.45f,0.16f,ballZ);
	 glColor3f(1.0f, 1.0f, 0.0f);
	 glScalef(0.0003f,0.0003f,0.0003f);
     glutStrokeCharacter(GLUT_STROKE_ROMAN , 'f');
	 glutStrokeCharacter(GLUT_STROKE_ROMAN , 'o');
	 glutStrokeCharacter(GLUT_STROKE_ROMAN , 'r');
     glutStrokeCharacter(GLUT_STROKE_ROMAN , 'c');
     glutStrokeCharacter(GLUT_STROKE_ROMAN , 'e');
     glPopMatrix();

	 glColor3f(3.0f, 2.0f, 1.0f);
	 glLoadIdentity();
	 glTranslatef(-0.5f,0.2f,ballZ);

	glRectf(0.0f,0.0f, 0.05f, -0.05f);


}

void create_force(int x1, int y1){
    glLineWidth(2.5);

   //glColor3f(1.0, 0.0, 0.0);
    glLoadIdentity();
    glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, ballZ);
    glVertex3f(0.0f, 0.05f, ballZ);
    glEnd();

    glLoadIdentity();
    glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, ballZ);
    glVertex3f(-0.01f, 0.01f, ballZ);
    glEnd();

     glLoadIdentity();
    glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, ballZ);
    glVertex3f(0.01f, 0.01f, ballZ);
    glEnd();


     glPushMatrix();
     glLoadIdentity();
	 glTranslatef(-0.05f,-0.15f,ballZ);
	 glColor3f(1.0f, 1.0f, 0.0f);
	 glScalef(0.0003f,0.0003f,0.0003f);
     glutStrokeCharacter(GLUT_STROKE_ROMAN , 'x');
	 glutStrokeCharacter(GLUT_STROKE_ROMAN , '=');
	 glutStrokeCharacter(GLUT_STROKE_ROMAN , '(');
	 glutStrokeCharacter(GLUT_STROKE_ROMAN , 'L');
	 glutStrokeCharacter(GLUT_STROKE_ROMAN , '/');
	 glutStrokeCharacter(GLUT_STROKE_ROMAN , '2');
	 glutStrokeCharacter(GLUT_STROKE_ROMAN , ')');
     glPopMatrix();

    /*
    line(x1,y1-50,x1,y1);
    line(x1-10,y1-10,x1,y1);
    line(x1+10,y1-10,x1,y1);*/
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

void Draw(void) {
	//glClear(GL_COLOR_BUFFER_BIT);
	 glColor3f(3.0f, 2.0f, 1.0f);
	 glLoadIdentity();
	 glTranslatef(0.0f,0.0f,ballZ);
	 //cout<<ballX<<endl;
	glRectf(-0.26f,0.0f, 0.26f, -0.05f);
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

    glPushMatrix();
     glLoadIdentity();
	 glTranslatef(-0.30f,-0.15f,ballZ);
	 glColor3f(1.0f, 1.0f, 0.0f);
	 glScalef(0.0003f,0.0003f,0.0003f);
     glutStrokeCharacter(GLUT_STROKE_ROMAN , 'x');
	 glutStrokeCharacter(GLUT_STROKE_ROMAN , '=');
	 glutStrokeCharacter(GLUT_STROKE_ROMAN , '0');
     glPopMatrix();

     glPushMatrix();
     glLoadIdentity();
	 glTranslatef(0.26f,-0.15f,ballZ);
	 glColor3f(1.0f, 1.0f, 0.0f);
	 glScalef(0.0003f,0.0003f,0.0003f);
     glutStrokeCharacter(GLUT_STROKE_ROMAN , 'x');
	 glutStrokeCharacter(GLUT_STROKE_ROMAN , '=');
	 glutStrokeCharacter(GLUT_STROKE_ROMAN , 'L');
     glPopMatrix();

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

float func(float x,float a,float P,float L){

if(x<a){ return -P*sin(t)*((L-a)/L*x*x*x/6-(L-a)/6/L*(2*L*a-a*a)*x); }
else{return -P*sin(t)*((L-a)/L*x*x*x/6-(L-a)/6/L*(2*L*a-a*a)*x-(x-a)*(x-a)*(x-a)/6); }
}

void draw_graph(){

float P=1;
float a=0.52/2;
float b=a;


float x, dx = 0.01f;

    glTranslatef(0.24f,-0.25f,0);
	glPushMatrix(); /* GL_MODELVIEW is default */

	glColor3f(1.0, 1.0, 0.0);
	//glTranslatef()
    //glLoadIdentity();

	glBegin(GL_LINE_STRIP);
	glVertex3f(-0.25f, -0.45f, ballZ);
    glVertex3f(-0.25f, -.55f, ballZ);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex3f(0.78f, -0.45f , ballZ);
    glVertex3f(0.78f, -.55f, ballZ);
	glEnd();
	glBegin(GL_LINE_STRIP);


	for(x = 0.0f; x < 0.52f; x += dx)
	{

		glVertex2f(x, -0.2f+func(x,0.26f,P,0.52f));

	}

	glEnd();
	glBegin(GL_LINE_STRIP);
	for(x = 0.0f; x < 0.52f; x += dx)
	{

		glVertex2f(x, -0.25f +  func(x,0.26f,P,0.52f));

	}


	glEnd();

	glPopMatrix();


}

int bar=0; int force=0;

void mousePress(int button,int state,int x, int y)
{
int k=0;
    if(state==GLUT_DOWN)
    {

         if(button==GLUT_LEFT_BUTTON)
         {
             cout<<"x:"<<x<<"y:"<<y<<endl;
             if(x>230 && x<280 && y>100 && y<180){k=1;}
             else if(x>230 && x<280 && y>180 && y<235 ){k=2;}
             else{k=3;}
             switch(k){
            case 1:
            Draw();
            bar=1;
            break;
            case 2:
            create_force(655,0);
            force=1;
            break;





             }

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
	glClearColor(0.0, 0.0, 0.0, 0.0);
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

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    button_1();
    button_2();
    if(bar==1 && force==1){draw_graph();}
    //glLoadIdentity();
    if(bar==1){Draw();}

    if(force==1){create_force(655,0);}
    //drawBall2();

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
    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);

    glutInitWindowSize(1366,768);

    glutCreateWindow("Moving Rect");

    initRendering();

    glutDisplayFunc(drawScene);
    glutMouseFunc(mousePress);
    //glutMotionFunc(mousehold);

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
