#include <windows.h>
#include <typeinfo>
#include<iostream>
#include<fstream>
using namespace std;

int isnumber(string s){
char arr[]={'0','1','2','3','4','5','6','7','8','9','.'};
int count=1,check;
for(int i=0;i<s.length();i++){
    check=0;
for(int j=0;j<11;j++){
    if(s[i]==arr[j]){check=1;}
}
if(check==0){return 0;}


}
return 1;

}

int string_to_number(string s){
if(!isnumber(s)){return -1;}
else{
char arr[]={'0','1','2','3','4','5','6','7','8','9'};
int count=1,sum=0;
for(int i=0;i<s.length();i++){
for(int j=0;j<10;j++){
    if(s[i]==arr[j]){sum=sum*10+j;}
}

}
return sum;
}
}

ofstream out1("data.txt");

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

HWND textfield, textfieldx, textfieldy,textfieldZ, textfield_type_of_force, textfield_of_magnitude, cantilever, simply_supported, forced, free_vibration,drag_drop,location;
HWND button, button_insert_bar, button_insert_force, button_ok;
HWND textbox, textboxX, textboxY,textboxZ, force_combobox, textbox_magnitude;
char position1[20],position2[20],position3[20],position4[20],position5[20];
int pos1[20];
const char *A[]={"Axial","Bending","Torsion"};

