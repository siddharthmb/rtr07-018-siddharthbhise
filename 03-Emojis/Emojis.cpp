#include <GL/freeglut.h>
#include "SMBDrawingMath.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

bool bIsFullScreen = false;

enum emoji_t
{
	POKER_FACE = 0,
	SMILE = 1,
	SAD,
	BORED,
	ANGRY,
	BOSS,
	FEAR,
	TRIANGLE_EYED_SMILE,
	UPSIDE_DOWN_SMILE,
	BLANK_FACE
};

static emoji_t currentEmoji = SMILE;

int main(int argc, char* argv[])
{
	// function declaration
	void display(void);
	void initialize(void);
	void uninitialize(void);
	void resize(int, int);
	void keyboard(unsigned char, int, int);
	void mouse(int, int, int, int);
	
	// code
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(500, 100);
	glutInitWindowSize(900, 900);
	glutCreateWindow("SMB : EMOJIs assignment");

	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutCloseFunc(uninitialize);
	glutReshapeFunc(resize);
	glutMouseFunc(mouse);

	initialize();
	glutMainLoop();

	// flow never comes here
	return 0;
}

void drawEyes(float r, float scalePercent, float h, float v)
{
	drawCircleWithScale(r, r, h + (-4.0 * r), v + (3.0f * r), 0.0f, 2 * M_PI, scalePercent, GL_POLYGON);
	drawCircleWithScale(r, r, h + (4.0 * r),  v + (3.0f * r), 0.0f, 2 * M_PI, scalePercent, GL_POLYGON);
}

void drawTriangleEye(float scalePercent, float h, float v)
{
	float scale = scalePercent / 100.0f;
	float x, y, z = 0.0f;
	glBegin(GL_TRIANGLES);
	{
		x = -1.0f, y = 0.0f;
		glVertex3f((x + h) * scale, (y + v) * scale, z);
		x = 0.0f, y = 1.0f;
		glVertex3f((x + h) * scale, (y + v) * scale, z);
		y = 0.8f;
		glVertex3f((x + h) * scale, (y + v) * scale, z);

		// same point
		glVertex3f((x + h) * scale, (y + v) * scale, z);
		y = 1.0f;
		glVertex3f((x + h) * scale, (y + v) * scale, z);
		x = 1.0f, y = 0.0f;
		glVertex3f((x + h) * scale, (y + v) * scale, z);
	}
	glEnd();
}

void drawFaceCommonFeatures(float r, float scalePercent, float h, float v)
{
	drawCircleWithScale(r, r, h, v, 0.0f, 2 * M_PI, scalePercent, GL_POLYGON);
	// eyes - black
	glColor3f(0.0f, 0.0f, 0.0f);
	drawEyes(r / 10.0f, 100.0f, h, v);
}

