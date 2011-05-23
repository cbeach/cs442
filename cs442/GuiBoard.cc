/*****************************************************************************
The MIT License

Copyright (c) 2010 Casey Beach

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*****************************************************************************/

#include <iostream>
#include <QtGui/QWidget>
#include <QtGui/QPushButton>
#include <QtGui/QFont>
#include <QGridLayout>
#include <QBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QPalette>

#include "board.h"
#include "structures.h"
#include "defs.h"
#include "GuiBoard.h"

using namespace std;


GuiBoard::GuiBoard(){
	
	LabelBoard = new QLabel**[5];
	GameStatusInteger = 0;

	Player= true;
	for (int i = 0; i < 6; i++){
		LabelBoard[i] = new QLabel*[6];
	}	
	
	init();
}

GuiBoard::~GuiBoard()
{
	for (int i = 0; i < 6; i++){
		for (int j = 0; j < 6; j++){
			delete LabelBoard[i][j];
		}
		delete[] LabelBoard[i];
	}
	delete[] LabelBoard;
	
}

//I use init functions to handle the initialization of more complex
//data types that take a little more processing.
void
GuiBoard::init()
{
	chessBoard = new Board();
	WhitePieces = new QPixmap*[6];
	BlackPieces = new QPixmap*[6];
	QPalette *pal = NULL;

	bool blackSquare = false;

	WhitePieces[0] = new QPixmap(".qrc/K.png");
	WhitePieces[1] = new QPixmap(".qrc/Q.png");
	WhitePieces[2] = new QPixmap(".qrc/B.png");
	WhitePieces[3] = new QPixmap(".qrc/N.png");
	WhitePieces[4] = new QPixmap(".qrc/R.png");
	WhitePieces[5] = new QPixmap(".qrc/P.png");

	BlackPieces[0] = new QPixmap(".qrc/k.png");
	BlackPieces[1] = new QPixmap(".qrc/q.png");
	BlackPieces[2] = new QPixmap(".qrc/b.png");
	BlackPieces[3] = new QPixmap(".qrc/n.png");
	BlackPieces[4] = new QPixmap(".qrc/r.png");
	BlackPieces[5] = new QPixmap(".qrc/p.png");
	
	nullPixmap = new QPixmap("");

	QGridLayout *grid = new QGridLayout;
	
	//these are the icons at the bottom that show who's turn it is

	TurnLabel = new QLabel();
	GameStatusLabel = new QLabel();
	GameStatusLabel->setPixmap(*WhitePieces[0]);
	QPushButton *nextTurnButton = new QPushButton();
	
	//this block adds all of the labels to the grid.
	nextTurnButton->setMaximumSize(75,75);
	nextTurnButton->setMinimumSize(75,75);
 	connect(nextTurnButton, SIGNAL(clicked()),
					this, SLOT(nextTurn()));

	grid->addWidget(nextTurnButton, 6, 0, Qt::AlignHCenter | Qt::AlignVCenter);
	grid->addWidget(TurnLabel, 6, 2, Qt::AlignHCenter | Qt::AlignVCenter);
	grid->addWidget(GameStatusLabel, 6, 4, Qt::AlignHCenter | Qt::AlignVCenter);
	//create 9 new GuiButtons, connect all of the signals to the apropriate slots,
	//set their size and font, show them the pointer to the tictactoe engine and 
	//put them in the grid layout.
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			LabelBoard[i][j] = new QLabel();
			LabelBoard[i][j]->setAutoFillBackground(true);
			if(blackSquare){
				pal = new QPalette(LabelBoard[i][j]->palette());
				pal->setColor(QPalette::Window, Qt::darkGray);
				LabelBoard[i][j]->setPalette(*pal);
			}
			blackSquare = !blackSquare;
			grid->addWidget(LabelBoard[i][j],i,j);	
					
		}
	}
	for(int i = 0; i < 5; i++){
		grid->setColumnStretch(i,0);
		grid->setColumnMinimumWidth(i,75);
	}

	for(int i = 0; i < 7; i++){
		grid->setRowStretch(i,0);
		grid->setRowMinimumHeight(i,75);
	}

	//add the gridLayout to a BoxLayout so that Qt will look at it as one widget.
	QVBoxLayout *box = new QVBoxLayout;
	box->addLayout(grid);
	setLayout(box);
}

//this slot gets called everytime a player pushes a button

void GuiBoard::nextTurn() {
	chessBoard->executeMove(chessBoard->getRandomMove());

	char** temp = chessBoard->getBoard();
	displayBoard(temp);

}

void GuiBoard::displayBoard(char** textBoard){
	
	
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 6; j++){
			LabelBoard[j][i]->setPixmap(NULL);		
			switch(textBoard[i][j]){
				case 'K':
					LabelBoard[j][i]->setPixmap(*WhitePieces[0]);
					break;
				case 'Q':
					LabelBoard[j][i]->setPixmap(*WhitePieces[1]);
					break;
				case 'B':
					LabelBoard[j][i]->setPixmap(*WhitePieces[2]);
					break;
				case 'N':
					LabelBoard[j][i]->setPixmap(*WhitePieces[3]);
					break;
				case 'R':
					LabelBoard[j][i]->setPixmap(*WhitePieces[4]);
					break;
				case 'P':
					LabelBoard[j][i]->setPixmap(*WhitePieces[5]);
					break;
				case 'k':
					LabelBoard[j][i]->setPixmap(*BlackPieces[0]);
					break;
				case 'q':
					LabelBoard[j][i]->setPixmap(*BlackPieces[1]);
					break;
				case 'b':
					LabelBoard[j][i]->setPixmap(*BlackPieces[2]);
					break;
				case 'n':
					LabelBoard[j][i]->setPixmap(*BlackPieces[3]);
					break;
				case 'r':
					LabelBoard[j][i]->setPixmap(*BlackPieces[4]);
					break;
				case 'p':
					LabelBoard[j][i]->setPixmap(*BlackPieces[5]);
					break;





			}
		}
	}


}

























