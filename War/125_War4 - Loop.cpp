/*=========================================================================================
 PROGRAMMERS:			Yang Wang:	 designed and implemented function main( )
						Tara Walton: designed preparation(), drawCards(), displayCards(),
							gameResults(), and continueBattle() functions
 COURSE:				CSC 125, Homework 12
 MODIFIED BY:			N/A
 LAST MODIFIED DATE:	April 30, 2014
 DESCRIPTION:			This program is to simulate multiple battles of the card game: WAR.
 NOTE:					
 FILES:					war.cpp, hwProject.sln
 IDE/COMPILER:			MicroSoft Visual Studio 2012
 INSTRUCTION FOR COMPILATION AND EXECUTION:
	1.	Double click on hwProject.sln			to OPEN the project
	2.	Press Ctrl+F7							to COMPILE
	3.	Press Ctrl+Shift+B						to BUILD (COMPILE+LINK)
	4.	Press Ctrl+F5							to EXECUTE
==========================================================================================*/
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<iomanip>
#include<string>
	using namespace std;

//function prototypes
	void preparation();
	void drawCards(	unsigned short & yourFaceValue, char & yourSuit, 
					unsigned short & opponentFaceValue, char & opponentSuit);
	void displayCards(	unsigned short yourFaceValue, char yourSuit, 
						unsigned short opponentFaceValue, char opponentSuit);
	void gameResult(unsigned short yourFaceValue, unsigned short opponentFaceValue);
	bool continueBattle();

/*---------------------------------------------------------------------------- 
 Function main() is given and you should NOT change anything in this function.
 -----------------------------------------------------------------------------*/
int main( )
{unsigned short yourFaceValue, opponentFaceValue; 
 char			yourSuit, opponentSuit;
 
 preparation(); 
 do
 {drawCards(yourFaceValue, yourSuit, opponentFaceValue, opponentSuit);
  displayCards(yourFaceValue, yourSuit, opponentFaceValue, opponentSuit);
  gameResult(yourFaceValue, opponentFaceValue);
 } while (continueBattle());

 cout<<"\n\n\t********** Game is over! **********\n\n";
 return 0;
}

/*---------------------------------------------------------------------------------------------
Includes any initial operations that do not need to be repeated in each hand of the game.
Does NOT receive any data item from its caller. 
Does NOT send any data item back to its caller 
---------------------------------------------------------------------------------------------*/
void preparation( )
{
srand(time(0));
}

/*--------------------------------------------------------------------
Draws 2 different cards from a deck of cards.
Does NOT receive information from its caller.
Sends face value (unsigned short) and suits (char) back to its caller.
---------------------------------------------------------------------*/
void drawCards(unsigned short & yourFaceValue, char & yourSuit, 
				unsigned short & opponentFaceValue, char & opponentSuit)
{
yourSuit			=rand() % 4 + 3;		//{3, 4, 5, 6}
opponentSuit		=rand() % 4 + 3;		//{3, 4, 5, 6}
yourFaceValue		=rand() %13 + 2;		//{2-14}
opponentFaceValue	=rand() %13 + 2;		//{2-14}

if ((yourFaceValue == opponentFaceValue) && (yourSuit == opponentSuit))	//If same card
	if (opponentSuit <= 5) 
		opponentSuit += 1;										//change suit of opponent card
	else 	opponentSuit = 3;						
}