int case_from[]={0};



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

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           "Tool Bar",       /* Title Text */
           WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU | WS_TABSTOP, /* default window, WS_MAXIMIZE- allows to maximise window similarly WS_MINIMIZEBOX */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           500,                 /* The programs width */
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
    {   L1:
        out1.close();
        out1.open("D:/project/temp2-10-16/data.txt", std::ofstream::out | std::ofstream::trunc);

        //out1.open("D:/project/temp2-10-16/data.txt", std::ofstream::out | std::ofstream::trunc);
        case WM_CREATE:

            cantilever = CreateWindow("BUTTON",
                                      "Cantilever",
                                      WS_VISIBLE | WS_CHILD | WS_BORDER,
                                      140,200,200,40,
                                      hwnd,(HMENU)1,NULL,NULL); //If cantilever is clicked go to case 1


            simply_supported = CreateWindow("BUTTON",
                                      "Simply Supported Beam",
                                      WS_VISIBLE | WS_CHILD | WS_BORDER,
                                      140,100,200,40,
                                      hwnd,(HMENU)2,NULL,NULL); //If simly supported  is clicked go to case 2

        break;

        case WM_COMMAND:

        switch (LOWORD(wParam))
        {


        case 1:
            out1<<"cantilever"<<endl;
            DestroyWindow(cantilever);
            DestroyWindow(simply_supported);
            UpdateWindow(hwnd);
            forced = CreateWindow("BUTTON",
                                      "Forced",
                                      WS_VISIBLE | WS_CHILD | WS_BORDER,
                                      140,200,200,40,
                                      hwnd,(HMENU)3,NULL,NULL); //If cantilever + force is clicked go to case 3
          free_vibration = CreateWindow("BUTTON",
                                      "Free vibration",
                                      WS_VISIBLE | WS_CHILD | WS_BORDER,
                                      140,100,200,40,
                                      hwnd,(HMENU)4,NULL,NULL);  //If cantilever + free vibration is clicked go to case 4

            GetWindowText(textboxX, &position1[0] ,20);

        break;

      case 2:

              out1<<"simply_supported"<<endl;
            DestroyWindow(cantilever);
            DestroyWindow(simply_supported);
            forced = CreateWindow("BUTTON",
                                      "Forced",
                                      WS_VISIBLE | WS_CHILD | WS_BORDER,
                                      140,200,200,40,
                                      hwnd,(HMENU)5,NULL,NULL);  //If simply supported + force is clicked go to case 5
          free_vibration = CreateWindow("BUTTON",
                                      "Free vibration",
                                      WS_VISIBLE | WS_CHILD | WS_BORDER,
                                      140,100,200,40,
                                      hwnd,(HMENU)6,NULL,NULL);   //If simply supported + free vibration is clicked go to case 6
        break;
    break;


    case 3:

        out1<<"forced"<<endl;
          DestroyWindow(forced);
            DestroyWindow(free_vibration);
            drag_drop = CreateWindow("BUTTON",
                                      "Drag and Drop",
                                      WS_VISIBLE | WS_CHILD | WS_BORDER,
                                      140,100,200,40,
                                      hwnd,(HMENU)9,NULL,NULL);  //If cantilever + force + drag and drop is clicked go to case 9

            location = CreateWindow("BUTTON",
                                      "Location",
                                      WS_VISIBLE | WS_CHILD | WS_BORDER,
                                      140,200,200,40,
                                      hwnd,(HMENU)8,NULL,NULL);

    break;


    case 4:
            case_from[0]=4;
             out1<<"free"<<endl;
          DestroyWindow(forced);
            DestroyWindow(free_vibration);
            textfieldx = CreateWindow("STATIC",
                                      "Length: (Between 0 and 10000):",
                                      WS_VISIBLE | WS_CHILD ,
                                      20,20,210,20,
                                      hwnd,NULL,NULL,NULL);
            textboxX = CreateWindow("EDIT",
                                   "",
                                   WS_VISIBLE | WS_CHILD | WS_BORDER,
                                   240,20,150,20,
                                   hwnd,NULL,NULL,NULL);

            textfieldy = CreateWindow("STATIC",
                                      "Width:  (Between 0 and 1000): ",
                                      WS_VISIBLE | WS_CHILD ,
                                      20,50,210,20,
                                      hwnd,NULL,NULL,NULL);


            textboxY = CreateWindow("EDIT",
                                   "",
                                   WS_VISIBLE | WS_CHILD | WS_BORDER,
                                   240,50,150,20,
                                   hwnd,NULL,NULL,NULL);

            textfieldZ = CreateWindow("STATIC",
                                      "Thickness: (Between 0 and 1000): ",
                                      WS_VISIBLE | WS_CHILD,
                                      20,80,230,20,
                                      hwnd,NULL,NULL,NULL);


            textboxZ = CreateWindow("EDIT",
                                   "",
                                   WS_VISIBLE | WS_CHILD | WS_BORDER,
                                   240,80,150,20,
                                   hwnd,NULL,NULL,NULL);
            button_ok = CreateWindow("BUTTON",
                                    "OK",
                                    WS_VISIBLE | WS_CHILD | WS_BORDER,
                                    350,400,100,20,
                                    hwnd,(HMENU)12,NULL,NULL);

    break;


    case 5:
         out1<<"forced"<<endl;
          DestroyWindow(forced);
            DestroyWindow(free_vibration);
            drag_drop = CreateWindow("BUTTON",
                                      "Drag and Drop",
                                      WS_VISIBLE | WS_CHILD | WS_BORDER,
                                      140,100,200,40,
                                      hwnd,(HMENU)11,NULL,NULL);

            location = CreateWindow("BUTTON",
                                      "Location",
                                      WS_VISIBLE | WS_CHILD | WS_BORDER,
                                      140,200,200,40,
                                      hwnd,(HMENU)10,NULL,NULL);

    break;


    case 6:
        case_from[0]=6;
         out1<<"free"<<endl;
          DestroyWindow(forced);
            DestroyWindow(free_vibration);
                textfieldx = CreateWindow("STATIC",
                                      "Length: (Between 0 and 10000):",
                                      WS_VISIBLE | WS_CHILD ,
                                      20,20,210,20,
                                      hwnd,NULL,NULL,NULL);
            textboxX = CreateWindow("EDIT",
                                   "",
                                   WS_VISIBLE | WS_CHILD | WS_BORDER,
                                   240,20,150,20,
                                   hwnd,NULL,NULL,NULL);

            textfieldy = CreateWindow("STATIC",
                                      "Width:  (Between 0 and 1000): ",
                                      WS_VISIBLE | WS_CHILD ,
                                      20,50,210,20,
                                      hwnd,NULL,NULL,NULL);


            textboxY = CreateWindow("EDIT",
                                   "",
                                   WS_VISIBLE | WS_CHILD | WS_BORDER,
                                   240,50,150,20,
                                   hwnd,NULL,NULL,NULL);

            textfieldZ = CreateWindow("STATIC",
                                      "Thickness: (Between 0 and 1000): ",
                                      WS_VISIBLE | WS_CHILD,
                                      20,80,230,20,
                                      hwnd,NULL,NULL,NULL);


            textboxZ = CreateWindow("EDIT",
                                   "",
                                   WS_VISIBLE | WS_CHILD | WS_BORDER,
                                   240,80,150,20,
                                   hwnd,NULL,NULL,NULL);
            button_ok = CreateWindow("BUTTON",
                                    "OK",
                                    WS_VISIBLE | WS_CHILD | WS_BORDER,
                                    350,400,100,20,
                                    hwnd,(HMENU)12,NULL,NULL);

    break;




    case 8:
        case_from[0]=8;
        out1<<"location"<<endl;
           DestroyWindow(drag_drop);
            DestroyWindow(location);
                textfieldx = CreateWindow("STATIC",
                                      "Length: (Between 0 and 10000):",
                                      WS_VISIBLE | WS_CHILD ,
                                      20,20,210,20,
                                      hwnd,NULL,NULL,NULL);
            textboxX = CreateWindow("EDIT",
                                   "",
                                   WS_VISIBLE | WS_CHILD | WS_BORDER,
                                   240,20,150,20,
                                   hwnd,NULL,NULL,NULL);

            textfieldy = CreateWindow("STATIC",
                                      "Width:  (Between 0 and 1000): ",
                                      WS_VISIBLE | WS_CHILD ,
                                      20,50,210,20,
                                      hwnd,NULL,NULL,NULL);


            textboxY = CreateWindow("EDIT",
                                   "",
                                   WS_VISIBLE | WS_CHILD | WS_BORDER,
                                   240,50,150,20,
                                   hwnd,NULL,NULL,NULL);

            textfieldZ = CreateWindow("STATIC",
                                      "Thickness: (Between 0 and 1000): ",
                                      WS_VISIBLE | WS_CHILD,
                                      20,80,230,20,
                                      hwnd,NULL,NULL,NULL);


            textboxZ = CreateWindow("EDIT",
                                   "",
                                   WS_VISIBLE | WS_CHILD | WS_BORDER,
                                   240,80,150,20,
                                   hwnd,NULL,NULL,NULL);
           textfield_type_of_force = CreateWindow("STATIC",
                                      "Location of Force (Between 0 and 1):",
                                      WS_VISIBLE | WS_CHILD ,
                                      20,230,240,20,
                                      hwnd,NULL,NULL,NULL);
            force_combobox = CreateWindow("EDIT",
                                          "",
                                           WS_VISIBLE | WS_CHILD | WS_BORDER,
                                          270,230,100,20,
                                          hwnd,NULL,NULL,NULL);

            textfield_of_magnitude = CreateWindow("STATIC",
                                      "Magnitude:(Between 0 and 100)(N):",
                                      WS_VISIBLE | WS_CHILD,
                                      20,260,230,20,
                                      hwnd,NULL,NULL,NULL);

            textbox_magnitude = CreateWindow("EDIT",
                                   "",
                                   WS_VISIBLE | WS_CHILD | WS_BORDER,
                                   270,260,100,20,
                                   hwnd,NULL,NULL,NULL);

            button_ok = CreateWindow("BUTTON",
                                    "OK",
                                    WS_VISIBLE | WS_CHILD | WS_BORDER,
                                    350,400,100,20,
                                    hwnd,(HMENU)12,NULL,NULL);


    break;


    case 9:
        case_from[0]=9;
         out1<<"drag_and_drop"<<endl;
          DestroyWindow(drag_drop);
            DestroyWindow(location);
            textfieldx = CreateWindow("STATIC",
                                      "Length: (Between 0 and 10000):",
                                      WS_VISIBLE | WS_CHILD ,
                                      20,20,210,20,
                                      hwnd,NULL,NULL,NULL);
            textboxX = CreateWindow("EDIT",
                                   "",
                                   WS_VISIBLE | WS_CHILD | WS_BORDER,
                                   240,20,150,20,
                                   hwnd,NULL,NULL,NULL);

            textfieldy = CreateWindow("STATIC",
                                      "Width:  (Between 0 and 1000): ",
                                      WS_VISIBLE | WS_CHILD ,
                                      20,50,210,20,
                                      hwnd,NULL,NULL,NULL);


            textboxY = CreateWindow("EDIT",
                                   "",
                                   WS_VISIBLE | WS_CHILD | WS_BORDER,
                                   240,50,150,20,
                                   hwnd,NULL,NULL,NULL);

            textfieldZ = CreateWindow("STATIC",
                                      "Thickness: (Between 0 and 1000): ",
                                      WS_VISIBLE | WS_CHILD,
                                      20,80,230,20,
                                      hwnd,NULL,NULL,NULL);


            textboxZ = CreateWindow("EDIT",
                                   "",
                                   WS_VISIBLE | WS_CHILD | WS_BORDER,
                                   240,80,150,20,
                                   hwnd,NULL,NULL,NULL);


            textfield_of_magnitude = CreateWindow("STATIC",
                                      "Magnitude:(Between 0 and 100)(N):",
                                      WS_VISIBLE | WS_CHILD,
                                      20,260,230,20,
                                      hwnd,NULL,NULL,NULL);

            textbox_magnitude = CreateWindow("EDIT",
                                   "",
                                   WS_VISIBLE | WS_CHILD | WS_BORDER,
                                   270,260,100,20,
                                   hwnd,NULL,NULL,NULL);

            button_ok = CreateWindow("BUTTON",
                                    "OK",
                                    WS_VISIBLE | WS_CHILD | WS_BORDER,
                                    350,400,100,20,
                                    hwnd,(HMENU)12,NULL,NULL);
    break;


    case 10:
            case_from[0]=10;
         out1<<"location"<<endl;
          DestroyWindow(drag_drop);
            DestroyWindow(location);
            textfieldx = CreateWindow("STATIC",
                                      "Length: (Between 0 and 10000):",
                                      WS_VISIBLE | WS_CHILD ,
                                      20,20,210,20,
                                      hwnd,NULL,NULL,NULL);
            textboxX = CreateWindow("EDIT",
                                   "",
                                   WS_VISIBLE | WS_CHILD | WS_BORDER,
                                   240,20,150,20,
                                   hwnd,NULL,NULL,NULL);

            textfieldy = CreateWindow("STATIC",
                                      "Width:  (Between 0 and 1000): ",
                                      WS_VISIBLE | WS_CHILD ,
                                      20,50,210,20,
                                      hwnd,NULL,NULL,NULL);


            textboxY = CreateWindow("EDIT",
                                   "",
                                   WS_VISIBLE | WS_CHILD | WS_BORDER,
                                   240,50,150,20,
                                   hwnd,NULL,NULL,NULL);

            textfieldZ = CreateWindow("STATIC",
                                      "Thickness: (Between 0 and 1000): ",
                                      WS_VISIBLE | WS_CHILD,
                                      20,80,230,20,
                                      hwnd,NULL,NULL,NULL);


            textboxZ = CreateWindow("EDIT",
                                   "",
                                   WS_VISIBLE | WS_CHILD | WS_BORDER,
                                   240,80,150,20,
                                   hwnd,NULL,NULL,NULL);
            textfield_type_of_force = CreateWindow("STATIC",
                                      "Location of Force (Between 0 and 1):",
                                      WS_VISIBLE | WS_CHILD ,
                                      20,230,240,20,
                                      hwnd,NULL,NULL,NULL);
            force_combobox = CreateWindow("EDIT",
                                          "",
                                           WS_VISIBLE | WS_CHILD | WS_BORDER,
                                          270,230,100,20,
                                          hwnd,NULL,NULL,NULL);

            textfield_of_magnitude = CreateWindow("STATIC",
                                      "Magnitude:(Between 0 and 100)(N):",
                                      WS_VISIBLE | WS_CHILD,
                                      20,260,230,20,
                                      hwnd,NULL,NULL,NULL);

            textbox_magnitude = CreateWindow("EDIT",
                                   "",
                                   WS_VISIBLE | WS_CHILD | WS_BORDER,
                                   270,260,100,20,
                                   hwnd,NULL,NULL,NULL);
            button_ok = CreateWindow("BUTTON",
                                    "OK",
                                    WS_VISIBLE | WS_CHILD | WS_BORDER,
                                    350,400,100,20,
                                    hwnd,(HMENU)12,NULL,NULL);
    break;


    case 11:
        case_from[0]=11;
         out1<<"drag_and_drop"<<endl;
          DestroyWindow(drag_drop);
            DestroyWindow(location);
            textfieldx = CreateWindow("STATIC",
                                      "Length: (Between 0 and 10000):",
                                      WS_VISIBLE | WS_CHILD ,
                                      20,20,210,20,
                                      hwnd,NULL,NULL,NULL);
            textboxX = CreateWindow("EDIT",
                                   "",
                                   WS_VISIBLE | WS_CHILD | WS_BORDER,
                                   240,20,150,20,
                                   hwnd,NULL,NULL,NULL);

            textfieldy = CreateWindow("STATIC",
                                      "Width:  (Between 0 and 1000): ",
                                      WS_VISIBLE | WS_CHILD ,
                                      20,50,210,20,
                                      hwnd,NULL,NULL,NULL);


            textboxY = CreateWindow("EDIT",
                                   "",
                                   WS_VISIBLE | WS_CHILD | WS_BORDER,
                                   240,50,150,20,
                                   hwnd,NULL,NULL,NULL);

            textfieldZ = CreateWindow("STATIC",
                                      "Thickness: (Between 0 and 1000): ",
                                      WS_VISIBLE | WS_CHILD,
                                      20,80,230,20,
                                      hwnd,NULL,NULL,NULL);


            textboxZ = CreateWindow("EDIT",
                                   "",
                                   WS_VISIBLE | WS_CHILD | WS_BORDER,
                                   240,80,150,20,
                                   hwnd,NULL,NULL,NULL);



            textfield_of_magnitude = CreateWindow("STATIC",
                                      "Magnitude:(Between 0 and 100)(N):",
                                      WS_VISIBLE | WS_CHILD,
                                      20,260,230,20,
                                      hwnd,NULL,NULL,NULL);

            textbox_magnitude = CreateWindow("EDIT",
                                   "",
                                   WS_VISIBLE | WS_CHILD | WS_BORDER,
                                   270,260,100,20,
                                   hwnd,NULL,NULL,NULL);

            button_ok = CreateWindow("BUTTON",
                                    "OK",
                                    WS_VISIBLE | WS_CHILD | WS_BORDER,
                                    350,400,100,20,
                                    hwnd,(HMENU)12,NULL,NULL);

    break;


    case 12:


            int gwtstat1=0,gwtstat2=0,gwtstat3=0,gwtstat4=0,gwtstat5=0;
            gwtstat1 = GetWindowText(textboxX, &position1[0] ,20);
            gwtstat2 = GetWindowText(textboxY, &position2[0] ,20);
            gwtstat3 = GetWindowText(textboxZ, &position3[0] ,20);
            int check=1;
            if(!isnumber(position1) || !isnumber(position2) || !isnumber(position3)){cout<<"error 1"; check=0;}

            if(isnumber(position1)){if( 0>=string_to_number(position1) || string_to_number(position1)>10000){cout<<"error 2"; check=0;}}
            if(isnumber(position2)){if( 0>=string_to_number(position2) || string_to_number(position2)>1000){cout<<"error 3";check=0;}}
            if(isnumber(position3)){if( 0>=string_to_number(position3) || string_to_number(position3)>1000){cout<<"error 4"; check=0;}}

             if(case_from[0]==9 || case_from[0]==11 || case_from[0]==8 || case_from[0]==10)
            {
                gwtstat4=GetWindowText(textbox_magnitude, &position4[0] ,20);
                if(!isnumber(position4)){cout<<"error 5";check=0;}
                if(isnumber(position4)){
                    cout<<string_to_number(position4);
                    if( 0>=string_to_number(position4) || string_to_number(position4)>100){cout<<"error 6";check=0;}}


            }
            if(case_from[0]==8 || case_from[0]==10){
                gwtstat5=GetWindowText(force_combobox, &position5[0] ,20);
                if(!isnumber(position5)){cout<<"error 7"; check=0;}
               // if(isnumber(position5)){cout<<"error 8";if( 0>string_to_number(position5) || string_to_number(position5)>1){check=0;}}
            }

    if(check==1)
        {


           out1<<position1<<endl;
            out1<<position2<<endl;
            out1<<position3<<endl;


                 if(case_from[0]==9 || case_from[0]==11 || case_from[0]==8 || case_from[0]==10)
            {

                out1<<position4<<endl;

            }
            if(case_from[0]==8 || case_from[0]==10){

                out1<<position5<<endl;
            }

        }

        else {
              ::MessageBeep(MB_ICONWARNING);
            ::MessageBox(hwnd,"Invalid Input","Error Message",MB_OKCANCEL);


            DestroyWindow(textfieldx);
            DestroyWindow(textfieldy);
            DestroyWindow(textfieldZ);
            DestroyWindow(textfield_of_magnitude);
            DestroyWindow(textboxX);
            DestroyWindow(textboxY);
            DestroyWindow(textboxZ);
            DestroyWindow(textfield_of_magnitude);
            DestroyWindow(textbox_magnitude);
            DestroyWindow(force_combobox);
            DestroyWindow(textfield_type_of_force);
            DestroyWindow(location);
            DestroyWindow(button_ok);
            goto L1;
             }

       /* out1<<position1<<endl;
            out1<<position2<<endl;
            out1<<position3<<endl;*/


            //gwtstat4 = GetWindowText(force_combobox, &position4[0] ,20);
            //gwtstat5 = GetWindowText(textbox_magnitude, &position5[0] ,20);
            /*
            if (gwtstat1>0)
            {
                ::MessageBeep(MB_ICONWARNING);
                ::MessageBox(hwnd,position1,"The text was",MB_OKCANCEL);
                    //prompt to enter something
            }
            */
            //char path[] = "explorer D:\\project\\temp2-10-16\\bin\\Debug\\CGPM.exe";
            char path[] = "explorer ..\\graphics_code\\bin\\Debug\\CGPM.exe";
            system(path);
           // ShellExecute(hwnd, NULL, "C:\Program Files (x86)\Windows Media Player\wmplayer.exe", "-l", NULL, SW_HIDE);


            //SendMessage(force_combobox,(UINT) CB_ADDSTRING,(WPARAM) 0,(LPARAM) A[0]);
            //SendMessage(force_combobox,(UINT) CB_ADDSTRING,(WPARAM) 0,(LPARAM) A[1]);
            //SendMessage(force_combobox,(UINT) CB_ADDSTRING,(WPARAM) 0,(LPARAM) A[2]);

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
