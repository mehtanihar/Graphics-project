#include <windows.h>
#include <typeinfo>
#include <iostream>
#include<algorithm>
#include<stdlib.h>
#include<windows.h>
#include<GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include<math.h>
#include <conio.h>//needed for getch
#define GL_GLEXT_PROTOTYPES 1
using namespace std;

void
display()
{
    /* rotate a triangle around */
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2i(0,  1);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2i(-1, -1);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2i(1, -1);
    glEnd();
    glFlush();
}




float ballZ = -1.0f;
int bar=0; int force=0;
int length,breadth,thickness;

int char_to_int(char c){
int val;
 char k[]={'0','1','2','3','4','5','6','7','8','9'};
for(int i=0;i<10;i++){

    if(k[i]==c){val=i;}

}
return val;

}


int string_to_int(char* str,int len)
    {


            int val=0;
            for(int i=0;i<len;i++){

                val=val+(char_to_int(*(str+i))*pow(10,len-i-1));


            }
            return val;
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

void Draw(int len, int breadth) {
	//glClear(GL_COLOR_BUFFER_BIT);
	 glColor3f(3.0f, 2.0f, 1.0f);
	 glLoadIdentity();
	 glTranslatef(0.0f,0.0f,ballZ);
	 //cout<<ballX<<endl;
	 double k=len/1000.0;
	glRectf(-k,0.0f, k, -0.05f);
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
/*
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
*/
float func(float x,float P,float L){
return -1*P*x/48*(3*L*L-4*x*x)*5;
}


void draw_graph(){

float P=1;
float a=0.52/2;


float x, dx = 0.01f;

    glTranslatef(0.24f,-0.25f,0);
	glPushMatrix(); /* GL_MODELVIEW is default */

	glColor3f(1.0, 1.0, 0.0);
	//glTranslatef()
    //glLoadIdentity();
	glBegin(GL_LINE_STRIP);


	for(x = 0.0f; x < 0.5f; x += dx)
	{

		glVertex2f(x, func(x,P,0.52f));
	}

	glEnd();

	glPopMatrix();


}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    //draw_graph();
    //glLoadIdentity();
   if(bar==1){Draw(length,breadth);}

    //if(force==1){create_force(655,0);}
    //drawBall2();

    glutSwapBuffers();
}


void initRendering()
{
    glEnable(GL_DEPTH_TEST);
}




HWND
CreateOpenGLWindow(char* title, int x, int y, int width, int height,
		   BYTE type, DWORD flags)
{
    int         pf;
    HDC         hDC;
    HWND        hWnd;
    WNDCLASS    wc;
    PIXELFORMATDESCRIPTOR pfd;
    static HINSTANCE hInstance = 0;

    /* only register the window class once - use hInstance as a flag. */
    if (!hInstance) {
	hInstance = GetModuleHandle(NULL);
	wc.style         = CS_OWNDC;
	wc.lpfnWndProc   = (WNDPROC)WindowProcedure;
	wc.cbClsExtra    = 0;
	wc.cbWndExtra    = 0;
	wc.hInstance     = hInstance;
	wc.hIcon         = LoadIcon(NULL, IDI_WINLOGO);
	wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = NULL;
	wc.lpszMenuName  = NULL;
	wc.lpszClassName = "OpenGL";

	if (!RegisterClass(&wc)) {
	    MessageBox(NULL, "RegisterClass() failed:  "
		       "Cannot register window class.", "Error", MB_OK);
	    return NULL;
	}
    }

    hWnd = CreateWindow("OpenGL", title, WS_OVERLAPPEDWINDOW |
			WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
			x, y, width, height, NULL, NULL, hInstance, NULL);

    if (hWnd == NULL) {
	MessageBox(NULL, "CreateWindow() failed:  Cannot create a window.",
		   "Error", MB_OK);
	return NULL;
    }

    hDC = GetDC(hWnd);

    /* there is no guarantee that the contents of the stack that become
       the pfd are zeroed, therefore _make sure_ to clear these bits. */
    memset(&pfd, 0, sizeof(pfd));
    pfd.nSize        = sizeof(pfd);
    pfd.nVersion     = 1;
    pfd.dwFlags      = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | flags;
    pfd.iPixelType   = type;
    pfd.cColorBits   = 32;

    pf = ChoosePixelFormat(hDC, &pfd);
    if (pf == 0) {
	MessageBox(NULL, "ChoosePixelFormat() failed:  "
		   "Cannot find a suitable pixel format.", "Error", MB_OK);
	return 0;
    }

    if (SetPixelFormat(hDC, pf, &pfd) == FALSE) {
	MessageBox(NULL, "SetPixelFormat() failed:  "
		   "Cannot set format specified.", "Error", MB_OK);
	return 0;
    }

    DescribePixelFormat(hDC, pf, sizeof(PIXELFORMATDESCRIPTOR), &pfd);

    ReleaseDC(hWnd,hDC);

    return hWnd;
}






/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

HWND textfield, textfieldx, textfieldy,textfieldZ, textfield_type_of_force, textfield_of_magnitude,textfield_Location_of_force;
HWND button, button_insert_bar, button_insert_force, button_ok;
HWND textbox, textboxX, textboxY,textboxZ, force_combobox, textbox_magnitude,force_Location;
char position1[20],position2[20],position3[20],position4[20],position5[20];
int pos1[20];
const char *A[]={"Axial","Bending","Torsion"};





/*  Make the class name into a global variable  */
char szClassName[ ] = "CodeBlocksWindowsApp";

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */
    HDC hDC;				/* device context */
    HGLRC hRC;				/* opengl context */


    hwnd = CreateOpenGLWindow("minimal", 0, 0, 256, 256, PFD_TYPE_RGBA, 0);
    if (hwnd == NULL)
	exit(1);


    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */



    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;




   glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);

    glutInitWindowSize(1366,768);

    glutCreateWindow("Moving Rect");

    initRendering();

    glutDisplayFunc(drawScene);


    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           "Toolbar",       /* Title Text */
           WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU, /* default window, WS_MAXIMIZE- allows to maximise window similarly WS_MINIMIZEBOX */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           350,                 /* The programs width */
           500,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages); //calls the window procedure
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}




