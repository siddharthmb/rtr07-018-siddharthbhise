#include "Fence.h"
#include <GL/freeglut.h>
#define _USE_MATH_DEFINES
#include <math.h>

void drawFence(void)
{
	glColor3f(0.85f, 0.71f, 0.54f);
	glBegin(GL_LINE_STRIP);
	{
		float y1, y2, x, a, f, h, v, vdash, z;
		h = 0.0f;
		v = -1.0f;
		a = 0.04f;
		z = 0.0f;
		f = 1.0f;
		vdash = -0.58f;

		float step = 0.0025f;

		for (x = -1.05f; x < 1.05f; x = x + step)
		{
			y1 = a * sin(f * x * 0.1 + h) + v;
			y2 = a * sin(f * x * 0.1 + h) + vdash;
			glVertex3f(x, y1, z);
			glVertex3f(x, y2, z);
		}
	}
	glEnd();
}