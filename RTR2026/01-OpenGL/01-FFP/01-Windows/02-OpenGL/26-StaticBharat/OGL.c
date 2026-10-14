// header files
#include <windows.h>
#include <stdio.h>  // for file I/O
#include <stdlib.h> // for exit()
// math header
#define _USE_MATH_DEFINES
#include <math.h>
// OpenGL related headers
#include <gl/GL.h>
#include <gl/GLU.h>
// our headers
#include "OGL.h"

// link with OpenGL import library
#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "GLU32.lib")

// macros
#define WIN_WIDTH   800
#define WIN_HEIGHT  600

#define lerp(a, b, t) (a + (b - a) * t)

// global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void drawQuad(void);

// global variable declarations
FILE *gpFile = NULL;
HWND  ghwnd = NULL;
BOOL  bFullscreen = FALSE;
BOOL  bActiveWindow = FALSE;
BOOL  bEscapeKeyIsPressed = FALSE;
DWORD dwStyle;
WINDOWPLACEMENT wpPrev;
// for OpenGL
HDC   ghdc;
HGLRC ghrc;

// Entry point function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
    // function declarations
    int  initialize(void);
    void render(void);  // some of the times, we may name this function display or draw..
    void update(void);
    void uninitialize(void);

    // variable declarations
    WNDCLASSEX wndClass;
    HWND       hwnd = NULL;
    MSG        msg;
    TCHAR      szAppName[] = TEXT("RTR7_SMB");
    // for centering
    int        screenWidth, screenHeight;
    RECT       pvParamRect;
    // for game loop
    BOOL       bDone = FALSE;

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
    wndClass.style          = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
    wndClass.cbClsExtra     = 0;
    wndClass.cbWndExtra     = 0;
    wndClass.lpfnWndProc    = WndProc;
    wndClass.hInstance      = hInstance;
    wndClass.hbrBackground  = (HBRUSH)GetStockObject(BLACK_BRUSH);              // the first Win32 API encountered. Humbled :-)
    wndClass.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));     // second Win32 API encountered
    wndClass.hCursor        = LoadCursor(NULL, IDC_ARROW);                      // third Win32 API encountered
    wndClass.lpszClassName  = szAppName;
    wndClass.lpszMenuName   = NULL;
    wndClass.hIconSm        = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));

    // Register the above wndClass
    RegisterClassEx(&wndClass);                                                 // fourth Win32 API encountered

    // centering logic
    if(SystemParametersInfo(SPI_GETWORKAREA, 0, &pvParamRect, 0))
    {
        fprintf(gpFile, "SMB: left = %ld, top = %ld, right = %ld, bottom = %ld\n", pvParamRect.left, pvParamRect.top, pvParamRect.right, pvParamRect.bottom);
        screenWidth = pvParamRect.right - pvParamRect.left;
        screenHeight = pvParamRect.bottom - pvParamRect.top;
    }
    else
    {
        screenWidth = GetSystemMetrics(SM_CXSCREEN);                            // C stands for Count, X for X coordinate, of the screen,
        screenHeight = GetSystemMetrics(SM_CYSCREEN);                           // get the Y count means, the height of the screen
    }

    // create the window
    hwnd = CreateWindowEx(                                                       // fifth Win32 API we saw
        WS_EX_APPWINDOW,
        szAppName,
        TEXT("SMB : Static Bharat"),                                      // This is the same as what we gave as parameter to glutCreateWindow in our Shuddha-Lekhan program
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

    int iResult = initialize();
    if(iResult != 0)
    {
        fprintf(gpFile, "SMB:WinMain(): Initialization function failed\n");
        DestroyWindow(hwnd);    // send, not post (not coming from h/w)
        hwnd  = NULL;
        ghwnd = NULL;
        exit(1);
    }
    else
    {
        fprintf(gpFile, "SMB:WinMain(): Initialization function succeeded\n");
    }

    // show window
    ShowWindow(hwnd, iCmdShow);                                                   // sixth Win32 API

    // update the window to paint its background
    UpdateWindow(hwnd);                                                           // seventh Win32 API

    SetForegroundWindow(hwnd);
    SetFocus(hwnd);

    // game loop
    while(bDone == FALSE)
    {
        if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            if(msg.message == WM_QUIT)
            {
                bDone = TRUE;
            }
            else
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            if(bActiveWindow == TRUE)
            {
                if(bEscapeKeyIsPressed == TRUE)
                {
                    bDone = TRUE;
                }

                render();
                update();
            }
        }
    }

    uninitialize();

    return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    // function declarations
    void resize(int width, int height);
    void uninitialize(void);
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
            bActiveWindow = TRUE;
        break;
        case WM_KILLFOCUS:
            bActiveWindow = FALSE;
        break;
        case WM_SIZE:
            resize(LOWORD(lParam), HIWORD(lParam));
        break;
        case WM_KEYDOWN:
            switch(wParam)
            {
                case VK_ESCAPE:
                    bEscapeKeyIsPressed = TRUE;
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
            uninitialize();
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

int initialize(void)
{
    // function declarations
    void resize(int, int);
    void printGLInfo(void);

    // variable declarations
    PIXELFORMATDESCRIPTOR pfd;
    int iPixelFormatIndex;

    // code
    memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));
    pfd.nSize      = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.nVersion   = 1;
    pfd.dwFlags    = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cRedBits   = 8;
    pfd.cGreenBits = 8;
    pfd.cBlueBits  = 8;
    pfd.cAlphaBits = 8;
    pfd.cDepthBits = 32;    // for 3D depth

    ghdc = GetDC(ghwnd);
    if(ghdc == NULL)
    {
        fprintf(gpFile, "SMB:initialize(): Failed to get DC!\n");
        return -1;
    }

    iPixelFormatIndex = ChoosePixelFormat(ghdc, &pfd);
    if(iPixelFormatIndex == 0)
    {
        fprintf(gpFile, "SMB:initialize(): Failed to get the pixel format\n");
        return -2;
    }

    // set the pixel format
    if(SetPixelFormat(ghdc, iPixelFormatIndex, &pfd) == FALSE)
    {
        fprintf(gpFile, "SMB:initialize(): Failed to set the pixel format\n");
        return -3;
    }
    
    // bridging API !!
    ghrc = wglCreateContext(ghdc);
    if(ghrc == NULL)
    {
        fprintf(gpFile, "SMB:initialize(): Failed to create the rendering context!\n");
        return -4;
    }

    if(wglMakeCurrent(ghdc, ghrc) == FALSE)
    {
        fprintf(gpFile, "SMB:initialize(): Failed to set the rendering context as current context!\n");
        return -5;
    }

    // enable depth
    glShadeModel(GL_SMOOTH);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);


    // enable alpha
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // print GL info
    printGLInfo();

    // choose screen clearing color as blue
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // warmup resize
    resize(WIN_WIDTH, WIN_HEIGHT);   

    return 0;
}

