/*
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


cout<<"Enter values for the beam:"<<endl;
int x1,y1,x2,y2;
cin>>x1>>y1>>x2>>y2;
create_beam(x1,y1,x2,y2);

cout<<"Enter values for the force:"<<endl;
int x3,y3;

while(!ismouseclick(WM_LBUTTONDOWN)){}
getmouseclick(WM_LBUTTONDOWN,x3,y3);

create_force(x3,y3);

move_force();

        getch();




}
*/

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

	 glColor3f(3.0f, 2.0f, 1.0f);
	 glLoadIdentity();
	 glTranslatef(-0.5f,0.3f,ballZ);

	glRectf(0.0f,0.0f, 0.05f, -0.05f);

}

void button_2(void) {

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

    /*
    line(x1,y1-50,x1,y1);
    line(x1-10,y1-10,x1,y1);
    line(x1+10,y1-10,x1,y1);*/
}



void Draw(void) {
	//glClear(GL_COLOR_BUFFER_BIT);
	 glColor3f(3.0f, 2.0f, 1.0f);
	 glLoadIdentity();
	 glTranslatef(0.0f,0.0f,ballZ);
	 //cout<<ballX<<endl;
	glRectf(-0.26f,0.0f, 0.26f, -0.05f);
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
