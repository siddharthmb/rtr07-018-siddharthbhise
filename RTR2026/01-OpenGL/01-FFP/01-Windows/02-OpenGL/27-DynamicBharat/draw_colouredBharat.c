// header files
#include <stdio.h>
#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
// our custom headers
#include "SceneEnumerations.h"

// macros
#define lerp(a, b, t) (a + (b - a) * t)

// struct for colours
typedef struct _colourStructForStructures
{
	float r1, g1, b1, a1;
	float r2, g2, b2, a2;
	float r3, g3, b3, a3;

} HVCOLOURSTRUCT;

// function declarations
void drawVerticalStructure(HVCOLOURSTRUCT *);
void drawHorizontalStructure(HVCOLOURSTRUCT *);
void drawB(void);
void drawH(void);
void drawA(void);
void drawR(void);
void drawA_II(void);
void drawT(void);
// full BHARAT rendering
void drawBHARAT(void);
// scene specific lerping functions
void lerpLettersT(void);
void scene2Resets(void);
// resetting letterT
void resetLetterT(void);

// global variable declarations
float eyeX = 0.0f, eyeY = 0.0f, eyeZ = 2.0f;
float centerX = 0.0f, centerY = 0.0f, centerZ = 0.0f;
float upX = 0.0f, upY = 1.0f, upZ = 0.0f;

extern float testAngle;
extern Scene_t currentScene;
extern FILE *gpFile;
extern float seconds;

// this shall be used to get the index of the alphabet that needs lerping
int lerpingAlphabetIndex = 0;

// start colour: grey, all 0.5f
HVCOLOURSTRUCT csGrey = {
	0.5f, 0.5f, 0.5f, 1.0f,
	0.5f, 0.5f, 0.5f, 1.0f,
	0.5f, 0.5f, 0.5f, 1.0f
};

// end colour: Tiranga (your commented-out struct)
HVCOLOURSTRUCT csTiranga = {
	1.0f, 0.467f, 0.133f, 1.0f,
	1.0f, 1.0f, 1.0f, 1.0f,
	0.0f, 0.416f, 0.306f, 1.0f
};

// one t per letter: B H A R A T (0 = grey, 1 = Tiranga)
float letterT[6] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };

void resetLetterT(void)
{
	// code
	// memset(letterT, 0.0f, sizeof(float) * 6);
	for(int i = 0; i < 6; ++i)
	{
		letterT[i] = 0.0f;
	}
}

void lerpLettersT(void)
{
	// function declarations
	int getLerpingAlphabetIndex(void);

	// variable declarations
	int i;
	float tStep = 0.01f;

	// code
	if(currentScene == SCENE_2)
	{
		if(seconds < 17.87f) return;	// SMBNOTE: This value comes from experimenting... 
		tStep = 0.0048f;
	}

	// update lerp variables in letterT
	// find correct value of lerping variable
	i = getLerpingAlphabetIndex();
	if(i != -1)
	{
		letterT[i] = letterT[i] + tStep;
		if(letterT[i] > 1.0f) letterT[i] = 1.0f;
	}
}

int getLerpingAlphabetIndex(void)
{
	// code
	if(lerpingAlphabetIndex >= 6) return -1;

	while(1)
	{
		if(letterT[lerpingAlphabetIndex] < 1.0f) return lerpingAlphabetIndex;
		++lerpingAlphabetIndex;
		if(lerpingAlphabetIndex >= 6) break;
	}

	return -1;
}

void scene2Resets(void)
{
	// variable declarations
	static BOOL bNeedUpdateLetterTArray = TRUE;
	static BOOL bNeedUpdateLerpingAlphabetIndex = TRUE;

	// code
	if(bNeedUpdateLetterTArray)
	{
		resetLetterT();
		bNeedUpdateLetterTArray = FALSE;
	}
	if(bNeedUpdateLerpingAlphabetIndex)
	{
		lerpingAlphabetIndex = 0;
		bNeedUpdateLerpingAlphabetIndex = FALSE;
	}
}


// this function is getting called from render(), may re-organize later if the need is felt...
void draw_bharat(void)
{
	// function / function_pointer declarations
	void (*pFnLerp)(void) = NULL;	// was used, currently no in use. SMB NOTE: Remove later...
    // code
	gluLookAt(
		eyeX, eyeY, eyeZ,
		centerX, centerY, centerZ,
		upX, upY, upZ
	);

	if(currentScene == SCENE_1)
	{
		// nothing to reset
	}
	else if(currentScene == SCENE_2)
	{
		scene2Resets();
	}
	else
	{
		// no action
	}

	// drawB
	glTranslatef(0.0f, 1.32f, -22.0f);
	// glTranslatef(0.0f, 0.0f, -5.0f);
	glScalef(2.0f, 2.0f, 2.0f);
	// glRotatef(testAngle, 0.0f, 1.0f, 0.0f);

	drawBHARAT();

	// lerping based on scene
	lerpLettersT();
}

