//Inclusions
#include <iostream>
#include "TicTacToeSubject.h"
#include "BoardObserver.h"
#include "BinObserver.h"

//Namespace
using namespace std;

//Fields
TicTacToeSubject *subject;
BoardObserver* board;
BinObserver* bin;

//Main
int main()
{
	//Create subject and observers
	subject = new TicTacToeSubject();
	board = new BoardObserver(subject);
	bin = new BinObserver(subject);

	//Set default states
	subject->defaultState();
	board->copyState(subject->getState());
	bin->copyState(subject->getState());
	
	//Attach observers
	subject->attach(board);
	subject->attach(bin);

	//Initialize game
	subject->playGame();

	system("Pause");	//Pause to prevent instant exit
	return 0;	//Terminate program
}