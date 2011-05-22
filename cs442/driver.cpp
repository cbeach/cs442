#include <QtGui/QApplication>
#include <QtGui/QPushButton>
#include <QtGui/QGridLayout>
#include <QtGui/QWidget>
#include <QtGui/QGraphicsView>
#include <QtGui/QGraphicsScene>
#include <QtGui/QGraphicsItem>
#include <QtGui/QLabel>


#include "board.h"
#include "defs.h"
#include "GuiBoard.h"

#define GUI

using namespace std;
#ifdef GUI
int main(int argc, char** argv)
{
		QApplication app(argc,argv);	
		GuiBoard board;
		board.show();
		return app.exec();
}
#endif
/*
#ifndef GUI

int main( int argc, char** argv){
	board b;
	move* tempMove = 0;
	cout << endl;

	while(b.getWinner() == 0){
		tempMove = b.getRandomMove();
		b.displayBoard();
		cout << endl << endl;
		b.displayMoves();
		cout << endl;

		cout << "--------------------------" << endl;
		b.executeMove(tempMove);
	}
	if(b.getWinner() == 1)
		cout << "White Wins" << endl;
	else 
		cout << "Black Wins" << endl;

	return 0;
}
#endif
*/

