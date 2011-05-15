#ifndef _BOARD_H
#define _BOARD_H

#include "structures.h"

using namespace std;


class Board{

	public:
		Board();
		Board(int pieceType, int x, int y);
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
		

		bool scanMove(int x, int y, int dir, bool recure, int piece, move* moveArray,
		int moveArrayidx, bool srcPlayer);

		bool kqMoveCheck(int xsrc, int ysrc, int xdst, int ydst, bool srcPlayer);
		bool bishopMoveCheck(int xsrc, int ysrc, int xdst, int ydst, bool srcPlayer, int dir);
		bool rookMoveCheck(int xsrc, int ysrc, int xdst, int ydst, bool srcPlayer);
		bool pawnMoveCheck(int xsrc, int ysrc, int xdst, int ydst, bool srcPlayer);

		
};
#endif