/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {

        case WM_CREATE:

            /*textbox = CreateWindow("EDIT",
                                   "",
                                   WS_VISIBLE | WS_CHILD | WS_BORDER,
                                   20,90,280,20,
                                   hwnd,NULL,NULL,NULL);
            button = CreateWindow("BUTTON",
                                  "GO",
                                   WS_VISIBLE | WS_CHILD | WS_BORDER,
                                   20,10,70,20,
                                   hwnd,(HMENU)1,NULL,NULL);
            textfield = CreateWindow("STATIC",
                                "Magnitude(SI units)",
                                WS_VISIBLE | WS_CHILD | WS_BORDER,
                                20,30,80,20,
                                hwnd,NULL,NULL,NULL);*/


            textfieldx = CreateWindow("STATIC",
                                      "Length:",
                                      WS_VISIBLE | WS_CHILD ,
                                      20,20,45,20,
                                      hwnd,NULL,NULL,NULL);



            textboxX = CreateWindow("EDIT",
                                   "",
                                   WS_VISIBLE | WS_CHILD | WS_BORDER,
                                   95,20,150,20,
                                   hwnd,NULL,NULL,NULL);

            textfieldy = CreateWindow("STATIC",
                                      "Width:",
                                      WS_VISIBLE | WS_CHILD ,
                                      20,50,45,20,
                                      hwnd,NULL,NULL,NULL);


            textboxY = CreateWindow("EDIT",
                                   "",
                                   WS_VISIBLE | WS_CHILD | WS_BORDER,
                                   95,50,150,20,
                                    hwnd,NULL,NULL,NULL);


            textfieldZ = CreateWindow("STATIC",
                                      "Thickness:",
                                      WS_VISIBLE | WS_CHILD ,
                                      20,80,70,20,
                                      hwnd,NULL,NULL,NULL);


            textboxZ = CreateWindow("EDIT",
                                   "",
                                   WS_VISIBLE | WS_CHILD | WS_BORDER,
                                   95,80,150,20,
                                   hwnd,NULL,NULL,NULL);

            button_insert_bar = CreateWindow("BUTTON",
                                  "Insert Bar",
                                   WS_VISIBLE | WS_CHILD | WS_BORDER,
                                   20,180,100,20,
                                   hwnd,(HMENU) 1,NULL,NULL);




            textfield_Location_of_force = CreateWindow("STATIC",
                                      "Location of Force from Support",
                                      WS_VISIBLE | WS_CHILD ,
                                      20,230,200,20,
                                      hwnd,NULL,NULL,NULL);
            force_Location = CreateWindow("EDIT",
                                          "",
                                         WS_VISIBLE | WS_CHILD | WS_BORDER,
                                          230,230,100,20,
                                          hwnd,NULL,NULL,NULL);
/*
           textfield_type_of_force = CreateWindow("STATIC",
                                      "Type of Force",
                                      WS_VISIBLE | WS_CHILD | WS_BORDER,
                                      20,230,100,20,
                                      hwnd,NULL,NULL,NULL);
            force_combobox = CreateWindow("COMBOBOX",
                                          "hey",
                                          CBS_DROPDOWN | CBS_HASSTRINGS | WS_VISIBLE | WS_CHILD | WS_BORDER,
                                          130,230,100,2000,
                                          hwnd,NULL,NULL,NULL);*/

            textfield_of_magnitude = CreateWindow("STATIC",
                                      "Magnitude (SI units) :",
                                      WS_VISIBLE | WS_CHILD ,
                                      20,260,150,20,
                                      hwnd,NULL,NULL,NULL);

            textbox_magnitude = CreateWindow("EDIT",
                                   "",
                                   WS_VISIBLE | WS_CHILD | WS_BORDER,
                                   180,260,150,20,
                                   hwnd,NULL,NULL,NULL);

           button_insert_force = CreateWindow("BUTTON",
                                  "Insert Force",
                                   WS_VISIBLE | WS_CHILD | WS_BORDER,
                                   20,290,100,20,
                                   hwnd,NULL,NULL,NULL);

           button_ok = CreateWindow("BUTTON",
                                    "OK",
                                    WS_VISIBLE | WS_CHILD | WS_BORDER,
                                    125,400,100,20,
                                    hwnd,(HMENU) 2,NULL,NULL);



            SendMessage(force_combobox,(UINT) CB_ADDSTRING,(WPARAM) 0,(LPARAM) A[0]);
            SendMessage(force_combobox,(UINT) CB_ADDSTRING,(WPARAM) 0,(LPARAM) A[1]);
            SendMessage(force_combobox,(UINT) CB_ADDSTRING,(WPARAM) 0,(LPARAM) A[2]);


        /*button = CreateWindow("BUTTON",
                              "This is a button",
                              WS_VISIBLE | WS_CHILD | WS_BORDER,
                              30,50,180,30,
                              hwnd,(HMENU)1,NULL,NULL);*/


        /*HWND WINAPI CreateWindow(
  _In_opt_ LPCTSTR   lpClassName,
  _In_opt_ LPCTSTR   lpWindowName,
  _In_     DWORD     dwStyle,
  _In_     int       x,
  _In_     int       y,
  _In_     int       nWidth,
  _In_     int       nHeight,
  _In_opt_ HWND      hWndParent,
  _In_opt_ HMENU     hMenu,
  _In_opt_ HINSTANCE hInstance,
  _In_opt_ LPVOID    lpParamtextbox
);
*/
        break;

        case WM_COMMAND:
        //this is where actual action takes place

     /*   if(LOWORD(wParam)==1)  //if the button was pressed. Can be used instead of switch case
        {
        char *TextEntered = NULL;
        TextEntered = (char*)malloc(sizeof(char) * 50); //creating a block which is 50 bytes in size-- same as char TExtEntered[50];
        int lengthcopied;
        lengthcopied = GetWindowText(textbox, TextEntered,49);
        if(lengthcopied>0)
        {
        ::MessageBeep(MB_ICONWARNING);
        ::MessageBox(hwnd,TextEntered,"The text was",MB_YESNOCANCEL);
        }
        free(textbox);

        }
        break;
*///textboxX, textboxY,textboxZ, force_combobox, textbox_magnitude,force_Location
        switch (LOWORD(wParam))
        {
        case 1:
            int gwtstat1=0,gwtstat2=0,gwtstat3=0,gwtstat4=0,gwtstat5=0;
            gwtstat1 = GetWindowText(textboxX, &position1[0] ,20);
            gwtstat2 = GetWindowText(textboxY, &position2[0] ,20);
            gwtstat3 = GetWindowText(textboxZ, &position3[0] ,20);
            gwtstat4 = GetWindowText(textbox_magnitude, &position4[0] ,20);
            gwtstat5 = GetWindowText(force_Location, &position5[0] ,20);
            length=string_to_int(&position1[0],gwtstat1);
            breadth=string_to_int(&position2[0],gwtstat2);
            thickness=string_to_int(&position3[0],gwtstat3);
            cout<<length<<endl;
            cout<<breadth<<endl;
            cout<<thickness<<endl;
            Draw(length,breadth);bar=1;


            ::MessageBeep(MB_ICONWARNING);
            ::MessageBox(hwnd,position1,"The text was",MB_OKCANCEL);
                    //prompt to enter something




            break;



        }
        break;

        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}

/*
glutInit(&argc,argv);

glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);

glutInitWindowSize(1366,768);

glutCreateWindow("Moving Rect");

initRendering();

glutDisplayFunc(drawScene);
*/
/*
int main(int argc,char** argv)
{


    //glutInit(&argc,argv);

   // glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);

    //glutInitWindowSize(1366,768);

    //glutCreateWindow("Moving Rect");

    //initRendering();

    //glutDisplayFunc(drawScene);
    //glutMouseFunc(mousePress);
    //glutMotionFunc(mousehold);

    //glutMouseFunc(mousePress); // keyboard function
    //glutReshapeFunc(handleResize);
    //autorot();

    //glutTimerFunc(25, update, 0);

    //glutMainLoop();

    return(0);
}

*/
