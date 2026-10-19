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
// for animations
float angleCube = 0.0f;
float anglePyramid = 0.0f;
float angleRotation = 0.0f;

GLuint texture_stone = 0;

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
        TEXT("SMB : Pyramid (TEXTURES)"),                                      // This is the same as what we gave as parameter to glutCreateWindow in our Shuddha-Lekhan program
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
    // texture
    BOOL loadGLTexture(GLuint *, TCHAR[]);

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

    // print GL info
    printGLInfo();

    // choose screen clearing color as blue
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // load textures
    BOOL bResult = FALSE;
    bResult = loadGLTexture(&texture_stone, MAKEINTRESOURCE(IDBITMAP_STONE));  // texture_stone will go as out param and comeback with some positive value
    if(bResult == FALSE)
    {
        fprintf(gpFile, "SMB:initialize(): Failed to load stone texture (return val = %d)\n", texture_stone);
        return -6;
    }

    // enable texturing
    glEnable(GL_TEXTURE_2D);

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
    void draw3DCube(void);
    void draw3DTriangle(void);

    // code
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    draw3DTriangle();

    // do double buffering
    SwapBuffers(ghdc);
}

void draw3DCube(void)
{
    // code
    // cube
    /* la front - red, 
       right - green,
       back - blue,
       left - cyan
       top - yellow,
       bottom - magenta
    */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(1.2f, 0.0f, -6.0f);
    glScalef(0.75f, 0.75f, 0.75f);
    glRotatef(angleCube, 1.0f, 1.0f, 1.0f);
    // glBindTexture(GL_TEXTURE_2D, texture_kundali);

    glBegin(GL_QUADS);
    {
        // front
        // glColor3f(1.0f, 0.0f, 0.0f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, 1.0f);   // top-right of front
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);  // top-left of front
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f); // bottom-left of front
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);  // bottom-right of front

        // right
        // glColor3f(0.0f, 1.0f, 0.0f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, -1.0f);  // top-right of right
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, 1.0f);   // top-left of right
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);  // bottom-left of right
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, -1.0f); // bottom-right of right

        // back
        // glColor3f(0.0f, 0.0f, 1.0f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, -1.0f);   // top-right of back
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, -1.0f);  // top-left of back
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f); // bottom-left of back
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);  // bottom-right of back

        // left
        // glColor3f(0.0f, 1.0f, 1.0f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);   // top-right of left
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, -1.0f);  // top-left of left
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f); // bottom-left of left
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);  // bottom-right of left

        // top
        // glColor3f(1.0f, 0.0f, 1.0f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, -1.0f);  // top-right of top
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, -1.0f); // top-left of top
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);  // bottom-left of top
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(1.0f, 1.0f, 1.0f);   // bottom-right of top

        // bottom
        // glColor3f(1.0f, 1.0f, 0.0f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);   // top-right of bottom
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);  // top-left of bottom
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f); // bottom-left of bottom
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);  // bottom-right of bottom
    }
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
}

void draw3DTriangle(void)
{
    // code
    // pyramid 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(-1.2f, 0.0f, -6.0f);
    glRotatef(anglePyramid, 0.0f, 1.0f, 0.0f);
    glBindTexture(GL_TEXTURE_2D, texture_stone);

    glBegin(GL_TRIANGLES);
    {
        // front face
        // glColor3f(1.0f, 0.0f, 0.0f);
        glTexCoord2f(0.5f, 1.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);

        // right face
        glTexCoord2f(0.5f, 1.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);

        // back face
        glTexCoord2f(0.5f, 1.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);

        // left
        glTexCoord2f(0.5f, 1.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
    }
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
}


void update(void)
{
    // code
    anglePyramid = anglePyramid + 1.0f;
    if(anglePyramid > 360) anglePyramid = 0.0f;

    angleCube = angleCube + 1.0f;
    if(angleCube > 360) angleCube = 0.0f;
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

     if(texture_stone)
    {
        glDeleteTextures(1, &texture_stone);
        texture_stone = 0;
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

BOOL loadGLTexture(GLuint *tex, TCHAR imageResourceID[])
{
    // variable declarations
    /*
        ALGORITHM: Steps for loading texture
        ------------------------------------
        1. Load the image resource and get its handle.
        2. Use this handle to get the Windows struct BITMAP texture object.
        3. Decide how OpenGL should store and align the bits in the image in the memory.
        4. Create the OpenGL texture object.
        5. Bind with that newly created OpenGL texture object.
        6. Set the OpenGL texture object's parameters.
        7. Accordingly, build the texture object and its mipmaps. (MIPMAPS means ?)
        8. Unbind with the OpenGL texture object.
        9. Delete Windows texture object. (obtained in Step 2)
    */

    HBITMAP hBitmap = NULL;
    BITMAP bmp;

    // code
    // 1.
    hBitmap = (HBITMAP)LoadImage(
        (HINSTANCE)GetModuleHandle(NULL),  // we get the instance handle to exe by GetModuleHandle(NULL)
        imageResourceID,        // MAKEINTRESOURCE was used to send this as 2nd param to this function
        IMAGE_BITMAP,           // We are dealing with BITMAP, hence...
        0,                      // ICON and CURSOR requires width and height, but textures we give this value 0
        0,
        LR_CREATEDIBSECTION     // Load the image as resource, and put that in the device independent section of the resource file.
    );

    if(hBitmap == NULL)
    {
        fprintf(gpFile, "SMB: loadGLTexture failed with LoadImage failure\n");
        return FALSE;
    }

    // 2 .
    GetObject(hBitmap, sizeof(BITMAP), &bmp);
    // 3.
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);  // 4 because R, G, B, A. To obtain only Red, give 1 and so on...
    // 4.
    glGenTextures(1, tex);  // this is OpenGL's texture object
    // 5.
    glBindTexture(GL_TEXTURE_2D, *tex);
    // 6.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);    // MAGNIFICATION filter means, when the object moves away from camera, quality is reduced to reduce load.
                                                                // if img is of 32x32, it creates internally, 16x16, 8x8, 4x4, 2x2, 1x1 internally and applies accordingly.
                                                                // this is called as MIPMAPPING.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); // use linear, but the one that OpenGL created while mipmapping.
    // GL_LINEAR means that the TEXEL to PIXEL mapping has colours of 4 surrounding TEXELS (average)
    // GL_NEAREST means one to one mapping of TEXEL to PIXEL

    // 7.
    gluBuild2DMipmaps(
        GL_TEXTURE_2D,
        GL_RGB,
        bmp.bmWidth,
        bmp.bmHeight,
        GL_BGR_EXT,     // Windows OS format
        GL_UNSIGNED_BYTE,
        bmp.bmBits
    );

    // 8.
    glBindTexture(GL_TEXTURE_2D, 0);
    // 9.
    DeleteObject(hBitmap);
    hBitmap = NULL;

    return TRUE;
}
