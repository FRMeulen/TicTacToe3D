//Pragma
#pragma once

//Inclusions
#include "Observer.h"

//Class dependencies
class TicTacToeSubject;

//Class
class TicTacToeObserver : public Observer {
public:
	TicTacToeObserver(Subject *);	//Constructor
	virtual ~TicTacToeObserver();	//Destructor
	
	char copiedState[64];	//Copied game state from subject
	int gameWon = -1;	//-1 = in progress, 0 = draw, 1 = won
	TicTacToeSubject *subject;	//Pointer to subject

	void update(TicTacToeSubject *);
	void copyState(char* originalState);
};

//Late Inclusions
#include "TicTacToeSubject.h"