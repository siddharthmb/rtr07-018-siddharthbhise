#ifndef _SMB_DRAWING_H
#define _SMB_DRAWING_H

void renderSineWave(
	float xStart, 
	float xEnd, 
	float xStep, 
	float a, 
	float f, 
	float 
	y1_displacement, 
	float y2_displacement, float z);

void drawCircle(float h, float v, float r);

void drawVerticalQuad(float x1, float x2, float yStart, float z, float width);

#endif
