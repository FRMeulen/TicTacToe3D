//Pragma
#pragma once

//Inclusions
#include "Observer.h"

//Definitions
#define fieldWidth 4
#define fieldHeight 4
#define fieldDepth 4

//Class
class TicTacToeSubject
{
public:
	char state[fieldWidth][fieldHeight][fieldDepth];	//Field state

	TicTacToeSubject();	//Constructor
	~TicTacToeSubject();	//Destructor

	void attach(Observer);
	char getState();
	void setState();
};