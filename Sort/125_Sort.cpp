/*==========================================================================================
 PROGRAMMER:			Tara Walton, Tara1984
 COURSE:				CSC 125.001, Homework Assignment 11
 MODIFIED BY:			N/A
 LAST MODIFIED DATE:	April 15, 2014
 DESCRIPTION:			Read from a file and determine highest and lowest number
 NOTE:										
 FILES:					hw11.cpp, data0.txt, data1.txt, data2.txt, data3.txt, data4.txt, 
						data5.txt
 IDE/COMPILER:			MicroSoft Visual Studio 2012
 INSTRUCTION FOR COMPILATION AND EXECUTION:
	1.		Double click on hwProj.sln		to OPEN the project
	2.		Press Ctrl+F7					to COMPILE
	3.		Press Ctrl+Shift+B				to BUILD (COMPILE+LINK)
	4.		Press Ctrl+F5					to EXECUTE
==========================================================================================*/

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
	using namespace std;

void main()
{
float		flt(0),			//float number read from file
			maxVal(0),		//maximum Value 
			minVal(0),		//minimum Value 
			temp(0);		//buffer for comparison of min and max
short		count(0);		//first number in file giving count of numbers
string		fileName = " ",
			filePath = "C:\\Users\\Kitty\\Desktop\\CSC125\\hw11\\",		//home
			//filePath = "C:\\temp\\",									//turn in
			fileIn	 = " ";
ifstream	fin;

// 1. Input the file name
cout<<endl<<endl;
cout<<"Your file should be stored at the following location:"<<endl;
cout<<"\t\t"<<filePath<<endl;
cout<<"Please enter the name of the file you would like to work with:  ";
cin>>fileName;
cout<<endl;

			fileIn = filePath + fileName;

// 2. Open the input file and verify
fin.open(fileIn);
if (!fin.is_open())
{cout<<"\n*** Error: file \"" <<fileName <<"\" failed to open for input. ***\n\n"
      <<" 1. Does the file exist in the folder:\n\t" <<filePath<<" ?\n"
	  <<" 2. Do you have a read permission for that file?\n"
	  <<" 3. Otherwise, check your spelling carefully, and please try again.\n\n";
exit(0);
}
// 3. Read file, compute, display
fin>>count;		cout<<"This file contains "<<count<<" number(s).\n";
	if (count==0)										//if there are no numbers
		cout<<"\nThere are no numbers to list.\n";
		else {cout<<"They are listed below: \n";		//if there is at least 1
			for (int n=count, i=1; n>0; --n, ++i)
				{fin>>flt;	cout<<setw(2)<<i<<setw(3)<<")  "<<flt<<endl;
				if (i==1)								//first number read
				{	maxVal = flt;							//initialize max as first #
					minVal = flt;							//initialize min as first #
				}
				else {	if (flt > maxVal)				//if next # higher than max
							maxVal = flt;					//set as max
						if (flt < minVal)				//if next # lower than min
							minVal = flt;					//set as min

						if (maxVal < minVal)			//if max less than min, swap
							{temp  = maxVal;
							maxVal = minVal;
							minVal = temp;}
					}
				}	
		cout<<endl;
		cout<<"The minimum value in the list is: "<<right<<setw(6)<<minVal<<endl;
		cout<<"The maximum value in the list is: "<<right<<setw(6)<<maxVal<<endl;
			}
fin.close();
cout<<endl;
}