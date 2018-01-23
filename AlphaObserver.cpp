//Inclusions
#include "AlphaObserver.h"
#include "TicTacToeSubject.h"
#include "TicTacToeObserver.h"
#include <iostream>

//Namespace
using namespace std;

//Constructor
AlphaObserver::AlphaObserver(TicTacToeSubject *subject) : TicTacToeObserver(subject)
{
	this->subject = subject;
}

//Destructor
AlphaObserver::~AlphaObserver() {

}

//Methods
void AlphaObserver::update() {
	super::update(subject);
}