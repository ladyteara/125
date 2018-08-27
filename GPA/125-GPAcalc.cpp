/*	COURSE:				CSC 125.001, HW Assignment 4
	PROGRAMMER:			Tara Walton, Tara1984
	MODIFIED BY:
	LAST MODIFIED:		February 13, 2014
	DESCRIPTION:		Calculating GPA for Peter	
	NOTES:	
	FILES:				hw4.cpp
	IDE/COMPILER:		Microsoft Visual Studio Professional 2012
INSTRUCTIONS FOR COMPLIATION AND EXECUTION:
1. Double Click on hwProject.sln		to OPEN project
2. Press CTRL+F7						to COMPILE
3. Press CTRL+SHIFT+B					to BUILD (Compile + Link)
4. Press CTRL+F5						to EXECUTE					*/

#include<iostream>
using namespace std;

#include<string>					//needed to use string variables

void main( )
{
//Variable declaration
string			name="", ssn="", sex="";
float			ptsPrev, ptsMSU, ptsTot, gpaPrev, gpaMSU, gpaTot;
unsigned short	age, creditsPrev, creditsMSU, creditsTot;

//Peter's information
name=	"Peter Ford"; 
ssn=	"789-34-1256", 
sex=	"Male";
age=	21;

//Previous college
creditsPrev=	52;					//Hours attempted at previous school
ptsPrev=	182.0;					//quality points from previous school
gpaPrev=	ptsPrev/creditsPrev;	//calculation of GPA (points divided by hours)

//MSU
creditsMSU=	25;						//Hours attempted at MSU
ptsMSU=	 93.0;						//quality points from MSU
gpaMSU=	 ptsMSU/creditsMSU;			//calculation of GPA (points divided by hours)

//Cumulative
creditsTot=	creditsPrev+creditsMSU; //Hours attempted total
ptsTot=	 ptsPrev+ptsMSU;			//quality points total
gpaTot=	 ptsTot/creditsTot;			//calculation of GPA (points divided by hours)

//Display Output
cout<<"**********************************************************************";
cout<<"\n\n Name: \t"<<name<<endl;
cout<<" SSN: \t"<<ssn<<" \t\tAge: \t"<<age<<"yrs \t\tSex: \t"<<sex<<endl;
cout<<endl<<endl;
cout<<" Previous School:\n";
cout<<"   Hours Attempted: "<<creditsPrev<<"\tQuality Points Earned: "<<ptsPrev<<endl;
cout<<"   GPA: "<<gpaPrev<<endl<<endl;
cout<<" Missouri State University:\n";
cout<<"   Hours Attempted: "<<creditsMSU<<"\tQuality Points Earned: "<<ptsMSU<<endl;
cout<<"   GPA: "<<gpaMSU<<endl<<endl<<endl;
cout<<" Cumulative:\n";
cout<<"   Total Hours: "<<creditsTot<<"\tQuality Points Earned: "<<ptsTot<<endl;
cout<<"   GPA: "<<gpaTot<<endl;
cout<<endl<<endl;
cout<<"**********************************************************************";
cout<<endl;
}