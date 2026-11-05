// header files
#include <windows.h>    // must come before gl.h on Windows
#include <gl/GL.h>
#include <gl/GLU.h>
#include <stdio.h>
#include "CatmullRom.h"

// function declarations
void drawPlane(void);

// global variable declarations
extern float eyeX, eyeY, eyeZ;
extern float centerX, centerY, centerZ;
extern float upX, upY, upZ;

extern float testAngle;
extern GLUquadric *quadric;
extern FILE *gpFile;

CatmullRomPoints_t *pPlane1Path = NULL;
Point_t plane1Position = { -18.46f, 13.84f, 1.0f };
float plane1Angle = 0.0f;

CatmullRomPoints_t *pPlane2Path = NULL;
Point_t plane2Position = { -18.46f, -13.84f, 1.0f };
float plane2Angle = 0.0f;

CatmullRomPoints_t *pPlane3Path = NULL;
Point_t plane3Position = { -25.32f, 0.0f, 1.0f };
float plane3Angle = 0.0f;

void draw_plane(void)
{
	// function declarations
	void drawAllPlanes(void);

	// code
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(
		eyeX, eyeY, eyeZ,
		centerX, centerY, centerZ,
		upX, upY, upZ
	);

	glTranslatef(0.0f, 0.0f, -22.0f);

	drawAllPlanes();
}

// nose points along +Y, 1 unit = 1 m
void drawPlane(void)
{
	// function declarations
	void drawTriangularPyramid(void);

	// code
	glColor3f(0.6f, 0.62f, 0.65f);

	// nose
	glPushMatrix();
	{
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
		gluCylinder(
			quadric, // quadric
			0.8f, 	 // base radius
			0.0f, 	 // top radius
			3.0f, 	 // height
			10, 	 // slices
			10		 // stacks
		);
	}
	glPopMatrix();

	// body
	glPushMatrix();
	{
		glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
		gluCylinder(
			quadric, // quadric
			0.8f, 	 // base radius
			0.8f, 	 // top radius
			11.0f, 	 // height
			10, 	 // slices
			10		 // stacks
		);
	}
	glPopMatrix();

	// canopy
	glColor3f(0.12f, 0.2f, 0.32f);
	glPushMatrix();
	{
		glTranslatef(0.0f, -1.5f, 0.7f);
		glScalef(0.5f, 1.5f, 0.7f);
		gluSphere(
			quadric, // quadric
			1.0f, 	 // radius
			30, 	 // slices
			10		 // stacks
		);
	}
	glPopMatrix();
	glColor3f(0.6f, 0.62f, 0.65f);

	// left intake
	glPushMatrix();
	{
		glTranslatef(-1.1f, -2.7f, -0.3f);
		glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
		gluCylinder(
			quadric, // quadric
			0.4f, 	 // base radius
			0.4f, 	 // top radius
			2.3f, 	 // height
			10, 	 // slices
			10		 // stacks
		);
	}
	glPopMatrix();

	// right intake
	glPushMatrix();
	{
		glTranslatef(1.1f, -2.7f, -0.3f);
		glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
		gluCylinder(
			quadric, // quadric
			0.4f, 	 // base radius
			0.4f, 	 // top radius
			2.3f, 	 // height
			10, 	 // slices
			10		 // stacks
		);
	}
	glPopMatrix();

	// left canard
	glPushMatrix();
	{
		glTranslatef(-0.6f, -2.7f, 0.2f);
		glScalef(-1.6f, 1.2f, 0.1f);
		drawTriangularPyramid();
	}
	glPopMatrix();

	// right canard
	glPushMatrix();
	{
		glTranslatef(0.6f, -2.7f, 0.2f);
		glScalef(1.6f, 1.2f, 0.1f);
		drawTriangularPyramid();
	}
	glPopMatrix();

	// left wing
	glPushMatrix();
	{
		glTranslatef(-0.6f, -4.6f, -0.2f);
		glScalef(-4.85f, 6.4f, 0.3f);
		drawTriangularPyramid();
	}
	glPopMatrix();

	// right wing
	glPushMatrix();
	{
		glTranslatef(0.6f, -4.6f, -0.2f);
		glScalef(4.85f, 6.4f, 0.3f);
		drawTriangularPyramid();
	}
	glPopMatrix();

	// fin
	glPushMatrix();
	{
		glTranslatef(0.0f, -7.7f, 0.6f);
		glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
		glScalef(4.3f, 3.0f, 0.2f);
		drawTriangularPyramid();
	}
	glPopMatrix();

	// left engine
	glPushMatrix();
	{
		glTranslatef(-0.45f, -11.0f, 0.0f);
		glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
		gluCylinder(
			quadric, // quadric
			0.45f, 	 // base radius
			0.45f, 	 // top radius
			1.3f, 	 // height
			10, 	 // slices
			10		 // stacks
		);

		// exhaust
		glColor3f(0.1f, 0.1f, 0.1f);
		glTranslatef(0.0f, 0.0f, 1.3f);
		gluDisk(
			quadric, // quadric
			0.0f, 	 // inner radius
			0.45f, 	 // outer radius
			10, 	 // slices
			1		 // loops
		);
		glColor3f(0.6f, 0.62f, 0.65f);
	}
	glPopMatrix();

	// right engine
	glPushMatrix();
	{
		glTranslatef(0.45f, -11.0f, 0.0f);
		glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
		gluCylinder(
			quadric, // quadric
			0.45f, 	 // base radius
			0.45f, 	 // top radius
			1.3f, 	 // height
			10, 	 // slices
			10		 // stacks
		);

		// exhaust
		glColor3f(0.1f, 0.1f, 0.1f);
		glTranslatef(0.0f, 0.0f, 1.3f);
		gluDisk(
			quadric, // quadric
			0.0f, 	 // inner radius
			0.45f, 	 // outer radius
			10, 	 // slices
			1		 // loops
		);
		glColor3f(0.6f, 0.62f, 0.65f);
	}
	glPopMatrix();
}

