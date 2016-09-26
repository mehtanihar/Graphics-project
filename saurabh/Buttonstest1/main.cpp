#define WIN32_LEAN_AND_MEAN
#include<iostream>


#include <windows.h>

#include "resource.h"

using namespace std;

HINSTANCE hInst;

BOOL CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        case WM_INITDIALOG:
            /*
             * TODO: Add code to initialize the dialog.
             */
            return TRUE;

        case WM_CLOSE:
            EndDialog(hwndDlg, 0);
            return TRUE;

        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                /*
                 * TODO: Add more control ID's, when needed.
                 */
                case IDC_BTN_QUIT:
                    EndDialog(hwndDlg, 0);
                    return TRUE;

                case IDC_BTN_create_bar:
                    MessageBox(hwndDlg, "Now bar will be created", "Information", MB_ICONINFORMATION);
                    return TRUE;

                case X_VAL == NULL:
                    int x = X_VAL;
                    cout<<x<<endl;
                    //MessageBox(hwndDlg, "x", "this is the val of x", MB_ICONINFORMATION);
                    return TRUE;


            }
    }

    return FALSE;
}


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    hInst = hInstance;

    // The user interface is a modal dialog box
    return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DialogProc);
}
