/*=========================================================================================
 PROGRAMMERS:			Yang Wang:	1) designed the attributes of class Record 
									2) designed and implemented functions main(), nextStep()
						Tara Walton	1) designed and implemented displayArecord(), 
										validPersonalInfo(), getName(), getArecord(), 
										computeGPAs(), setDate(), saveArecord(), Record()									
 COURSE:				CSC 125, Homework 13
 MODIFIED BY:			
 LAST MODIFIED DATE:	May 8, 2014
 DESCRIPTION:			This program is to use a class "Record" to process a student's 
						GPAs. It reads info of a student from a text file, calculates 
						his/her three GPAs, displays on screen all read info with the
						GPAs, and also writes them into file "record_of_xxx", where  
						"xxx" is the name of the input file.
 NOTE:					info5.txt and info6.txt created to test errorFlag.
 FILES:					computeGPAs.cpp, hwProject.sln
 COMPILER:				MicroSoft Visual Studio 2012
 INSTRUCTION FOR COMPILATION AND EXECUTION:
	1.		Double click on xxx.sln			to OPEN the project
	2.		Press Ctrl+F7					to COMPILE
	3.		Press Ctrl+Shift+B				to BUILD (COMPILE+LINK)
	4.		Press Ctrl+F5					to EXECUTE
=========================================================================================*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
	using namespace std;

/***********************************************************************************
						Beginning of the class definition  
***********************************************************************************/
class Record
{/************************ Part1: attributes of the class *************************/
private:
	bool			errorFlag;
	string			name;
	unsigned int	ID;
	char			sex;
	unsigned short	age, transHours, msuHours, transPoints, msuPoints, overallHours, overallPoints;
	float			transGPA, msuGPA, overallGPA;

public:
	string processingDate;

 /********************* Part2: member functions of the class **********************/
Record()
	{errorFlag		= false;
	name			= "X";		processingDate	= "X";	sex				= 'X';
	ID				=  0;		age				=  0;
	transHours		=  0;		msuHours		=  0;	overallHours	=  0;
	transPoints		=  0;		msuPoints		=  0;
	transGPA		= -1.0;		msuGPA			= -1.0;	overallGPA		= -1.0;}

void displayArecord()
{	cout<<endl;
	cout<<"Processing Date:  "<<processingDate<<endl;
	cout<<"Error Flag:       "<<boolalpha<<errorFlag<<endl;
	cout<<"********************************************************************"<<endl;
	cout<<" Name: "<<name<<endl;
	cout<<" SSN:  "<<ID<<" \tAge: "<<age<<" yrs \tSex: "<<sex<<endl;
	cout<<"********************************************************************"<<endl;
	cout<<"   Transfer Hours:      "	<<setw(4)<<transHours;
	cout<<"\t Transfer Quality Points: "<<setw(4)<<transPoints<<endl;
	cout<<"   MSU Hours Attempted: "	<<setw(4)<<msuHours;
	cout<<"\t MSU Quality Points:      "<<setw(4)<<msuPoints<<endl;
		cout<<endl;	cout.precision(2); cout<<fixed;
	cout<<"   Transfer GPA: "<<setw(6)<<transGPA<<endl;
	cout<<"   MSU GPA:      "<<setw(6)<<msuGPA<<endl;
	cout<<"   Overall GPA:  "<<setw(6)<<overallGPA<<endl;
	cout<<"********************************************************************"<<endl;
}
private: 
	bool validPersonalInfo()
	{sex = toupper(sex);
		if ((ID<=999999999) && (age<=150) && ((sex=='M'||sex=='F')))
			{ return errorFlag = false; }
		else { return errorFlag = true; }			
	}
public: 
	string getName()
		{ return name;		}
	void getArecord(string & inputFileName);
	void computeGPAs();	
	void saveArecord(string inputFileName);
};
/***********************************************************************************
							End of the class definition
***********************************************************************************/

