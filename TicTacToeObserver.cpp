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
	copyState(subject->getState());	//Update game state in observer
}

void TicTacToeObserver::copyState(char* originalState) {
	for (int i = 0; i < 64; i++) {
		copiedState[i] = originalState[i];
	}
}