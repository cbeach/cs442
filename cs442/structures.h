#ifndef _STRUCTURE_H
#define _STRUCTURE_H

#include <vector>


using namespace std;


struct piece{
	int x;
	int y;
	int val;
	bool player;
	int designation;
};

struct move{

	int x1, y1;	//source coordinates
	int x2, y2;	//destination coordinates
	bool player; 	//true = white
	int childrenSize;
	move *parent;
	move *children[128];
	piece* movedPiece;
	
		
	move(int inX1, int inY1, int inX2, int inY2, bool inPlayer){
		x1 = inX1;
		y1 = inY1;
		x2 = inX2;
		y2 = inY2;
		player = inPlayer;
		childrenSize = 0;
	}
	move(move* old){
		x1 = old->x1;
		y1 = old->y1;
		
		x2 = old->x2;
		y2 = old->y2;

		player = old->player;

		parent = NULL;		
		childrenSize = old->childrenSize;
		for(int i = 0; i < childrenSize; i++){
			children[i] = old->children[i];
		}
	}
};

struct cell{
	int coord[2];
};

#endif
