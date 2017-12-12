//Includes
#include "stdafx.h"
#include <iostream>
#include "TicTacToe3D.h"

//Definitions
//Played in a 4x4x4 cube
#define fieldWidth 4	//Width of the board
#define fieldHeight 4	//Height of the board
#define fieldDepth 4	//Depth of the board

//Namespace
using namespace std;

//Fields
char fields[fieldWidth][fieldDepth][fieldHeight];	//3d Array to hold marks
int player = 1;	//Player currently active
char quit;	//Int to prevent program from closing

//Methods
void TicTacToe3D::enterMark() {
	//Location ints, all unreachable by default
	int layer = -1;	//Desired layer
	int row = -1;	//Desired row
	int column = -1;	//Desired column

	cout << "Layer: ";	//Ask which layer is desired
	cin >> layer;	//Store desired layer
	cout << "Column: ";	//Ask which column is desired
	cin >> column;	//Store desired column
	cout << "Row: ";	//Ask which row is desired
	cin >> row;	//Store desired row
	

	if (fields[row - 1][layer - 1][column - 1] == ' ') {
		if (player == 1) {	//If player 1 is active...
			fields[row - 1][layer - 1][column - 1] = 'X';	//...put an X char in selected field
			player = 2;	//Player 2's turn starts
		}
		else if (player == 2) {	//If player 2 is active...
			fields[row - 1][layer - 1][column - 1] = 'O';	//...put an O char in selected field
			player = 1;	//Player 1's turn starts
		}
		else {	//If neither is active...
			cout << "Unrecognized player!" << endl;	//... crash I guess?
		}
	}
	else {
		cout << "Field already taken!" << endl;
	}

	

	system("CLS");	//Clear screen
	printBoard();	//Print board with move made
}

void TicTacToe3D::fillArray() {
	for (int i = 0; i < fieldDepth; i++) {
		for (int j = 0; j < fieldHeight; j++) {
			for (int k = 0; k < fieldWidth; k++) {
				fields[i][j][k] = ' ';
			}
		}
	}
}

int TicTacToe3D::determineWin() {

	return -1;
}

void TicTacToe3D::printBoard() {
	cout << "\t\t\t\t    Tic tac toe!" << endl;
	cout << "\t\t\t   Player 1 'X' vs. Player 2 'O'" << endl << endl;

	for (int i = 0; i < 4; i++) {
		cout << "Layer " << i+1 << "                ";	//Prints layer labels
	}
	cout << endl;

	for (int j = 0; j < 4; j++) {	//Loop for every layer
		for (int k = 0; k < 4; k++) {	//Loop for every column
			for (int l = 0; l < 4; l++) {	//Loop for every row
				cout << " " << fields[j][k][l];	//Print space between fields
				if (l < 3) {	//If in same layer
					cout << " " << char(179);	//Vertical lines
				}
			}
			cout << "         ";	//Space between layers
		}
		cout << endl;	//Go to next line
		
		if (j < 3) {
			for (int m = 0; m < 4; m++) {	//Horizontal lines
				for (int n = 0; n < 3; n++) {
					cout << char(196) << char(196) << char(196) << char(197);
				}
				cout << char(196) << char(196) << char(196) << "        ";
			}
			cout << endl;
		}
	}
}