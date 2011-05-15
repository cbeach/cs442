#ifndef _STRUCTURE_H
#define _STRUCTURE_H

#include <vector>


using namespace std;

struct move{

	int x1, y1;	//source coordinates
	int x2, y2;	//destination coordinates
	bool player; 	//true = white
	move *parent;
	vector <move*> children;
	vector <move*>::iterator it;
	
	move(int inX1, int inY1, int inX2, int inY2, bool inPlayer){
	

	}
	move(move* old){
		x1 = old->x1;
		y1 = old->y1;
		
		x2 = old->x2;
		y2 = old->y2;

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
	int designation;
};

#endif