void resize(int width, int height)
{
    // variables
    float fovy = 45.0f;
    float nr = 0.1f;
    // code
    if(height <= 0) height = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    // perspective projection
    // float H = tanf((fovy / 2.0f) / 180.0f * M_PI) * nr;
    // float W = H * ((GLsizei)width / (GLsizei)height);
    // glFrustum(-W, W, -H, H, nr, 100.0f);
    gluPerspective(
        fovy, 
        (GLfloat)width / (GLfloat)height,
        nr,
        100.0f
    );
}

void render(void)
{
    // function declarations
    void drawB(void);
    void drawH(void);
    void drawA(void);
    void drawR(void);
    void drawT(void);

    // variable declarations
    static float t_orangeToWhite = 0.0f;
    static float t_whiteToGreen = 0.0f;
    static float t_greenToOrange = 0.0f;

    // code
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(-2.8f, 0.0f, -12.0f);

    // background
    // glPushMatrix();
    // {
    //     if(t_orangeToWhite <= 1.0f)
    //     {
    //         glColor4f(1.0f, lerp(0.6f, 1.0f, t_orangeToWhite), lerp(0.2f, 1.0f, t_orangeToWhite), 0.4f);
    //     }
    //     else
    //     {
    //         if(t_whiteToGreen <= 1.0f)
    //         {
    //             // glColor3f(0.074f, 0.533f, 0.22f);
    //             glColor4f(
    //                 lerp(1.0f, 0.074f, t_whiteToGreen),
    //                 lerp(1.0f, 0.533f, t_whiteToGreen),
    //                 lerp(1.0f, 0.22f, t_whiteToGreen),
    //                 0.4f
    //             );
    //         }
    //         else
    //         {
    //             if(t_greenToOrange <= 1.0f)
    //             {
    //                 glColor4f(
    //                     lerp(0.074, 1.0f, t_greenToOrange),
    //                     lerp(0.533, 0.6f, t_greenToOrange),
    //                     lerp(0.074, 0.2f, t_greenToOrange),
    //                     0.4f
    //                 );
    //             }
    //         }
    //     }
    //     glLoadIdentity();
    //     glTranslatef(-10.0f, 0.0f, -13.0f);
    //     glScalef(100.0f, 10.0f, 1.0f);
    //     drawQuad();
    // }
    // glPopMatrix();

    // saffron
    glColor3f(1.0f, 0.6f, 0.2f);
    drawB();
    glPushMatrix();
    {
        glTranslatef(-0.4f, 0.0f, 0.0f);
        drawH();
    }
    glPopMatrix();

    // white
    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
    {
        glTranslatef(1.2f, 0.0f, 0.0f);
        drawA();
    }
    glPopMatrix();
    glPushMatrix();
    {
        glTranslatef(4.8f, 0.0f, 0.0f);
        drawR();
    }
    glPopMatrix();

    // green
    glColor3f(0.074f, 0.533f, 0.22f);
    glPushMatrix();
    {
        glTranslatef(4.4f, 0.0f, 0.0f);
        drawA();
    }
    glPushMatrix();
    {
        glTranslatef(1.8f, 0.0f, 0.0f);
        drawT();
    }
    glPopMatrix();

    // altering lerping variables (COMMENTED BECAUSE NOT LOOKING GOOD)
    // if(t_orangeToWhite < 1.0f) t_orangeToWhite = t_orangeToWhite + 0.01f;
    // else
    // {
    //     t_orangeToWhite = 1.0f;
    //     if(t_whiteToGreen < 1.0f) t_whiteToGreen = t_whiteToGreen + 0.01f;
    //     else if(t_greenToOrange < 1.0f) t_greenToOrange = t_greenToOrange + 0.01f;
    //     else
    //     {
    //         // reset lerping
    //         t_orangeToWhite = 0.0f, t_whiteToGreen = 0.0f, t_greenToOrange = 0.0f;
    //     }
    // }

    // swap buffers
    SwapBuffers(ghdc);
}

