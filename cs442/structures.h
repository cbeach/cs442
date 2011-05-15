#ifndef _STRUCTURE_H
#define _STRUCTURE_H

#include <vector>

const int NW = 1;
const int N = 2;
const int NE = 3;
const int E = 4;
const int SE = 5;
const int S = 6;
const int SW = 7;
const int W = 8;

const int KING = 1;
const int QUEEN = 2;
const int BISHOP = 3;
const int KNIGHT = 4;
const int ROOK = 5;
const int PAWN = 6;

using namespace std;

struct move{

	int to[2];
	int from[2];
	bool player; //white = true
	move *parent;
	vector <move*> children;
	vector <move*>::iterator it;

	move(move* old){
		to[0] = old->to[0];
		to[1] = old->to[1];

		from[0] = old->from[0];
		from[1] = old->from[1];
		
		player = old->player;

		parent = NULL;		
	}
};

struct cell{
	int coord[2];
};

struct piece{
	int x;
	int y;
	int val;
	bool player;
};

#endif
