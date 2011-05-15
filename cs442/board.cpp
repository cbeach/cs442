#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include "board.h"
#include "defs"


using namespace std;

Board::Board(){

	pieceCount = 20;
	onMove = true;

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
	
	board[0] = king;
	king = new piece; 

	king->x = 4;
	king->y = 5;
	king->val = 10000;
	king->player = true;

	board[1] = king;
	
	queen->x = 1;
	queen->y = 0;
	queen->val = 900;
	queen->player = false;

	board[2] = queen;
	queen = new piece; 
	
	queen->x = 3;
	queen->y = 5;
	queen->val = 900;
	queen->player = true;
	
	board[3] = queen;
	
	bishop->x = 2;
	bishop->y = 0;
	bishop->val = 301;
	bishop->player = false;

	board[4] = bishop;
	bishop = new piece;

	bishop->x = 2;
	bishop->y = 5;
	bishop->val = 301;
	bishop->player = true;
	
	board[5] = bishop;

	knight->x = 3;
	knight->y = 0;
	knight->val = 300;
	knight->player = false;
	
	board[6] = knight;
	knight = new piece;

	knight->x = 1;
	knight->y = 5;
	knight->val = 300;
	knight->player = true;
	
	board[7] = knight;
	
	rook->x = 4;
	rook->y = 0;
	rook->val = 500;
	rook->player = false;

	board[8] = rook;
	rook = new piece;

	rook->x = 0;
	rook->y = 5;
	rook->val = 500;
	rook->player = true;

	board[9] = rook;

	for(int i = 10; i < 15; i++){
		
		pawn->x = i - 10;
		pawn->y = 1;
		pawn->val = 100;
		pawn->player = false;
		board[i] = pawn;
		pawn = new piece;

	}
	for(int i = 15; i < 20; ++i){
		pawn->x = i - 15;
		pawn->y = 4;
		pawn->val = 100;
		pawn->player = true;
		board[i] = pawn;
		pawn = new piece;
	}

}

Board::~Board(){
}

vector<piece>* Board::getBoard(){
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

void Board::moveGen(move *subRoot){

	kingGen(subRoot);
		
}

void Board::kingGen(move* subRoot){
	
	move *temp = NULL;

	if(onMove){
		for(int i = 0; i < pieceCount; i++){
			if(board[i]->player && board[i]->val == 10000){
				if(board[i]->x < 4){
					temp = new move(subRoot);
					temp->x = board[i]->x + 1;
					subRoot->children.insert(subRoot->it, temp);
					if(board[i]->y < 5){
						temp = new move(subRoot);
						temp->x = board[i]->x + 1;
						temp->y = board[i]->y + 1;
						subRoot->children.insert(subRoot->it, temp);
					}
					if(board[i]->y > 0){
						temp = new move(subRoot);
						temp->x = board[i]->x + 1;
						temp->y = board[i]->y - 1;
						subRoot->children.insert(subRoot->it, temp);
					}
					
				}
				#ifdef CAREFUL
				else
					cerr << "White king out of bounds " << board[i]->x << " " << board[i]->y << endl;
				#endif

				if(board[i]->x > 0){
					temp = new move(subRoot);
					temp->x = board[i]->x - 1;
					subRoot->children.insert(subRoot->it, temp);
					if(board[i]->y < 5){
						temp = new move(subRoot);
						temp->x = board[i]->x - 1;
						temp->y = board[i]->y + 1;
						subRoot->children.insert(subRoot->it, temp);
					}
					if(board[i]->y > 0){
						temp = new move(subRoot);
						temp->x = board[i]->x - 1;
						temp->y = board[i]->y - 1;
						subRoot->children.insert(subRoot->it, temp);
					}
					
				}
				#ifdef CAREFUL
				else
					cerr << "White king out of bounds " << board[i]->x << " " << board[i]->y << endl;
				#endif

				if(board[i]->y > 0){
					temp = new move(subRoot);
					temp->x = board[i]k

				}
			}
		}

	}
	else{


	}
}
void Board::queenGen(move * subRoot){
	

}
void Board::bishGen(move *subRoot){}
void Board::knightGen(move *subRoot){}
void Board::rookGen(move *subRoot){}
void Board::pawnGen(move *subRoot){}

