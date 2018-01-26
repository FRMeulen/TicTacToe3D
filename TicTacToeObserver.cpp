//Inclusions
#include "TicTacToeObserver.h"
#include "Subject.h"
#include "Observer.h"
#include <iostream>

//Namespace
using namespace std;

//Constructor
TicTacToeObserver::TicTacToeObserver(Subject *subject) : Observer(subject) {

}

//Destructor
TicTacToeObserver::~TicTacToeObserver() {

}

void TicTacToeObserver::update(TicTacToeSubject *subject) {
	copyState(subject->getState());	//Update game state in observer

	//Check for winner
	checkWinOptions();

	//If there is a winner
	if (gameWon == 1) {
		cout << "Game ended! Player " << subject->activePlayer << " has won!" << endl;
	}

	//If the field is full
	else if (gameWon == 0) {
		cout << "Game ended in a draw!" << endl;
	}

	//If the game isn't done yet
	else {
		if (subject->activePlayer == 1) {	//If player 1 was active
			subject->activePlayer++;	//It will now be player 2's turn
			subject->playGame();	//Continue game
		}

		else if (subject->activePlayer == 2) {	//If player 2 was active
			subject->activePlayer--;	//It will not be player 1's turn
			subject->playGame();	//Continue game
		}

		else {	//If neither was active
			cout << "Error! Unknown player!" << endl;	//End game
		}
	}
}

void TicTacToeObserver::copyState(char* originalState) {
	for (int i = 0; i < 64; i++) {
		copiedState[i] = originalState[i];
	}
}

