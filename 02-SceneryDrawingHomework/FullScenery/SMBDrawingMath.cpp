#include "SMBDrawingMath.h"
#include <GL/freeglut.h>
#define _USE_MATH_DEFINES
#include <math.h>


void renderSineWave(float xStart, float xEnd, float xStep, float a, float f, float y1_displacement, float y2_displacement, float z)
{
	for (float x = xStart; x < xEnd; x = x + xStep)
	{
		float y1 = a * sin(f * x) + y1_displacement;
		float y2 = a * sin(f * x) + y2_displacement;
		glVertex3f(x, y1, z);
		glVertex3f(x, y2, z);
	}
}

void drawCircle(float h, float v, float r)
{
	glBegin(GL_TRIANGLE_FAN);
	{
		float z = 0.0f;
		for (float i = 0.0f; i < 2.0f; i = i + 0.01f)
		{
			float theta = i * M_PI;

			float x = r * cos(theta);
			float y = r * sin(theta);

			glVertex3f(x + h, y + v, z);
		}
	}
	glEnd();
}

void drawVerticalQuad(float x1, float x2, float yStart, float z, float width)
{
	glBegin(GL_QUAD_STRIP);
	{
		for (float i = yStart; i > -1.0f; i = i - 0.01)
		{
			glVertex3f(x1, i, z);
			glVertex3f(x2, i, z);
		}
	}
	glEnd();
}
