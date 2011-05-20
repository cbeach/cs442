#ifndef _BOARD_H
#define _BOARD_H

#include "structures.h"

using namespace std;


class Board{

	public:
		Board();
		Board(int x, int y, int pieceType);
		~Board();

		vector<piece>* getBoard();
		move* getMove();
		move* getRandomMove();
		void updateBoard(char*);
		int eval();
		void displayBoard();
		void displayMoves();
		
		void executeMove(move*);

		void Init();

		int getWinner();
	protected:
		int pieceCount;
		bool winner;

		string startingPosition;
		
		piece* board[20];	
		bool onMove;  //true = white
	
		move * root;
		
		vector<move*>::iterator it;
		
		void undoMove();


		void moveGen(move*);
		bool scanMove(int x, int y, int dir, bool recure, int piece,
		move *subRoot, bool srcPlayer);

		bool kqMoveCheck(int xsrc, int ysrc, int xdst, int ydst, bool srcPlayer);
		bool bishopMoveCheck(int xsrc, int ysrc, int xdst, int ydst, bool srcPlayer, int dir);
		 
		void knightOffset(int xsrc, int ysrc, int *xdst, int* ydst, int dir);
		bool knightMoveCheck(int xsrc, int ysrc, int xdst, int ydst, bool srcPlayer, int dir);
		bool rookMoveCheck(int xsrc, int ysrc, int xdst, int ydst, bool srcPlayer);
		bool pawnMoveCheck(int xsrc, int ysrc, int xdst, int ydst, bool srcPlayer);
		

		
};
#endif
