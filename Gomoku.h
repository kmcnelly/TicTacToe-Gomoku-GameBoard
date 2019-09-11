// Gomokus.h : Declares Gomoku class w/ methods and instances. Also, overloaded <<

#pragma once

//link other files
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Base.h"


using namespace std;


class GomokuGame : public GameBase {

private:
	enum board { n = 19,
		board_height = n, board_width = n, max_height = board_height + 2, max_width = board_width + 2,
		xCorner = 0, yCorner = 0, xStart = xCorner + 1, yStart = yCorner + 1, boarder_count,
		win_Length = 5
	};
	
	//max_height & width include out of bounds boarder
	//static unsigned int board_height;
	//static unsigned int board_width;
	//static unsigned int max_height;
	//static unsigned int max_width;

	//static unsigned int winLength;

public:
	GomokuGame(); //default

	GomokuGame(unsigned int, unsigned int); //altered dimensions and winlength

	//overrides of Gamebase's
	virtual void print();
	virtual bool done();
	virtual bool draw();

	virtual int turn();

	friend ostream & operator<<  (ostream &, const GomokuGame &);
};

//overload to print TicTacToeGame
ostream & operator<< (ostream &, const GomokuGame &);
