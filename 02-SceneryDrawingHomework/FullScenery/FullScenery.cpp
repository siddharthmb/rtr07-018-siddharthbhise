#include <GL/freeglut.h>
#include <sysinfoapi.h>
#include <stdio.h>
#include <time.h>
// SMB headers
#include "FullScenery.h"
#include "SMBDrawingMath.h"

bool bIsFullScreen = false;
extern unsigned int currentHour = 0;

int main(int argc, char* argv[])
{
	// function declarations
	void initialize(void);
	void uninitialize(void);
	void resize(int, int);
	void display(void);
	void keyboard(unsigned char, int, int);
	void mouse(int, int, int, int);
	// smb func
	void initCurrentHourFromTime(void);
	void initColorSchemesForCurrentHour(void);

	// code
	srand(time(NULL));
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Retreat : by SiddharthMB");

	initialize();

	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutCloseFunc(uninitialize);

	glutMainLoop();

	// should never come here...!
	return 0;
}

void initCurrentHourFromTime(void)
{
	// code
	SYSTEMTIME st;
	GetLocalTime(&st);
	// setting this global var here so that same value is reflected in all funcs that need to draw based on Time of Day.
	currentHour = ((unsigned int)st.wHour);
	currentHour = 21;
}

void initColorSchemesForCurrentHour(void)
{
	// code
	if (currentHour >= 6 && currentHour < 9)
	{
		//glClearColor(0.85f, 0.7f, 0.65f, 1.0f);
		glClearColor(0.60f, 0.70f, 0.85f, 1.0f);
	}
	else if (currentHour >= 9 && currentHour < 12)
	{
		glClearColor(0.53f, 0.81f, 0.98f, 1.0f);
	}
	else if (currentHour >= 12 && currentHour < 15)
	{
		//glClearColor(0.9f, 0.95f, 1.0f, 1.0f);
		glClearColor(0.20f, 0.60f, 1.0f, 1.0f);
	}
	else if (currentHour >= 15 && currentHour < 18)
	{
		glClearColor(0.40f, 0.70f, 0.95f, 1.0f);
		//glClearColor(0.88f, 0.55f, 0.58f, 1.0f);
	}
	else if (currentHour >= 18 && currentHour < 21)
	{
		glClearColor(0.2f, 0.2f, 0.4f, 1.0f);
	}
	else if (currentHour >= 21 && currentHour <= 23)
	{
		glClearColor(0.05f, 0.05f, 0.2f, 1.0f);
	}
	else if (currentHour >= 0 && currentHour < 3)
	{
		glClearColor(0.02f, 0.02f, 0.1f, 1.0f);
	}
	else if (currentHour >= 3 && currentHour < 6)
	{
		//glClearColor(0.15f, 0.25f, 0.45f, 1.0f);
		glClearColor(0.05f, 0.07f, 0.12f, 1.0f);
	}
}

void initialize(void)
{
	// code
	initCurrentHourFromTime();
	initColorSchemesForCurrentHour();
}

void resize(int width, int height)
{
	// code
	if (height <= 0)
	{
		height = 1;
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
}

void display(void)
{
	// code
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	drawStars();
	drawWave();
	//drawWavyLines();
	drawFence();
	drawBackGrass();
	drawNTrees(5);
	//drawRoundedGrass();
	drawHouse();
	drawFrontGrass();
	
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	// code
	switch (key)
	{
	case 27:
		glutLeaveMainLoop();
		break;
	case 'f':
	case 'F':
		if (bIsFullScreen == false)
		{
			glutFullScreen();
			bIsFullScreen = true;
		}
		else
		{
			glutLeaveFullScreen();
			bIsFullScreen = false;
		}
		break;
	default:
		break;
	}
}

void mouse(int button, int state, int x, int y)
{
	// code
	switch (button)
	{
	case GLUT_RIGHT_BUTTON:
		glutLeaveMainLoop();
		break;
	default:
		break;
	}
}

void uninitialize(void)
{
	// code
}
