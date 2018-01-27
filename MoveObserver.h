//Pragma
#pragma once

//Inclusions
#include "TicTacToeObserver.h"
#include "TicTacToeSubject.h"

//Class
class MoveObserver : public TicTacToeObserver {
private:
	TicTacToeSubject * subject;

	int xs = 0;
	int os = 0;
public:
	typedef TicTacToeObserver super;

	MoveObserver(TicTacToeSubject *);	//Constructor
	virtual ~MoveObserver();	//Destructor
	
	void update();
	void countMoves();
};