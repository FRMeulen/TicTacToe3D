//Pragma
#pragma once

//Inclusions
#include "Subject.h"
#include "TicTacToeObserver.h"

//Definitions
#define fieldCount 64

//Class
class TicTacToeSubject:public Subject
{
public:
	char state[fieldCount] = {'a'};	//Field state

	TicTacToeSubject();	//Constructor
	~TicTacToeSubject();	//Destructor

	void attach(TicTacToeObserver);
	char* getState();
	void setState();
};