/*--------------------------------------------------------------------------
Clears screen first, then displays game title bar and 2 cards.
Receives two cards' face value (unsigned short) and suits (char) from caller.
Does NOT send any data items back to caller.
---------------------------------------------------------------------------*/
void displayCards(	unsigned short yourFaceValue, char yourSuit,
					unsigned short opponentFaceValue, char opponentSuit)
{string urFaceVal=" ", oppFaceVal=" ";
switch (yourFaceValue)
	{
	case 1:		urFaceVal="1";	break;
	case 2:		urFaceVal="2";	break;
	case 3:		urFaceVal="3";	break;
	case 4:		urFaceVal="4";	break;
	case 5:		urFaceVal="5";	break;
	case 6:		urFaceVal="6";	break;
	case 7:		urFaceVal="7";	break;
	case 8:		urFaceVal="8";	break;
	case 9:		urFaceVal="9";	break;
	case 10:	urFaceVal="10";	break;
	case 11:	urFaceVal="J";	break;
	case 12:	urFaceVal="Q";	break;
	case 13:	urFaceVal="K";	break;
	case 14:	urFaceVal="A";	break;          
	}
switch (opponentFaceValue)
	{
	case 1:		oppFaceVal="1";	break;
	case 2:		oppFaceVal="2";	break;
	case 3:		oppFaceVal="3";	break;
	case 4:		oppFaceVal="4";	break;
	case 5:		oppFaceVal="5";	break;
	case 6:		oppFaceVal="6";	break;
	case 7:		oppFaceVal="7";	break;
	case 8:		oppFaceVal="8";	break;
	case 9:		oppFaceVal="9";	break;
	case 10:	oppFaceVal="10";break;
	case 11:	oppFaceVal="J";	break;
	case 12:	oppFaceVal="Q";	break;
	case 13:	oppFaceVal="K";	break;
	case 14:	oppFaceVal="A";	break;          
	}
char		heart=' ', diamond=' ', club=' ', spade=' ', space=' ',
			vEdge=' ', hEdge=' ', tlEdge=' ', trEdge=' ', blEdge=' ', brEdge=' ',  
			vDbl=' ', hDbl=' ', tlDbl=' ', trDbl=' ', blDbl=' ', brDbl=' ';
heart		=3;
diamond		=4;
club		=5;
spade		=6;
vEdge		=179;	//vertical edge
hEdge		=196;	//horizontal edge
tlEdge		=218;	//top left edge
trEdge		=191;	//top right edge
blEdge		=192;	//bottom left edge
brEdge		=217;	//bottom right edge
vDbl		=186;	//vertical double edge
hDbl		=205;	//horizontal double edge
tlDbl		=201;	//top left double edge
trDbl		=187;	//top right double edge
blDbl		=200;	//bottom left double edge
brDbl		=188;	//bottom right double edge

system("CLS");
cout <<endl<<endl;
cout.width(28); cout.fill(space); cout<<tlDbl<<setw(23); cout.fill(hDbl); cout<<trDbl<<endl;
cout.width(28); cout.fill(space); cout<<vDbl<<" The card game: \"WAR\" " <<vDbl<<endl;
cout.width(28); cout.fill(space); cout<<blDbl<<setw(23); cout.fill(hDbl); cout<<brDbl<<endl;
cout <<endl<<endl;
cout.width(16); cout.fill(space); cout<<"Your card : "<<tlEdge<<setw(11); cout.fill(hEdge);
			cout<<trEdge; 
cout.width(24); cout.fill(space); cout<<"Their card: "<<tlEdge<<setw(11); cout.fill(hEdge); 
			cout<<trEdge<<endl;
cout.fill(space);
cout.width(17); cout<<right<<vEdge<<" "<<setw(8)<<left<<urFaceVal<<setw(2)<<right<<vEdge;
	cout.width(25); cout<<right<<vEdge<<" "<<setw(8)<<left<<oppFaceVal<<setw(2)<<right<<vEdge<<endl;
cout.width(17); cout<<right<<vEdge<<setw(11)<<vEdge; 
	cout.width(25); cout<<right<<vEdge<<setw(11)<<vEdge<<endl;
cout.width(17); cout<<right<<vEdge<<setw(11)<<vEdge; 
	cout.width(25); cout<<right<<vEdge<<setw(11)<<vEdge<<endl;
cout.width(17); cout<<right<<vEdge<<setw(11)<<vEdge; 
	cout.width(25); cout<<right<<vEdge<<setw(11)<<vEdge<<endl;
cout.width(17); cout<<right<<vEdge<<setw(5)<<yourSuit<<setw(6)<<vEdge; 
	cout.width(25); cout<<right<<vEdge<<setw(5)<<opponentSuit<<setw(6)<<vEdge<<endl;
cout.width(17); cout<<right<<vEdge<<setw(11)<<vEdge; 
	cout.width(25); cout<<right<<vEdge<<setw(11)<<vEdge<<endl;
cout.width(17); cout<<right<<vEdge<<setw(11)<<vEdge; 
	cout.width(25); cout<<right<<vEdge<<setw(11)<<vEdge<<endl;
cout.width(17); cout<<right<<vEdge<<setw(11)<<vEdge; 
	cout.width(25); cout<<right<<vEdge<<setw(11)<<vEdge<<endl;
cout.width(17); cout<<right<<vEdge<<setw(9)<<right<<urFaceVal<<" "<<vEdge; 
	cout.width(25); cout<<right<<vEdge<<setw(9)<<right<<oppFaceVal<<" "<<vEdge<<endl;
cout.width(17); cout.fill(space); cout<<blEdge<<setw(11); cout.fill(hEdge); cout<<brEdge; 
	cout.width(25); cout.fill(space); cout<<blEdge<<setw(11); cout.fill(hEdge); cout<<brEdge<<endl;
cout <<endl <<endl;
}

/*-----------------------------------------------
Displays game result.
Receives face values of two cards from caller.
Does NOT send any data items back to caller.
------------------------------------------------*/
void gameResult(unsigned short yourFaceValue, unsigned short opponentFaceValue)
{
if (yourFaceValue > opponentFaceValue) 
	cout<<right<<"\t\t\tCongratulations! You WIN this battle!\n\n";
else if (yourFaceValue == opponentFaceValue) 
	cout<<right<<"\t\t\t      This is a TIE game!            \n\n";
else if (yourFaceValue < opponentFaceValue) 
	cout<<right<<"\t\t\t  Sorry! You LOST this battle!       \n\n";
}

/*--------------------------------------------------------------
Tests if a user wants to continue to battle or not.
Asks a user to enter Y/N.
Returns TRUE to its caller if y or Y is enter, otherwise FALSE.
--------------------------------------------------------------*/
bool continueBattle( )
{
char answer = ' ';
cout<<"Would you like to play again? (Y or N)   ";
cin>>answer;	
answer = toupper(answer);
if (answer == 'Y')
	return true;
else 
	return false;
}