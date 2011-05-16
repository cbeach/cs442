#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include "board.h"
#include "defs.h"


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
	king->designation = KING;
	
	board[0] = king;
	king = new piece; 

	king->x = 4;
	king->y = 5;
	king->val = 10000;
	king->player = true;
	king->designation = KING;

	board[1] = king;
	
	queen->x = 1;
	queen->y = 0;
	queen->val = 900;
	queen->player = false;
	queen->designation = QUEEN;

	board[2] = queen;
	queen = new piece; 
	
	queen->x = 3;
	queen->y = 5;
	queen->val = 900;
	queen->player = true;
	queen->designation = QUEEN;
	
	board[3] = queen;
	
	bishop->x = 2;
	bishop->y = 0;
	bishop->val = 301;
	bishop->player = false;
	bishop->designation = BISHOP;

	board[4] = bishop;
	bishop = new piece;

	bishop->x = 2;
	bishop->y = 5;
	bishop->val = 301;
	bishop->player = true;
	bishop->designation = BISHOP;
	
	board[5] = bishop;

	knight->x = 3;
	knight->y = 0;
	knight->val = 300;
	knight->player = false;
	bishop->designation = KNIGHT;
	
	board[6] = knight;
	knight = new piece;

	knight->x = 1;
	knight->y = 5;
	knight->val = 300;
	knight->player = true;
	knight->designation = KNIGHT;
	
	board[7] = knight;
	
	rook->x = 4;
	rook->y = 0;
	rook->val = 500;
	rook->player = false;
	rook->designation = ROOK;

	board[8] = rook;
	rook = new piece;

	rook->x = 0;
	rook->y = 5;
	rook->val = 500;
	rook->player = true;
	rook->designation = ROOK;

	board[9] = rook;

	for(int i = 10; i < 15; i++){
		
		pawn->x = i - 10;
		pawn->y = 1;
		pawn->val = 100;
		pawn->player = false;
		pawn->designation = PAWN;
		board[i] = pawn;
		pawn = new piece;

	}
	for(int i = 15; i < 20; i++){
		pawn->x = i - 15;
		pawn->y = 4;
		pawn->val = 100;
		pawn->player = true;
		pawn->designation = PAWN;
		board[i] = pawn;
		pawn = new piece;
	}

}

//constructor for setting up test boards

