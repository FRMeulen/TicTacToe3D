//Pragma
#pragma once

//Inclusions
#include "Observer.h"

//Class
class TicTacToeObserver : public Observer
{
public:
	char copiedState;
	
	TicTacToeObserver(Subject subject);	//Constructor
	~TicTacToeObserver();	//Destructor

	void update();
};

