/*==========================================================================================
 PROGRAMMER:			Tara Walton, Tara1984
 COURSE:				CSC 125.001, Homework Assignment 9
 MODIFIED BY:			N/A
 LAST MODIFIED DATE:	April 22, 2014
 DESCRIPTION:			Read from and write data items into a text file with specified format
 NOTE:					info1.txt, info2.txt, info3.txt are located in the hw9 folder on 
						eccentric for trouble shooting purposes
 FILES:					hw9.cpp, info1.txt, info2.txt, info3.txt, info4.txt
 IDE/COMPILER:			MicroSoft Visual Studio 2012
 INSTRUCTION FOR COMPILATION AND EXECUTION:
	1.		Double click on hwProj.sln		to OPEN the project
	2.		Press Ctrl+F7					to COMPILE
	3.		Press Ctrl+Shift+B				to BUILD (COMPILE+LINK)
	4.		Press Ctrl+F5					to EXECUTE
==========================================================================================*/

#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
	using namespace std;

void main( )
{	//Variable declaration
	float			gpaPrev(0), gpaMSU(0), gpaTot(0);
	unsigned short	age(0), hrsPrev(0), hrsMSU(0), hrsTot(0), ptsPrev(0), ptsMSU(0), ptsTot(0);
	string			skippedLine, skippedWord;					//For skipping data read from file
	char			skippedChar	= ' ';							//For skipping data read from file
			//Student's information initialization
	string	firstName	= " ",
			lastName	= " ",
			name		= " ",
			ssn			= " "; 
	char	sex			= ' ';
			//File information
	string	/*filePath	= "H:\\CSC125\\HW7\\",  //at home*/
		    filePath    = "C:\\Temp\\",         //turn in
			fileName	= " ",
			fileIn		= " ",
			fileOut		= " ";

	//Explanation Display, file entry
	cout<<endl<<endl;
	cout<<" This program will calculate the transfer GPA, Missouri State University GPA";
	cout<<" and the Cumulative GPA for any given student."<<endl;
	cout<<" Your file must be located in C:\\Temp\\"<<endl;
	cout<<" Please enter the file name:   ";
		cin>>fileName;

	fileIn  = filePath + fileName;
	fileOut = "record_of_" + fileName;
		//Reading from file
			//1 Declare
		ifstream		fin;
			//2 Open
		fin.open(fileIn);
			//3 Verify
		if (!fin.is_open())
		{cout<<"\n*** Error: file \"" <<fileName <<"\" failed to open ***\n\n";
		cout<<" 1. Is your file located in the following location:\t\n" <<filePath <<" ?\n";
		cout<<" 2. Do you have a read permission for that file?\n";
		cout<<" Please make necessary corrections, check your spelling carefully, and try again.\n\n";
		exit(0);
		}
			//4 Read from File
		else {
		fin>>skippedWord>>firstName>>lastName;
		fin>>skippedWord>>age;
		fin>>skippedWord>>ssn;
		fin>>skippedWord>>sex;
		fin>>skippedWord>>skippedWord>>hrsPrev;
		fin>>skippedWord>>skippedWord>>skippedWord>>ptsPrev;
		fin>>skippedWord>>skippedWord>>hrsMSU;
		fin>>skippedWord>>skippedWord>>skippedWord>>ptsMSU;
		}
		//Cumulative calculations
	hrsTot		= hrsPrev + hrsMSU;
	ptsTot		= ptsPrev + ptsMSU;
	name		= firstName + " " + lastName;				//Concatonation
	ssn			= ssn.insert(3, 1, '-');							//xxx-xxxxxx
		ssn		= ssn.insert(6, 1, '-');							//xxx-xx-xxxx

	//Validation of read integers
/*FOUR SCENARIOS:	1) pts==hrs==0		:yields a zero gpa
					2) pts>0 && hrs>0	:do arithmetic
					3) pts==0, hrs>0	:yields a zero gpa
					4) pts>0, hrs==0	:dividing by zero should yield -1 for that gpa and gpaTot*/
/*1*/	if ((ptsPrev==0) && (hrsPrev==0))								
		{gpaPrev =	0;
			if ((ptsMSU==0) && (hrsMSU==0))//1				
				{gpaMSU = 0;
				 gpaTot = float(ptsTot)/hrsTot;}
				else if ((0<ptsMSU && ptsMSU<=999) && (0<hrsMSU && hrsMSU<=999))//2
						{gpaMSU = float(ptsMSU)/hrsMSU;
						 gpaTot = float(ptsTot)/hrsTot;}
						else if ((ptsMSU==0) && (0<hrsMSU && hrsMSU<=999))//3
								{gpaMSU = float(ptsMSU)/hrsMSU;
								 gpaTot = float(ptsTot)/hrsTot;}
								else if ((ptsMSU!= 0) && (hrsMSU==0))//4						
										{gpaMSU =	-1;	
										gpaTot =	-1;}
		}
/*2*/	else if ((0<ptsPrev && ptsPrev<=999) && (0<hrsPrev && hrsPrev<=999))	
		{gpaPrev =	float(ptsPrev)/hrsPrev;
			if ((ptsMSU==0) && (hrsMSU==0))//1				
				{gpaMSU = 0;
				 gpaTot = float(ptsTot)/hrsTot;}
				else if ((0<ptsMSU && ptsMSU<=999) && (0<hrsMSU && hrsMSU<=999))//2
						{gpaMSU = float(ptsMSU)/hrsMSU;
						 gpaTot = float(ptsTot)/hrsTot;}
						else if ((ptsMSU==0) && (0<hrsMSU && hrsMSU<=999))//3
								{gpaMSU = float(ptsMSU)/hrsMSU;
								 gpaTot = float(ptsTot)/hrsTot;}
								else if ((ptsMSU!= 0) && (hrsMSU==0))//4						
										{gpaMSU =	-1;	
										gpaTot =	-1;}	
		}
/*3*/	else if ((ptsPrev==0) && (0<hrsPrev && hrsPrev<=999))
		{gpaPrev = float(ptsPrev)/hrsPrev;
			if ((ptsMSU==0) && (hrsMSU==0))//1				
				{gpaMSU = 0;
				 gpaTot = float(ptsTot)/hrsTot;}
				else if ((0<ptsMSU && ptsMSU<=999) && (0<hrsMSU && hrsMSU<=999))//2
						{gpaMSU = float(ptsMSU)/hrsMSU;
						 gpaTot = float(ptsTot)/hrsTot;}
						else if ((ptsMSU==0) && (0<hrsMSU && hrsMSU<=999))//3
								{gpaMSU = float(ptsMSU)/hrsMSU;
								 gpaTot = float(ptsTot)/hrsTot;}
								else if ((ptsMSU!= 0) && (hrsMSU==0))//4						
										{gpaMSU =	-1;	
										gpaTot =	-1;}
		}
/*4*/	else if ((ptsPrev!= 0) && (hrsPrev==0))
		{gpaPrev = -1;
		if ((ptsMSU==0) && (hrsMSU==0))//1				
			{gpaMSU = 0;}	
			else if ((0<ptsMSU && ptsMSU<=999) && (0<hrsMSU && hrsMSU<=999))//2
					{gpaMSU = float(ptsMSU)/hrsMSU;}
					else if ((ptsMSU==0) && (0<hrsMSU && hrsMSU<=999))//3
							{gpaMSU = float(ptsMSU)/hrsMSU;}
							else if ((ptsMSU!= 0) && (hrsMSU==0))//4						
							{gpaMSU =	-1;}
		gpaTot =	-1;} //always set gpaTot as

//Writing to File
			//1 Declare
		ofstream		fout;
			//2 Open
		fout.open(filePath + fileOut);	
			//3 Verify
		if (!fout.is_open())
		{cout<<"\n*** Error: file \"" <<fileOut <<"\" failed to open ***\n\n";
		cout<<" 1. Do you have permission to write to the following location:\t\n" <<filePath <<" ?\n";
		cout<<" 2. Do you have permission to write to the file "<<fileOut<<" ?\n";
		cout<<" Please make necessary corrections and try again.\n\n";
		exit(0);
		}
			//4 Write to File
		else {
		fout<<endl<<endl;
		fout<<"********************************************************************"<<endl;
		fout<<" Name: \t"<<name<<endl;
		fout<<" SSN: \t"<<ssn<<" \t\tAge: \t"<<age<<" yrs \t\tSex: \t"<<sex<<endl;
		fout<<endl;
		fout<<"********************************************************************"<<endl;
		fout<<"   Transfer Hours:      "	<<setw(4)<<hrsPrev;
		fout<<"\t Transfer Quality Points: "<<setw(4)<<ptsPrev<<endl;
		fout<<"   MSU Hours Attempted: "	<<setw(4)<<hrsMSU;
		fout<<"\t MSU Quality Points:      "<<setw(4)<<ptsMSU<<endl;
		fout<<endl;
			fout.precision(2);
		fout<<"   Transfer GPA: "<<setw(6)<<fixed<<gpaPrev<<endl;
		fout<<"   MSU GPA:      "<<setw(6)<<gpaMSU<<endl;
		fout<<"   Overall GPA:  "<<setw(6)<<gpaTot<<endl;
		fout<<"********************************************************************"<<endl;
		fout<<endl;
		}
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
	cout<<"   Transfer Hours:      "	<<setw(4)<<hrsPrev;
	cout<<"\t Transfer Quality Points: "<<setw(4)<<ptsPrev<<endl;
	cout<<"   MSU Hours Attempted: "	<<setw(4)<<hrsMSU;
	cout<<"\t MSU Quality Points:      "<<setw(4)<<ptsMSU<<endl;
	cout<<endl;
		cout.precision(2);
	cout<<"   Transfer GPA: "<<setw(6)<<fixed<<gpaPrev<<endl;
	cout<<"   MSU GPA:      "<<setw(6)<<gpaMSU<<endl;
	cout<<"   Overall GPA:  "<<setw(6)<<gpaTot<<endl;
	cout<<"********************************************************************"<<endl;
	cout<<endl;
	cout<<" A file containing this information has been created.\n"; 
	cout<<" To review see "<<filePath<<fileOut<<endl<<endl;
}