void drawBHARAT(void)
{
	// code
	glPushMatrix();
	{
		if(currentScene == SCENE_1)
		{
			glTranslatef(
				lerp(-11.0f, -7.73f, letterT[0]),
				0.0f,
				0.0f
			);
		}
		else
		{
			glTranslatef(-7.73f, 0.0f, 0.0f);
		}
		drawB();
	}
	glPopMatrix();

	glPushMatrix();
	{
		if(currentScene == SCENE_1)
		{
			glTranslatef(
				lerp(-11.0f, -4.92f, letterT[1]),
				lerp(7.0f, 0.0f, letterT[1]),
				0.0f
			);
		}
		else
		{
			glTranslatef(-4.92f, 0.0f, 0.0f);
		}
		drawH();
	}
	glPopMatrix();
	glPushMatrix();
	{
		if(currentScene == SCENE_1)
		{
			glTranslatef(
				lerp(-11.0f, -1.96f, letterT[2]),
				lerp(-7.0f, 0.0f, letterT[2]),
				0.0f
			);
		}
		else
		{
			glTranslatef(-1.96f, 0.0f, 0.0f);
		}
		drawA();
	}
	glPopMatrix();
	glPushMatrix();
	{
		if(currentScene == SCENE_1)
		{
			glTranslatef(
				lerp(11.0f, 1.00f, letterT[3]),
				lerp(7.0f, 0.0f, letterT[3]),
				0.0f
			);
		}
		else
		{
			glTranslatef(1.00f, 0.0f, 0.0f);
		}
		drawR();
	}
	glPopMatrix();
	glPushMatrix();
	{
		if(currentScene == SCENE_1)
		{
			glTranslatef(
				lerp(11.0f, 3.81f, letterT[4]),
				lerp(-7.0f, 0.0f, letterT[4]),
				0.0f
			);
		}
		else
		{
			glTranslatef(3.81f, 0.0f, 0.0f);
		}
		drawA_II();
	}
	glPopMatrix();

	glPushMatrix();
	{
		if(currentScene == SCENE_1)
		{
			glTranslatef(
				lerp(11.0f, 7.25f, letterT[5]),
				0.0f,
				0.0f
			);
		}
		else
		{
			glTranslatef(7.25f, 0.0f, 0.0f);
		}
		drawT();
	}
	glPopMatrix();
}

void drawT(void)
{
	// variable declarations
	HVCOLOURSTRUCT csLetter = csGrey;
	HVCOLOURSTRUCT csGreyToSaffron = csGrey;

	// code
	if(currentScene == SCENE_1)
	{
	}
	else if(currentScene == SCENE_2)
	{
		csLetter.r1 = lerp(csGrey.r1, csTiranga.r1, letterT[5]);
		csLetter.g1 = lerp(csGrey.g1, csTiranga.g1, letterT[5]);
		csLetter.b1 = lerp(csGrey.b1, csTiranga.b1, letterT[5]);
		csLetter.a1 = 1.0f;

		csLetter.r2 = lerp(csGrey.r2, csTiranga.r2, letterT[5]);
		csLetter.g2 = lerp(csGrey.g2, csTiranga.g2, letterT[5]);
		csLetter.b2 = lerp(csGrey.b2, csTiranga.b2, letterT[5]);
		csLetter.a2 = 1.0f;

		csLetter.r3 = lerp(csGrey.r3, csTiranga.r3, letterT[5]);
		csLetter.g3 = lerp(csGrey.g3, csTiranga.g3, letterT[5]);
		csLetter.b3 = lerp(csGrey.b3, csTiranga.b3, letterT[5]);
		csLetter.a3 = 1.0f;
	}
	else
	{
		// no action
	}

	drawVerticalStructure(&csLetter);

	if(currentScene == SCENE_1)
	{
	}
	else if(currentScene == SCENE_2)
	{
		csGreyToSaffron.r1 = lerp(csGrey.r1, csTiranga.r1, letterT[5]);
		csGreyToSaffron.g1 = lerp(csGrey.g1, csTiranga.g1, letterT[5]);
		csGreyToSaffron.b1 = lerp(csGrey.b1, csTiranga.b1, letterT[5]);
		csGreyToSaffron.a1 = 1.0f; //lerp(csGrey.r1, csTiranga.r1, letterT[5]);

		csGreyToSaffron.r2 = csGreyToSaffron.r1;
		csGreyToSaffron.g2 = csGreyToSaffron.g1;
		csGreyToSaffron.b2 = csGreyToSaffron.b1;
		csGreyToSaffron.a2 = csGreyToSaffron.a1;

		csGreyToSaffron.r3 = csGreyToSaffron.r1;
		csGreyToSaffron.g3 = csGreyToSaffron.g1;
		csGreyToSaffron.b3 = csGreyToSaffron.b1;
		csGreyToSaffron.a3 = csGreyToSaffron.a1;
	}
	else
	{
		// no action
	}

	glScalef(0.5f, 1.0f, 1.0f);
	glPushMatrix();
	{
		glTranslatef(-0.78f, 0.282f, 0.0f);
		drawHorizontalStructure(&csGreyToSaffron);
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(0.78f, 0.282f, 0.0f);
		drawHorizontalStructure(&csGreyToSaffron);
	}
	glPopMatrix();
}

