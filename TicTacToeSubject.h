//Pragma
#pragma once

//Inclusions
#include "Subject.h"

//Definitions
#define fieldCount 64

//Class
class TicTacToeSubject : public Subject {
public:
	char state[fieldCount];	//Field state
	bool gameAlive = true;	//Game ended
	int activePlayer = 1;

	TicTacToeSubject();	//Constructor
	~TicTacToeSubject();	//Destructor

	char* getState();
	void setState(int pos, char mark);
	void playGame();
	void setMark();
	void defaultState();
};