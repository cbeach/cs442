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

#ifndef GUIBOARD_H
#define GUIBOARD_H

#include <QtGui/QWidget>

class QPushButton;
class GuiButton;
class QLabel;
class Board;

class GuiBoard: public QWidget
{

	Q_OBJECT;
	
	public:
		GuiBoard();
		~GuiBoard();
		
		void setBoard(Board*);	//this sets the Board(tictactoe engine)
		Board const* getBoard();//get the Board

	public slots:
		//if a player clicks a button this slot is notified
		void nextTurn();
	signals:
		//if the players click a button after the game is over
		//(win or draw)
		void newGameSignal();
	protected:
		//status int and enum that keeps track of what state the game is in
		int GameStatusInteger;
		
		//this is the 3X3 grid of GuiButton Pointers
		QLabel ***LabelBoard;	
		QPixmap **WhitePieces;
		QPixmap **BlackPieces;

		//status symbols that tell the player who's turn it is

		QLabel *TurnLabel;
		
		//game status, White won, Black won, draw
		QLabel *GameStatusLabel;

		//tictactoe engine
		Board *chessBoard;
		
		//who's turn is it
		bool Player;	//true = White false = Black

		//complex initialization taskes that I didn't want to
		//handle in the constructor
		void init();
		void setPieces();
		//erase everything and start over

};

#endif
