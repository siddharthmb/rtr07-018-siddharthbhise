#include "WildTree.h"
#include "SMBDrawingMath.h"
#include <stdlib.h>
#include <GL/freeglut.h>

void drawTree(float hOrig, float vOrig, float rOrig)
{
	glColor3f(0.30f, 0.20f, 0.15);
	float x1, x2, y, z = 0.0f;
	float width = rOrig / 2.0f;
	x1 = hOrig + rOrig;
	x2 = x1 + width;
	y = vOrig + rOrig;
	drawVerticalQuad(x1, x2, y, z, width);

	glColor3f(0.02f, 0.15f, 0.03f);
	float h, v, r;
	h = hOrig;
	v = vOrig;
	r = rOrig;
	drawCircle(h, v, r);
	h = h + 0.1f;
	v = v + r;
	r = r + 0.5f * r;
	drawCircle(h, v, r);
	h = h + 0.1f;
	v = vOrig;
	r = rOrig;
	drawCircle(h, v, r);
}

void drawNTrees(const int n)
{
	float h, v, r;
	h = -1.0f;
	v = 0.2f;
	r = 0.08f;
	float spacing = 0;
	for (int i = 0; i < n; ++i)
	{
		drawTree(h, v, r);
		v = (rand() % 4) / 10.0f;
		spacing = ((rand() % 5) + 2) / 10.0f;
		h = h + spacing;
	}
}