void drawR(void)
{
	// variable declarations
	HVCOLOURSTRUCT csLetter = csGrey;
	HVCOLOURSTRUCT csGreyToWhite = csGrey;
	HVCOLOURSTRUCT csGreyToSaffron = csGrey;
	HVCOLOURSTRUCT csGreyToGreen = csGrey;
	HVCOLOURSTRUCT csVerticalWhiteGreen = csGrey;
	HVCOLOURSTRUCT csVerticalSaffronWhite = csGrey;

	// code
	if(currentScene == SCENE_1)
	{
	}
	else if(currentScene == SCENE_2)
	{
		csLetter.r1 = lerp(csGrey.r1, csTiranga.r1, letterT[3]);
		csLetter.g1 = lerp(csGrey.g1, csTiranga.g1, letterT[3]);
		csLetter.b1 = lerp(csGrey.b1, csTiranga.b1, letterT[3]);
		csLetter.a1 = 1.0f;

		csLetter.r2 = lerp(csGrey.r2, csTiranga.r2, letterT[3]);
		csLetter.g2 = lerp(csGrey.g2, csTiranga.g2, letterT[3]);
		csLetter.b2 = lerp(csGrey.b2, csTiranga.b2, letterT[3]);
		csLetter.a2 = 1.0f;

		csLetter.r3 = lerp(csGrey.r3, csTiranga.r3, letterT[3]);
		csLetter.g3 = lerp(csGrey.g3, csTiranga.g3, letterT[3]);
		csLetter.b3 = lerp(csGrey.b3, csTiranga.b3, letterT[3]);
		csLetter.a3 = 1.0f;
	}
	else
	{
		// no action
	}

	drawVerticalStructure(&csLetter);

	glTranslatef(0.63f, 0.282f, 0.0f);
	if(currentScene == SCENE_1)
	{
	}
	else if(currentScene == SCENE_2)
	{
		csGreyToSaffron.r1 = lerp(csGrey.r1, csTiranga.r1, letterT[3]);
		csGreyToSaffron.g1 = lerp(csGrey.r1, csTiranga.g1, letterT[3]);
		csGreyToSaffron.b1 = lerp(csGrey.r1, csTiranga.b1, letterT[3]);
		csGreyToSaffron.a1 = 1.0f;

		csGreyToSaffron.r2 = lerp(csGrey.r1, csTiranga.r1, letterT[3]);
		csGreyToSaffron.g2 = lerp(csGrey.r1, csTiranga.g1, letterT[3]);
		csGreyToSaffron.b2 = lerp(csGrey.r1, csTiranga.b1, letterT[3]);
		csGreyToSaffron.a2 = 1.0f;

		csGreyToSaffron.r3 = lerp(csGrey.r1, csTiranga.r1, letterT[3]);
		csGreyToSaffron.g3 = lerp(csGrey.r1, csTiranga.g1, letterT[3]);
		csGreyToSaffron.b3 = lerp(csGrey.r1, csTiranga.b1, letterT[3]);
		csGreyToSaffron.a3 = 1.0f;
	}
	else
	{
		// no action
	}
	drawHorizontalStructure(&csGreyToSaffron);

	if(currentScene == SCENE_1)
	{
	}
	else if(currentScene == SCENE_2)
	{
		csGreyToWhite.r1 = lerp(csGrey.r1, csTiranga.r2, letterT[3]);
		csGreyToWhite.g1 = lerp(csGrey.g1, csTiranga.g2, letterT[3]);
		csGreyToWhite.b1 = lerp(csGrey.r1, csTiranga.b2, letterT[3]);
		csGreyToWhite.a1 = 1.0f;

		csGreyToWhite.r2 = lerp(csGrey.r1, csTiranga.r2, letterT[3]);
		csGreyToWhite.g2 = lerp(csGrey.g1, csTiranga.g2, letterT[3]);
		csGreyToWhite.b2 = lerp(csGrey.b1, csTiranga.b2, letterT[3]);
		csGreyToWhite.a2 = 1.0f;

		csGreyToWhite.r3 = lerp(csGrey.r1, csTiranga.r2, letterT[3]);
		csGreyToWhite.g3 = lerp(csGrey.g1, csTiranga.g2, letterT[3]);
		csGreyToWhite.b3 = lerp(csGrey.b1, csTiranga.b2, letterT[3]);
		csGreyToWhite.a3 = 1.0f;
	}
	else
	{
		// no action
	}

	glTranslatef(0.0f, -0.846f, 0.0f);
	drawHorizontalStructure(&csGreyToWhite);

	if(currentScene == SCENE_1)
	{
	}
	else if(currentScene == SCENE_2)
	{
		csGreyToGreen.r1 = lerp(csGrey.r1, csTiranga.r3, letterT[3]);
		csGreyToGreen.g1 = lerp(csGrey.r1, csTiranga.g3, letterT[3]);
		csGreyToGreen.b1 = lerp(csGrey.r1, csTiranga.b3, letterT[3]);
		csGreyToGreen.a1 = 1.0f;
	}
	else
	{
		// no action
	}

	glTranslatef(0.0f, -0.846f, 0.0f);
	glScalef(0.5f, 0.4f, 1.0f);
	glTranslatef(1.11f, 1.38f, 0.0f);
	glPushMatrix();
	{
		if(currentScene == SCENE_1)
		{
		}
		else if(currentScene == SCENE_2)
		{
			csVerticalWhiteGreen.r1 = csGreyToWhite.r1;
			csVerticalWhiteGreen.g1 = csGreyToWhite.g1;
			csVerticalWhiteGreen.b1 = csGreyToWhite.b1;
			csVerticalWhiteGreen.a1 = 1.0f;

			csVerticalWhiteGreen.r2 = csGreyToGreen.r1;
			csVerticalWhiteGreen.g2 = csGreyToGreen.g1;
			csVerticalWhiteGreen.b2 = csGreyToGreen.b1;
			csVerticalWhiteGreen.a2 = 1.0f;

			csVerticalWhiteGreen.r3 = csGreyToGreen.r1;
			csVerticalWhiteGreen.g3 = csGreyToGreen.g1;
			csVerticalWhiteGreen.b3 = csGreyToGreen.b1;
			csVerticalWhiteGreen.a3 = 1.0f;
		}
		else
		{
			// no action
		}

		glTranslatef(0.0f, 0.0825f, 0.0f);
		glScalef(1.0f, 1.25f, 1.0f);
		drawVerticalStructure(&csVerticalWhiteGreen);
	}
	glPopMatrix();
	glPushMatrix();
	{
		if(currentScene == SCENE_1)
		{
		}
		else if(currentScene == SCENE_2)
		{
			csVerticalSaffronWhite.r1 = csGreyToSaffron.r1;
			csVerticalSaffronWhite.g1 = csGreyToSaffron.g1;
			csVerticalSaffronWhite.b1 = csGreyToSaffron.b1;
			csVerticalSaffronWhite.a1 = 1.0f;

			csVerticalSaffronWhite.r2 = csGreyToSaffron.r1;
			csVerticalSaffronWhite.g2 = csGreyToSaffron.g1;
			csVerticalSaffronWhite.b2 = csGreyToSaffron.b1;
			csVerticalSaffronWhite.a2 = 1.0f;

			csVerticalSaffronWhite.r3 = csGreyToWhite.r1;
			csVerticalSaffronWhite.g3 = csGreyToWhite.g1;
			csVerticalSaffronWhite.b3 = csGreyToWhite.b1;
			csVerticalSaffronWhite.a3 = 1.0f;
		}
		else
		{
			// no action
		}

		glTranslatef(0.0f, 2.31f, 0.0f);
		drawVerticalStructure(&csVerticalSaffronWhite);
	}
	glPopMatrix();
}

