// Base.h : base class of Games <<

#pragma once

//link other files
#include "Pieces.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


class GameBase {

public:
	GameBase(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, string, string);

	enum response { success, fail, quit, terminate, drawEnd };

	static GameBase* createGame(int argc, char * argv[]); 

	//Pure Virtual
	virtual void print() = 0; //print board
	virtual bool done() = 0; //has win happend?
	virtual bool draw() = 0; //is win no longer possible?
	virtual int turn() = 0; //implements player's move

	int play(); //play full game

protected:
	//MEMBER VARIABLES

	//dimensions of display
	unsigned int height;
	unsigned int width;

	//dimensions of actual board
	unsigned int boardHeight;
	unsigned int boardWidth;

	unsigned int longestDisp; //UPDATE 

	unsigned int winLength;

	bool turnFirst; //is player 1's turn
	string firstLog; //player 1's move history
	string secondLog; //player 2's move history

	string playerOne;
	string playerTwo;

	vector<game_piece> pieceBoard; //stores the board

	//METHODS:

	virtual int prompt(unsigned int &, unsigned int &);
	
};