void initialize(void)
{
	// code
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void drawSmile(float r, float scalePercent, float h, float v, GLenum mode, bool redrawCommonFeatures)
{
	if (redrawCommonFeatures)
	{
		glColor3f(1.0f, 1.0f, 0.0f);	// that yellow color of the emojis
		drawFaceCommonFeatures(0.2f, 100.0f, h, v);
	}

	glColor3f(0.0f, 0.0f, 0.0f);
	// smile
	drawCircleWithScale(r * 1.25f, r * 0.8f, h, v - r, 0.0f + 0.05f, M_PI - 0.05f, scalePercent, mode);
}

void drawSad(float r, float scalePercent, float h, float v, GLenum mode, bool redrawCommonFeatures)
{
	if (redrawCommonFeatures)
	{
		glColor3f(1.0f, 1.0f, 0.0f);	// that yellow color of the emojis
		drawFaceCommonFeatures(0.2f, 100.0f, h, v);
	}

	glColor3f(0.0f, 0.0f, 0.0f);
	// sad
	drawCircleWithScale(r * 1.25f, r * 0.8f, h, v - r * 1.15f, M_PI, 2 * M_PI, scalePercent, mode);
}

void drawBored(float scalePercent, float h, float v, float width, float height, bool redrawCommonFeatures)
{
	if (redrawCommonFeatures)
	{
		glColor3f(1.0f, 1.0f, 0.0f);	// that yellow color of the emojis
		drawFaceCommonFeatures(0.2f, 100.0f, h, v);
	}

	glColor3f(0.0f, 0.0f, 0.0f);
	// bored
	drawQuad1(h, v - 0.1f, width, height, scalePercent);
}

void drawAngry(float scalePercent, float h, float v, bool redrawCommonFeatures)
{
	if (redrawCommonFeatures)
	{
		glColor3f(1.0f, 0.35f, 0.11f);	// orange color for angry
		drawFaceCommonFeatures(0.2f, 100.0f, h, v);
	}

	// angry
	glColor3f(0.0f, 0.0f, 0.0f);
	// angry - small lips, sad
	drawSad(0.08f, 20.0f, h, v - 0.05f, GL_LINE_STRIP, false);
	// angry - eyebrows
	glColor3f(0.0f, 0.0f, 0.0f);
	drawQuadWithXYCoordinates(h - 0.7f, v + 0.85f, -0.2f, 0.2f, -0.19f, 0.21f,  0.21f, 0.05f,  0.2f, 0.03f, scalePercent * 0.1f);
	drawQuadWithXYCoordinates(h + 0.7f, v + 0.85f,  0.2f, 0.2f,  0.19f, 0.21f, -0.21f, 0.05f, -0.2f, 0.03f, scalePercent * 0.1f);
}

void drawBoss(float scalePercent, float h, float v, float redrawCommonFeatures)
{
	if (redrawCommonFeatures)
	{
		glColor3f(1.0f, 1.0f, 0.0f);	// that yellow color of the emojis
		drawFaceCommonFeatures(0.2f, 100.0f, h, v);
	}

	// boss
	glColor3f(0.0f, 0.0f, 0.0f);
	drawQuad1(h - 0.08f, v + 0.06f, 0.24f, 0.15f, scalePercent * 0.4f);
	drawQuad1(h + 0.08f, v + 0.06f, 0.24f, 0.15f, scalePercent * 0.4f);
	drawQuad1(h, v + 0.06f, 0.08f, 0.004f, scalePercent);
	drawSmile(0.08f, scalePercent * 0.5f, h, v - 0.03f, GL_LINE_STRIP, false);
}

void drawFear(float scalePercent, float h, float v, bool redrawCommonFeatures)
{
	if (redrawCommonFeatures)
	{
		glColor3f(1.0f, 1.0f, 0.0f);
		drawFaceCommonFeatures(0.2f, 100.0f, h, v);
	}

	// angry
	glColor3f(0.0f, 0.0f, 0.0f);
	// fear lips - sad
	drawSad(0.08f, 20.0f, h, v - 0.05f, GL_POLYGON, false);
	// fear - eyebrows
	glColor3f(0.0f, 0.0f, 0.0f);
	//drawQuadWithXYCoordinates(h - 0.7f, v + 0.85f, -0.2f, 0.2f, -0.21f, 0.21f, 0.21f, 0.25f, 0.2f, 0.24f, scalePercent * 0.1f);
	//drawQuadWithXYCoordinates(h + 0.7f, v + 0.85f, 0.2f, 0.2f, 0.19f, 0.21f, -0.21f, 0.05f, -0.2f, 0.03f, scalePercent * 0.1f);
	glColor3f(0.0f, 0.0f, 0.0f);
	drawQuadWithXYCoordinates(h - 0.15f, v + 0.08f, -0.2f, 0.2f, -0.19f, 0.19f, 0.0f, 0.25f, -0.01f, 0.26f, scalePercent * 0.35f);
	drawQuadWithXYCoordinates(h + 0.15f, v + 0.08f, 0.2f, 0.2f, 0.19f, 0.19f, 0.0f, 0.25f, 0.01f, 0.26f, scalePercent * 0.35f);
}

void drawTriangleEyedSmile(float scalePercent, float h, float v, bool redrawCommonFeatures)
{
	float r = 0.2f;
	glColor3f(1.0f, 1.0f, 0.0f);	// that yellow color of the emojis
	drawCircleWithScale(r, r, h, v, 0.0f, 2 * M_PI, scalePercent, GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	drawTriangleEye(scalePercent * 0.05f, h - 1.5f, v + 1.0f);
	drawTriangleEye(scalePercent * 0.05f, h + 1.5f, v + 1.0f);
	drawSmile(0.08f, scalePercent * 0.5f, h, v - 0.03f, GL_POLYGON, false);
}

void drawUpsideDownSmile(float scalePercent, float h, float v, bool redrawCommonFeatures)
{
	float r = 0.2f;
	glColor3f(1.0f, 1.0f, 0.0f);	// that yellow color of the emojis
	drawCircleWithScale(r, r, h, v, 0.0f, 2 * M_PI, scalePercent, GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	r = r / 10.0f;
	drawEyes(r, scalePercent, h, v - 0.15f);
	drawSad(0.08f, scalePercent * 0.5f, h, v + 0.18f, GL_LINE_STRIP, false);
}

void drawBlankFace(float scalePercent, float h, float v, bool redrawCommonFeatures)
{
	glColor3f(1.0f, 1.0f, 0.0f);
	drawFaceCommonFeatures(0.2f, scalePercent, h, v);
}

void drawPokerFace(float scalePercent, float h, float v, bool redrawCommonFeatures)
{
	float r = 0.2f;
	glColor3f(1.0f, 1.0f, 0.0f);	// that yellow color of the emojis
	drawCircleWithScale(r, r, h, v, 0.0f, 2 * M_PI, scalePercent, GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	drawQuad1(h - 0.07f, v + 0.07f, 0.2f, 0.01f, scalePercent * 0.4);
	drawQuad1(h + 0.07f, v + 0.07f, 0.2f, 0.01f, scalePercent * 0.4);
	drawQuad1(h, v - 0.07f, 0.5f, 0.02f, scalePercent * 0.4);
}

void display(void)
{
	// code
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// emoji happy
	float x, y, z = 0.0f;
	float h = 0.0f, v = 0.0f;
	
	switch (currentEmoji)
	{
	case SMILE:
		// 1. smile
		drawSmile(0.08f, 100.0f, h, v, GL_LINE_STRIP, true);
		break;
	case SAD:
		// 2. sad
		drawSad(0.08f, 100.0f, h, v, GL_LINE_STRIP, true);
		break;
	case BORED:
		// 3. bored
		drawBored(100.0f, h, v, 0.2f, 0.008f, true);
		break;
	case ANGRY:
		// 4. angry
		drawAngry(100.0f, h, v, true);
		break;
	case BOSS:
		// 5. boss
		drawBoss(100.0f, h, v, true);
		break;
	case FEAR:
		// 6. fear
		drawFear(100.0f, h, v, true);
		break;
	case TRIANGLE_EYED_SMILE:
		// 7. triangle eyed smile
		drawTriangleEyedSmile(100.0f, h, v, true);
		break;
	case UPSIDE_DOWN_SMILE:
		// 8. upside down smile
		drawUpsideDownSmile(100.0f, h, v, false);
		break;
	case BLANK_FACE:
		// 9. blank face
		drawBlankFace(100.0f, h, v, true);
		break;
	case POKER_FACE:
		// 10. poker face
		drawPokerFace(100.0f, h, v, false);
		break;
	default:
		break;
	}

	glutSwapBuffers();
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

void keyboard(unsigned char key, int x, int y)
{
	bool shouldPostRedisplay = true;
	// code
	switch (key)
	{
	case 27:
		shouldPostRedisplay = false;	// not needed really, but still...
		glutLeaveMainLoop();
		break;
	case 'f':
	case 'F':
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

		shouldPostRedisplay = false;	// done anyway
		break;
	case 49:	// 0
		currentEmoji = SMILE;
		break;
	case 50:	// 1
		currentEmoji = SAD;
		break;
	case 51:	// 2
		currentEmoji = BORED;
		break;
	case 52:	// 3
		currentEmoji = ANGRY;
		break;
	case 53:	// 4
		currentEmoji = BOSS;
		break;
	case 54:	// 5
		currentEmoji = FEAR;
		break;
	case 55:	// 6
		currentEmoji = TRIANGLE_EYED_SMILE;
		break;
	case 56:	// 7
		currentEmoji = UPSIDE_DOWN_SMILE;
		break;
	case 57:	// 8
		currentEmoji = BLANK_FACE;
		break;
	case 48:	// 9
		currentEmoji = POKER_FACE;
		break;
	default:
		break;
	}

	if (shouldPostRedisplay) glutPostRedisplay();
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
