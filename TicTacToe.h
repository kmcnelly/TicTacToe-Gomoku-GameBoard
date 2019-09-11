// TicTacToe.h : Declares TicTaceToeGame class w/ methods and instances. Also, overloaded <<

#pragma once

//link other files
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Base.h"


using namespace std;


class TicTacToeGame: public GameBase {

private:
	enum board {
		max_height = 5, max_width = 5,
		board_height = 3, board_width = 3,
		xCorner = 0, yCorner = 0,
		xStart = xCorner + 1, yStart = yCorner + 1,
		winLength = 5,
	};

//	const unsigned int height = max_height;
//	const unsigned int width = max_width;
//	bool turnFirst;
//	string firstLog;
//	string secondLog;
//
//	vector<game_piece> pieceBoard;


public:
	TicTacToeGame();

	//overrides of Gamebase's
	virtual void print();
	virtual bool done();
	virtual bool draw();
	
	virtual int turn();
	

	friend ostream & operator<<  (ostream &, const TicTacToeGame &);
};

//overload to print TicTacToeGame
ostream & operator<< (ostream &, const TicTacToeGame &);