void drawA(void)
{
	// variable declarations
	HVCOLOURSTRUCT csLetter = csGrey;
	HVCOLOURSTRUCT csGreyToSaffron = csGrey;
	HVCOLOURSTRUCT csGreyToWhite = csGrey;

	// code
	if(currentScene == SCENE_1)
	{
	}
	else if(currentScene == SCENE_2)
	{
		csLetter.r1 = lerp(csGrey.r1, csTiranga.r1, letterT[2]);
		csLetter.g1 = lerp(csGrey.g1, csTiranga.g1, letterT[2]);
		csLetter.b1 = lerp(csGrey.b1, csTiranga.b1, letterT[2]);
		csLetter.a1 = 1.0f; //lerp(csGrey.a1, csTiranga.a1, letterT[1]);

		csLetter.r2 = lerp(csGrey.r2, csTiranga.r2, letterT[2]);
		csLetter.g2 = lerp(csGrey.g2, csTiranga.g2, letterT[2]);
		csLetter.b2 = lerp(csGrey.b2, csTiranga.b2, letterT[2]);
		csLetter.a2 = 1.0f; //lerp(csGrey.a2, csTiranga.a2, letterT[1]);

		csLetter.r3 = lerp(csGrey.r3, csTiranga.r3, letterT[2]);
		csLetter.g3 = lerp(csGrey.g3, csTiranga.g3, letterT[2]);
		csLetter.b3 = lerp(csGrey.b3, csTiranga.b3, letterT[2]);
		csLetter.a3 = 1.0f; //lerp(csGrey.a3, csTiranga.a3, letterT[1]);
	}
	else
	{
		// no action
	}
	drawVerticalStructure(&csLetter);

	// this should be totally saffron
	if(currentScene == SCENE_1)
	{
	}
	else if(currentScene == SCENE_2)
	{
		csGreyToSaffron.r1 = lerp(csGrey.r1, csTiranga.r1, letterT[2]);
		csGreyToSaffron.g1 = lerp(csGrey.r1, csTiranga.g1, letterT[2]);
		csGreyToSaffron.b1 = lerp(csGrey.r1, csTiranga.b1, letterT[2]);
		csGreyToSaffron.a1 = 1.0f; //lerp(csGrey.r1, csTiranga.a1, letterT[0]);

		csGreyToSaffron.r2 = csGreyToSaffron.r1;
		csGreyToSaffron.g2 = csGreyToSaffron.g1;
		csGreyToSaffron.b2 = csGreyToSaffron.b1;
		csGreyToSaffron.a2 = 1.0f; //csGreyToSaffron.r1;

		csGreyToSaffron.r3 = csGreyToSaffron.r1;
		csGreyToSaffron.g3 = csGreyToSaffron.g1;
		csGreyToSaffron.b3 = csGreyToSaffron.b1;
		csGreyToSaffron.a3 = 1.0f; //csGreyToSaffron.r1;
	}
	else
	{
		// no action
	}
    glTranslatef(0.63f, 0.282f, 0.0f);
    drawHorizontalStructure(&csGreyToSaffron);

	// this has to be totally white
	if(currentScene == SCENE_1)
	{
	}
	else if(currentScene == SCENE_2)
	{
		csGreyToWhite.r1 = lerp(csGrey.r1, csTiranga.r2, letterT[2]);
		csGreyToWhite.g1 = lerp(csGrey.g1, csTiranga.g2, letterT[2]);
		csGreyToWhite.b1 = lerp(csGrey.r1, csTiranga.b2, letterT[2]);
		csGreyToWhite.a1 = 1.0f; //lerp(csGrey.r1, csTiranga.r2, letterT[1]);

		csGreyToWhite.r2 = csGreyToWhite.r1;
		csGreyToWhite.g2 = csGreyToWhite.g1;
		csGreyToWhite.b2 = csGreyToWhite.b1;
		csGreyToWhite.a2 = 1.0f; //lerp(csGrey.r1, csTiranga.r2, letterT[1]);

		csGreyToWhite.r3 = csGreyToWhite.r1;
		csGreyToWhite.g3 = csGreyToWhite.g1;
		csGreyToWhite.b3 = csGreyToWhite.b1;
		csGreyToWhite.a3 = 1.0f; //lerp(csGrey.r1, csTiranga.r2, letterT[1]);
	}
	else
	{
		// no action
	}
    glTranslatef(0.0f, -0.846f, 0.0f);
    drawHorizontalStructure(&csGreyToWhite);

	glTranslatef(0.63f, 0.564f, 0.0f);
	drawVerticalStructure(&csLetter);
}

