// header files
#include <windows.h>

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
    wndClass.hIcon          = LoadIcon(NULL, IDI_APPLICATION);               // second Win32 API encountered
    wndClass.hCursor        = LoadCursor(NULL, IDC_ARROW);                 // third Win32 API encountered
    wndClass.lpszClassName  = szAppName;
    wndClass.lpszMenuName   = NULL;
    wndClass.hIconSm        = LoadIcon(NULL, IDI_APPLICATION);

    // Register the above wndClass
    RegisterClassEx(&wndClass);                                     // fourth Win32 API encountered

    // create the window
    hwnd = CreateWindow(                                            // fifth Win32 API we saw
        szAppName,
        TEXT("SMB : First Window Program"),     // This is the same as what we gave as parameter to glutCreateWindow in our Shuddha-Lekhan program
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
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
    while(GetMessage(&msg, NULL, 0, 0) != WM_QUIT)                  // eight Win32 API
    {
        TranslateMessage(&msg);                                     // ninth Win32 API
        DispatchMessage(&msg);                                      // tenth Win32 API
    }

    return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    // code
    switch(iMsg)
    {
        case WM_DESTROY:
            PostQuitMessage(0);                                     // eleventh Win32 API
        break;
        default:
        break;
    }

    return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
