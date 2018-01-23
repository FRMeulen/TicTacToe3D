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
	copyState(copiedState);	//Update game state in observer

	cout << "Updated observers!" << endl;

	//Check for winner
	int temp = 0;
	
	//Horizontal rows
	for (int i = 0; i < 4; i++) {	//Check every layer
		for (int j = 0; j < 4; j+=4) {	//Check every row
			if (copiedState[16 * i + j] != ' ' && copiedState[j] == copiedState[j + 1] && copiedState[j] == copiedState[j + 2] && copiedState[j] == copiedState[j + 3]) {
				subject->gameAlive = false;	//Somebody won
			}
		}
	}
	
	
}

void TicTacToeObserver::copyState(char *obsState) {
	for (int i = 0; i < 64; i++) {
		obsState[i] = subject->getState[i];
	}
}