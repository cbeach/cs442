#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
#include <stdio.h>
#include "board.h"

using namespace std;

Board::Board(){

	pieceCount = 20;

	piece * king = new piece; 
	piece *queen = new piece; 
	piece *rook = new piece; 
	piece *bishop = new piece; 
	piece *knight = new piece; 
	piece *pawn = new piece; 

	king->x = 0;
	king->y = 0;
	king->val = 10000;
	king->player = false;

	queen->x = 1;
	queen->y = 0;
	queen->val = 900;
	queen->player = false;

	bishop->x = 2;
	bishop->y = 0;
	bishop->val = 301;
	bishop->player = false;

	knight->x = 3;
	knight->y = 0;
	knight->val = 300;
	knight->player = false;
	
	rook->x = 4;
	rook->y = 0;
	rook->val = 500;
	rook->player = false;

	board[0] = king;
	board[1] = queen;
	board[2] = bishop;
	board[3] = knight;
	board[4] = rook;
	

	for(int i = 5; i < 10; i++){
		
		pawn->x = i - 5;
		pawn->y = 1;
		pawn->val = 100;
		pawn->player = false;
		board[i] = pawn;
		pawn = new piece;

	}
	for(int i = 10; i < 15; ++i){
		pawn->x = i - 10;
		pawn->y = 4;
		pawn->val = 100;
		pawn->player = true;
		board[i] = pawn;
		pawn = new piece;
	}

	king = new piece; 
	queen = new piece; 
	rook = new piece; 
	bishop = new piece; 
	knight = new piece; 
	pawn = new piece; 
	
	king->x = 4;
	king->y = 5;
	king->val = 10000;
	king->player = true;

	queen->x = 3;
	queen->y = 5;
	queen->val = 900;
	queen->player = true;

	bishop->x = 2;
	bishop->y = 5;
	bishop->val = 301;
	bishop->player = true;

	knight->x = 1;
	knight->y = 5;
	knight->val = 300;
	knight->player = true;
	
	rook->x = 0;
	rook->y = 5;
	rook->val = 500;
	rook->player = true;
	
	board[15] = king;
	board[16] = queen;
	board[17] = bishop;
	board[18] = knight;
	board[19] = rook;
}

Board::~Board(){
}

vector<piece>* Board::getBoard(){
	return NULL;
}

int** Board::moveGen(){


	return NULL;
}
void Board::updateBoard(char* move){}
int Board::eval(){

	return NULL;
}

void Board::displayBoard(){
	char * textBoard[5];

	for(int i = 0; i < 5; ++i){
		textBoard[i] = new char[6];
		for(int j = 0; j < 6; ++j){
			textBoard[i][j] = 'x';

		}
	}

	for(int i = 0; i < pieceCount; i++){
		switch(board[i]->val){
			case 10000: textBoard[board[i]->x][board[i]->y] = 'k';
				  break;
				 
			case 900: textBoard[board[i]->x][board[i]->y] = 'q';
				  break;
			case 301: textBoard[board[i]->x][board[i]->y] = 'b';
				  break;
			case 300: textBoard[board[i]->x][board[i]->y] = 'n';
				  break;
			case 500: textBoard[board[i]->x][board[i]->y] = 'r';
				  break;
			case 100: textBoard[board[i]->x][board[i]->y] = 'p';
				  break;
			default:  break;
		}

		if(board[i]->player && textBoard != 'x')
			textBoard[board[i]->x][board[i]->y] =
			toupper(textBoard[board[i]->x][board[i]->y]);
	}
	
	for(int i = 0; i < 5; i++){
		cout << textBoard[i] << endl;
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

