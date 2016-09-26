/*
#ifndef WIN32 //if using windows then do windows specific stuff.
#define WIN32_LEAN_AND_MEAN //remove MFC overhead from windows.h which can cause slowness
#define WIN32_EXTRA_LEAN

#include <windows.h>
#endif

#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <conio.h>//needed for getch

void setup() {
       glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void create_bar() {
       glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
       glColor3f(0.0f, 0.0f, 0.0f);
       glRectf(-0.6f,-0.1f, 0.6f, -0.3f);
       glutSwapBuffers();
}

int main(int argc, char *argv[])
{
       glutInit(&argc, argv);
       glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
       glutInitWindowSize(800,600);
       glutCreateWindow("Hello World");

       setup();
       glutDisplayFunc(create_bar);

       glutMainLoop();

       getch();//pause here to see results or lack there of
       return 0;
}

*/

#ifndef WIN32 //if using windows then do windows specific stuff.
#define WIN32_LEAN_AND_MEAN //remove MFC overhead from windows.h which can cause slowness
#define WIN32_EXTRA_LEAN

#include <windows.h>
#endif

#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <conio.h>//needed for getch
#include<iostream>
#include<stdlib.h>

#ifdef __APPLE__
#include<openGL/openGL.h>
#include<GLUT/glut.h>
#else
#include<GL/glut.h>
#endif

using namespace std;

float ballX = -0.3f;
float ballY = 0.0f;
float ballZ = -1.0f;
/*
float ballX2 = 0.3f;
float ballY2 = 0.0f;
float ballZ2 = -1.0f;
*/
static int flag=1;

void drawBall(void) {

        glColor3f(0.0, 1.0, 0.0); //set ball colour
        glTranslatef(ballX,ballY,ballZ); //moving it toward the screen a bit on creation
        glutSolidSphere (0.1, 10, 10); //create ball.

}

void mousePress(int button,int state,int x, int y)
{
    if(state==GLUT_DOWN)
    {
         if(button==GLUT_LEFT_BUTTON)
         {
            ballX -=0.05f ;
         }

          if(button==GLUT_RIGHT_BUTTON)
         {
            ballX +=0.05f ;
         }

    }


    glutPostRedisplay();
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
    drawBall();
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

    glutInitWindowSize(1440,900);

    glutCreateWindow("Moving Circle");

    initRendering();

    glutDisplayFunc(drawScene);

    glutMouseFunc(mousePress); // keyboard function
    glutReshapeFunc(handleResize);
    //autorot();

    //glutTimerFunc(25, update, 0);

    glutMainLoop();

    return(0);
}