void drawTriangularPyramid(void)
{
	// code
	glBegin(GL_TRIANGLES);
	{
		// bottom
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, -1.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, 0.0f);

		// triangle face 1
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, -1.0f, 0.0f);
		glVertex3f(0.333f, -0.667f, 1.0f);

		// triangle face 2
		glVertex3f(0.0f, -1.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, 0.0f);
		glVertex3f(0.333f, -0.667f, 1.0f);

		// triangle face 3
		glVertex3f(1.0f, -1.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.333f, -0.667f, 1.0f);
	}
	glEnd();
}

int initializePlanes(void)
{
	// variable declarations
	const char *logFn = "initializePlanes()";
	int iStatus;
	// plane 1
	Point_t plane1Guide1 = { -18.94f, 15.34f, 1.0f };
	Point_t plane1Guide2 = { 18.94f, 15.34f, 1.0f };
	Point_t plane1Waypoints[7] = {
		{ -18.46f, 13.84f, 1.0f },
		{ -16.29f, 7.94f, 1.0f },
		{ -9.43f, 2.2f, 1.0f },
		{ 0.0f, 2.2f, 1.0f },
		{ 9.43f, 2.2f, 1.0f },
		{ 16.29f, 7.94f, 1.0f },
		{ 18.46f, 13.84f, 1.0f }
	};

	// plane 2
	Point_t plane2Guide1 = { -18.94f, -15.34f, 1.0f };
	Point_t plane2Guide2 = { 18.94f, -15.34f, 1.0f };
	Point_t plane2Waypoints[7] = {
		{ -18.46f, -13.84f, 1.0f },
		{ -16.29f, -7.94f, 1.0f },
		{ -9.43f, -2.2f, 1.0f },
		{ 0.0f, -2.2f, 1.0f },
		{ 9.43f, -2.2f, 1.0f },
		{ 16.29f, -7.94f, 1.0f },
		{ 18.46f, -13.84f, 1.0f }
	};

	// plane 3
	Point_t plane3Guide1 = { -34.35f, 0.0f, 1.0f };
	Point_t plane3Guide2 = { 34.35f, 0.0f, 1.0f };
	Point_t plane3Waypoints[7] = {
		{ -25.32f, 0.0f, 1.0f },
		{ -16.29f, 0.0f, 1.0f },
		{ -9.43f, 0.0f, 1.0f },
		{ 0.0f, 0.0f, 1.0f },
		{ 9.43f, 0.0f, 1.0f },
		{ 16.29f, 0.0f, 1.0f },
		{ 25.32f, 0.0f, 1.0f }
	};

	// code
	// plane1
	pPlane1Path = newCatmullRomPointsObject();
	if(pPlane1Path == NULL)
	{
		fprintf(gpFile, "%s:[%s, %d] Failed to create plane 1 path, check!\n", logFn, __FILE__, __LINE__);
		return -1;
	}

	iStatus = setupWaypoints(&pPlane1Path, plane1Waypoints, 7, &plane1Guide1, &plane1Guide2);
	if(iStatus != 0)
	{
		fprintf(gpFile, "%s:[%s, %d] Failed to setup plane 1 waypoints (%d), check!\n", logFn, __FILE__, __LINE__, iStatus);
		destroyCatmullRomPointsObject(&pPlane1Path);
		return -2;
	}
	
	// plane2
	pPlane2Path = newCatmullRomPointsObject();
	if(pPlane2Path == NULL)
	{
		fprintf(gpFile, "%s:[%s, %d] Failed to create plane 2 path, check!\n", logFn, __FILE__, __LINE__);
		destroyCatmullRomPointsObject(&pPlane1Path);
		return -1;
	}

	iStatus = setupWaypoints(&pPlane2Path, plane2Waypoints, 7, &plane2Guide1, &plane2Guide2);
	if(iStatus != 0)
	{
		fprintf(gpFile, "%s:[%s, %d] Failed to setup plane 2 waypoints (%d), check!\n", logFn, __FILE__, __LINE__, iStatus);
		destroyCatmullRomPointsObject(&pPlane1Path);
		destroyCatmullRomPointsObject(&pPlane2Path);
		return -2;
	}

	// plane3
	pPlane3Path = newCatmullRomPointsObject();
	if(pPlane3Path == NULL)
	{
		fprintf(gpFile, "%s:[%s, %d] Failed to create plane 3 path, check!\n", logFn, __FILE__, __LINE__);
		destroyCatmullRomPointsObject(&pPlane1Path);
		destroyCatmullRomPointsObject(&pPlane2Path);
		return -1;
	}

	iStatus = setupWaypoints(&pPlane3Path, plane3Waypoints, 7, &plane3Guide1, &plane3Guide2);
	if(iStatus != 0)
	{
		fprintf(gpFile, "%s:[%s, %d] Failed to setup plane 3 waypoints (%d), check!\n", logFn, __FILE__, __LINE__, iStatus);
		destroyCatmullRomPointsObject(&pPlane1Path);
		destroyCatmullRomPointsObject(&pPlane2Path);
		destroyCatmullRomPointsObject(&pPlane3Path);
		return -2;
	}

	return 0;
}

