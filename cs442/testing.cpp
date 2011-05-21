#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
#include <assert.h>
#include <time.h>

#include "board.h"
#include "defs.h"


using namespace std;


//for displaying the moves on the test board
void Board::displayMoves(){
	
	char * textBoard[5];

	for(int i = 0; i < 5; i++){
		textBoard[i] = new char[6];
		for(int j = 0; j < 6; ++j){
			textBoard[i][j] = '.';
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

		if(board[i]->player && textBoard[board[i]->x][board[i]->y] != '.')
			textBoard[board[i]->x][board[i]->y] =
			toupper(textBoard[board[i]->x][board[i]->y]);
	}

	move *tempMove = NULL;
	
	for(int i = 0; i < root->childrenSize; i++){
		tempMove = root->children[i];
		textBoard[tempMove->x2][tempMove->y2] = 'x';
	}
		
	for(int i = 4; i >= 0; i--){
		cout << textBoard[i] << endl;
	}

	
}

void Board::displayBoard(){
	char * textBoard[5];

	for(int i = 0; i < 5; i++){
		textBoard[i] = new char[6];
		for(int j = 0; j < 6; ++j){
			textBoard[i][j] = '.';
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

		if(board[i]->player && textBoard[board[i]->x][board[i]->y] != 'x')
			textBoard[board[i]->x][board[i]->y] =
			toupper(textBoard[board[i]->x][board[i]->y]);
	}
	
	for(int i = 4; i >= 0; i--){
		cout << textBoard[i] << endl;
	}

}

void Board::displayPieces(){
	for(int i = 0; i < pieceCount; i++){	
		cout << "x: " << board[i]-> x << '\t';
	}
	for(int i = 0; i < pieceCount; i++){
		cout << "y: " << board[i]-> y << '\t';
	}
	for(int i = 0; i < pieceCount; i++){
		switch(board[i]->designation){
			case KING:
				cout << "King" << '\t';
				break;
			case QUEEN:
				cout << "Queen" << '\t';
				break;
			case BISHOP:
				cout << "Bishop" << '\t';
				break;
			case KNIGHT:
				cout << "Knight" << '\t';
				break;
			case ROOK:
				cout << "Rook" << '\t';
				break;
			case PAWN:
				cout << "Pawn" << '\t';
				break;
		}
	}
	for(int i = 0; i < 15; i++){	
		cout << "x: " << board[i]-> x << endl;
		cout << "y: " << board[i]-> y << endl;
		switch(board[i]->designation){
			case KING:
				cout << "King" << endl;
				break;
			case QUEEN:
				cout << "Queen" << endl;
				break;
			case BISHOP:
				cout << "Bishop" << endl;
				break;
			case KNIGHT:
				cout << "Knight" << endl;
				break;
			case ROOK:
				cout << "Rook" << endl;
				break;
			case PAWN:
				cout << "Pawn" << endl;
				break;
		}
	}
}

void Board::displayMove(move* mv){

	cout << "x1: " << mv->x1 << '\t' << "x2: " << mv->x2 << endl;
	cout << "y1: " << mv->y1 << '\t' << "y2: " << mv->y2 << endl;
	if(onMove == WHITE)
		cout << "White" << endl;
	else 
		cout << "Black" << endl;

}
