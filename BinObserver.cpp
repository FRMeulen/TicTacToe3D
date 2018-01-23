//Inclusions
#include "BinObserver.h"
#include "TicTacToeSubject.h"
#include "TicTacToeObserver.h"
#include <iostream>

//Namespace
using namespace std;

//Constructor
BinObserver::BinObserver(TicTacToeSubject *subject) : TicTacToeObserver(subject) {
	this->subject = subject;
}

//Destructor
BinObserver::~BinObserver() {

}

//Methods
void BinObserver::update() {
	super::update(subject);
}