void updatePlanes(void)
{
	// code
	// plane 1
	if(moveAlongPiece(&pPlane1Path, &plane1Position) >= 0)
	{
		plane1Angle = getHeadingAngle(&pPlane1Path->lastPosition, &plane1Position, plane1Angle);
	}

	// plane 2
	if(moveAlongPiece(&pPlane2Path, &plane2Position) >= 0)
	{
		plane2Angle = getHeadingAngle(&pPlane2Path->lastPosition, &plane2Position, plane2Angle);
	}

	// plane 3
	if(moveAlongPiece(&pPlane3Path, &plane3Position) >= 0)
	{
		plane3Angle = getHeadingAngle(&pPlane3Path->lastPosition, &plane3Position, plane3Angle);
	}
}

void drawAllPlanes(void)
{
	// code
	// plane 2
	glPushMatrix();
	{
		glTranslatef(plane1Position.x, plane1Position.y, plane1Position.z);
		glRotatef(plane1Angle, 0.0f, 0.0f, 1.0f);
		glScalef(0.08f, 0.08f, 0.08f);
		drawPlane();
	}
	glPopMatrix();

	// plane 2
	glPushMatrix();
	{
		glTranslatef(plane2Position.x, plane2Position.y, plane2Position.z);
		glRotatef(plane2Angle, 0.0f, 0.0f, 1.0f);
		glScalef(0.08f, 0.08f, 0.08f);
		drawPlane();
	}
	glPopMatrix();

	// plane 3
	glPushMatrix();
	{
		glTranslatef(plane3Position.x, plane3Position.y, plane3Position.z);
		glRotatef(plane3Angle, 0.0f, 0.0f, 1.0f);
		glScalef(0.08f, 0.08f, 0.08f);
		drawPlane();
	}
	glPopMatrix();
}

void uninitializePlanes(void)
{
	// variable declarations
	const char *logFn = "uninitializePlanes()";

	// code
	fprintf(gpFile, "%s: destroying plane 1\n", logFn);
	destroyCatmullRomPointsObject(&pPlane1Path);
	fprintf(gpFile, "%s: destroying plane 2\n", logFn);
	destroyCatmullRomPointsObject(&pPlane2Path);
	fprintf(gpFile, "%s: destroying plane 3\n", logFn);
	destroyCatmullRomPointsObject(&pPlane3Path);
}
