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

void TicTacToeSubject::playGame() {
	cout << "Player " << activePlayer << "'s turn!" << endl;
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
	}
	
	else if (activePlayer == 2) {
		setState(16 * layer + 4 * row + column, 'O');
	}

	else {
		cout << "Unknown player!" << endl;
	}

	system("cls");	//Clear screen
	notifyAll();
}

void TicTacToeSubject::defaultState() {
	for (int i = 0; i < 64; i++) {
		state[i] = ' ';
	}
}