#include <iostream>
#include "board.h"

using namespace std;

int main( int argc, char** argv){
	Board b;
	b.displayBoard();
	cout << "entering gen" << endl;	
	b.moveGen();

	return 0;
}
