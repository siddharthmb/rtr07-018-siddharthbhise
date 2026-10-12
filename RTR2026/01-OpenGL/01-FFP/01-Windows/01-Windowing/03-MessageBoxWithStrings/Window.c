// header files
#include <windows.h>
#include <stdio.h>  // for sprintf
#include "Window.h"

// macros
#define WIN_WIDTH   800
#define WIN_HEIGHT  600

// global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// Entry point function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
    // variable declarations
    WNDCLASSEX wndClass;
    HWND hwnd = NULL;
    MSG msg;
    TCHAR szAppName[] = TEXT("RTR7_SMB");

    // code
    // WNDCLASSEX structure initialization
    wndClass.cbSize         = sizeof(WNDCLASSEX);
    wndClass.style          = CS_HREDRAW | CS_VREDRAW;
    wndClass.cbClsExtra     = 0;
    wndClass.cbWndExtra     = 0;
    wndClass.lpfnWndProc    = WndProc;
    wndClass.hInstance      = hInstance;
    wndClass.hbrBackground  = (HBRUSH)GetStockObject(BLACK_BRUSH);   // the first Win32 API encountered. Humbled :-)
    wndClass.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));               // second Win32 API encountered
    wndClass.hCursor        = LoadCursor(NULL, IDC_ARROW);                 // third Win32 API encountered
    wndClass.lpszClassName  = szAppName;
    wndClass.lpszMenuName   = NULL;
    wndClass.hIconSm        = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));

    // Register the above wndClass
    RegisterClassEx(&wndClass);                                     // fourth Win32 API encountered

    // centering logic
    int screenWidth  = GetSystemMetrics(SM_CXSCREEN);    // C stands for Count, X for X coordinate, of the screen, 
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);    // get the Y count means, the height of the screen

    // create the window
    hwnd = CreateWindow(                                            // fifth Win32 API we saw
        szAppName,
        TEXT("SMB : First Window Program"),     // This is the same as what we gave as parameter to glutCreateWindow in our Shuddha-Lekhan program
        WS_OVERLAPPEDWINDOW,
        (screenWidth / 2) - (WIN_WIDTH / 2),
        (screenHeight / 2) - (WIN_HEIGHT / 2),
        WIN_WIDTH,
        WIN_HEIGHT,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    // show window
    ShowWindow(hwnd, iCmdShow);                                     // sixth Win32 API

    // update the window to paint its background
    UpdateWindow(hwnd);                                             // seventh Win32 API

    // message loop
    while(GetMessage(&msg, NULL, 0, 0))                  // eight Win32 API
    {
        TranslateMessage(&msg);                                     // ninth Win32 API
        DispatchMessage(&msg);                                      // tenth Win32 API
    }

    TCHAR str[255];
    wsprintf(str, TEXT("%d"), (int)msg.wParam);
    MessageBox(hwnd, str, TEXT("WPARAM"), MB_OK);

    return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    // code
    switch(iMsg)
    {
        case WM_CREATE:
        // this message arrives only once, and that too just when the window is created in the memory, and not yet shown
        // again, this means that just after createWindow finishes...
        // hence this is better for doing things like initializing stuff...
            char message[100];
            sprintf(message, "Hello, Siddharth! The window is getting created... :-)");
            MessageBox(hwnd, message, TEXT("Message"), MB_OK);
        break;
        case WM_SETFOCUS:
            // Sir asked to remove the messagebox we added here..
        break;
        case WM_KILLFOCUS:
            // Sir asked to remove the MessageBox we added here...
        break;
        case WM_SIZE:
            MessageBox(hwnd, TEXT("WM_SIZE received"), TEXT("Message"), MB_OK);
        break;
        case WM_KEYDOWN:
            MessageBox(hwnd, TEXT("WM_KEYDOWN received"), TEXT("Message"), MB_OK);
            switch(wParam)
            {
                case VK_ESCAPE:
                    MessageBox(hwnd, TEXT("VK_ESCAPE: Escape key pressed!"), TEXT("Message"), MB_OK);
                break;
                default:
                break;
            }
        break;
        case WM_CHAR:
            switch(wParam)
            {
                case 'f':
                case 'F':
                    MessageBox(hwnd, TEXT("WM_CHAR: 'F' or 'f' key pressed!"), TEXT("Message"), MB_OK);
                break;
                default:
                break;
            }
        break;
        case WM_CLOSE:
            MessageBox(hwnd, TEXT("WM_CLOSE received"), TEXT("Message"), MB_OK);
        break;
        case WM_DESTROY:
        // the hwnd param is passed NULL here, because, 
        // we are here means we have already received WM_CLOSE, 
        // which means that our window has been closed...
            MessageBox(NULL, TEXT("WM_DESTROY received. Bye!"), TEXT("Message"), MB_OK);
            PostQuitMessage(0);                                     // eleventh Win32 API
        break;
        default:
        break;
    }

    return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