void drawA_II(void)
{
	// variable declarations
	HVCOLOURSTRUCT csLetter = csGrey;
	HVCOLOURSTRUCT csGreyToSaffron = csGrey;
	HVCOLOURSTRUCT csGreyToWhite = csGrey;

	// code
	if(currentScene == SCENE_1)
	{
	}
	else if(currentScene == SCENE_2)
	{
		csLetter.r1 = lerp(csGrey.r1, csTiranga.r1, letterT[4]);
		csLetter.g1 = lerp(csGrey.g1, csTiranga.g1, letterT[4]);
		csLetter.b1 = lerp(csGrey.b1, csTiranga.b1, letterT[4]);
		csLetter.a1 = 1.0f; //lerp(csGrey.a1, csTiranga.a1, letterT[1]);

		csLetter.r2 = lerp(csGrey.r2, csTiranga.r2, letterT[4]);
		csLetter.g2 = lerp(csGrey.g2, csTiranga.g2, letterT[4]);
		csLetter.b2 = lerp(csGrey.b2, csTiranga.b2, letterT[4]);
		csLetter.a2 = 1.0f; //lerp(csGrey.a2, csTiranga.a2, letterT[1]);

		csLetter.r3 = lerp(csGrey.r3, csTiranga.r3, letterT[4]);
		csLetter.g3 = lerp(csGrey.g3, csTiranga.g3, letterT[4]);
		csLetter.b3 = lerp(csGrey.b3, csTiranga.b3, letterT[4]);
		csLetter.a3 = 1.0f; //lerp(csGrey.a3, csTiranga.a3, letterT[1]);
	}
	else
	{
		// no action
	}
	drawVerticalStructure(&csLetter);

	// this should be totally saffron
	if(currentScene == SCENE_1)
	{
	}
	else if(currentScene == SCENE_2)
	{
		csGreyToSaffron.r1 = lerp(csGrey.r1, csTiranga.r1, letterT[4]);
		csGreyToSaffron.g1 = lerp(csGrey.r1, csTiranga.g1, letterT[4]);
		csGreyToSaffron.b1 = lerp(csGrey.r1, csTiranga.b1, letterT[4]);
		csGreyToSaffron.a1 = 1.0f; //lerp(csGrey.r1, csTiranga.a1, letterT[0]);

		csGreyToSaffron.r2 = csGreyToSaffron.r1;
		csGreyToSaffron.g2 = csGreyToSaffron.g1;
		csGreyToSaffron.b2 = csGreyToSaffron.b1;
		csGreyToSaffron.a2 = 1.0f; //csGreyToSaffron.r1;

		csGreyToSaffron.r3 = csGreyToSaffron.r1;
		csGreyToSaffron.g3 = csGreyToSaffron.g1;
		csGreyToSaffron.b3 = csGreyToSaffron.b1;
		csGreyToSaffron.a3 = 1.0f; //csGreyToSaffron.r1;
	}
	else
	{
		// no action
	}
    glTranslatef(0.63f, 0.282f, 0.0f);
    drawHorizontalStructure(&csGreyToSaffron);

	// this has to be totally white
	if(currentScene == SCENE_1)
	{
	}
	else if(currentScene == SCENE_2)
	{
		csGreyToWhite.r1 = lerp(csGrey.r1, csTiranga.r2, letterT[4]);
		csGreyToWhite.g1 = lerp(csGrey.g1, csTiranga.g2, letterT[4]);
		csGreyToWhite.b1 = lerp(csGrey.r1, csTiranga.b2, letterT[4]);
		csGreyToWhite.a1 = 1.0f; //lerp(csGrey.r1, csTiranga.r2, letterT[1]);

		csGreyToWhite.r2 = csGreyToWhite.r1;
		csGreyToWhite.g2 = csGreyToWhite.g1;
		csGreyToWhite.b2 = csGreyToWhite.b1;
		csGreyToWhite.a2 = 1.0f; //lerp(csGrey.r1, csTiranga.r2, letterT[1]);

		csGreyToWhite.r3 = csGreyToWhite.r1;
		csGreyToWhite.g3 = csGreyToWhite.g1;
		csGreyToWhite.b3 = csGreyToWhite.b1;
		csGreyToWhite.a3 = 1.0f; //lerp(csGrey.r1, csTiranga.r2, letterT[1]);
	}
	else
	{
		// no action
	}
    glTranslatef(0.0f, -0.846f, 0.0f);
    drawHorizontalStructure(&csGreyToWhite);

	glTranslatef(0.63f, 0.564f, 0.0f);
	drawVerticalStructure(&csLetter);
}

