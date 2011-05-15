#ifndef _BOARD_H
#define _BOARD_H

#include "structures.h"

using namespace std;


class Board{

	public:
		Board();
		~Board();

		vector<piece>* getBoard();
		void moveGen(move*);
		void updateBoard(char*);
		int eval();
		void displayBoard();
	protected:
		int pieceCount;
		string startingPosition;
		
		piece* board[20];	
		bool onMove;  //true = white
	
		move * root;
		
		void kingGen(move*);		
		void queenGen(move*);		
		void bishGen(move*);		
		void knightGen(move*);		
		void rookGen(move*);		
		void pawnGen(move*);		
		


		
};
#endif
