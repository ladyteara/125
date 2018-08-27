/*
COURSE:			CSC 125.001, Lab Assignment 3
PROGRAMMER:		Tara Walton, Tara1984
MODIFIED BY:
LAST MODIFIED:	January 30, 2014
DESCRIPTION:	This program calculates the student's quality points.
NOTES:		
FILES:			lab3.cpp
IDE/COMPILER:	Microsoft Visual Studio 2012
INSTRUCTIONS FOR COMPLIATION AND EXECUTION:
	1. Double Click on Lab3.sln		to OPEN project
	2. Press CTRL+F7				to COMPILE
	3. Press CTRL+SHIFT+B			to BUILD (Compile + Link)
	4. Press CTRL+F5				to EXECUTE
*/

#include<iostream>
using namespace std;

void main()

{int hoursAttempted, gradePoints, qualityPoints;

 hoursAttempted=17;
 gradePoints=4;
 qualityPoints=hoursAttempted*gradePoints;

cout<< "\nAfter taking "<< hoursAttempted << " credit hours, student has "<< qualityPoints <<" quality points earned. \n\n";
}
