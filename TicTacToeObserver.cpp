//Inclusions
#include "TicTacToeObserver.h"
#include "Subject.h"
#include "Observer.h"
#include <iostream>

//Namespace
using namespace std;

//Constructor
TicTacToeObserver::TicTacToeObserver(Subject *subject) : Observer(subject) {

}

//Destructor
TicTacToeObserver::~TicTacToeObserver() {

}

void TicTacToeObserver::update(TicTacToeSubject *subject) {
	copyState();	//Update game state in observer

	cout << "Updated observers!" << endl << endl;
	

	//Check for winner
	int temp = 0;
	
	//Horizontal rows
	for (int i = 0; i < 4; i++) {	//Check every layer
		for (int j = 0; j < 4; j+=4) {	//Check every row
			if (copiedState[16 * i + j] != ' ' && copiedState[j] == copiedState[j + 1] && copiedState[j] == copiedState[j + 2] && copiedState[j] == copiedState[j + 3]) {
				cout << "Test" << endl;
				subject->gameAlive = false;	//Somebody won
			}
		}
	}

	//Vertical rows
	/*
	for (int i = 0; i < 4; i++) {	//Check every layer
		for (int j = 0; j < 4; j++) {	//Check every column
			if (copiedState[16 * i + j] != ' ' && copiedState[j] == copiedState[j + 4] && copiedState[j] == copiedState[j + 8] && copiedState[j] == copiedState[j + 12]);
		}
	}
	*/
	
	if (subject->gameAlive) {
		subject->printBoard();
	}
	else {
		cout << "Game ended! Player " << subject->activePlayer << " has won!" << endl;
	}
}

void TicTacToeObserver::defaultState() {
	for (int i = 0; i < 64; i++) {
		copiedState[i] = ' ';
	}
}

void TicTacToeObserver::copyState() {
	for (int i = 0; i < 64; i++) {
		copiedState[i] = subject->getState()[i];
	}
}