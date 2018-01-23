//Inclusions
#include <iostream>
#include "TicTacToeSubject.h"
#include "AlphaObserver.h"
#include "BinObserver.h"

//Namespace
using namespace std;

//Fields
TicTacToeSubject subject;
AlphaObserver* alpha;
BinObserver* bin;

//Main
int main()
{
	subject.defaultState();
	subject.attach(alpha);
	subject.attach(bin);
	subject.printBoard();	
	system("Pause");
	return 0;
}