void drawT(void)
{
    // code
    drawQuad();
    glTranslatef(0.1f, 0.8f, 0.0f);
    glScalef(0.5f, 1.0f, 1.0f);
    glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
    drawQuad();
}

void drawR(void)
{
    // code
    glPushMatrix();
    {
        glTranslatef(-2.0f, 0.0f, 0.0f);
        drawQuad();
    }
    glPopMatrix();
    glPushMatrix();
    {
        glTranslatef(-1.9f, 0.0f, 0.0f);
        glScalef(1.67f, 1.67f, 1.0f);
        glRotatef(-90.0f, 0.0f, 0.0f, 1.0f);
        float r = 0.4f;
        float freq = 5.0f;
        glBegin(GL_TRIANGLE_STRIP);
        {
            for(float x = -0.6f, theta = M_PI; x < 0.0f; x = x + 0.01f, theta = theta - 0.01f)
            {
                float y = r * fabs(sinf(freq * x));
                float ydash = y + r * 0.5f;

                glVertex3f(x, y, 0.0f);
                glVertex3f(x, ydash, 0.0f);
            }
        }
        glEnd();
    }
    glPopMatrix();
    glPushMatrix();
    {
        glTranslatef(-1.5f, -0.5f, 0.0f);
        glScalef(0.7f, 0.6f, 1.0f);
        glRotatef(33.0f, 0.0f, 0.0f, 1.0f);
        drawQuad();
    }
    glPopMatrix();
}

