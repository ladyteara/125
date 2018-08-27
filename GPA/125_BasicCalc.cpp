/*
COURSE:			CSC125.001, Quiz1
PROGRAMMER:		Tara Walton, TARA1984
DATE:			Feb 6, 2014
DESCRIPTION:	Calculating the GPA of a student
NOTES:
FILES:			GPA.cpp
*/

#include <iostream>
using namespace std;

void main()
{
//Variables
unsigned short qPts;
float hrsAttempt, grdPt;

//Assign
hrsAttempt=52.0;
qPts=182;
grdPt=qPts/hrsAttempt;

cout<<"\n Student has taken "<<hrsAttempt<<" hours, earning "<<qPts<<". Student's GPA is "<<grdPt<<". \n \n";
}
