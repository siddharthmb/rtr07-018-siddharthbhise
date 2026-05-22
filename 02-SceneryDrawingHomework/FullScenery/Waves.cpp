#include "Waves.h"
#include "SMBDrawingMath.h"
#include <GL/freeglut.h>
#include <stdio.h>

extern unsigned int currentHour;

void setColorThemeBeforeDrawingForCurrentHour(void)
{
	// code
	if (currentHour >= 6 && currentHour < 9)
	{
		//glColor3f(0.05f, 0.08f, 0.15f);
		glColor3f(0.30f, 0.45f, 0.60f);
	}
	else if (currentHour >= 9 && currentHour < 12)
	{
		//glColor3f(0.05f, 0.08f, 0.15f);
		glColor3f(0.15f, 0.45f, 0.65f);
	}
	else if (currentHour >= 12 && currentHour < 15)
	{
		//glColor3f(0.05f, 0.08f, 0.15f);
		glColor3f(0.0f, 0.35f, 0.55f);
	}
	else if (currentHour >= 15 && currentHour < 18)
	{
		glColor3f(0.10f, 0.40f, 0.60f);
	}
	else if (currentHour >= 18 && currentHour < 21)
	{
		printf("WOWWWW\n");
		glColor3f(0.12f, 0.12f, 0.28f);
	}
	else if (currentHour >= 21 && currentHour <= 23)
	{
		glColor3f(0.05f, 0.08f, 0.15f);
	}
	else if (currentHour >= 0 && currentHour < 3)
	{
		glColor3f(0.05f, 0.08f, 0.15f);
	}
	else if (currentHour >= 3 && currentHour < 6)
	{
		//glColor3f(0.05f, 0.08f, 0.15f);
		glColor3f(0.05f, 0.02f, 0.09f);
	}
}

void drawWavyLines(void)
{
	glBegin(GL_LINE_STRIP);
	{
		// TBD
	}
	glEnd();
}

void drawWave(void)
{
	glBegin(GL_TRIANGLE_STRIP);
	{
		setColorThemeBeforeDrawingForCurrentHour();
		// water wave code
		float x1 = -1.05f, x2 = 1.05f;
		float step = 0.01f;
		float z = 0.0f;
		float a = 0.005f;
		float f = 50.0f;
		// size of the wave
		float y1_displacement = -0.27f, y2_displacement = -1.05f;

		renderSineWave(x1, x2, step, a, f, y1_displacement, y2_displacement, z);
	}
	glEnd();
}
