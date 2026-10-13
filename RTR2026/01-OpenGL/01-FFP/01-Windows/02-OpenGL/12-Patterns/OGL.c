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

// global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

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
// for viewport settings
float gHeight, gWidth;
void setViewport(GLint x, GLint y, GLsizei width, GLsizei height);

///////////////////////////////////////////////
// pattern assignment specific enum
typedef enum
{
    NO_PATTERN = -1,
    PATTERN_1 = 0,
    PATTERN_2,
    PATTERN_3,
    PATTERN_4,
    PATTERN_5,
    PATTERN_6
} Pattern;

Pattern currentPattern = NO_PATTERN;
///////////////////////////////////////////////

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
        TEXT("SMB : Perspective BW Triangle"),                                      // This is the same as what we gave as parameter to glutCreateWindow in our Shuddha-Lekhan program
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
            // set global width and height
            gWidth = LOWORD(lParam);
            gHeight = HIWORD(lParam);
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
                case '1':
                    currentPattern = PATTERN_1;
                break;
                case '2':
                    currentPattern = PATTERN_2;
                break;
                case '3':
                    currentPattern = PATTERN_3;
                break;
                case '4':
                    currentPattern = PATTERN_4;
                break;
                case '5':
                    currentPattern = PATTERN_5;
                break;
                case '6':
                    currentPattern = PATTERN_6;
                break;
                default:
                    currentPattern = NO_PATTERN;
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
    pfd.nSize           = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.nVersion        = 1;
    pfd.dwFlags         = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType      = PFD_TYPE_RGBA;
    pfd.cRedBits        = 8;
    pfd.cGreenBits      = 8;
    pfd.cBlueBits       = 8;
    pfd.cAlphaBits      = 8;

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
    // pattern assignment related functions
    void drawPattern1(void);
    void drawPattern2(void);
    void drawPattern3(void);
    void drawPattern4(void);
    void drawPattern5(void);
    void drawPattern6(void);
    // code
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    switch(currentPattern)
    {
        case PATTERN_1:
            drawPattern1();
        break;
        case PATTERN_2:
            drawPattern2();
        break;
        case PATTERN_3:
            drawPattern3();
        break;
        case PATTERN_4:
            drawPattern4();
        break;
        case PATTERN_5:
            drawPattern5();
        break;
        case PATTERN_6:
            drawPattern6();
        break;
        case NO_PATTERN:
        break;
        default:
        break;
    }

    // do double buffering
    SwapBuffers(ghdc);
}

void drawPattern1(void)
{
    // code
    glEnable(GL_POINT_SMOOTH);
    glPointSize(3.0);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POINTS);
    {
        int xcounter = 4;
        float stepSize = 0.25f;
        for(float x = -0.75f + stepSize; xcounter && x <= 1.0f; x = x + stepSize, --xcounter)
        {
            int ycounter = 4;
            for(float y = 0.75f - stepSize; ycounter && y >= -1.0f; y = y - stepSize, --ycounter)
            {
                glVertex3f(x, y, -2.0f);
            }
        }
    }
    glEnd();
    glPointSize(1.0f);
    glDisable(GL_POINT_SMOOTH);
}

void drawPattern2(void)
{
    // code
    float step = 0.6f;
    int xcounter = 3;
    for(float x = -0.9f; xcounter && x < 0.9f; x = x + step, --xcounter)
    {
        glBegin(GL_LINES);
        {
            glVertex3f(x, 0.9, -4.0f);
            glVertex3f(x, -0.9, -4.0f);
        }
        glEnd();
    }

    int ycounter = 3;
    for(float y = 0.9f; ycounter && y > -0.9f; y = y - step, --ycounter)
    {
        glBegin(GL_LINES);
        {
            glVertex3f(-0.9, y, -4.0f);
            glVertex3f(0.9, y, -4.0f);
        }
        glEnd();
    }

    int totalLines = 5;
    int xycounter = totalLines;
    float substep = step;
    for(float x = -0.9, y = 0.9f; xycounter; --xycounter)
    {
        glBegin(GL_LINES);
        {
            if(xycounter <= (totalLines - totalLines/2))
            {
                step -= substep;
                glVertex3f(x + step, -y, -4.0f);
                glVertex3f(-x, y - step, -4.0f);
            }
            else
            {
                glVertex3f(x, y - step, -4.0f);
                glVertex3f(x + step, y, -4.0f);
                step += substep;
            }
        }
        glEnd();
    }
}

