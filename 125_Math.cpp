/*	COURSE:				CSC 125.001, Lab Assignment 6
	PROGRAMMER:			Tara Walton, Tara1984
	MODIFIED BY:
	LAST MODIFIED:		February 27, 2014
	DESCRIPTION:		
	NOTES:				
	FILES:				lab6.cpp
	IDE/COMPILER:		Microsoft Visual Studio Professional 2012
INSTRUCTIONS FOR COMPLIATION AND EXECUTION:
1. Double Click on labProject.sln		to OPEN project
2. Press CTRL+F7						to COMPILE
3. Press CTRL+SHIFT+B					to BUILD (Compile + Link)
4. Press CTRL+F5						to EXECUTE	*/

#include<iostream>
#include<cmath>
using namespace std;

#define pi 3.14159265

void main( )
{
//variable declaration
	double			rad(0), 
					angle(0),
					conversion(0);					
	float			oSide(0),
					hSide(0),
					aSide(0);

//calculation necessities
	conversion =pi/180;

//user entered variables
cout<<endl<<endl;
cout<<"Enter the value of a non-right angle in your triangle to \n\tthe nearest 10th of a degree: ";
	cin>>angle;
cout<<"Enter the length of the opposite side of your triangle \n\trounded to the nearest inch:(1-500) ";
	cin>>oSide;

//calculations
	rad=		angle*conversion;		//angle conversion
	aSide=		oSide/tan(rad);			//adjacent side calc
	hSide=		hypot(oSide, aSide);	//hypotenuse calc


//Display
cout<<endl<<endl;
cout<<"****************************************************************\n";
cout<<"You gave your triangle's opposite side as "<<oSide<<" inches.\n";
cout<<"Your triangle's adjacent side is "<<aSide<<" inches.\n";
cout<<"Your triangle's hypotenuse is "<<hSide<<" inches.\n";
cout<<"****************************************************************\n\n\n";
}