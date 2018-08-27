/* COURSE:							CSC 125.001, HW Assignment 6
PROGRAMMER:							Tara Walton, Tara1984
LAST MODIFIED:						February 28, 2014
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
using namespace std;

void main( )
{
//Declare variables
char	heart=' ', diamond=' ', club=' ', spade=' ', space=' ',
		vEdge=' ', hEdge=' ', tlEdge=' ', trEdge=' ', blEdge=' ', brEdge=' ',  
		vDbl=' ', hDbl=' ', tlDbl=' ', trDbl=' ', blDbl=' ', brDbl=' ';
char	suit1=' ', suit2=' ';
int		value1=' ', value2=' ';

srand(time(0));
suit1	=rand() % 4 + 3;		//{3, 4, 5, 6}
suit2	=rand() % 4 + 3;		//{3, 4, 5, 6}
value1	=rand() %12 + 2;		//{2-14}
value2	=rand() %12 + 2;		//{2-14}

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
cout.width(17); cout<<right<<vEdge<<" "<<setw(8)<<left<<value1<<setw(2)<<right<<vEdge; 
cout.width(25); cout<<right<<vEdge<<" "<<setw(8)<<left<<value2<<setw(2)<<right<<vEdge<<endl;
cout.width(17); cout<<right<<vEdge<<setw(11)<<vEdge; cout.width(25); cout<<right<<vEdge<<setw(11)<<vEdge<<endl;
cout.width(17); cout<<right<<vEdge<<setw(11)<<vEdge; cout.width(25); cout<<right<<vEdge<<setw(11)<<vEdge<<endl;
cout.width(17); cout<<right<<vEdge<<setw(11)<<vEdge; cout.width(25); cout<<right<<vEdge<<setw(11)<<vEdge<<endl;
cout.width(17); cout<<right<<vEdge<<setw(5)<<suit1<<setw(6)<<vEdge; 
cout.width(25); cout<<right<<vEdge<<setw(5)<<suit2<<setw(6)<<vEdge<<endl;
cout.width(17); cout<<right<<vEdge<<setw(11)<<vEdge; cout.width(25); cout<<right<<vEdge<<setw(11)<<vEdge<<endl;
cout.width(17); cout<<right<<vEdge<<setw(11)<<vEdge; cout.width(25); cout<<right<<vEdge<<setw(11)<<vEdge<<endl;
cout.width(17); cout<<right<<vEdge<<setw(11)<<vEdge; cout.width(25); cout<<right<<vEdge<<setw(11)<<vEdge<<endl;
cout.width(17); cout<<right<<vEdge<<setw(9)<<right<<value1<<" "<<vEdge; 
cout.width(25); cout<<right<<vEdge<<setw(9)<<right<<value2<<" "<<vEdge<<endl;
cout.width(17); cout.fill(space); cout<<blEdge<<setw(11); cout.fill(hEdge); cout<<brEdge; 
cout.width(25); cout.fill(space); cout<<blEdge<<setw(11); cout.fill(hEdge); cout<<brEdge<<endl;
cout <<endl <<endl;

if (value1>value2) {
	cout<<"\t\t\t\t  YOU WIN!!!\n\n";
}
else if (value1==value2) {
	cout<<"\t\t\t\t  IT'S A TIE!\n\n";
}
else if (value1<value2) {
	cout<<"\t\t\t\t  YOU LOSE!!!\n\n";
}	
}