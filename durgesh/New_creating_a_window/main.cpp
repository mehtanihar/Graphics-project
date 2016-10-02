#include <windows.h>
#include <typeinfo>

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

HWND textfield, textfieldx, textfieldy,textfieldZ, textfield_type_of_force, textfield_of_magnitude;
HWND button, button_insert_bar, button_insert_force, button_ok;
HWND textbox, textboxX, textboxY,textboxZ, force_combobox, textbox_magnitude;
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
           WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU, /* default window, WS_MAXIMIZE- allows to maximise window similarly WS_MINIMIZEBOX */
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
    {

        case WM_CREATE:

            /*textbox = CreateWindow("EDIT",
                                   "",
                                   WS_VISIBLE | WS_CHILD | WS_BORDER,
                                   20,90,280,20,
                                   hwnd,NULL,NULL,NULL);*/
            /*button = CreateWindow("BUTTON",
                                  "GO",
                                   WS_VISIBLE | WS_CHILD | WS_BORDER,
                                   20,10,70,20,
                                   hwnd,(HMENU)1,NULL,NULL);*/
            /*textfield = CreateWindow("STATIC",
                                "Magnitude(SI units)",
                                WS_VISIBLE | WS_CHILD | WS_BORDER,
                                20,30,80,20,
                                hwnd,NULL,NULL,NULL);*/
            textfieldx = CreateWindow("STATIC",
                                      "Lenth:",
                                      WS_VISIBLE | WS_CHILD ,
                                      20,20,70,20,
                                      hwnd,NULL,NULL,NULL);
            textboxX = CreateWindow("EDIT",
                                   "",
                                   WS_VISIBLE | WS_CHILD | WS_BORDER,
                                   100,20,150,20,
                                   hwnd,NULL,NULL,NULL);

            textfieldy = CreateWindow("STATIC",
                                      "Width:",
                                      WS_VISIBLE | WS_CHILD ,
                                      20,50,70,20,
                                      hwnd,NULL,NULL,NULL);


            textboxY = CreateWindow("EDIT",
                                   "",
                                   WS_VISIBLE | WS_CHILD | WS_BORDER,
                                   100,50,150,20,
                                   hwnd,NULL,NULL,NULL);

            textfieldZ = CreateWindow("STATIC",
                                      "Thickness:",
                                      WS_VISIBLE | WS_CHILD,
                                      20,80,70,20,
                                      hwnd,NULL,NULL,NULL);


            textboxZ = CreateWindow("EDIT",
                                   "",
                                   WS_VISIBLE | WS_CHILD | WS_BORDER,
                                   100,80,150,20,
                                   hwnd,NULL,NULL,NULL);

            button_insert_bar = CreateWindow("BUTTON",
                                  "Insert Bar",
                                   WS_VISIBLE | WS_CHILD | WS_BORDER,
                                   20,120,100,20,
                                   hwnd,(HMENU)1,NULL,NULL);

           textfield_type_of_force = CreateWindow("STATIC",
                                      "Location of Force from support:",
                                      WS_VISIBLE | WS_CHILD ,
                                      20,230,210,20,
                                      hwnd,NULL,NULL,NULL);
            force_combobox = CreateWindow("EDIT",
                                          "",
                                           WS_VISIBLE | WS_CHILD | WS_BORDER,
                                          240,230,100,20,
                                          hwnd,NULL,NULL,NULL);

            textfield_of_magnitude = CreateWindow("STATIC",
                                      "Magnitude (SI units):",
                                      WS_VISIBLE | WS_CHILD,
                                      20,260,150,20,
                                      hwnd,NULL,NULL,NULL);

            textbox_magnitude = CreateWindow("EDIT",
                                   "",
                                   WS_VISIBLE | WS_CHILD | WS_BORDER,
                                   240,260,100,20,
                                   hwnd,NULL,NULL,NULL);

           button_insert_force = CreateWindow("BUTTON",
                                  "Insert Force",
                                   WS_VISIBLE | WS_CHILD | WS_BORDER,
                                   20,290,100,20,
                                   hwnd,NULL,NULL,NULL);
           button_ok = CreateWindow("BUTTON",
                                    "OK",
                                    WS_VISIBLE | WS_CHILD | WS_BORDER,
                                    350,400,100,20,
                                    hwnd,NULL,NULL,NULL);


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
*/
        switch (LOWORD(wParam))
        {
        case 1:
            int gwtstat1=0,gwtstat2=0,gwtstat3=0,gwtstat4=0,gwtstat5=0;
            gwtstat1 = GetWindowText(textboxX, &position1[0] ,20);
            gwtstat2 = GetWindowText(textboxY, &position2[0] ,20);
            gwtstat3 = GetWindowText(textboxZ, &position3[0] ,20);
            gwtstat4 = GetWindowText(force_combobox, &position4[0] ,20);
            gwtstat5 = GetWindowText(textbox_magnitude, &position5[0] ,20);
            if (gwtstat1>0)
            {
                ::MessageBeep(MB_ICONWARNING);
                ::MessageBox(hwnd,position1,"The text was",MB_OKCANCEL);
                    //prompt to enter something
            }
char path[] = "C:\Program Files (x86)\Windows Media Player\wmplayer.exe -1";
system(path);
           // ShellExecute(hwnd, NULL, "C:\Program Files (x86)\Windows Media Player\wmplayer.exe", "-l", NULL, SW_HIDE);

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
