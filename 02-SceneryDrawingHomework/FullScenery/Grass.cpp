#include "Grass.h"
#include "SMBDrawingMath.h"
#include <GL/freeglut.h>
#include <stdlib.h>

extern unsigned int currentHour;

void drawRoundedGrass(void)
{
	if (currentHour >= 0 && currentHour < 6 || currentHour >= 20 && currentHour < 24)
	{
		glColor3f(0.02f, 0.15f, 0.03f);
	}
	else if (currentHour >= 6 && currentHour < 9)
	{
		glColor3f(0.20f, 0.45f, 0.25f);
	}
	else
	{
		glColor3f(0.02f, 0.45f, 0.03f);
	}
	// rounded grass
	for (float h = -1.05f; h < 1.05f; h = h + 0.1f)
	{
		srand((int)currentHour);
		int r = rand() % 10;
		if (r < 0) r = r * -1;

		int v_rand = 5 + rand() % r;
		float v = (float)(v_rand / 100.0f);

		drawCircle(h, -0.85f + v, (float)r / 100.0f);
	}
}

void drawBackGrass(void)
{
	glBegin(GL_TRIANGLES);
	{
		// step for incrementing [x,y]
		float step = 0.125f;
		// back grass
		float x = -1.0f;
		float y = -1.0f;
		float z = -0.5f;
		//glColor3f(0.3f, 0.7f, 0.4f);
		//glColor3f(0.02f, 0.15f, 0.03f);
		if (currentHour >= 0 && currentHour < 6 || currentHour >= 20 && currentHour < 24)
		{
			glColor3f(0.02f, 0.09f, 0.03f);
		}
		else if (currentHour >= 6 && currentHour < 9)
		{
			glColor3f(0.10f, 0.225f, 0.125f);
		}
		else
		{
			glColor3f(0.02f, 0.25f, 0.03f);
		}
		for (float _x = x; _x <= 1.0f; _x = _x + step)
		{
			glVertex3f(_x, y, z);
			glVertex3f(_x + (step / 2.0f), y + 0.4f, z);
			glVertex3f(_x + step, y, z);
		}
	}
	glEnd();
}

void drawFrontGrass(void)
{
	glBegin(GL_TRIANGLES);
	{
		float x;
		float y;
		float z;
		float step = 0.125f;
		// second set of grass
		x = -1.0f; y = -1.0f, z = 1.0;
		//glColor3f(0.3f, 0.6f, 0.1f);
		if (currentHour >= 0 && currentHour < 6 || currentHour >= 20 && currentHour < 24)
		{
			glColor3f(0.02f, 0.15f, 0.03f);
		}
		else if (currentHour >= 6 && currentHour < 9)
		{
			glColor3f(0.20f, 0.45f, 0.25f);
		}
		else
		{
			glColor3f(0.02f, 0.45f, 0.03f);
		}
		for (float _x = x + 0.05; _x <= 1.0f; _x = _x + step)
		{
			// straight blades
			glVertex3f(_x, y, z);
			if (_x <= 0.5)
			{
				glVertex3f(_x + (step / 2.0), y + 0.46, z);
			}
			else if (_x <= 0.7)
			{
				glVertex3f(_x + (step / 2.0), y + 0.53, z);
			}
			else
			{
				glVertex3f(_x + (step / 2.0), y + 0.38, z);
			}
			glVertex3f(_x + step, y, z);

			// crooked blades - 1
			glVertex3f(_x - 0.2, y, z);
			if (_x <= 0.5)
			{
				glVertex3f(_x - (step / 2.0), y + 0.33, z);
			}
			else if (_x <= 0.7)
			{
				glVertex3f(_x - (step / 2.0), y + 0.28, z);
			}
			else
			{
				glVertex3f(_x - (step / 2.0), y + 0.35, z);
			}
			glVertex3f(_x + step, y, z);

			// crooked blades - 2
			glVertex3f(_x, y, z);
			if (_x <= 0.5)
			{
				glVertex3f(_x - (step / 2.0), y - 0.33, z);
			}
			else if (_x <= 0.7)
			{
				glVertex3f(_x - (step / 2.0), y - 0.28, z);
			}
			else
			{
				glVertex3f(_x - (step / 2.0), y - 0.35, z);
			}
			glVertex3f(_x + step, y, z);
		}
	}
	glEnd();
}