/***********************************************************************************
						Beginning of the stand-alone Functions
***********************************************************************************/
void nextStep()
{cout<<"\n\n*** Press [Enter] key to continue ***\n\n";
 system("pause");
}
void Record::getArecord(string & inputFileName)
	{string filePath = "C:\\temp\\";
	string skippedWord =" ", firstName = " ", lastName = " ";
	cout<<" Your file must be located in C:\\Temp\\"<<endl;
	cout<<" Please enter the file name:   ";
		cin>>inputFileName;
		ifstream		fin;		/*1 Declare*/ 
		fin.open(filePath + inputFileName);	/*2 Open*/
		if (!fin.is_open())			/*3 Verify*/
			{cout<<"\n*** Error: file \"" <<inputFileName <<"\" failed to open ***\n\n";
			cout<<" 1. Is your file located in the following location:\t\n" <<filePath <<" ?\n";
			cout<<" 2. Do you have a read permission for that file?\n";
			cout<<" Please make necessary corrections, check your spelling carefully, and try again.\n\n";
			exit(0);
			}
		else {						/*4 Read from File*/
			fin>>skippedWord; getline(fin, name);
			fin>>skippedWord>>age;
			fin>>skippedWord>>ID;
			fin>>skippedWord>>sex;
			fin>>skippedWord>>skippedWord>>transHours;
			fin>>skippedWord>>skippedWord>>skippedWord>>transPoints;
			fin>>skippedWord>>skippedWord>>msuHours;
			fin>>skippedWord>>skippedWord>>skippedWord>>msuPoints;
			}
		validPersonalInfo();
		fin.close();
		}
