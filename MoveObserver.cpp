//Inclusions
#include "MoveObserver.h"
#include "TicTacToeSubject.h"
#include "TicTacToeObserver.h"
#include <iostream>

//Namespace
using namespace std;

//Constructor
MoveObserver::MoveObserver(TicTacToeSubject *subject) : TicTacToeObserver(subject) {
	this->subject = subject;
}

//Destructor
MoveObserver::~MoveObserver() {

}

//Methods
void MoveObserver::update() {
	super::update(subject);
	countMoves();
}

void MoveObserver::countMoves() {
	xs = 0;
	os = 0;

	for (int i = 0; i < 64; i++) {
		if (copiedState[i] == 'X') {
			xs++;
		}
		else if (copiedState[i] == 'O') {
			os++;
		}
	}
	cout << "*** Move observer ***" << endl;
	cout << "Player 1 (X) has made " << xs << " moves." << endl;
	cout << "Player 2 (O) has made " << os << " moves." << endl;
	if (subject->gameAlive) {
		cout << "It is now player " << subject->activePlayer << "'s turn!" << endl;
	}
	cout << endl;
}