//Inclusions
#include "BoardObserver.h"
#include "TicTacToeSubject.h"
#include "TicTacToeObserver.h"
#include <iostream>

//Namespace
using namespace std;

//Constructor
BoardObserver::BoardObserver(TicTacToeSubject *subject) : TicTacToeObserver(subject)
{
	this->subject = subject;
}

//Destructor
BoardObserver::~BoardObserver() {

}

//Methods
void BoardObserver::update() {
	super::update(subject);
}

void BoardObserver::printBoard() {
	cout << "    Layer 1   \t\t    Layer 2   \t\t    Layer 3   \t\t    Layer 4" << endl << endl;
	for (int x = 0; x < 4; x++) {	// For every layer increment x
		for (int y = 0; y < 4; y++) {	// For every row increment y
			for (int z = 0; z < 4; z++) {	// For every column increment z
				cout << " " << copiedState[16 * y + 4 * x + z];	//Print state in right cubicle
				if (z < 3) {	//For every cubicle except right one
					cout << " " << char(179);	//Print right border
				}
			}
			cout << "		";	//Print space between layers
		}
		cout << endl;	//Next line
		if (x < 3) {	//For every cubicle except bottom one
			for (int i = 0; i < 4; i++) {	//Add bottom border
				for (int j = 0; j < 3; j++) {	//For every cubicle
					cout << char(196) << char(196) << char(196) << char(197);	//Print bottom border and intersection
				}
				cout << char(196) << char(196) << char(196) << "		";	//Print space between tabs
			}
			cout << endl;
		}
	}
}