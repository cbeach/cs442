#include <iostream>
#include "board.h"
#include "defs.h"

using namespace std;

int main( int argc, char** argv){
	Board b;
	move* tempMove = 0;
	cout << endl;

	while(b.getWinner() == 0){
		tempMove = b.getRandomMove();
		b.displayBoard();
		cout << endl << endl;
		b.displayMoves();
		cout << endl;

		cout << "--------------------------" << endl;
		b.executeMove(tempMove);
	}
	if(b.getWinner() == 1)
		cout << "White Wins" << endl;
	else 
		cout << "Black Wins" << endl;

	return 0;
}