void drawH(void)
{
	// variable declarations
	HVCOLOURSTRUCT csLetter = csGrey;
	HVCOLOURSTRUCT csGreyToWhite = csGrey;

	// code
	if(currentScene == SCENE_1)
	{
	}
	else if(currentScene == SCENE_2)
	{
		csLetter.r1 = lerp(csGrey.r1, csTiranga.r1, letterT[1]);
		csLetter.g1 = lerp(csGrey.g1, csTiranga.g1, letterT[1]);
		csLetter.b1 = lerp(csGrey.b1, csTiranga.b1, letterT[1]);
		csLetter.a1 = 1.0f; //lerp(csGrey.a1, csTiranga.a1, letterT[1]);

		csLetter.r2 = lerp(csGrey.r2, csTiranga.r2, letterT[1]);
		csLetter.g2 = lerp(csGrey.g2, csTiranga.g2, letterT[1]);
		csLetter.b2 = lerp(csGrey.b2, csTiranga.b2, letterT[1]);
		csLetter.a2 = 1.0f; //lerp(csGrey.a2, csTiranga.a2, letterT[1]);

		csLetter.r3 = lerp(csGrey.r3, csTiranga.r3, letterT[1]);
		csLetter.g3 = lerp(csGrey.g3, csTiranga.g3, letterT[1]);
		csLetter.b3 = lerp(csGrey.b3, csTiranga.b3, letterT[1]);
		csLetter.a3 = 1.0f; //lerp(csGrey.a3, csTiranga.a3, letterT[1]);
	}
	else
	{
		// no action
	}
	drawVerticalStructure(&csLetter);

    glTranslatef(0.63f, -0.564f, 0.0f);
	// this structure should only lerp from grey to white
	if(currentScene == SCENE_1)
	{
	}
	else if(currentScene == SCENE_2)
	{
		csGreyToWhite.r1 = lerp(0.5f, 1.0f, letterT[1]);
		csGreyToWhite.g1 = lerp(0.5f, 1.0f, letterT[1]);
		csGreyToWhite.b1 = lerp(0.5f, 1.0f, letterT[1]);
		csGreyToWhite.a1 = 1.0f; //lerp(0.5f, 1.0f, letterT[1]);

		csGreyToWhite.r2 = lerp(0.5f, 1.0f, letterT[1]);
		csGreyToWhite.g2 = lerp(0.5f, 1.0f, letterT[1]);
		csGreyToWhite.b2 = lerp(0.5f, 1.0f, letterT[1]);
		csGreyToWhite.a2 = 1.0f; //lerp(0.5f, 1.0f, letterT[1]);

		csGreyToWhite.r3 = lerp(0.5f, 1.0f, letterT[1]);
		csGreyToWhite.g3 = lerp(0.5f, 1.0f, letterT[1]);
		csGreyToWhite.b3 = lerp(0.5f, 1.0f, letterT[1]);
		csGreyToWhite.a3 = 1.0f; //lerp(0.5f, 1.0f, letterT[1]);
	}
	else
	{
		// no action
	}
    drawHorizontalStructure(&csGreyToWhite);


	glTranslatef(0.63f, 0.564f, 0.0f);
	drawVerticalStructure(&csLetter);
}

