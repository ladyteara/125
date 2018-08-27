/*	COURSE:				CSC 125.001, Lab Assignment 5
	PROGRAMMER:			Tara Walton, Tara1984
	MODIFIED BY:
	LAST MODIFIED:		February 20, 2014
	DESCRIPTION:		Calculate teh change in percentagefor two different years at MSU
	NOTES:				
	FILES:				lab5.cpp
	IDE/COMPILER:		Microsoft Visual Studio Professional 2012
INSTRUCTIONS FOR COMPLIATION AND EXECUTION:
1. Double Click on labProject.sln		to OPEN project
2. Press CTRL+F7						to COMPILE
3. Press CTRL+SHIFT+B					to BUILD (Compile + Link)
4. Press CTRL+F5						to EXECUTE	*/

#include<iostream>
using namespace std;

void main( )
{	//Variable declaration
	unsigned short	yearOne=0, yearTwo=0, popOne=0, popTwo=0;	//user input data
	signed short	yearDiff=0, popDiff=0;						//calculated
	float			rate=0;										//calculated

	//Prompt
	cout<<"\n\n What is the first year you would like to enter?  ";
	cin>>yearOne;
	cout<<" What was the student enrollment for the year "<<yearOne<<"?  ";
	cin>>popOne;
	cout<<" What is the second year you would like to enter?  ";
	cin>>yearTwo;
	cout<<" What was the student enrollment for the year "<<yearTwo<<"?  ";
	cin>>popTwo;

	//Calculation
	yearDiff	= yearTwo-yearOne;
	popDiff		= popTwo-popOne;
	rate		= (float(popDiff)/popOne)*100;
		
	//Display
	cout<<"\n\n In the "<<yearDiff<<" years, the student enrollment has changed "<<rate<<"%\n\n";

}	