#include <stdio.h>

#define MY_PI      3.1414926535898932
#define AMC_STRING "AstroMediComp"

// unnamed weekdays' names enum
enum
{
	SUNDAY,
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY
};

// unnamed months' names enum
enum
{
	JANUARY = 1,
	FEBRUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER
};

// named enum
enum Number
{
	ONE,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN
};

enum Boolean
{
	FALSE,
	TRUE
};

int main(void)
{
	// code

	printf("\n\n");

	const double epsilon = 0.000001;
	printf("Local Constant Epsilon = %lf\n", epsilon);

	// using unnamed enums
	printf("            Sunday is day number : %2d\n", SUNDAY);
	printf("            Monday is day number : %2d\n", MONDAY);
	printf("           Tuesday is day number : %2d\n", TUESDAY);
	printf("         Wednesday is day number : %2d\n", WEDNESDAY);
	printf("          Thursday is day number : %2d\n", THURSDAY);
	printf("            Friday is day number : %2d\n", FRIDAY);
	printf("          Saturday is day number : %2d\n", SATURDAY);

	printf("\n\n");
	printf("              One is enum number : %2d\n", ONE);
	printf("              Two is enum number : %2d\n", TWO);
	printf("            Three is enum number : %2d\n", THREE);
	printf("             Four is enum number : %2d\n", FOUR);
	printf("             Five is enum number : %2d\n", FIVE);
	printf("              Six is enum number : %2d\n", SIX);
	printf("            Seven is enum number : %2d\n", SEVEN);
	printf("            Eight is enum number : %2d\n", EIGHT);
	printf("             Nine is enum number : %2d\n", NINE);
	printf("              Ten is enum number : %2d\n", TEN);

	printf("\n\n");
	printf("         January is month number : %2d\n", JANUARY);
	printf("        February is month number : %2d\n", FEBRUARY);
	printf("           March is month number : %2d\n", MARCH);
	printf("           April is month number : %2d\n", APRIL);
	printf("             May is month number : %2d\n", MAY);
	printf("            June is month number : %2d\n", JUNE);
	printf("            July is month number : %2d\n", JULY);
	printf("          August is month number : %2d\n", AUGUST);
	printf("       September is month number : %2d\n", SEPTEMBER);
	printf("         October is month number : %2d\n", OCTOBER);
	printf("        November is month number : %2d\n", NOVEMBER);
	printf("        December is month number : %2d\n", DECEMBER);

	printf("\n\n");
	printf("              TRUE value in enum : %d\n", TRUE);
	printf("             FALSE value in enum : %d\n", FALSE);
	printf("                     MY_PI macro : %.15lf\n", MY_PI);
	printf("Area of circle of radius 2 units : %.1f sq. units.\n", MY_PI * 2.0f * 2.0f);

	printf("\n\n");
	return 0;
}