Board::Board(int x, int y, int pieceType){
	piece *tempPiece = new piece;
	pieceCount = 1;
	root = new move(0,0,0,0,WHITE);
	
	switch(pieceType){
		case KING:	
			tempPiece->x = x;
			tempPiece->y = y;
			tempPiece->val = 10000;
			tempPiece->player = false;
			tempPiece->designation = KING;
			
			board[0] = tempPiece;
			break;

		case QUEEN:	
			tempPiece->x = x;
			tempPiece->y = y;
			tempPiece->val = 900;
			tempPiece->player = false;
			tempPiece->designation = QUEEN;
			
			board[0] = tempPiece;
			break;

		case BISHOP:
			tempPiece->x = x;
			tempPiece->y = y;
			tempPiece->val = 301;
			tempPiece->player = false;
			tempPiece->designation = BISHOP;
			
			board[0] = tempPiece;
			break;

		case KNIGHT:
			tempPiece->x = x;
			tempPiece->y = y;
			tempPiece->val = 301;
			tempPiece->player = false;
			tempPiece->designation = KNIGHT;
			
			board[0] = tempPiece;
			break;

		case ROOK:
			tempPiece->x = x;
			tempPiece->y = y;
			tempPiece->val = 301;
			tempPiece->player = false;
			tempPiece->designation = ROOK;
			
			board[0] = tempPiece;
			break;

		case PAWN:
			tempPiece->x = x;
			tempPiece->y = y;
			tempPiece->val = 301;
			tempPiece->player = false;
			tempPiece->designation = PAWN;
			
			board[0] = tempPiece;
			break;
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
		
	for(int i = 0; i < 5; i++){
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
	
	for(int i = 0; i < 5; i++){
		cout << textBoard[i] << endl;
	}

}

move* Board::getMove(){
	moveGen(root);
	displayMoves();
	return NULL;
}

void Board::moveGen(move *subRoot){

	for(int i = 0; i < pieceCount; i++){
		switch(board[i]->designation){
			case KING:
				for(int j = 1; j < 9; j++)
					scanMove(board[i]->x, board[i]->y,
						j, false, KING, subRoot, 
						board[i]->player);
				break;
				
			case QUEEN:
				break;
			case BISHOP:
				break;
			case KNIGHT:
				break;
			case ROOK:
				break;	
			case PAWN:
				break;
		}
	}
}
void Board::kingGen(move* subRoot){
/*
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
*/
}
void Board::queenGen(move * subRoot){
	

}
void Board::bishGen(move *subRoot){}
void Board::knightGen(move *subRoot){}
void Board::rookGen(move *subRoot){}
void Board::pawnGen(move *subRoot){}

bool Board::scanMove(int x, int y, int dir, bool recure, int piece, 
			move *subRoot, bool srcPlayer){
	int x2 = 0;
	int y2 = 0;
	bool goodMove;
	
	move* tempMove;

	switch(dir){
		case NW: 
			x2 = -1;
			y2 = 1;
			break;
		case N:  
			x2 = 0;
			y2 = 1;
			break;
		case NE: 
			x2 = 1;
			y2 = 1;
			break;
		case E:  
			x2 = 1;
			y2 = 0;
			break;
		case SE: 
			x2 = 1;
			y2 = -1;
			break;
		case S:  
			x2 = 0;
			y2 = -1;
			break;
		case SW: 
			x2 = -1;
			y2 = -1;
			break;
		case W:	 
			x2 = -1;
			y2 = 0;
			break;
	}

	switch(piece){
		case KING: 
			goodMove = kqMoveCheck(x, y, x2, y2, srcPlayer);		
			break;
		case QUEEN:
			goodMove = kqMoveCheck(x, y, x2, y2, srcPlayer);		
			break;
		case BISHOP: 
			goodMove = bishopMoveCheck(x, y, x2, y2, srcPlayer, dir);		
			break;
		case KNIGHT: 
			goodMove = knightMoveCheck(x, y, x2, y2, srcPlayer, dir);		
		        break;
		case ROOK: 
			goodMove = rookMoveCheck(x, y, x2, y2, srcPlayer);		
			break;
		case PAWN: 
			goodMove = pawnMoveCheck(x, y, x2, y2, srcPlayer);		
			break;
	}
	if(goodMove){
		tempMove = new move(x, y, x2, y2, srcPlayer);
		subRoot->children[subRoot->childrenSize] = tempMove;
		subRoot->childrenSize++;
	}
	if(goodMove && recure)
		scanMove(x2, y2, dir, recure, piece, subRoot, srcPlayer);
	else return true;
	
	return true;
}

bool Board::kqMoveCheck(int xsrc, int ysrc, int xdst, int ydst, bool srcPlayer){
	if(xdst < 0 || xdst > X_MAX)
		return false;
	if(ydst < 0 || ydst > Y_MAX)
		return false;
	

	for(int i = 0; i < pieceCount; i++){
		if(xsrc == board[i]->x && ysrc == board[i]->y)
			continue;
		else if(xdst == board[i]->x && ydst == board[i]->y)
			if(board[i]->player == srcPlayer)
				return false;
			
	}
	return true;
}
bool Board::bishopMoveCheck(int xsrc, int ysrc, int xdst, int ydst, bool srcPlayer, int dir){

	if(xdst < 0 || xdst > X_MAX)
		return false;
	if(ydst < 0 || ydst > Y_MAX)
		return false;
	//if dir is odd do a normal bishop move. In the directional
	//constants, the diagonals are odd, and the laterals are even
	//Bit wise and with one yield zero if the number is even,
	//and it's a LOT faster than num%2

	if(dir & 1){//check the diagonals 		
		for(int i = 0; i < pieceCount; i++){
			if(xsrc == board[i]->x && ysrc == board[i]->y)
				continue;
			//check if there is a piece in the dest square
			else if(xdst == board[i]->x && ydst == board[i]->y)
				//if there is, check to see if it's the same color
				if(board[i]->player == srcPlayer)
					//if it is return false
					return false;
		}
	}
	else{//check the lateral directions
		for(int i = 0; i < pieceCount; i++){
			if(xsrc == board[i]->x && ysrc == board[i]->y)
				continue;
			//check if there is a piece in the dest square
			else if(xdst == board[i]->x && ydst == board[i]->y)
				//if there is return false
				return false;
		}
	}


	return true;
}
//god this is going to be ugly
bool Board::knightMoveCheck(int xsrc, int ysrc, int xdst, int ydst, bool srcPlayer, int dir){
	//the dest coordinates are only a distance of one away from the 


	return false;
}
bool Board::rookMoveCheck(int xsrc, int ysrc, int xdst, int ydst, bool srcPlayer){return false;}
bool Board::pawnMoveCheck(int xsrc, int ysrc, int xdst, int ydst, bool srcPlayer){return false;}


