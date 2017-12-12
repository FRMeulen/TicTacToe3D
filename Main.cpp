//Inclusions
#include "stdafx.h"
#include <iostream>
#include "TicTacToe3D.h"

//Definitions
	//#define something value

//Namespace
using namespace std;

//Fields
TicTacToe3D ticTacToe;
int quit;

//Method declarations
	//void doSomething();

//Main
int main()
{
	ticTacToe.fillArray();
	ticTacToe.printBoard();
	for (int i = 0; i < 64; i++) {
		ticTacToe.enterMark();
	}
	cin >> quit;
	return 0;
}

//Methods
