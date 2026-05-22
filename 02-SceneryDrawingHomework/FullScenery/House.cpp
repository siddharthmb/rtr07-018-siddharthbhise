#include "House.h"
#include <GL/freeglut.h>

void drawHouse(void)
{
	glBegin(GL_TRIANGLES);
	{
		float x, y, z;
		// first outer triangle in brown
		x = 0.2f; y = -0.2f; z = 0.0f;
		glColor3f(0.4f, 0.2f, 0.0f);
		glVertex3f(x, y, z);
		x = 0.1f; y = -0.35f;
		glVertex3f(x, y, z);
		x = 0.3f; y = -0.4f;
		glVertex3f(x, y, z);

		// main entrance wall
		// bottom triangle
		z = 0.0f;
		glVertex3f(x, y, z);
		y = -0.8f;
		glVertex3f(x, y, z);
		x = 0.9f;
		glVertex3f(x, y, z);

		// upper triangle
		glVertex3f(x, y, z);
		y = -0.4f;
		glVertex3f(x, y, z);
		x = 0.3f;
		glVertex3f(x, y, z);


		// windows of the house
		// above triangle's inner triangle window
		x = 0.2f; y = -0.24f; z = -0.75f;
		glColor3f(0.2f, 0.2f, 0.2f);
		glVertex3f(x, y, z);
		x = 0.14f; y = -0.33f;
		glColor3f(0.1f, 0.1f, 0.2f);
		glVertex3f(x, y, z);
		x = 0.25f; y = -0.36f;
		glVertex3f(x, y, z);


		// barn side
		// left triangle
		glColor3f(0.4f, 0.1f, 0.0f);
		x = 0.1f; y = -0.35f; z = 0.0f;
		glVertex3f(x, y, z);
		y = -0.75f;
		glVertex3f(x, y, z);
		x = 0.3f; y = -0.8f;
		glVertex3f(x, y, z);

		// right triangle
		glVertex3f(x, y, z);
		y = -0.4f;
		glVertex3f(x, y, z);
		x = 0.1f; y = -0.35f;
		glVertex3f(x, y, z);


		// main entrance rectangular window
		// upper triangle
		glColor3f(0.1f, 0.1f, 0.2f);
		x = 0.32f; y = -0.42f; z = 0.0f;
		glVertex3f(x, y, z);
		x = 0.88f;
		glColor3f(0.2f, 0.2f, 0.2f);
		glVertex3f(x, y, z);
		x = 0.32f; y = -0.58f;
		glVertex3f(x, y, z);

		// bottom triangle
		glVertex3f(x, y, z);
		x = 0.88f;
		glVertex3f(x, y, z);
		y = -0.42f;
		glColor3f(0.1f, 0.1f, 0.2f);
		glVertex3f(x, y, z);


		// roof
		// upper triangle
		glColor3f(0.4f, 0.1f, 0.0f);
		x = 0.2f; y = -0.2f; z = -0.25f;
		glVertex3f(x, y, z);
		x = 0.3f; y = -0.4f;
		glVertex3f(x, y, z);
		x = 0.8f; y = -0.2f;
		glVertex3f(x, y, z);

		// bottom triangle
		glVertex3f(x, y, z);
		x = 0.3f; y = -0.4f;
		glVertex3f(x, y, z);
		x = 0.9f;
		glVertex3f(x, y, z);
	}
	glEnd();
}