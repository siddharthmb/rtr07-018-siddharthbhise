#include "Stars.h"
#include <GL/freeglut.h>
#include <stdlib.h>

extern unsigned int currentHour;

void drawStars(void)
{
	if ((currentHour >= 18 && currentHour < 24) || (currentHour >=0 && currentHour < 6))
	{
		glBegin(GL_POINTS);
		{
			for (float x = -1.05f; x < 1.05f; x = x + 0.05f)
			{
				int r = rand() % 10;
				if (r % 3 == 0 || r % 7 == 0)
				{
					glColor3f(0.5f, 0.5f, 0.5f);
				}
				else
				{
					glColor3f(1.0f, 1.0f, 1.0f);
				}
				float y = (float)r / 10.0f;
				glVertex3f(x, y, 0.0f);
			}
		}
		glEnd();
	}
}