//Inclusions
#include <iostream>
#include "TicTacToeSubject.h"
#include "BoardObserver.h"
#include "MoveObserver.h"

//Namespace
using namespace std;

//Fields
TicTacToeSubject *subject;
BoardObserver* board;
MoveObserver* moves;

//Main
int main()
{
	//Create subject and observers
	subject = new TicTacToeSubject();
	board = new BoardObserver(subject);
	moves = new MoveObserver(subject);

	//Set default state
	subject->defaultState();
	
	//Attach observers
	subject->attach(board);
	subject->attach(moves);

	//Update observers
	subject->notifyAll();

	//Initialize game
	subject->playGame();

	//Delete subject and observers once game is finished
	delete moves;
	delete board;
	delete subject;

	system("Pause");	//Pause to prevent instant exit
	return 0;	//Terminate program
}