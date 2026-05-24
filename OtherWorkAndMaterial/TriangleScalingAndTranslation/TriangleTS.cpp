#include <GL/freeglut.h>

#define TRANSLATION_STEP  0.01f
#define SCALING_STEP	  0.01f

bool bIsFullScreen = false;

static float x_translation = 0.0f;
static float y_translation = 0.0f;
static float scaling_base  = 100.0f;

int main(int argc, char* argv[])
{
	// function declarations
	void initialize(void);
	void uninitialize(void);
	void display(void);
	void resize(int, int);
	void keyboard(unsigned char, int, int);
	void mouse(int, int, int, int);

	// code
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Triangle with translation & scaling: by SMB");

	initialize();

	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutCloseFunc(uninitialize);

	glutMainLoop();

	// the flow never comes here...
	return 0;
}

void initialize(void)
{
	// code
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
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

	glBegin(GL_TRIANGLES);
	{
		float x, y, z = 0.0f;
		glColor3f(1.0f, 0.0f, 0.0f);
		x = 0.0f, y = 1.0f;
		glVertex3f
		(
			(x + x_translation) * (scaling_base / 100.0f),
			(y + y_translation) * (scaling_base / 100.0f),
			z
		);

		glColor3f(0.0f, 1.0f, 0.0f);
		x = -1.0f, y = -1.0f;
		glVertex3f
		(
			(x + x_translation) * (scaling_base / 100.0f),
			(y + y_translation) * (scaling_base / 100.0f),
			z
		);

		glColor3f(0.0f, 0.0f, 1.0f);
		x = 1.0f;
		glVertex3f
		(
			(x + x_translation) * (scaling_base / 100.0f),
			(y + y_translation) * (scaling_base / 100.0f),
			z
		);
	}
	glEnd();

	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	bool postRedislay = true;
	// code
	switch (key)
	{
	case 27:
		glutLeaveMainLoop();
		postRedislay = false;	// not needed
		break;
	case 'f':
	case 'F':
		postRedislay = false;	// happens as the window dimension changes
		if (bIsFullScreen)
		{
			glutLeaveFullScreen();
			bIsFullScreen = false;
		}
		else
		{
			glutFullScreen();
			bIsFullScreen = true;
		}
		break;
	case 'w':
	case 'W':
		y_translation = y_translation + TRANSLATION_STEP;
		break;
	case 'a':
	case 'A':
		x_translation = x_translation - TRANSLATION_STEP;
		break;
	case 's':
	case 'S':
		y_translation = y_translation - TRANSLATION_STEP;
		break;
	case 'd':
	case 'D':
		x_translation = x_translation + TRANSLATION_STEP;
		break;
	case '+':
		scaling_base = scaling_base + (SCALING_STEP * 100.0f);
		break;
	case '-':
		scaling_base = scaling_base - (SCALING_STEP * 100.0f);
		break;
	default:
		break;
	}

	if (postRedislay)
	{
		postRedislay = false;
		glutPostRedisplay();
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
	case GLUT_LEFT_BUTTON:
		// reset all scaling and translation params
		scaling_base  = 100.0f;
		x_translation = 0.0f;
		y_translation = 0.0f;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}

void uninitialize(void)
{
	// code
}