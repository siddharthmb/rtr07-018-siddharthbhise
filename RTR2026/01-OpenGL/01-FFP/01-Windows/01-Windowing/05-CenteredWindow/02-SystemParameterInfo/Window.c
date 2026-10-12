// header files
#include <windows.h>
#include <stdio.h>  // for file I/O
#include <stdlib.h> // for exit()
#include "Window.h"

// macros
#define WIN_WIDTH   800
#define WIN_HEIGHT  600

// global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// global variable declarations
FILE *gpFile = NULL;
HWND  ghwnd = NULL;
BOOL  bFullscreen = FALSE;
DWORD dwStyle;
WINDOWPLACEMENT wpPrev;

// Entry point function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
    // variable declarations
    WNDCLASSEX wndClass;
    HWND hwnd = NULL;
    MSG msg;
    TCHAR szAppName[] = TEXT("RTR7_SMB");

    // code
    gpFile = fopen("Log.txt", "w");
    if(gpFile == NULL)
    {
        // log file creation failed
        MessageBox(NULL, TEXT("Log.txt file creation failed!"), TEXT("Error"), MB_ICONERROR | MB_OK);
        exit(1);
    }
    else
    {
        fprintf(gpFile, "SMB: Program started successfully!\n");
    }

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
    // int screenWidth  = GetSystemMetrics(SM_CXSCREEN);    // C stands for Count, X for X coordinate, of the screen, 
    // int screenHeight = GetSystemMetrics(SM_CYSCREEN);    // get the Y count means, the height of the screen
    RECT pvParamRect;
    if(SystemParametersInfo(SPI_GETWORKAREA, 0, &pvParamRect, 0))
    {
        fprintf(gpFile, "SMB: left = %ld, top = %ld, right = %ld, bottom = %ld\n", pvParamRect.left, pvParamRect.top, pvParamRect.right, pvParamRect.bottom);
    }

    int screenWidth = pvParamRect.right - pvParamRect.left;
    int screenHeight = pvParamRect.bottom - pvParamRect.top;

    // create the window
    hwnd = CreateWindowEx(                                            // fifth Win32 API we saw
        WS_EX_APPWINDOW,
        szAppName,
        TEXT("SMB : First Window Program"),     // This is the same as what we gave as parameter to glutCreateWindow in our Shuddha-Lekhan program
        WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE,
        (screenWidth / 2) - (WIN_WIDTH / 2),
        (screenHeight / 2) - (WIN_HEIGHT / 2),
        WIN_WIDTH,
        WIN_HEIGHT,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    // set global window handle
    ghwnd = hwnd;

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

    // close the log file
    if(gpFile)
    {
        fprintf(gpFile, "SMB: Program terminated successfully!\n");
        fclose(gpFile);
        gpFile = NULL;
    }

    return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    // function declarations
    void toggleFullscreen(void);

    // code
    switch(iMsg)
    {
        case WM_CREATE:
        // this message arrives only once, and that too just when the window is created in the memory, and not yet shown
        // again, this means that just after createWindow finishes...
        // hence this is better for doing things like initializing stuff...
        memset(&wpPrev, 0, sizeof(WINDOWPLACEMENT));
        wpPrev.length = sizeof(WINDOWPLACEMENT);
        break;
        case WM_SETFOCUS:
            // Sir asked to remove the messagebox we added here..
        break;
        case WM_KILLFOCUS:
            // Sir asked to remove the MessageBox we added here...
        break;
        case WM_SIZE:
        break;
        case WM_KEYDOWN:
            switch(wParam)
            {
                case VK_ESCAPE:
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
                if(bFullscreen == FALSE)
                {
                    toggleFullscreen();
                    bFullscreen = TRUE;
                }
                else
                {
                    toggleFullscreen();
                    bFullscreen = FALSE;
                }
                break;
                default:
                break;
            }
        break;
        case WM_CLOSE:
        break;
        case WM_DESTROY:
        // the hwnd param is passed NULL here, because, 
        // we are here means we have already received WM_CLOSE, 
        // which means that our window has been closed...
            PostQuitMessage(0);                                     // eleventh Win32 API
        break;
        default:
        break;
    }

    return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

void toggleFullscreen(void)
{
    // variable declarations
    MONITORINFO mi;

    // code
    if(bFullscreen == FALSE)
    {
        dwStyle = GetWindowLong(ghwnd, GWL_STYLE);
        if(dwStyle & WS_OVERLAPPEDWINDOW)
        {
            memset(&mi, 0, sizeof(MONITORINFO));
            mi.cbSize = sizeof(MONITORINFO);

            if(GetWindowPlacement(ghwnd, &wpPrev) && GetMonitorInfo(MonitorFromWindow(ghwnd, MONITORINFOF_PRIMARY), &mi))
            {
                SetWindowLong(ghwnd, GWL_STYLE, dwStyle & ~WS_OVERLAPPEDWINDOW);
                SetWindowPos(
                    ghwnd,
                    HWND_TOP,
                    mi.rcMonitor.left,
                    mi.rcMonitor.top,
                    mi.rcMonitor.right - mi.rcMonitor.left,
                    mi.rcMonitor.bottom - mi.rcMonitor.top,
                    SWP_NOZORDER | SWP_FRAMECHANGED
                );
            }
        }

        ShowCursor(FALSE);
    }
    else
    {
        // already fullscreen, now we make it not fullscreen
        SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);
        SetWindowPlacement(ghwnd, &wpPrev);
        SetWindowPos(
            ghwnd,
            HWND_TOP,
            0,
            0,
            0,
            0,
            SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED
        );

        ShowCursor(TRUE);
    }
}

// SWP_NOMOVE : Don't change the placement (done by the wpPrev in our prior call) 
// SWP_NOSIZE : Don't size the window
// SWP_NOOWNERZORDER : See owned window and read msdn and listen to Sir's audio again..