void drawPattern3(void)
{
    // code
    float step = 0.6f;
    int xcounter = 3;
    float x;
    glColor3f(1.0f, 1.0f, 1.0f);
    for(x = -0.9f; xcounter && x < 0.9f; x = x + step, --xcounter)
    {
        glBegin(GL_LINES);
        {
            glVertex3f(x, 0.9, -4.0f);
            glVertex3f(x, -0.9, -4.0f);
        }
        glEnd();
    }
    glBegin(GL_LINES);
    {
        glVertex3f(x, 0.9, -4.0f);
        glVertex3f(x, -0.9, -4.0f);
    }
    glEnd();

    int ycounter = 3;
    float y;
    for(y = 0.9f; ycounter && y > -0.9f; y = y - step, --ycounter)
    {
        glBegin(GL_LINES);
        {
            glVertex3f(-0.9, y, -4.0f);
            glVertex3f(0.9, y, -4.0f);
        }
        glEnd();
    }
    glBegin(GL_LINES);
    {
        glVertex3f(-0.9, y, -4.0f);
        glVertex3f(0.9, y, -4.0f);
    }
    glEnd();
}

void drawPattern4(void)
{
    // code
    drawPattern3();
    float step = 0.6f;
    int totalLines = 5;
    int xycounter = totalLines;
    float substep = step;
    for(float x = -0.9, y = 0.9f; xycounter; --xycounter)
    {
        glBegin(GL_LINES);
        {
            if(xycounter <= (totalLines - totalLines/2))
            {
                step -= substep;
                glVertex3f(x + step, -y, -4.0f);
                glVertex3f(-x, y - step, -4.0f);
            }
            else
            {
                glVertex3f(x, y - step, -4.0f);
                glVertex3f(x + step, y, -4.0f);
                step += substep;
            }
        }
        glEnd();
    }
}

void drawPattern5(void)
{
    // code
    int totalLines = 3;
    float substep = (2.0f * 0.9f) / 3.0f;
    float step = 0.0f;
    for(float x = -0.9f, y = 0.9f; totalLines; --totalLines, step += substep)
    {
        glBegin(GL_LINES);
        {
            glVertex3f(x, y, -4.0f);
            glVertex3f(x + step, -y, -4.0f);
        }
        glEnd();
    }
    // again for y now
    totalLines = 3;
    step = 0.0f;
    for(float y = 0.9f, x = -0.9f; totalLines; --totalLines, step += substep)
    {
        glBegin(GL_LINES);
        {
            glVertex3f(x, y, -4.0f);
            glVertex3f(-x, y - step, -4.0f);
        }
        glEnd();
    }
    glBegin(GL_LINES);
    {
        float x = -0.9f, y = 0.9f;
        glVertex3f(x, y, -4.0f);
        glVertex3f(-x, -y, -4.0f);
    }
    glEnd();
    glBegin(GL_LINE_STRIP);
    {
        float x = 0.9f, y = 0.9f;
        glVertex3f(x, y, -4.0f);
        glVertex3f(x, -y, -4.0f);
        glVertex3f(-x, -y, -4.0f);
    }
    glEnd();
}

void drawPattern6(void)
{
    // code
    float step = 0.6f;
    float x = -0.9f, y = 0.9f;
    int totalTimesToPaint = 3;
    int totalQuadsToPaint = 3;
    while(totalTimesToPaint--)
    {
        switch(totalTimesToPaint + 1)
        {
            case 3:
                glColor3f(1.0f, 0.0f, 0.0f);
            break;
            case 2:
                glColor3f(0.0f, 1.0f, 0.0f);
            break;
            case 1:
                glColor3f(0.0f, 0.0f, 1.0f);
            break;
            default:
                glColor3f(1.0f, 1.0f, 1.0f);
            break;
        }

        y = 0.9f;
        totalQuadsToPaint = 3;
        while (totalQuadsToPaint--)
        {
            glBegin(GL_QUADS);
            {
                glVertex3f(x, y, -4.0f);
                glVertex3f(x, y - step, -4.0f);
                glVertex3f(x + step, y - step, -4.0f);
                glVertex3f(x + step, y, -4.0f);
            }
            glEnd();
            y -= step;
        }

        x += step;
    }

    drawPattern3();
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

void setViewport(GLint x, GLint y, GLsizei width, GLsizei height)
{
    // code
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(x, y, width, height);
    gluPerspective(
        45.0f,
        (GLfloat)width / (GLfloat)height,
        0.1f,
        100.0f
    );
}

void printGLInfo(void)
{
    // code
    fprintf(gpFile, "\tOpenGL Vendor   : %s\n", glGetString(GL_VENDOR));
    fprintf(gpFile, "\tOpenGL Renderer : %s\n", glGetString(GL_RENDERER));
    fprintf(gpFile, "\tOpenGL Version  : %s\n", glGetString(GL_VERSION));
}
