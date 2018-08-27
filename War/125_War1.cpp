/* COURSE:							CSC 125.001, HW Assignment 3
PROGRAMMER:							Tara Walton, Tara1984
MODIFIED BY:
LAST MODIFIED:						February 26, 2014
DESCRIPTION:						Extended ASCII projection of a hand of WAR
NOTES:
FILES:								hw3.cpp
IDE/COMPILER:						Visual Studio Professional 2012
		INSTRUCTIONS FOR COMPLIATION AND EXECUTION:
1. Double Click on hwProect.sln		to OPEN project
2. Press CTRL+F7					to COMPILE
3. Press CTRL+SHIFT+B				to BUILD (Compile + Link)
4. Press CTRL+F5					to EXECUTE				*/

#include<iostream>
using namespace std;

void main( )
{
//Declare variables
char	heart=' ', club=' ', 
		vertEdge='   ', horEdge='   ', tlEdge='   ', trEdge='   ', blEdge='   ', brEdge='   ',  
		vertDbl='   ', horDbl='   ', tlDbl='   ', trDbl='   ', blDbl='   ', brDbl='   ';

//Assign ASCII OEM variables
heart		=3;
club		=5;
vertEdge	=179;
horEdge		=196;
tlEdge		=218;
trEdge		=191;
blEdge		=192;
brEdge		=217;
vertDbl		=186;
horDbl		=205;
tlDbl		=201;
trDbl		=187;
blDbl		=200;
brDbl		=188;

//Output Design
cout <<"\n \n \t \t     " <<tlDbl<<horDbl<<horDbl<<horDbl<<horDbl<<horDbl<<horDbl<<horDbl<<horDbl<<horDbl<<horDbl<<horDbl<<horDbl;
	cout<<horDbl<<horDbl<<horDbl<<horDbl<<horDbl<<horDbl<<horDbl<<horDbl<<horDbl<<horDbl<<trDbl<<endl;
cout <<"\t \t     " <<vertDbl<<" The card game: \"WAR\" " <<vertDbl<<endl;
cout <<"\t \t     " <<blDbl<<horDbl<<horDbl<<horDbl<<horDbl<<horDbl<<horDbl<<horDbl<<horDbl<<horDbl<<horDbl<<horDbl<<horDbl<<horDbl;
	cout<<horDbl<<horDbl<<horDbl<<horDbl<<horDbl<<horDbl<<horDbl<<horDbl<<horDbl<<brDbl<<endl;
cout <<endl <<endl;
cout <<"\t \t"<<tlEdge<<horEdge<<horEdge<<horEdge<<horEdge<<horEdge<<horEdge<<horEdge<<horEdge<<horEdge<<trEdge<<"\t \t";
	cout<<tlEdge<<horEdge<<horEdge<<horEdge<<horEdge<<horEdge<<horEdge<<horEdge<<horEdge<<horEdge<<trEdge<<endl;
cout <<"\t \t"<<vertEdge<<" 5       "<<vertEdge<<"\t \t"<<vertEdge<<" 10      "<<vertEdge<<endl;
cout <<"\t \t"<<vertEdge<<"         "<<vertEdge<<"\t \t"<<vertEdge<<"         "<<vertEdge<<endl;
cout <<"\t \t"<<vertEdge<<"         "<<vertEdge<<"\t \t"<<vertEdge<<"         "<<vertEdge<<endl;
cout <<"\t \t"<<vertEdge<<"         "<<vertEdge<<"\t \t"<<vertEdge<<"         "<<vertEdge<<endl;
cout <<"\t \t"<<vertEdge <<"    "<<heart<<"    "<<vertEdge<<"\t \t"<<vertEdge<<"    "<<club<<"    "<<vertEdge<<endl;
cout <<"\t \t"<<vertEdge<<"         "<<vertEdge<<"\t \t"<<vertEdge<<"         "<<vertEdge<<endl;
cout <<"\t \t"<<vertEdge<<"         "<<vertEdge<<"\t \t"<<vertEdge<<"         "<<vertEdge<<endl;
cout <<"\t \t"<<vertEdge<<"         "<<vertEdge<<"\t \t"<<vertEdge<<"         "<<vertEdge<<endl;
cout <<"\t \t"<<vertEdge<<"       5 "<<vertEdge<<"\t \t"<<vertEdge<<"      10 "<<vertEdge<<endl;
cout <<"\t \t"<<blEdge<<horEdge<<horEdge<<horEdge<<horEdge<<horEdge<<horEdge<<horEdge<<horEdge<<horEdge<<brEdge<<"\t \t";
	cout<<blEdge<<horEdge<<horEdge<<horEdge<<horEdge<<horEdge<<horEdge<<horEdge<<horEdge<<horEdge<<brEdge;
cout <<endl <<endl;
}