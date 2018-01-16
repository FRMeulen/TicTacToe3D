//Inclusions
#include "stdafx.h"
#include <iostream>
#include "TicTacToeSubject.h"

//Namespace
using namespace std;

//Fields
TicTacToeSubject subject;

//Main
int main()
{
	cout << "Hey" << endl;
	cout << subject.getState() << endl;
	cout << "End test" << endl;
	
	system("Pause");
	return 0;
}