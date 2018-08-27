/*	COURSE:				CSC 125.001, Lab Assignment 4
	PROGRAMMER:			Tara Walton, Tara1984
	MODIFIED BY:
	LAST MODIFIED:		February 13, 2014
	DESCRIPTION:		Calculating the width and length of a rectangle with a user defined perimeter	
	NOTES:				I don't know any way to break down perimeter into length and width based one ratio. The instructions on this do not make any sense. Obviously I was not the only one.
	FILES:				lab4.cpp
	IDE/COMPILER:		Microsoft Visual Studio Professional 2012
INSTRUCTIONS FOR COMPLIATION AND EXECUTION:
1. Double Click on hwProject.sln		to OPEN project
2. Press CTRL+F7						to COMPILE
3. Press CTRL+SHIFT+B					to BUILD (Compile + Link)
4. Press CTRL+F5						to EXECUTE					*/

#include<iostream>
using namespace std;

void main( )
{	//Variable declaration
	float perimeter,		//user entered
		width=0,			//calculated
		length=0;			//calculated
	const unsigned short ratio=3;	//Assumed the width is 3Xlength
	//Prompt
	cout<<"\n\nWhat is the perimeter of your rectangle?\n";
	cin>>perimeter;
	//Calculation
		length=perimeter/(2*(ratio+1));
		width=length*ratio;
	//Display
	cout<<"\n\nYour perimeter was "<<perimeter<<" which makes the length "<<length<<" and the width "<<width<<".\n\n";
}	
	



