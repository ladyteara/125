/* COURSE:		CSC 125.001, HW Assignment 5
PROGRAMMER:		Tara Walton, Tara1984
MODIFIED BY:
LAST MODIFIED:	February 25, 2014
DESCRIPTION:	To calculate the cumulative GPA for any given student as entered by user
NOTES:			
FILES:			hw5.cpp
IDE/COMPILER:	Microsoft Visual Studio Professional 2012
INSTRUCTIONS FOR COMPLIATION AND EXECUTION:
1. Double Click on hwProject.sln		to OPEN project
2. Press CTRL+F7						to COMPILE
3. Press CTRL+SHIFT+B					to BUILD (Compile + Link)
4. Press CTRL+F5						to EXECUTE					*/

#include <iostream>
#include <string>
using namespace std;

void main( )
{
	//Variable declaration
	float	 gpaPrev, gpaMSU, gpaTot;
	unsigned short age(0), creditsPrev(0), creditsMSU(0), creditsTot(0), ptsPrev(0), ptsMSU(0), ptsTot(0);

	//Student's information initialization
	string	firstName=	" ",
		lastName=	" ",
		ssn=		" ", 
		sex=		" ";

	//Explanation
	cout<<endl<<endl;
	cout<<" This program will calculate the transfer GPA, Missouri State University GPA";
	cout<<" and the Cumulative GPA for any given student.";
	cout<<"	\nPlease fill in the data prompts below to begin calculations:\n";
	cout<<endl;

	//Entering information
	cout<<" The student's personal information:\n";
	cout<<" What is the student's name? (First Last)  ";
		cin>>firstName>>lastName;
	cout<<" What is "<<firstName<<"\'s social security number? (format XXX-XX-XXXX)  ";
		cin>>ssn;
	cout<<" What is "<<firstName<<"\'s age in years?  ";
		cin>>age;
	cout<<" What is "<<firstName<<"\'s sex? (M or F)  ";
		cin>>sex;
	cout<<endl;
	cout<<" The student's transfer information:\n";
	cout<<" How many Credit Hours are being transferred from student's previous school?  ";
		cin>>creditsPrev;
	cout<< " How many Quality Points were earned?  ";
		cin>>ptsPrev;
	cout<<" The student's Missouri State University information:\n";
	cout<<" How many Credit Hours have been earned at MSU?  ";
		cin>>creditsMSU;
	cout<< " How many Quality Points have been earned?  ";
		cin>>ptsMSU;

	//Calculations 
	gpaPrev=		ptsPrev/float(creditsPrev);
	gpaMSU=			ptsMSU/float(creditsMSU);
	//Cumulative calculations
	creditsTot=		creditsPrev + creditsMSU;
	ptsTot=			ptsPrev+ptsMSU;
	gpaTot=			ptsTot/float(creditsTot);

	//Display entered information with calculations
	cout<<endl<<endl;
	cout<<"********************************************************************"<<endl;
	cout<<" Name: \t"<<lastName<<", "<<firstName<<endl;
	cout<<" SSN: \t"<<ssn<<" \t\tAge: \t"<<age<<"yrs \t\tSex: \t"<<sex<<endl;
	cout<<endl;
	cout<<" Transfer Information:\n";
	cout<<"   Hours Attempted: "<<creditsPrev<<"\tQuality Points Earned: "<<ptsPrev<<endl;
	cout<<"   GPA: "<<gpaPrev<<endl;
	cout<<" Missouri State University:\n";
	cout<<"   Hours Attempted: "<<creditsMSU<<"\tQuality Points Earned: "<<ptsMSU<<endl;
	cout<<"   GPA: "<<gpaMSU<<endl;
	cout<<endl;
	cout<<" Cumulative:\n";
	cout<<"   Total Hours: "<<creditsTot<<"\tQuality Points Earned: "<<ptsTot<<endl;
	cout<<"   GPA: "<<gpaTot<<endl;
	cout<<"********************************************************************"<<endl;
	cout<<endl;
}