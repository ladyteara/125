/*===================================================================================
 PROGRAMMER:			Tara Walton, Tara1984
 COURSE:				CSC 125.001
 MODIFIED BY:			N/A
 LAST MODIFIED DATE:	March 22, 2014
 DESCRIPTION:			Read from and write data items into a text file with specified format
 NOTE:					info1.txt, info2.txt, info3.txt are located in the hw 7 folder on eccentric for trouble shooting purposes
 FILES:					hw7.cpp, info1.txt, info2.txt, info3.txt
 IDE/COMPILER:			MicroSoft Visual Studio 2012
 INSTRUCTION FOR COMPILATION AND EXECUTION:
	1.		Double click on hwProj.sln		to OPEN the project
	2.		Press Ctrl+F7					to COMPILE
	3.		Press Ctrl+Shift+B				to BUILD (COMPILE+LINK)
	4.		Press Ctrl+F5					to EXECUTE
===================================================================================*/

#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<cassert>

using namespace std;

void main( )
{	//Variable declaration
	float			gpaPrev, gpaMSU, gpaTot;
	unsigned short	age(0), creditsPrev(0), creditsMSU(0), creditsTot(0), ptsPrev(0), ptsMSU(0), ptsTot(0);
	string			skippedLine, skippedWord;					//For skipping data read from file
	char			skippedChar	= ' ';							//For skipping data read from file
			//Student's information initialization
	string	firstName	= " ",
			lastName	= " ",
			name		= " ",
			ssn			= " "; 
	char	sex			= ' ';
		//File information
	string			filePath	= "C:\\Temp\\",
					fileName	= " ",
					fileIn		= " ",
					fileOut		= " ";

	//Explanation Display, file entry
	cout<<endl<<endl;
	cout<<" This program will calculate the transfer GPA, Missouri State University GPA";
	cout<<" and the Cumulative GPA for any given student."<<endl;
	cout<<" Your file must be located in C:\\Temp\\"<<endl;
	cout<<" Please enter one of the file name:   ";
		cin>>fileName;

	fileIn  = filePath + fileName;
	fileOut = "record_of_" + fileName;
		//Reading from file
			//1 Declare
		ifstream		fin;
			//2 Open
		fin.open(fileIn);
			//3 Verify
		assert(fin.is_open());
			//4 Read from File
		fin>>skippedWord>>firstName>>lastName;
		fin>>skippedWord>>age;
		fin>>skippedWord>>ssn;
		fin>>skippedWord>>sex;
		fin>>skippedWord>>skippedWord>>creditsPrev;
		fin>>skippedWord>>skippedWord>>skippedWord>>ptsPrev;
		fin>>skippedWord>>skippedWord>>creditsMSU;
		fin>>skippedWord>>skippedWord>>skippedWord>>ptsMSU;
	
	//Calculations 
	gpaPrev=		ptsPrev/float(creditsPrev);
	gpaMSU=			ptsMSU/float(creditsMSU);
		//Cumulative calculations
	creditsTot=		creditsPrev + creditsMSU;
	ptsTot=			ptsPrev+ptsMSU;
	gpaTot=			ptsTot/float(creditsTot);
		//Concatonation
	name		= firstName + " " + lastName;
	
		//Writing to File
			//1 Declare
		ofstream		fout;
			//2 Open
		fout.open(filePath + fileOut);	
			//3 Verify
		assert(fout.is_open());	
			//4 Write to File
		fout<<endl<<endl;
		fout<<"********************************************************************"<<endl;
		fout<<" Name: \t"<<name<<endl;
		fout<<" SSN: \t"<<ssn<<" \t\tAge: \t"<<age<<" yrs \t\tSex: \t"<<sex<<endl;
		fout<<endl;
		fout<<"********************************************************************"<<endl;
		fout<<"   Transfer Hours:      "	<<setw(4)<<creditsPrev;
		fout<<"\t Transfer Quality Points: "<<setw(4)<<ptsPrev<<endl;
		fout<<"   MSU Hours Attempted: "	<<setw(4)<<creditsMSU;
		fout<<"\t MSU Quality Points:      "<<setw(4)<<ptsMSU<<endl;
		fout<<endl;
			fout.precision(2);
		fout<<"   Transfer GPA: "<<setw(6)<<fixed<<gpaPrev<<endl;
		fout<<"   MSU GPA:      "<<setw(6)<<gpaMSU<<endl;
		fout<<"   Overall GPA:  "<<setw(6)<<gpaTot<<endl;
		fout<<"********************************************************************"<<endl;
		fout<<endl;
	
		//5 Close file
	fout.close();
	fin.close();
	
	//Display entered information with calculations
	cout<<endl<<endl;
	cout<<"********************************************************************"<<endl;
	cout<<" Name: \t"<<name<<endl;
	cout<<" SSN: \t"<<ssn<<" \t\tAge: \t"<<age<<" yrs \t\tSex: \t"<<sex<<endl;
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
	cout<<" A file containing this information has been created."; 
	cout<<" To review see "<<filePath<<fileOut<<endl<<endl;
	
}