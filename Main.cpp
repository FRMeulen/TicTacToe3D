//Inclusions
#include <iostream>
#include "TicTacToeSubject.h"
#include "AlphaObserver.h"
#include "BinObserver.h"

//Namespace
using namespace std;

//Fields
TicTacToeSubject *subject;
AlphaObserver* alpha;
BinObserver* bin;

//Main
int main()
{
	//Create subject and observers
	subject = new TicTacToeSubject();
	alpha = new AlphaObserver(subject);
	bin = new BinObserver(subject);

	//Set default states
	alpha->defaultState();
	bin->defaultState();
	subject->defaultState();
	
	//Attach observers
	subject->attach(alpha);
	subject->attach(bin);
	
	//Initialize game
	subject->printBoard();

	system("Pause");	//Pause to prevent instant exit
	return 0;	//Terminate program
}