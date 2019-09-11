// Base.cpp : Defines functions of GameBase base class, including
// Kenneth McNelly
// kmcnelly@wustl.edu

//NUMBER 17!!
#pragma once

#include "stdafx.h"

//link other files
#include "Base.h"
#include "TicTacToe.h"
#include "Gomoku.h"

#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>
#include <string>

#include <vector>

using namespace std;


GameBase::GameBase(unsigned int hIn, unsigned int wIn, unsigned int bHIn, unsigned int bWIn, unsigned int winIn, string one, string two)
	:height(hIn), width(wIn),boardHeight(bHIn),boardWidth(bWIn), winLength(winIn), playerOne(one), playerTwo(two){
	firstLog = "";
	secondLog = "";

	//initialize empty gameboard
	for (unsigned int i = 0; i < (height*width); i++) {
		pieceBoard.push_back(game_piece(noColor, "", " "));
	}

	//Player 1 going first
	turnFirst = true;
}

//Static: with program inputs, selects game to run and returns pointer to newly created game
 GameBase* GameBase::createGame(int argc, char * argv[]) {
	
	GameBase* game; //pointer
	
	//valid num inputs
	if (argc == cmdNum) {

		string inStr(argv[input]);

		//new TTT game
		if (inStr == "TicTacToe") {
			game = new TicTacToeGame();

			return game;
		}
		//new Gomoku Game
		else if(inStr == "Gomoku"){

			game = new GomokuGame();

			return game;
		}
	}
	else if (argc == gmkDim) {
		unsigned int dimIn; //expected Dimension in
		string inStr(argv[input]);

		if (inStr == "Gomoku") {
			//get dim val
			string dimStr = argv[gmkDim-1];
			if (stringstream(dimStr) >> dimIn) {
				
				//must be valid input
				if (dimIn > 2) {
					cout << "create" << endl;
					//set winlength
					unsigned int winL;
					if (dimIn < 5) {
						winL = 3; //reduced win length
					}
					else {
						winL = 5; //default
					}

					game = new GomokuGame(dimIn, winL);

					return game;
				}

			}
		}
	}
	else if (argc == gmkDimAndWin) {

		unsigned int dimIn; //expected Dimension in
		unsigned int winLIn; //expected Dimension in
		string inStr(argv[input]);

		if (inStr == "Gomoku") {
			//get dim val
			string dimStr = argv[gmkDim-1];
			if (stringstream(dimStr) >> dimIn) {
				//must be valid input
				if (dimIn > 2) {

					//get winLength in val
					string winLStr = argv[gmkDimAndWin - 1];
					if (stringstream(winLStr) >> winLIn) {

						//must be valid winLength
						if (winLIn > 2 && winLIn <= dimIn) {

							game = new GomokuGame(dimIn, winLIn);

							return game;
						}
					}
				}

			}
		}
	}
	
	game = 0; //singular 

	return game;
}

//acquires user inputed row and col or quit command. coord must be: x,y --------
int GameBase::prompt(unsigned int & x, unsigned int & y) {

	bool validResp = false;
	string input;

	unsigned int xIn, yIn;
	char c; //must be comma

	while (!validResp) {
		cout << "Enter the word 'quit' to end game or a valid coord: 'x, y' to play!" << endl;
		cout << "'" <<1 <<"," <<1 <<"' to ' " <<boardWidth << "," <<boardHeight <<"'" << endl;

		getline(cin, input);

		//check quit
		if (input == "quit") {
			validResp = true;

			cout << "*Exiting Game" << endl;

			return quit;
		}
		//check coord pair
		else if (stringstream(input) >> xIn >> c >> yIn) {
			//check comma
			if (c == ',') {
				validResp = true;

				//accepted format!
				x = xIn;
				y = yIn;

				return success;
			}
			else {
				cout << "x and y coord must be seperated with just a ," << endl;
			}
		}
		//neither coord or quit command
		else {
			cout << "Error: Invalid command!" << endl << endl;
		}
	}
	return success;
}

//conducts tictactoe game --------
int GameBase::play() {
	//initial game
	print();

	bool finished = false;
	unsigned int turnCount = 0;

	while (!finished) {

		int turnResult = turn();

		//user quit
		if (turnResult == terminate) {
			cout << "USER TERMINATED: " << turnCount << " turn(s) played." << endl << endl;

			finished = true;
			return terminate;
		}
		//user played
		else if (turnResult == success) {
			//game over
			if (done()) {

				if (turnFirst) { //if its X's turn and cant play
					cout << "Congrats Player " << playerTwo << "! " << endl;
					cout << playerTwo;
				}
				else { //if currently O's turn, X win's
					cout << "Congrats Player " << playerOne << "! "<< endl;
					cout << playerOne;
				}
				cout << " WON. " << endl << endl;

				finished = true;
				return success;
			}
			else if (draw()) {
				cout << "DRAW " << "(no winning moves remain): " << turnCount << " turn(s) played." << endl << endl;

				finished = true;
				return drawEnd;
			}
		}
		else if (turnResult == fail) {
			return fail;
		}

		//one turn made
		turnCount += 1;

	}

	return fail;

}
