//Inclusions
#include "BoardObserver.h"
#include "TicTacToeSubject.h"
#include "TicTacToeObserver.h"
#include <iostream>

//Namespace
using namespace std;

//Constructor
BoardObserver::BoardObserver(TicTacToeSubject *subject) : TicTacToeObserver(subject)
{
	this->subject = subject;
}

//Destructor
BoardObserver::~BoardObserver() {

}

//Methods
void BoardObserver::update() {
	super::update(subject);

	//Print the board
	printBoard();

	//If there is a winner
	if (checkWinOptions() == 1) {
		cout << "Game ended! Player " << subject->activePlayer << " has won!" << endl << endl;
		subject->gameAlive = false;
	}

	//If the field is full
	else if (checkWinOptions() == 0) {
		cout << "Game ended in a draw!" << endl << endl;
		subject->gameAlive = false;
	}

	//If the game isn't done yet
	else {
		if (subject->activePlayer == 1) {	//If player 1 was active
			subject->activePlayer++;	//It will now be player 2's turn
		}

		else if (subject->activePlayer == 2) {	//If player 2 was active
			subject->activePlayer--;	//It will not be player 1's turn
		}

		else {	//If neither was active
			cout << "Error! Unknown player!" << endl;	//End game
		}
	}
}

void BoardObserver::printBoard() {
	cout << "*** Board observer ***" << endl;
	
	cout << "    Layer 1   \t\t    Layer 2   \t\t    Layer 3   \t\t    Layer 4" << endl << endl;
	for (int x = 0; x < 4; x++) {	// For every layer increment x
		for (int y = 0; y < 4; y++) {	// For every row increment y
			for (int z = 0; z < 4; z++) {	// For every column increment z
				cout << " " << copiedState[16 * y + 4 * x + z];	//Print state in right cubicle
				if (z < 3) {	//For every cubicle except right one
					cout << " " << char(179);	//Print right border
				}
			}
			cout << "		";	//Print space between layers
		}
		cout << endl;	//Next line
		if (x < 3) {	//For every cubicle except bottom one
			for (int i = 0; i < 4; i++) {	//Add bottom border
				for (int j = 0; j < 3; j++) {	//For every cubicle
					cout << char(196) << char(196) << char(196) << char(197);	//Print bottom border and intersection
				}
				cout << char(196) << char(196) << char(196) << "		";	//Print space between tabs
			}
			cout << endl;
		}
	}

	cout << endl;
}

int BoardObserver::checkWinOptions() {
	//Flat horizontal
	for (int i = 0; i < 64; i+=16) {	//Check every layer
		for (int j = 0; j < 16; j+=4) {	//Check every row
			if (copiedState[i + j] != ' ' && copiedState[i + j] == copiedState[i + j + 1] && copiedState[i + j] == copiedState[i + j + 2] && copiedState[i + j] == copiedState[i + j + 3]) {
				return 1;
			}
		}
	}

	//Flat vertical
	for (int i = 0; i < 64; i += 16) {	//Check every layer
		for (int j = 0; j < 16; j++) {	//Check every column
			if (copiedState[i + j] != ' ' && copiedState[i + j] == copiedState[i + j + 4] && copiedState[i + j] == copiedState[i + j + 8] && copiedState[i + j] == copiedState[i + j + 12]) {
				return 1;
			}
		}
	}

	//Flat diagonal
	for (int i = 0; i < 64; i+=16) {	//Check every layer
		if (copiedState[i] != ' ' && copiedState[i] == copiedState[i + 5] && copiedState[i] == copiedState[i + 10] && copiedState[i] == copiedState[i + 15]) {
			return 1;
		}
	}

	for (int i = 3; i < 64; i+=16) {
		if (copiedState[i] != ' ' && copiedState[i] == copiedState[i + 3] && copiedState[i] == copiedState[i + 6] && copiedState[i] == copiedState[i + 9]) {
			return 1;
		}
	}

	//3D vertical
	for (int i = 0; i < 16; i++) {	//Check every row & column
		if (copiedState[i] != ' ' && copiedState[i] == copiedState[i + 16] && copiedState[i] == copiedState[i + 32] && copiedState[i] == copiedState[i + 48]) {
			return 1;
		}
	}

	//3D edge to edge
	for (int i = 0; i < 16; i += 4) {	//Check every row bottom west to top east
		if (copiedState[i] != ' ' && copiedState[i] == copiedState[i + 17] && copiedState[i] == copiedState[i + 34] && copiedState[i] == copiedState[i + 51]) {
			return 1;
		}
	}

	for (int i = 0; i < 4; i++) {	//Check every column bottom north to top south
		if (copiedState[i] != ' ' && copiedState[i] == copiedState[i + 20] && copiedState[i] == copiedState[i + 40] && copiedState[i] == copiedState[i + 60]) {
			return 1;
		}
	}

	for (int i = 3; i < 15; i += 4) {	//Check every row bottom east to top west
		if (copiedState[i] != ' ' && copiedState[i] == copiedState[i + 15] && copiedState[i] == copiedState[i + 30] && copiedState[i] == copiedState[i + 45]) {
			return 1;
		}
	}

	for (int i = 12; i < 16; i++) {	//Check every column bottom south to top north
		if (copiedState[i] != ' ' && copiedState[i] == copiedState[i + 12] && copiedState[i] == copiedState[i + 24] && copiedState[i] == copiedState[i + 36]) {
			return 1;
		}
	}

	//3D corner to corner
	if (copiedState[0] != ' ' && copiedState[0] == copiedState[21] && copiedState[0] == copiedState[42] && copiedState[0] == copiedState[63]) {
		return 1;
	}

	if (copiedState[12] != ' ' && copiedState[12] == copiedState[25] && copiedState[12] == copiedState[38] && copiedState[12] == copiedState[51]) {
		return 1;
	}

	//Check for available moves
	for (int i = 0; i < 64; i++) {
		if (copiedState[i] == ' ') {
			return -1;
		}
	}

	//If no more moves and no winner return 0 for draw
	return 0;
}