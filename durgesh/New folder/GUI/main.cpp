#include <windows.h>

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
HWND textfield, button, textbox;
char textsaved[20];
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
           "Project GUI",       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           1280,                 /* The programs width */
           720,                 /* and height in pixels */
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
        DispatchMessage(&messages);
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

        textfield = CreateWindow("STATIC",
                                 "Toolbar",
                                 WS_VISIBLE | WS_CHILD,
                                 100,20,52,18,
                                hwnd,NULL,NULL,NULL);


        textfield = CreateWindow("STATIC",
                                 "Lenth:",
                                 WS_VISIBLE | WS_CHILD,
                                 50,80,44,18,
                                hwnd,NULL,NULL,NULL);
                 textbox = CreateWindow("EDIT",
                                 "",
                                 WS_VISIBLE | WS_CHILD | WS_BORDER,
                                 160,80,44,18,
                                hwnd,NULL,NULL,NULL);

        textfield = CreateWindow("STATIC",
                                 "Width:",
                                 WS_VISIBLE | WS_CHILD ,
                                 50,120,44,18,
                                hwnd,NULL,NULL,NULL);

                   textbox = CreateWindow("EDIT",
                                 "",
                                 WS_VISIBLE | WS_CHILD | WS_BORDER,
                                 160,120,44,18,
                                hwnd,NULL,NULL,NULL);


        textfield = CreateWindow("STATIC",
                                 "Height:",
                                 WS_VISIBLE | WS_CHILD ,
                                 50,160,54,18,
                                hwnd,NULL,NULL,NULL);
                         textbox = CreateWindow("EDIT",
                                 "",
                                 WS_VISIBLE | WS_CHILD | WS_BORDER,
                                 160,160,44,18,
                                hwnd,NULL,NULL,NULL);


        button= CreateWindow("BUTTON",
                                 "Submit",
                                 WS_VISIBLE | WS_CHILD | WS_BORDER,
                                 100,200,54,18,
                                hwnd,(HMENU) 1,NULL,NULL);

            break;

        case WM_COMMAND:

            switch(LOWORD(wParam))
           {
               case 1:
                   int gwtstat= 0;
                   gwtstat= GetWindowText(textbox,&textsaved[0], 20);

                ::MessageBox(hwnd,textsaved,textsaved,MB_OK);
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
