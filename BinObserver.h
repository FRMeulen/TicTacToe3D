//Pragma
#pragma once

//Inclusions
#include "TicTacToeObserver.h"
#include "TicTacToeSubject.h"

//Class
class BinObserver : public TicTacToeObserver {
private:
	TicTacToeSubject * subject;
public:
	typedef TicTacToeObserver super;
	
	BinObserver(TicTacToeSubject *);	//Constructor
	virtual ~BinObserver();	//Destructor
	
	void update();
};