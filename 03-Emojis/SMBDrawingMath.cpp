#include "SMBDrawingMath.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

// LERP function (float)
// lerp logic to transit from eve to night
float lerp(float val, float endVal, float t)
{
	val = val + (endVal - val) * t;
	return val;
}


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
			float theta = i * M_PI; // 0 to 2*M_PI

			float x = r * cos(theta);
			float y = r * sin(theta);

			glVertex3f(x + h, y + v, z);
		}
	}
	glEnd();
}

void drawQuadWithXYCoordinates(float h, float v, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, float scaleFactor)
{
	float scale = (scaleFactor / 100.0f);
	float z = 0.0f;

	glBegin(GL_QUADS);
	{
		glVertex3f((x1 + h) * scale, (y1 + v) * scale, z);
		glVertex3f((x2 + h) * scale, (y2 + v) * scale, z);
		glVertex3f((x3 + h) * scale, (y3 + v) * scale, z);
		glVertex3f((x4 + h) * scale, (y4 + v) * scale, z);
	}
	glEnd();
}

void drawVerticalQuad(float x1, float x2, float yStart, float z, float width)		// very bad function, will improve and become more generic later
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

void drawQuad1(float h, float v, float width, float height, float scaleFactor)		// this is a much better version (not battle tested though)
{
	glBegin(GL_QUADS);
	{
		float x1, x2, y1, y2;
		float distributionX = width / 2.0f;
		float distributionY = height / 2.0f;
		// x1, y1

		x1 = 0.0f - distributionX;
		y1 = 0.0f - distributionY;

		// x2, y2
		x2 = 0.0f + distributionX;
		y2 = 0.0f + distributionY;

		printf("x1 = %0.2f, y1 = %0.2f\n", x1, y1);
		printf("x2 = %0.2f, y1 = %0.2f\n", x2, y1);
		printf("x2 = %0.2f, y2 = %0.2f\n", x2, y2);
		printf("x1 = %0.2f, y2 = %0.2f\n\n", x1, y2);

		glVertex2f(x1 * (scaleFactor / 100.0f) + h, y1 * (scaleFactor / 100.0f) + v);
		glVertex2f(x2 * (scaleFactor / 100.0f) + h, y1 * (scaleFactor / 100.0f) + v);
		glVertex2f(x2 * (scaleFactor / 100.0f) + h, y2 * (scaleFactor / 100.0f) + v);
		glVertex2f(x1 * (scaleFactor / 100.0f) + h, y2 * (scaleFactor / 100.0f) + v);
	}
	glEnd();
}

void drawQuad2(float h, float v, float width, float height, float scaleFactor)		// this is a much better version (not battle tested though)
{
	glBegin(GL_QUADS);
	{
		float x1, x2, y1, y2;
		float distributionX = width / 2.0f;
		float distributionY = height / 2.0f;
		// x1, y1
		
		x1 = 0.0f - distributionX + h;
		y1 = 0.0f - distributionY + v;

		// x2, y2
		x2 = 0.0f + distributionX + h;
		y2 = 0.0f + distributionY + v;

		printf("x1 = %0.2f, y1 = %0.2f\n", x1, y1);
		printf("x2 = %0.2f, y1 = %0.2f\n", x2, y1);
		printf("x2 = %0.2f, y2 = %0.2f\n", x2, y2);
		printf("x1 = %0.2f, y2 = %0.2f\n\n", x1, y2);

		glVertex2f(x1 * (scaleFactor / 100.0f), y1 * (scaleFactor / 100.0f));
		glVertex2f(x2 * (scaleFactor / 100.0f), y1 * (scaleFactor / 100.0f));
		glVertex2f(x2 * (scaleFactor / 100.0f), y2 * (scaleFactor / 100.0f));
		glVertex2f(x1 * (scaleFactor / 100.0f), y2 * (scaleFactor / 100.0f));
	}
	glEnd();
}

void drawCircleWithScale(float a, float b, float h, float v, float startAngle, float endAngle, float scaleFactor, GLenum mode)
{
	glBegin(mode);
	{
		float x1, y1;
		for (float t = startAngle; t <= endAngle; t = t + 0.01f)
		{
			x1 = a * cos(t);
			y1 = b * sin(t);
			glVertex2f(( -x1 * scaleFactor / 100.0f) + h, (-y1 * scaleFactor / 100.0f) + v);
		}
	}
	glEnd();
}

// helps to draw circle or semi or arc kind
void drawLinedEllipseWithScale(float a, float b, float h, float v, float startAngle, float endAngle, float scaleFactor)
{
	glBegin(GL_LINE_STRIP);
	{
		float x1, y1;
		float x2, y2;
		for (float t = 0.0f; t < M_PI; t = t + 0.01f)
		{
			x1 = a  * sin(t) + h;
			y1 = b  * cos(t) + v + 0.01f;
			x2 = -a * sin(t) + h;
			y2 = -b * cos(t) + v + 0.01f;
			glVertex2f(x1 * (scaleFactor + 0.9f) / 100.0f, y1 * (scaleFactor + 0.9f) / 100.0f);
			glVertex2f(x2 * (scaleFactor + 0.9f) / 100.0f, y2 * (scaleFactor + 0.9f) / 100.0f);
		}
	}
	glEnd();
}

void drawPolygonalEllipseWithScale(float a, float b, float h, float v, float startAngle, float endAngle, float scaleFactor)
{
	glBegin(GL_POLYGON);
	{
		float x1, y1;
		float x2, y2;
		for (float t = 0.0f; t < M_PI; t = t + 0.01f)
		{
			x1 = a  * sin(t) + h;
			y1 = b  * cos(t) + v;
			x2 = -a * sin(t) + h;
			y2 = -b * cos(t) + v;
			glVertex2f(x1 * scaleFactor / 100.0f, y1 * scaleFactor / 100.0f);
			glVertex2f(x2 * scaleFactor / 100.0f, y2 * scaleFactor / 100.0f);
		}
	}
	glEnd();
}

void drawEllipse(float a, float b, float h, float v, float scaleFactor)
{
	glBegin(GL_LINE_STRIP);
	{
		float x1, x2, y1, y2;
		for (float t = 0.0f; t < M_PI; t = t + 0.01f)
		{
			x1 = a  * sin(t) + h;
			y1 = b  * cos(t) + v;
			x2 = -a * sin(t) + h;
			y2 = -b * cos(t) + v;
			glVertex2f(x1 + h, (y1 * scaleFactor / 100.0f) + v);
			glVertex2f(x2 + h, (y2 * scaleFactor / 100.0f) + v);
		}
	}
	glEnd();
}

void drawEllipseWithMode(float a, float b, float h, float v, float startAngle, float endAngle, float scaleFactor, GLenum mode)
{
	glBegin(mode);
	{
		float x1, y1;
		float x2, y2;
		for (float t = 0.0f; t < M_PI; t = t + 0.01f)
		{
			x1 = a * sin(t) + h;
			y1 = b * cos(t) + v;// +0.01f;
			x2 = -a * sin(t) + h;
			y2 = -b * cos(t) + v;// +0.01f;
			glVertex2f(x1 * scaleFactor / 100.0f, y1 * scaleFactor / 100.0f);
			glVertex2f(x2 * scaleFactor / 100.0f, y2 * scaleFactor / 100.0f);
		}
	}
	glEnd();
}
