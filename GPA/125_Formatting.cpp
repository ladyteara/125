/* COURSE:		CSC 125.001, Lab 7
PROGRAMMER:		Tara Walton, Tara1984
MODIFIED BY:
LAST MODIFIED:	March 6, 2014
DESCRIPTION:	To calculate the cumulative GPA for any given student as entered by user
NOTES:			
FILES:			lab7.cpp
IDE/COMPILER:	Microsoft Visual Studio Professional 2012
INSTRUCTIONS FOR COMPLIATION AND EXECUTION:
1. Double Click on hwProject.sln		to OPEN project
2. Press CTRL+F7						to COMPILE
3. Press CTRL+SHIFT+B					to BUILD (Compile + Link)
4. Press CTRL+F5						to EXECUTE					*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void main( )
{
	//Variable declaration
	float	 gpaPrev, gpaMSU, gpaTot;
	unsigned short age(0), creditsPrev(0), creditsMSU(0), creditsTot(0), ptsPrev(0), ptsMSU(0), ptsTot(0);

	//Student's information initialization
	string	name=		" ",
			ssn=		" "; 
			
	char	sex=		' ';

	//Explanation
	cout<<endl<<endl;
	cout<<" This program will calculate the transfer GPA, Missouri State University GPA";
	cout<<" and the Cumulative GPA for any given student.";
	cout<<"\n Please fill in the data prompts below to begin calculations:\n";
	cout<<endl;

	//Entering information
	cout<<" The student's personal information:\n";
	cout<<" What is the student's name? (First Last)  ";
		getline(cin, name);
	cout<<" What is the student's social security number? (format XXX-XX-XXXX)  ";
		cin>>ssn;
	cout<<" What is the student's age in years?  ";
		cin>>age;
	cout<<" What is the student's sex? (M or F)  ";
		cin>>sex;
	cout<<endl;
	
	cout<<" How many Credit Hours were transfered from student's previous school?  ";
		cin>>creditsPrev;
	cout<< " How many Quality Points were earned at the previous school?  ";
		cin>>ptsPrev;
	cout<<" How many Credit Hours have been earned at MSU?  ";
		cin>>creditsMSU;
	cout<< " How many Quality Points have been earned at MSU?  ";
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
	cout<<" Name: \t"<<name<<endl;
	cout<<" SSN: \t"<<ssn<<" \t\tAge: \t"<<age<<"yrs \t\tSex: \t"<<sex<<endl;
	cout<<endl;
	cout<<"********************************************************************"<<endl;
	cout<<"   Transfer Hours:      "	<<setw(4)<<creditsPrev;
	cout<<"\t Transfer Quality Points: "<<setw(4)<<ptsPrev<<endl;
	cout<<"   MSU Hours Attempted: "	<<setw(4)<<creditsMSU;
	cout<<"\t MSU Quality Points:      "<<setw(4)<<ptsMSU<<endl;
	cout<<endl;
		cout.precision(2);
	cout<<"   Transfer GPA: "<<setw(6)<<fixed<<gpaPrev<<endl;
	cout<<"   MSU GPA:      "<<setw(6)<<gpaMSU<<endl;
	cout<<"   Overall GPA:  "<<setw(6)<<gpaTot<<endl;
	cout<<"********************************************************************"<<endl;
	cout<<endl;
}