void drawB(void)
{
	// variable declarations
	HVCOLOURSTRUCT csLetter = csGrey;
	HVCOLOURSTRUCT csGreyToWhite = csGrey;
	HVCOLOURSTRUCT csGreyToSaffron = csGrey;
	HVCOLOURSTRUCT csGreyToGreen = csGrey;
	HVCOLOURSTRUCT csVerticalWhiteGreen = csGrey;
	HVCOLOURSTRUCT csVerticalSaffronWhite = csGrey;

	// code
	if(currentScene == SCENE_1)
	{
	}
	else if(currentScene == SCENE_2)
	{
		csLetter.r1 = lerp(csGrey.r1, csTiranga.r1, letterT[0]);
		csLetter.g1 = lerp(csGrey.g1, csTiranga.g1, letterT[0]);
		csLetter.b1 = lerp(csGrey.b1, csTiranga.b1, letterT[0]);
		csLetter.a1 = 1.0f; //lerp(csGrey.a1, csTiranga.a1, letterT[0]);

		csLetter.r2 = lerp(csGrey.r2, csTiranga.r2, letterT[0]);
		csLetter.g2 = lerp(csGrey.g2, csTiranga.g2, letterT[0]);
		csLetter.b2 = lerp(csGrey.b2, csTiranga.b2, letterT[0]);
		csLetter.a2 = 1.0f; //lerp(csGrey.a2, csTiranga.a2, letterT[0]);

		csLetter.r3 = lerp(csGrey.r3, csTiranga.r3, letterT[0]);
		csLetter.g3 = lerp(csGrey.g3, csTiranga.g3, letterT[0]);
		csLetter.b3 = lerp(csGrey.b3, csTiranga.b3, letterT[0]);
		csLetter.a3 = 1.0f; //lerp(csGrey.a3, csTiranga.a3, letterT[0]);
	}
	else
	{
		// no action
	}

	// B specific
	drawVerticalStructure(&csLetter);

	// should only be saffron, only and only csTiranga r1,g1,b1 are saffron
	glTranslatef(0.63f, 0.282f, 0.0f);
	if(currentScene == SCENE_1)
	{
	}
	else if(currentScene == SCENE_2)
	{
		csGreyToSaffron.r1 = lerp(csGrey.r1, csTiranga.r1, letterT[0]);
		csGreyToSaffron.g1 = lerp(csGrey.r1, csTiranga.g1, letterT[0]);
		csGreyToSaffron.b1 = lerp(csGrey.r1, csTiranga.b1, letterT[0]);
		csGreyToSaffron.a1 = 1.0f; //lerp(csGrey.r1, csTiranga.a1, letterT[0]);

		csGreyToSaffron.r2 = lerp(csGrey.r1, csTiranga.r1, letterT[0]);
		csGreyToSaffron.g2 = lerp(csGrey.r1, csTiranga.g1, letterT[0]);
		csGreyToSaffron.b2 = lerp(csGrey.r1, csTiranga.b1, letterT[0]);
		csGreyToSaffron.a2 = 1.0f; //lerp(csGrey.r1, csTiranga.a1, letterT[0]);

		csGreyToSaffron.r3 = lerp(csGrey.r1, csTiranga.r1, letterT[0]);
		csGreyToSaffron.g3 = lerp(csGrey.r1, csTiranga.g1, letterT[0]);
		csGreyToSaffron.b3 = lerp(csGrey.r1, csTiranga.b1, letterT[0]);
		csGreyToSaffron.a3 = 1.0f; //lerp(csGrey.r1, csTiranga.a1, letterT[0]);
	}
	else
	{
		// no action
	}
	drawHorizontalStructure(&csGreyToSaffron);


	// this structure should only lerp from grey to white
	if(currentScene == SCENE_1)
	{
	}
	else if(currentScene == SCENE_2)
	{
		csGreyToWhite.r1 = lerp(csGrey.r1, csTiranga.r2, letterT[0]);
		csGreyToWhite.g1 = lerp(csGrey.g1, csTiranga.g2, letterT[0]);
		csGreyToWhite.b1 = lerp(csGrey.r1, csTiranga.b2, letterT[0]);
		csGreyToWhite.a1 = 1.0f; //berp(csGrey.r1, csTiranga.r2, letterT[1]);

		csGreyToWhite.r2 = lerp(csGrey.r1, csTiranga.r2, letterT[0]);
		csGreyToWhite.g2 = lerp(csGrey.g1, csTiranga.g2, letterT[0]);
		csGreyToWhite.b2 = lerp(csGrey.b1, csTiranga.b2, letterT[0]);
		csGreyToWhite.a2 = 1.0f; //lerp(csGrey.r1, csTiranga.r2, letterT[1]);

		csGreyToWhite.r3 = lerp(csGrey.r1, csTiranga.r2, letterT[0]);
		csGreyToWhite.g3 = lerp(csGrey.g1, csTiranga.g2, letterT[0]);
		csGreyToWhite.b3 = lerp(csGrey.b1, csTiranga.b2, letterT[0]);
		csGreyToWhite.a3 = 1.0f; //lerp(csGrey.r1, csTiranga.r2, letterT[1]);
	}
	else
	{
		// no action
	}

	glTranslatef(0.0f, -0.846f, 0.0f);
	drawHorizontalStructure(&csGreyToWhite);


	glTranslatef(0.0f, -0.846f, 0.0f);
	if(currentScene == SCENE_1)
	{
	}
	else if(currentScene == SCENE_2)
	{
		csGreyToGreen.r1 = lerp(csGrey.r1, csTiranga.r3, letterT[0]);
		csGreyToGreen.g1 = lerp(csGrey.r1, csTiranga.g3, letterT[0]);
		csGreyToGreen.b1 = lerp(csGrey.r1, csTiranga.b3, letterT[0]);
		csGreyToGreen.a1 = 1.0f; //lerp(csGrey.r1, csTiranga.a3, letterT[0]);

		csGreyToGreen.r2 = lerp(csGrey.r1, csTiranga.r3, letterT[0]);
		csGreyToGreen.g2 = lerp(csGrey.r1, csTiranga.g3, letterT[0]);
		csGreyToGreen.b2 = lerp(csGrey.r1, csTiranga.b3, letterT[0]);
		csGreyToGreen.a2 = 1.0f; //lerp(csGrey.r1, csTiranga.a3, letterT[0]);

		csGreyToGreen.r3 = lerp(csGrey.r1, csTiranga.r3, letterT[0]);
		csGreyToGreen.g3 = lerp(csGrey.r1, csTiranga.g3, letterT[0]);
		csGreyToGreen.b3 = lerp(csGrey.r1, csTiranga.b3, letterT[0]);
		csGreyToGreen.a3 = 1.0f; //lerp(csGrey.r1, csTiranga.a3, letterT[0]);
	}
	else
	{
		// no action
	}
	// this structue is fully green
	drawHorizontalStructure(&csGreyToGreen);

	glScalef(0.5f, 0.4f, 1.0f);
	glTranslatef(1.11f, 1.38f, 0.0f);
	glPushMatrix();
	{
		// top 1 part white, remaining 2 parts green
		if(currentScene == SCENE_1)
		{
		}
		else if(currentScene == SCENE_2)
		{
			csVerticalWhiteGreen.r1 = csGreyToWhite.r1;
			csVerticalWhiteGreen.g1 = csGreyToWhite.g1;
			csVerticalWhiteGreen.b1 = csGreyToWhite.b1;
			csVerticalWhiteGreen.a1 = 1.0f;

			csVerticalWhiteGreen.r2 = csGreyToGreen.r1;
			csVerticalWhiteGreen.g2 = csGreyToGreen.g1;
			csVerticalWhiteGreen.b2 = csGreyToGreen.b1;
			csVerticalWhiteGreen.a2 = 1.0f;

			csVerticalWhiteGreen.r3 = csGreyToGreen.r1;
			csVerticalWhiteGreen.g3 = csGreyToGreen.g1;
			csVerticalWhiteGreen.b3 = csGreyToGreen.b1;
			csVerticalWhiteGreen.a3 = 1.0f;
		}
		else
		{
			// no action
		}

		drawVerticalStructure(&csVerticalWhiteGreen);
	}
	glPopMatrix();
	glPushMatrix();
	{
		// top 2 parts saffron, remaining 1 part white
		if(currentScene == SCENE_1)
		{
		}
		else if(currentScene == SCENE_2)
		{
			csVerticalSaffronWhite.r1 = csGreyToSaffron.r1;
			csVerticalSaffronWhite.g1 = csGreyToSaffron.g1;
			csVerticalSaffronWhite.b1 = csGreyToSaffron.b1;
			csVerticalSaffronWhite.a1 = 1.0f; //csGreyToSaffron.r1;

			csVerticalSaffronWhite.r2 = csGreyToSaffron.r1;
			csVerticalSaffronWhite.g2 = csGreyToSaffron.g1;
			csVerticalSaffronWhite.b2 = csGreyToSaffron.b1;
			csVerticalSaffronWhite.a2 = 1.0f; //csGreyToSaffron.r1;

			csVerticalSaffronWhite.r3 = csGreyToWhite.r1;
			csVerticalSaffronWhite.g3 = csGreyToWhite.g1;
			csVerticalSaffronWhite.b3 = csGreyToWhite.b1;
			csVerticalSaffronWhite.a3 = 1.0f; //csGreyToSaffron.r1;
		}
		else
		{
			// no action
		}
		glTranslatef(0.0f, 2.31f, 0.0f);
		drawVerticalStructure(&csVerticalSaffronWhite);
	}
	glPopMatrix();
}

