//Pragma
#pragma once

//Inclusions
#include "TicTacToeObserver.h"
#include "TicTacToeSubject.h"

//Class
class AlphaObserver : public TicTacToeObserver
{
private:
	TicTacToeSubject * subject;
public:
	typedef TicTacToeObserver super;
	
	AlphaObserver(TicTacToeSubject *);	//Constructor
	virtual ~AlphaObserver();	//Destructor
	
	void update();
};