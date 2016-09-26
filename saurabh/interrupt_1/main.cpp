#include<stdlib.h>
#include<iostream>
#include<windows.h>
#include<GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <conio.h>//needed for getch

using namespace std;

float ballX = -0.3f;
float ballY = 0.0f;
float ballZ = -1.0f;

static int flag=1;

void button_1(void) {
	//glClear(GL_COLOR_BUFFER_BIT);
	 glColor3f(3.0f, 2.0f, 1.0f);
	 glTranslatef(-0.5f,0.3f,ballZ);
	 //cout<<ballX<<endl;
	glRectf(0.0f,0.0f, 0.1f, -0.1f);
	/*glBegin(GL_POLYGON);
		glVertex3f(0.25, 0.25, 0.0);
		glVertex3f(0.75, 0.75, 0.0);
		glVertex3f(1, 1.75, 0.0);
		glVertex3f(2, 2.75, 0.0);
	glEnd();*/
	//glutSwapBuffers();
	//glFlush();
}


void Draw(void) {
	//glClear(GL_COLOR_BUFFER_BIT);
	 glColor3f(3.0f, 2.0f, 1.0f);
	 glTranslatef(ballX,ballY,ballZ);
	 //cout<<ballX<<endl;
	glRectf(0.0f,0.0f, 0.26f, -0.13f);
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
    //temp=x;
    x=x-683.0;
    ballX=float(x)/683.0;
    glutTimerFunc(100,random,5);
   // ballY=y;
    //cout<<ballX<<endl;

    //Draw();



glutPostRedisplay();

}


void mousePress(int button,int state,int x, int y)
{
    if(state==GLUT_DOWN)
    {
         if(button==GLUT_LEFT_BUTTON)
         {
             //x=x-683;

            //cout<<"x"<<x<<endl;

            //ballX=float(x)/683.0;
            //ballX=-1.0f;

            cout<<"ballx"<<ballX<<endl;
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
      glLoadIdentity();
    Draw();
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
    glutMotionFunc(mousehold);
    //glutMouseFunc(mousePress); // keyboard function
    glutReshapeFunc(handleResize);
    //autorot();

    //glutTimerFunc(25, update, 0);

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
