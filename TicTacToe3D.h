#pragma once	//Make sure TicTacToe3D is only included once
class TicTacToe3D
{
public:
	void fillArray();	//Fills the 3d array with space chars
	void printBoard();	//Prints the board as is
	void enterMark();	//Asks user for desired field, then puts his/her mark there
	int determineWin();	//Check if somebody won
};

