#ifndef _SMB_DRAWING_H
#define _SMB_DRAWING_H

#include <GL/freeglut.h>

// lerp function float
float lerp(float val, float endVal, float t);

void renderSineWave(
	float xStart, 
	float xEnd, 
	float xStep, 
	float a, 
	float f, 
	float 
	y1_displacement, 
	float y2_displacement, float z);

// Circle
void drawCircle(float h, float v, float r);
void drawCircleWithScale(float a, float b, float h, float v, float startAngle, float endAngle, float scaleFactor, GLenum mode);

// Quad
void drawVerticalQuad(float x1, float x2, float yStart, float z, float width);
void drawQuad1(float h, float v, float width, float height, float scaleFactor);
void drawQuad2(float h, float v, float width, float height, float scaleFactor);
void drawQuadWithXYCoordinates(float h, float v, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, float scaleFactor);

// Ellipse
void drawPolygonalEllipseWithScale(float a, float b, float h, float v, float startAngle, float endAngle, float scaleFactor);
void drawLinedEllipseWithScale(float a, float b, float h, float v, float startAngle, float endAngle, float scaleFactor);
void drawEllipseWithMode(float a, float b, float h, float v, float startAngle, float endAngle, float scaleFactor, GLenum mode);
void drawEllipse(float a, float b, float h, float v, float scaleFactor);
#endif
