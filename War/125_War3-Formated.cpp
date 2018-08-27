/* COURSE:							CSC 125.001, HW Assignment 8
PROGRAMMER:							Tara Walton, Tara1984
LAST MODIFIED:						March 25, 2014
DESCRIPTION:						Extended ASCII projection of a RANDOM hand of WAR
NOTES:								
FILES:								hw6.cpp
IDE/COMPILER:						Visual Studio Professional 2012
		INSTRUCTIONS FOR COMPLIATION AND EXECUTION:
1. Double Click on hwProject.sln	to OPEN project
2. Press CTRL+F7					to COMPILE
3. Press CTRL+SHIFT+B				to BUILD (Compile + Link)
4. Press CTRL+F5					to EXECUTE				*/

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<iomanip>
#include<string>
using namespace std;

void main( )
{
//Declare variables
char	heart=' ', diamond=' ', club=' ', spade=' ', space=' ',
		vEdge=' ', hEdge=' ', tlEdge=' ', trEdge=' ', blEdge=' ', brEdge=' ',  
		vDbl=' ', hDbl=' ', tlDbl=' ', trDbl=' ', blDbl=' ', brDbl=' ';
char	suit1=' ', suit2=' ';
unsigned short		value1=' ', value2=' ';
string	val1=" ", val2=" ";

srand(time(0));
suit1	=rand() % 4 + 3;		//{3, 4, 5, 6}
suit2	=rand() % 4 + 3;		//{3, 4, 5, 6}
value1	=rand() %12 + 2;		//{2-14}
value2	=rand() %12 + 2;		//{2-14}

//52 cards, no two alike
if ((value1==value2) && (suit1==suit2)) //If value1 = value2 and suit1 = suit2 (ie, same card)
	if (suit2<=5) 
		suit2 += 1;						//then if suit2 <=5, add 1 to suit2
	else if (suit2=6) 
		suit2 = 3;						//otherwise if (suit2 = 6), assign 3 to suit2

////replacing card values with 2-10, J, Q, K, A
//if (value1<11)
//	val1 = value1;
//	else if (value1==11)
//		val1= 'J';
//	else if (value1==12)
//		val1= 'Q';
//	else if (value1==13)
//		val1= 'K';
//	else if (value1==14)
//		val1= 'A';

switch (value1)
	{
	case 1:		val1="1";
	break;
	case 2:		val1="2";
	break;
	case 3:		val1="3";
	break;
	case 4:		val1="4";
	break;
	case 5:		val1="5";
	break;
	case 6:		val1="6";
	break;
	case 7:		val1="7";
	break;
	case 8:		val1="8";
	break;
	case 9:		val1="9";
	break;
	case 10:	val1="10";
	break;
	case 11:	val1="J";
	break;
	case 12:	val1="Q";
	break;
	case 13:	val1="K";
	break;
	case 14:	val1="A";
	break;          
	}
switch (value2)
	{
	case 1:		val2="1";
	break;
	case 2:		val2="2";
	break;
	case 3:		val2="3";
	break;
	case 4:		val2="4";
	break;
	case 5:		val2="5";
	break;
	case 6:		val2="6";
	break;
	case 7:		val2="7";
	break;
	case 8:		val2="8";
	break;
	case 9:		val2="9";
	break;
	case 10:	val2="10";
	break;
	case 11:	val2="J";
	break;
	case 12:	val2="Q";
	break;
	case 13:	val2="K";
	break;
	case 14:	val2="A";
	break;          
	}
//Assign ASCII OEM variables
heart		=3;
diamond		=4;
club		=5;
spade		=6;
vEdge		=179;
hEdge		=196;
tlEdge		=218;
trEdge		=191;
blEdge		=192;
brEdge		=217;
vDbl		=186;
hDbl		=205;
tlDbl		=201;
trDbl		=187;
blDbl		=200;
brDbl		=188;

//Output Design
cout <<endl<<endl;
cout.width(28); cout.fill(space); cout<<tlDbl<<setw(23); cout.fill(hDbl); cout<<trDbl<<endl;
cout.width(28); cout.fill(space); cout<<vDbl<<" The card game: \"WAR\" " <<vDbl<<endl;
cout.width(28); cout.fill(space); cout<<blDbl<<setw(23); cout.fill(hDbl); cout<<brDbl<<endl;
cout <<endl<<endl;
cout.width(16); cout.fill(space); cout<<"Your card : "<<tlEdge<<setw(11); cout.fill(hEdge); cout<<trEdge; 
cout.width(24); cout.fill(space); cout<<"Their card: "<<tlEdge<<setw(11); cout.fill(hEdge); cout<<trEdge<<endl;
cout.fill(space);
cout.width(17); cout<<right<<vEdge<<" "<<setw(8)<<left<<val1<<setw(2)<<right<<vEdge; 
cout.width(25); cout<<right<<vEdge<<" "<<setw(8)<<left<<val2<<setw(2)<<right<<vEdge<<endl;
cout.width(17); cout<<right<<vEdge<<setw(11)<<vEdge; cout.width(25); cout<<right<<vEdge<<setw(11)<<vEdge<<endl;
cout.width(17); cout<<right<<vEdge<<setw(11)<<vEdge; cout.width(25); cout<<right<<vEdge<<setw(11)<<vEdge<<endl;
cout.width(17); cout<<right<<vEdge<<setw(11)<<vEdge; cout.width(25); cout<<right<<vEdge<<setw(11)<<vEdge<<endl;
cout.width(17); cout<<right<<vEdge<<setw(5)<<suit1<<setw(6)<<vEdge; 
cout.width(25); cout<<right<<vEdge<<setw(5)<<suit2<<setw(6)<<vEdge<<endl;
cout.width(17); cout<<right<<vEdge<<setw(11)<<vEdge; cout.width(25); cout<<right<<vEdge<<setw(11)<<vEdge<<endl;
cout.width(17); cout<<right<<vEdge<<setw(11)<<vEdge; cout.width(25); cout<<right<<vEdge<<setw(11)<<vEdge<<endl;
cout.width(17); cout<<right<<vEdge<<setw(11)<<vEdge; cout.width(25); cout<<right<<vEdge<<setw(11)<<vEdge<<endl;
cout.width(17); cout<<right<<vEdge<<setw(9)<<right<<val1<<" "<<vEdge; 
cout.width(25); cout<<right<<vEdge<<setw(9)<<right<<val2<<" "<<vEdge<<endl;
cout.width(17); cout.fill(space); cout<<blEdge<<setw(11); cout.fill(hEdge); cout<<brEdge; 
cout.width(25); cout.fill(space); cout<<blEdge<<setw(11); cout.fill(hEdge); cout<<brEdge<<endl;
cout <<endl <<endl;
cout.fill(space);

if (value1>value2) 
	cout<<right<<"\t\t\tCongratulations! You WIN this battle!\n\n";
else if (value1==value2) 
	cout<<right<<"\t\t\t      This is a TIE game!            \n\n";
else if (value1<value2) 
	cout<<right<<"\t\t\t  Sorry! You LOST this battle!       \n\n";

//value check
//cout<<"random value1 = "<<value1<<"random value2 = "<<value2<<endl;
}