void drawA()
{
    // code
    glPushMatrix();
    {
        glTranslatef(0.0f, -0.1f, 0.0f);
        glScalef(1.0f, 0.9f, 1.0f);
        drawQuad();
        glTranslatef(0.86f, 0.0f, 0.0f);
        drawQuad();
        glTranslatef(-0.3f, 0.14f, 0.0f);
        glScalef(0.5f, 0.9f, 1.0f);
        glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
        drawQuad();
    }
    glPopMatrix();
    glPushMatrix();
    {
        glTranslatef(0.53f, 0.45f, 0.0f);
        glScalef(2.65f, 1.5f, 0.0f);
        glBegin(GL_TRIANGLE_STRIP);
        {
            float r = 0.2f;
            for(float theta = M_PI; theta >= 0.0f; theta = theta - 0.1f)
            {
                float x = r * cosf(theta);
                float y = r * sinf(theta);
                float ydash = y + r;

                glVertex3f(x, y, 0.0f);
                glVertex3f(x, ydash, 0.0f);
            }
        }
        glEnd();
    }
    glPopMatrix();
}

void drawH(void)
{
    // code
    glPushMatrix();
    {
        drawQuad();
        glTranslatef(0.86f, 0.0f, 0.0f);
        drawQuad();
        glTranslatef(-0.36f, 0.0f, 0.0f);
        glScalef(0.5f, 0.9f, 1.0f);
        glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
        drawQuad();
    }
    glPopMatrix();
}

void drawB(void)
{
    // code
    // B
    // standing line of b
    glPushMatrix();
    {
        glTranslatef(-2.0f, 0.0f, 0.0f);
        drawQuad();
    }
    glPopMatrix();
    glPushMatrix();
    {
        glTranslatef(-1.9f, 0.0f, 0.0f);
        glScalef(1.67f, 1.67f, 1.0f);
        glRotatef(-90.0f, 0.0f, 0.0f, 1.0f);
        float r = 0.4f;
        float freq = 5.0f;
        glBegin(GL_TRIANGLE_STRIP);
        {
            for(float x = -0.6f, theta = M_PI; x < 0.6f; x = x + 0.01f, theta = theta - 0.01f)
            {
                float y = r * fabs(sinf(freq * x));
                float ydash = y + r * 0.5f;

                glVertex3f(x, y, 0.0f);
                glVertex3f(x, ydash, 0.0f);
            }
        }
        glEnd();
    }
    glPopMatrix();
}

void drawQuad(void)
{
    glBegin(GL_QUADS);
    {
        glVertex3f(0.0f, -1.0f, 0.0f);
        glVertex3f(0.2f, -1.0f, 0.0f);
        glVertex3f(0.2f, 1.0f, 0.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);
        //
        // glVertex3f(-0.7f, 0.9f, z);
        // glVertex3f(0.0f, 0.9f, z);
        // glVertex3f(0.0f, 0.6f, z);
        // glVertex3f(-0.7f, 0.6f, z);
        //
    }
    glEnd();
}

void update(void)
{
    // code
}

void uninitialize(void)
{
    // code
    // if exiting in fullscreen, first restore to original size and then proceed...
    if(bFullscreen == TRUE)
    {
        toggleFullscreen();
        bFullscreen = FALSE;
    }

    // first check the current context and if it is,
    // un-make it...
    if(wglGetCurrentContext() == ghrc)
    {
        wglMakeCurrent(NULL, NULL);
    }

    // now, destroy the rendering context
    if(ghrc)
    {
        wglDeleteContext(ghrc);
        ghrc = NULL;
    }

    // now, delete the device context
    if(ghdc)
    {
        ReleaseDC(ghwnd, ghdc);
        ghdc = NULL;
    }

    // destroy the window
    if(ghwnd)
    {
        DestroyWindow(ghwnd);
        ghwnd = NULL;
    }

    // close the log file
    if(gpFile)
    {
        fprintf(gpFile, "SMB:uninitialize(): Program terminated successfully!\n");
        fclose(gpFile);
        gpFile = NULL;
    }
}

void printGLInfo(void)
{
    // code
    fprintf(gpFile, "\tOpenGL Vendor   : %s\n", glGetString(GL_VENDOR));
    fprintf(gpFile, "\tOpenGL Renderer : %s\n", glGetString(GL_RENDERER));
    fprintf(gpFile, "\tOpenGL Version  : %s\n", glGetString(GL_VERSION));
}
