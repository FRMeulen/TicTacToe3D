//Pragma
#pragma once

//Inclusions
#include "Observer.h"
#include "TicTacToeSubject.h"

//Class
class TicTacToeObserver : public Observer {
private:
	char copiedState[64];
	TicTacToeSubject *subject;
public:
	TicTacToeObserver(Subject *);	//Constructor
	virtual ~TicTacToeObserver();	//Destructor
	
	void update(TicTacToeSubject *);
	void copyState(char *);
};