void Record::computeGPAs()
{overallHours		= transHours + msuHours;
 overallPoints		= transPoints + msuPoints;
/*FOUR SCENARIOS:	1) pts==hrs==0		:yields a zero gpa
					2) pts>0 && hrs>0	:do arithmetic
					3) pts==0, hrs>0	:yields a zero gpa
					4) pts>0, hrs==0	:dividing by 0 should yield -1 for that gpa and overallGPA*/
/*1*/	if ((transPoints==0) && (transHours==0))								
		{transGPA =	0;
			if ((msuPoints==0) && (msuHours==0))//1				
				{msuGPA = 0;
				 overallGPA = float(overallPoints)/overallHours;}
				else if ((0<msuPoints && msuPoints<=999) && (0<msuHours && msuHours<=999))//2
						{msuGPA = float(msuPoints)/msuHours;
						 overallGPA = float(overallPoints)/overallHours;}
						else if ((msuPoints==0) && (0<msuHours && msuHours<=999))//3
								{msuGPA = float(msuPoints)/msuHours;
								 overallGPA = float(overallPoints)/overallHours;}
								else if ((msuPoints!= 0) && (msuHours==0))//4						
										{msuGPA =	-1;	
										overallGPA =	-1;
										errorFlag = true;}							}
/*2*/	else if ((0<transPoints && transPoints<=999) && (0<transHours && transHours<=999))	
		{transGPA =	float(transPoints)/transHours;
			if ((msuPoints==0) && (msuHours==0))//1				
				{msuGPA = 0;
				 overallGPA = float(overallPoints)/overallHours;}
				else if ((0<msuPoints && msuPoints<=999) && (0<msuHours && msuHours<=999))//2
						{msuGPA = float(msuPoints)/msuHours;
						 overallGPA = float(overallPoints)/overallHours;}
						else if ((msuPoints==0) && (0<msuHours && msuHours<=999))//3
								{msuGPA = float(msuPoints)/msuHours;
								 overallGPA = float(overallPoints)/overallHours;}
								else if ((msuPoints!= 0) && (msuHours==0))//4						
										{msuGPA =	-1;	
										overallGPA =	-1;
										errorFlag = true;}							}
/*3*/	else if ((transPoints==0) && (0<transHours && transHours<=999))
		{transGPA = float(transPoints)/transHours;
			if ((msuPoints==0) && (msuHours==0))//1				
				{msuGPA = 0;
				 overallGPA = float(overallPoints)/overallHours;}
				else if ((0<msuPoints && msuPoints<=999) && (0<msuHours && msuHours<=999))//2
						{msuGPA = float(msuPoints)/msuHours;
						 overallGPA = float(overallPoints)/overallHours;}
						else if ((msuPoints==0) && (0<msuHours && msuHours<=999))//3
								{msuGPA = float(msuPoints)/msuHours;
								 overallGPA = float(overallPoints)/overallHours;}
								else if ((msuPoints!= 0) && (msuHours==0))//4						
										{msuGPA =	-1;	
										overallGPA =	-1;
										errorFlag = true;}							}
/*4*/	else if ((transPoints!= 0) && (transHours==0))
		{transGPA = -1;
		if ((msuPoints==0) && (msuHours==0))//1				
			{msuGPA = 0;}	
			else if ((0<msuPoints && msuPoints<=999) && (0<msuHours && msuHours<=999))//2
					{msuGPA = float(msuPoints)/msuHours;}
					else if ((msuPoints==0) && (0<msuHours && msuHours<=999))//3
							{msuGPA = float(msuPoints)/msuHours;}
							else if ((msuPoints!= 0) && (msuHours==0))//4						
							{msuGPA =	-1;
							errorFlag = true;}
		overallGPA =	-1;		//always set overallGPA as
		errorFlag = true;} 
}
void setDate(Record & aStudent)
{cout<<"Please enter the processing date for this file (mm//dd//yy):  ";
	cin>>aStudent.processingDate;
}
void Record::saveArecord(string fileInfo)
		{ofstream	fout;			/*1 Declare*/
		fout.open(fileInfo);		/*2 Open*/
		if (!fout.is_open())		/*3 Verify*/
			{cout<<"\n*** Error: file \"" <<fileInfo <<"\" failed to open ***\n\n";
			cout<<" 1. Do you have permission to write to the following location:  C:\\Temp\\?\n";
			cout<<" 2. Do you have permission to write to the file "<<fileInfo<<" ?\n";
			cout<<" Please make necessary corrections and try again.\n\n";
			exit(0);
			}
		else { /*4 Write to File*/
			fout<<"Processing Date:  "<<processingDate<<endl;
			fout<<"Error Flag:       "<<boolalpha<<errorFlag<<endl;
			fout<<"********************************************************************"<<endl;
			fout<<" Name: "<<name<<endl;
			fout<<" SSN:  "<<ID<<" \tAge: "<<age<<" yrs \tSex: "<<sex<<endl;
			fout<<"********************************************************************"<<endl;
			fout<<"   Transfer Hours:      "	<<setw(4)<<transHours;
			fout<<"\t Transfer Quality Points: "<<setw(4)<<transPoints<<endl;
			fout<<"   MSU Hours Attempted: "	<<setw(4)<<msuHours;
			fout<<"\t MSU Quality Points:      "<<setw(4)<<msuPoints<<endl;
				fout<<endl;	cout.precision(2); cout<<fixed;
			fout<<"   Transfer GPA: "<<setw(6)<<transGPA<<endl;
			fout<<"   MSU GPA:      "<<setw(6)<<msuGPA<<endl;
			fout<<"   Overall GPA:  "<<setw(6)<<overallGPA<<endl;
			fout<<"********************************************************************"<<endl;
			}
	fout.close();
}
//***********************************************************************************
int main()
{Record	aStudent;
 string inputFileName;

 // Step 1.
 {
  cout<<"\n=====================================================================\n"
	  <<"        Step 1.  The initial contents of the record are                  "
	  <<"\n=====================================================================\n";
  aStudent.displayArecord();
  nextStep();
 }

 // Step 2.
 {
  aStudent.getArecord(inputFileName);	// input a student's info from a file
  cout <<"\n=====================================================================\n"
	   <<" Step 2. " <<aStudent.getName( ) << "'s record BEFORE GPA calculation is"
       <<"\n=====================================================================\n";
  aStudent.displayArecord();
  nextStep();
 }

 // Step 3.
 {
  aStudent.computeGPAs();
  cout <<"\n=====================================================================\n"
	   << "Step 3. " <<aStudent.getName( ) << "'s record AFTER GPA calculation is"
       <<"\n=====================================================================\n";
  aStudent.displayArecord();
  nextStep();
 }

 // Step 4.
 {
  setDate(aStudent);
  cout <<"\n=====================================================================\n"
	   <<"   Step 4. " <<aStudent.getName( ) <<"'s full record is"
       <<"\n=====================================================================\n";
  aStudent.displayArecord();
  nextStep();
 }

 // Step 5.
 {
  string fileInfo = "C:\\TEMP\\record_of_" + inputFileName;
  aStudent.saveArecord(fileInfo);
  cout <<"\n=====================================================================\n"
	   << "Step 5. All info about " <<aStudent.getName( )
	   << "  has been written into text file: \n\n\t" <<fileInfo
       <<"\n=====================================================================\n";
 }
return 0;
}