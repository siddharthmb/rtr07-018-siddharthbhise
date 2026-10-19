#include "E_TimerFunctions.h"

// LEARNING RESOURCES
// -------- ---------
//
// https://learn.microsoft.com/en-us/windows/win32/api/profileapi/nf-profileapi-queryperformancefrequency
// https://learn.microsoft.com/en-us/windows/win32/api/profileapi/nf-profileapi-queryperformancecounter
// https://learn.microsoft.com/en-us/windows/win32/api/winnt/ns-winnt-large_integer-r1
//

static LARGE_INTEGER frequency;
static LARGE_INTEGER firstInvocationQuadValue;

// TimerFunctions
void timerParamsInit(void)
{
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&firstInvocationQuadValue);
}

float getTotalElapsedTimeInSeconds(void)
{
	return getTotalElapsedTimeSinceFirstInvocationInSeconds();
}

float getTotalElapsedTimeSinceFirstInvocationInSeconds(void)
{
	LARGE_INTEGER currentPerfCounter;
	float timeElapsedInSeconds;

	QueryPerformanceCounter(&currentPerfCounter);
	timeElapsedInSeconds = ((float)(currentPerfCounter.QuadPart - firstInvocationQuadValue.QuadPart)) / ((float)frequency.QuadPart);

	return timeElapsedInSeconds;
}

float getTotalElapsedTimeSinceFirstInvocationInMilliSeconds(void)
{
	return getTotalElapsedTimeSinceFirstInvocationInSeconds() * 1000.0f;
}