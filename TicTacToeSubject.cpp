//Inclusions
#include <iostream>
#include "TicTacToeSubject.h"

//Namespace
using namespace std;

//Constructor
TicTacToeSubject::TicTacToeSubject(){
	
}

//Destructor
TicTacToeSubject::~TicTacToeSubject(){

}

//Methods
char* TicTacToeSubject::getState() {
	return state;
}

void TicTacToeSubject::setState(int pos, char mark) {
	state[pos] = mark;
}

void TicTacToeSubject::printBoard() {
	cout << "Player " << activePlayer << "'s turn!" << endl;

	//Print board
	cout << "    Layer 1   \t\t    Layer 2   \t\t    Layer 3   \t\t    Layer 4" << endl << endl;
	for (int x = 0; x < 4; x++) {	// For every layer increment x
		for (int y = 0; y < 4; y++) {	// For every row increment y
			for (int z = 0; z < 4; z++) {	// For every column increment z
				cout << " " << state[16*y + 4*x + z];	//Print state in right cubicle
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
	setMark();
}

void TicTacToeSubject::setMark() {
	int layer = NULL;	//Holds chosen layer
	int column = NULL;	//Holds chosen column
	int row = NULL;	//Holds chosen row

	//Decide layer
	for (;;) {	//Endless loop
		cout << "Player " << activePlayer << ", please choose a layer: ";
		if (cin >> layer) {	//If input is an int
			if (layer > 0 && layer < 5) {	//And layer is valid
				break;	//Break endless loop
			}
			else {
				cout << "Please choose a valid layer." << endl;
				layer = NULL;	//Reset layer int
			}
		}

		else {	//If input is not an int
			cout << "Please choose a valid layer." << endl;
			cin.clear();	//Clear
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	//Ignore input
		}
	}

	//Decide column
	for (;;) {	//Endless loop
		cout << "Player " << activePlayer << ", please choose a column: ";
		if (cin >> column) {	//If input is an int
			if (column > 0 && column < 5) {	//And column is valid
				break;	//Break endless loop
			}
			else {
				cout << "Please choose a valid column." << endl;
				column = NULL;	//Reset column int
			}
		}

		else {	//If input is not an int
			cout << "Please choose a valid column." << endl;
			cin.clear();	//Clear
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	//Ignore input
		}
	}

	//Decide row
	for (;;) {	//Endless loop
		cout << "Player " << activePlayer << ", please choose a row: ";
		if (cin >> row) {	//If input is an int
			if (row > 0 && row < 5) {	//And row is valid
				break;	//Break endless loop
			}
			else {
				cout << "Please choose a valid row." << endl;
				row = NULL;	//Reset row int
			}
		}

		else {	//If input is not an int
			cout << "Please choose a valid row." << endl;
			cin.clear();	//Clear
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	//Ignore input
		}
	}

	//Lower ints to match arrays
	--layer;
	--column;
	--row;

	if (activePlayer == 1) {
		setState(16 * layer + 4 * row + column, 'X');
		activePlayer = 2;
	}
	
	else if (activePlayer == 2) {
		setState(16 * layer + 4 * row + column, 'O');
		activePlayer = 1;
	}

	else {
		cout << "Unknown player!" << endl;
	}

	system("cls");	//Clear screen
	notifyAll();
}

void TicTacToeSubject::defaultState() {
	for (int i = 0; i < 64; i++) {
		state[i] = 'a';
	}
}