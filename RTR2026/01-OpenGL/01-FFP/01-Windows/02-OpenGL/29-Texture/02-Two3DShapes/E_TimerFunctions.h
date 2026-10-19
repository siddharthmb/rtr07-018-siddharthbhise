#ifndef _SMB_TIMER_FUNCTIONS_H
#define _SMB_TIMER_FUNCTIONS_H

#include <Windows.h>
#include <profileapi.h>

void timerParamsInit(void);
float getTotalElapsedTimeSinceFirstInvocationInSeconds(void);
float getTotalElapsedTimeSinceFirstInvocationInMilliSeconds(void);
float getTotalElapsedTimeInSeconds(void);

// timer fn for freeglut timer func registration
void timer(int);	// signature for scene animator function

#endif
