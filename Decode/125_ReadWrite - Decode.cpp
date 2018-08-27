/*==========================================================================================
 PROGRAMMER:			Tara Walton, Tara1984
 COURSE:				CSC 125.001, Homework Assignment 10
 MODIFIED BY:			N/A
 LAST MODIFIED DATE:	April 7, 2014
 DESCRIPTION:			Read from a coded file and write decoded data into a text file 
 NOTE:					lines that don't contain target string cause abort failure					
 FILES:					hw10.cpp, jokesCoded.txt, welcomeCoded.txt, limerick1.txt, .txt
 IDE/COMPILER:			MicroSoft Visual Studio 2012
 INSTRUCTION FOR COMPILATION AND EXECUTION:
	1.		Double click on hwProj.sln		to OPEN the project
	2.		Press Ctrl+F7					to COMPILE
	3.		Press Ctrl+Shift+B				to BUILD (COMPILE+LINK)
	4.		Press Ctrl+F5					to EXECUTE
==========================================================================================*/

#include<iostream>
#include<string>
#include<fstream>
	using namespace std;

void main()
{
//Variable declaration
	string	line1, line2, line3, line4, line5,
			target = " ", key = " ",
			fileName = " ",
			filePath = "C:\\Users\\Kitty\\Desktop\\CSC125\\hw10\\",
			fileIn,
			fileOut;
	ifstream fin;
	ofstream fout;

// 1. Input the file name
cout<<"Your file should be stored at the following location:"<<endl;
cout<<"\t\t"<<filePath<<endl;
cout<<"Please enter the name of the file you would like decoded:";
cin>>fileName;
cout<<"Please enter the target string:";
cin>>target;
cout<<"Please enter the key string:";
cin>>key;

fileIn = filePath + fileName;

// 2. Open the input file and verify
fin.open(fileIn);
if (!fin.is_open())
{cout<<"\n*** Error: file \"" <<fileName <<"\" failed to open for input. ***\n\n"
      <<" 1. Does the file exist in the folder:\n\t" <<filePath<<" ?\n"
	  <<" 2. Do you have a read premission for that file?\n"
	  <<" 3. Otherwise, check your spelling carefully, and try again.\n\n";
exit(0);
}

// 3. Read file
getline(fin, line1); 
getline(fin, line2);  
getline(fin, line3);
getline(fin, line4);
getline(fin, line5);

// 4. Display original
cout<<endl<<endl;
cout<<"The original file reads: \n";
cout<<endl;
cout<<"*+-+*+-+*+-+*+-+*+-+*+-+*+-+*+-+*+-+*+-+*+-+*+-+*+-+*+-+*+-+*+-+*+-+*"<<endl;
cout<<line1<<endl;
cout<<line2<<endl;
cout<<line3<<endl;
cout<<line4<<endl;
cout<<line5<<endl;
cout<<"*+-+*+-+*+-+*+-+*+-+*+-+*+-+*+-+*+-+*+-+*+-+*+-+*+-+*+-+*+-+*+-+*+-+*"<<endl;
cout<<endl;

// 5. Decode
if (line1.find(target)>=0)										//If target is found,
	line1.replace(line1.find(target), target.length( ), key);	//replace in line 1 "target", "length", with "key"
if (line2.find(target)>=0)
	line2.replace(line2.find(target), target.length( ), key);
if (line3.find(target)>=0)
	line3.replace(line3.find(target), target.length( ), key);
if (line3.find(target)>=0)
	line4.replace(line4.find(target), target.length( ), key);
if (line4.find(target)>=0)
	line5.replace(line5.find(target), target.length( ), key);

//target.swap(key);

// 6. Open output file and verify

fileOut = fileIn.replace((fileIn.find("Coded.txt")), 9, "Decoded.txt");

fout.open(fileOut);
if (!fout.is_open())
{cout<<"\n*** Error: file \"" <<fileOut<<"\" failed to open for input. ***\n\n"
	<<" 1. Do you have write permission in the folder:\n\t" <<filePath<<" ?\n"
	<<" 2. Do you have write premission for that file?\n";
exit(0);
}

// 7. Display and write to output file
cout<<endl<<endl;
cout<<"The decoded file reads: \n";
cout<<endl;
cout<<"*+-+*+-+*+-+*+-+*+-+*+-+*+-+*+-+*+-+*+-+*+-+*+-+*+-+*+-+*+-+*+-+*+-+*"<<endl;
cout<<line1<<endl;
	fout<<line1<<endl;
cout<<line2<<endl;
	fout<<line2<<endl;
cout<<line3<<endl;
	fout<<line3<<endl;
cout<<line4<<endl;
	fout<<line4<<endl;
cout<<line5<<endl;
	fout<<line5<<endl;
cout<<"*+-+*+-+*+-+*+-+*+-+*+-+*+-+*+-+*+-+*+-+*+-+*+-+*+-+*+-+*+-+*+-+*+-+*"<<endl;
cout<<endl;
cout<<"A copy of this file can be found at: \n";
cout<<fileOut;
cout<<endl<<endl;

// 8. Close files
fin.close();
fout.close();
}