//Pragma
#pragma once

//Inclusions
#include "TicTacToeObserver.h"
#include "TicTacToeSubject.h"

//Class
class BoardObserver : public TicTacToeObserver
{
private:
	TicTacToeSubject * subject;
public:
	typedef TicTacToeObserver super;
	
	BoardObserver(TicTacToeSubject *);	//Constructor
	virtual ~BoardObserver();	//Destructor
	
	void update();
	void printBoard();
};