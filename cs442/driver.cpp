#include <iostream>
#include "board.h"
#include "defs.h"

using namespace std;

int main( int argc, char** argv){
	Board b(2, 4, KING);
	b.displayBoard();
	b.getMove();
	return 0;
}
