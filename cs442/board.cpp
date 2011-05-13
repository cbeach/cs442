#include <iostream>
#include <string>
#include <queue>
#include "board.h"

using namespace std;

Board::Board(){
	board = new char*[6];

	for(int i = 0; i < 6; i++)
		board[i] = new char[5];
	
	onMove = true;

	board[0][0] = 'k';
	board[0][1] = 'q';
	board[0][2] = 'b';
	board[0][3] = 'n';
	board[0][4] = 'r';

	board[1][0] = 'p';
	board[1][1] = 'p';
	board[1][2] = 'p';
	board[1][3] = 'p';
	board[1][4] = 'p';

	for(int i = 2; i < 4; i++)
		for(int j = 0; j < 6; j++){
			board[i][j] = 'x';
		}

	board[4][0] = 'P';
	board[4][1] = 'P';
	board[4][2] = 'P';
	board[4][3] = 'P';
	board[4][4] = 'P';

	board[5][4] = 'K';
	board[5][3] = 'Q';
	board[5][2] = 'B';
	board[5][1] = 'N';
	board[5][0] = 'R';
}

Board::~Board(){
	for(int i = 0; i < 5; i++)
		delete[] board[i];
	delete[] board;
}

const int ** Board::getBoard(){
	return (const int**)board;
}

int** Board::moveGen(){


	return NULL;
}
void Board::updateBoard(char* move){}
int Board::eval(){

	return NULL;
}

void Board::displayBoard(){
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 5; j++){
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}

}

void Board::kingGen(cell king){
	
	int x = king.coord[0];
	int y = king.coord[1];

	
	
	
}
void Board::queenGen(cell queen){
	

}
void Board::bishGen(cell bishop){}
void Board::knightGen(cell knight){}
void Board::rookGen(cell rook){}
void Board::pawnGen(cell pawn){}