void drawVerticalStructure(HVCOLOURSTRUCT *pcs)
{
	// function declarations
	void drawCube(void);

	// code
	glPushMatrix();
	{
		glScalef(0.15f, 0.33f, 0.2f);

		glColor4f(pcs->r1, pcs->g1, pcs->b1, pcs->a1);
		drawCube();

		glColor4f(pcs->r2, pcs->g2, pcs->b2, pcs->a2);
		glTranslatef(0.0f, -2.0f, 0.0f);
		drawCube();

		glColor4f(pcs->r3, pcs->g3, pcs->b3, pcs->a3);
		glTranslatef(0.0f, -2.0f, 0.0f);
		drawCube();
	}
	glPopMatrix();
}

void drawHorizontalStructure(HVCOLOURSTRUCT *pcs)
{
	// code
	void drawCube(void);

	glPushMatrix();
	{
		glScalef(0.48f, 0.048f, 0.2f);

		glColor4f(pcs->r1, pcs->g1, pcs->b1, pcs->a1);
		drawCube();

		glColor4f(pcs->r2, pcs->g2, pcs->b2, pcs->a2);
		glTranslatef(0.0f, -2.0f, 0.0f);
		drawCube();

		glColor4f(pcs->r3, pcs->g3, pcs->b3, pcs->a3);
		glTranslatef(0.0f, -2.0f, 0.0f);
		drawCube();
	}
	glPopMatrix();
}

void drawCube(void)
{
	// code
    glBegin(GL_QUADS);
    {
        // front
        // glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(1.0f, 1.0f, 1.0f);   // top-right of front
        glVertex3f(-1.0f, 1.0f, 1.0f);  // top-left of front
        glVertex3f(-1.0f, -1.0f, 1.0f); // bottom-left of front
        glVertex3f(1.0f, -1.0f, 1.0f);  // bottom-right of front

        // right
        // glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(1.0f, 1.0f, -1.0f);  // top-right of right
        glVertex3f(1.0f, 1.0f, 1.0f);   // top-left of right
        glVertex3f(1.0f, -1.0f, 1.0f);  // bottom-left of right
        glVertex3f(1.0f, -1.0f, -1.0f); // bottom-right of right

        // back
        // glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, -1.0f);   // top-right of back
        glVertex3f(-1.0f, 1.0f, -1.0f);  // top-left of back
        glVertex3f(-1.0f, -1.0f, -1.0f); // bottom-left of back
        glVertex3f(1.0f, -1.0f, -1.0f);  // bottom-right of back

        // left
        // glColor3f(0.0f, 1.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);   // top-right of left
        glVertex3f(-1.0f, 1.0f, -1.0f);  // top-left of left
        glVertex3f(-1.0f, -1.0f, -1.0f); // bottom-left of left
        glVertex3f(-1.0f, -1.0f, 1.0f);  // bottom-right of left

        // top
        // glColor3f(1.0f, 0.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, -1.0f);  // top-right of top
        glVertex3f(-1.0f, 1.0f, -1.0f); // top-left of top
        glVertex3f(-1.0f, 1.0f, 1.0f);  // bottom-left of top
        glVertex3f(1.0f, 1.0f, 1.0f);   // bottom-right of top

        // bottom
        // glColor3f(1.0f, 1.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);   // top-right of bottom
        glVertex3f(-1.0f, -1.0f, 1.0f);  // top-left of bottom
        glVertex3f(-1.0f, -1.0f, -1.0f); // bottom-left of bottom
        glVertex3f(1.0f, -1.0f, -1.0f);  // bottom-right of bottom
    }
    glEnd();
}