void TicTacToeObserver::checkWinOptions() {
	cout << "Checking..." << endl;
	
	///Flat horizontal
		//Layer 1
		if (copiedState[0] != ' ' && copiedState[0] == copiedState[1] && copiedState[0] == copiedState[2] && copiedState[0] == copiedState[3]) {
			gameWon = 1;
		}
		
		else if (copiedState[4] != ' ' && copiedState[4] == copiedState[5] && copiedState[4] == copiedState[6] && copiedState[4] == copiedState[7]) {
			gameWon = 1;
		}
		
		else if (copiedState[8] != ' ' && copiedState[8] == copiedState[9] && copiedState[8] == copiedState[10] && copiedState[8] == copiedState[11]) {
			gameWon = 1;
		}
		
		else if (copiedState[12] != ' ' && copiedState[12] == copiedState[13] && copiedState[12] == copiedState[14] && copiedState[12] == copiedState[15]) {
			gameWon = 1;
		}

		//Layer 2
		else if (copiedState[16] != ' ' && copiedState[16] == copiedState[17] && copiedState[16] == copiedState[18] && copiedState[16] == copiedState[19]) {
			gameWon = 1;
		}
		
		else if (copiedState[20] != ' ' && copiedState[20] == copiedState[21] && copiedState[20] == copiedState[22] && copiedState[20] == copiedState[23]) {
			gameWon = 1;
		}
		
		else if (copiedState[24] != ' ' && copiedState[24] == copiedState[25] && copiedState[24] == copiedState[26] && copiedState[24] == copiedState[27]) {
			gameWon = 1;
		}
		
		else if (copiedState[28] != ' ' && copiedState[28] == copiedState[29] && copiedState[28] == copiedState[30] && copiedState[28] == copiedState[31]) {
			gameWon = 1;
		}

		//Layer 3
		else if (copiedState[32] != ' ' && copiedState[32] == copiedState[33] && copiedState[32] == copiedState[34] && copiedState[32] == copiedState[35]) {
			gameWon = 1;
		}
		
		else if (copiedState[36] != ' ' && copiedState[36] == copiedState[37] && copiedState[36] == copiedState[38] && copiedState[36] == copiedState[39]) {
			gameWon = 1;
		}
		
		else if (copiedState[40] != ' ' && copiedState[40] == copiedState[41] && copiedState[40] == copiedState[42] && copiedState[40] == copiedState[43]) {
			gameWon = 1;
		}
		
		else if (copiedState[44] != ' ' && copiedState[44] == copiedState[45] && copiedState[44] == copiedState[46] && copiedState[44] == copiedState[47]) {
			gameWon = 1;
		}

		//Layer 4
		else if (copiedState[48] != ' ' && copiedState[48] == copiedState[49] && copiedState[48] == copiedState[50] && copiedState[48] == copiedState[51]) {
			gameWon = 1;
		}
		
		else if (copiedState[52] != ' ' && copiedState[52] == copiedState[53] && copiedState[52] == copiedState[54] && copiedState[52] == copiedState[55]) {
			gameWon = 1;
		}
		
		else if (copiedState[56] != ' ' && copiedState[56] == copiedState[57] && copiedState[56] == copiedState[58] && copiedState[56] == copiedState[59]) {
			gameWon = 1;
		}
		
		else if (copiedState[60] != ' ' && copiedState[60] == copiedState[61] && copiedState[61] == copiedState[62] && copiedState[60] == copiedState[63]) {
			gameWon = 1;
		}
	

	///Flat vertical
		//Layer 1
		else if (copiedState[0] != ' ' && copiedState[0] == copiedState[4] && copiedState[0] == copiedState[8] && copiedState[0] == copiedState[12]) {
			gameWon = 1;
		}

		else if (copiedState[1] != ' ' && copiedState[1] == copiedState[5] && copiedState[1] == copiedState[9] && copiedState[1] == copiedState[13]) {
			gameWon = 1;
		}

		else if (copiedState[2] != ' ' && copiedState[2] == copiedState[6] && copiedState[2] == copiedState[10] && copiedState[2] == copiedState[14]) {
			gameWon = 1;
		}

		else if (copiedState[3] != ' ' && copiedState[3] == copiedState[7] && copiedState[3] == copiedState[11] && copiedState[3] == copiedState[15]) {
			gameWon = 1;
		}

		//Layer 2
		else if (copiedState[16] != ' ' && copiedState[16] == copiedState[20] && copiedState[16] == copiedState[24] && copiedState[16] == copiedState[28]) {
			gameWon = 1;
		}

		else if (copiedState[17] != ' ' && copiedState[17] == copiedState[21] && copiedState[17] == copiedState[25] && copiedState[17] == copiedState[29]) {
			gameWon = 1;
		}

		else if (copiedState[18] != ' ' && copiedState[18] == copiedState[22] && copiedState[18] == copiedState[26] && copiedState[18] == copiedState[30]) {
			gameWon = 1;
		}

		else if (copiedState[19] != ' ' && copiedState[19] == copiedState[23] && copiedState[19] == copiedState[27] && copiedState[19] == copiedState[31]) {
			gameWon = 1;
		}

		//Layer 3
		else if (copiedState[32] != ' ' && copiedState[32] == copiedState[36] && copiedState[32] == copiedState[40] && copiedState[32] == copiedState[44]) {
			gameWon = 1;
		}

		else if (copiedState[33] != ' ' && copiedState[33] == copiedState[37] && copiedState[33] == copiedState[41] && copiedState[33] == copiedState[45]) {
			gameWon = 1;
		}

		else if (copiedState[34] != ' ' && copiedState[34] == copiedState[36] && copiedState[34] == copiedState[40] && copiedState[34] == copiedState[44]) {
			gameWon = 1;
		}

		else if (copiedState[35] != ' ' && copiedState[35] == copiedState[39] && copiedState[35] == copiedState[43] && copiedState[35] == copiedState[47]) {
			gameWon = 1;
		}

		//Layer 4
		else if (copiedState[48] != ' ' && copiedState[48] == copiedState[52] && copiedState[48] == copiedState[56] && copiedState[48] == copiedState[60]) {
			gameWon = 1;
		}

		else if (copiedState[49] != ' ' && copiedState[49] == copiedState[53] && copiedState[49] == copiedState[57] && copiedState[49] == copiedState[61]) {
			gameWon = 1;
		}

		else if (copiedState[50] != ' ' && copiedState[50] == copiedState[54] && copiedState[50] == copiedState[58] && copiedState[50] == copiedState[62]) {
			gameWon = 1;
		}

		else if (copiedState[51] != ' ' && copiedState[51] == copiedState[55] && copiedState[51] == copiedState[59] && copiedState[51] == copiedState[63]) {
			gameWon = 1;
		}


	///Flat diagonal
		//Layer 1
		else if (copiedState[0] != ' ' && copiedState[0] == copiedState[5] && copiedState[0] == copiedState[10] && copiedState[0] == copiedState[15]) {
			gameWon = 1;
		}

		else if (copiedState[3] != ' ' && copiedState[3] == copiedState[6] && copiedState[3] == copiedState[9] && copiedState[3] == copiedState[12]) {
			gameWon = 1;
		}

		//Layer 2
		else if (copiedState[16] != ' ' && copiedState[16] == copiedState[21] && copiedState[16] == copiedState[26] && copiedState[16] == copiedState[31]) {
			gameWon = 1;
		}

		else if (copiedState[19] != ' ' && copiedState[19] == copiedState[22] && copiedState[19] == copiedState[25] && copiedState[19] == copiedState[28]) {
			gameWon = 1;
		}

		//Layer 3
		else if (copiedState[32] != ' ' && copiedState[32] == copiedState[37] && copiedState[32] == copiedState[42] && copiedState[32] == copiedState[47]) {
			gameWon = 1;
		}

		else if (copiedState[35] != ' ' && copiedState[35] == copiedState[38] && copiedState[35] == copiedState[41] && copiedState[35] == copiedState[44]) {
			gameWon = 1;
		}

		//Layer 4
		else if (copiedState[48] != ' ' && copiedState[48] == copiedState[53] && copiedState[48] == copiedState[58] && copiedState[48] == copiedState[63]) {
			gameWon = 1;
		}

		else if (copiedState[51] != ' ' && copiedState[51] == copiedState[54] && copiedState[51] == copiedState[57] && copiedState[51] == copiedState[60]) {
			gameWon = 1;
		}

		
	///3D vertical
		//Row 1
		

		//Row 2


		//Row 3


		//Row 4

	

	///3D diagonal edge
		//Bottom north edge to top south edge


		//Bottom east edge to top west edge

		
		//Bottom south edge to top north edge


		//Bottom west eadge to top east edge



	///3D diagonal corners
		//Bottom northwest corner to top southeast corner


		//Bottom northeast corner to top southwest corner


		//Bottom southeast corner to top northwest corner
		

		//Bottom southwest corner to top northeast corner
}