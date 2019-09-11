// TicTacToe.cpp : Defines functions of TicTacToeGame, including all required to play full tictactoe game. Also, friend << operator .
// Kenneth McNelly
// kmcnelly@wustl.edu

#pragma once

#include "stdafx.h"

//link other files
#include "lab4.h"
#include "TicTacToe.h"
#include "Pieces.h"

#include <iomanip>
#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>
#include <string>

#include <vector>

using namespace std;


TicTacToeGame::TicTacToeGame(): GameBase(max_height, max_width,board_height,board_width, winLength, "X", "O") {

	longestDisp = 1; // board only 1 digits
}

//override print 
void TicTacToeGame::print() {
	cout << (*this) << endl;
}



//DONE: if SOMEONE has won, return true ----- 
bool TicTacToeGame::done() {

	unsigned int index;
	string val;

	//Check All Rows:
	for (unsigned int row = 1; row < (*this).height - 1; row++) {

		//track first value
		index = row*(*this).width + yStart;
		val = (*this).pieceBoard[index].disp;

		//compare with rest of row
		for (unsigned int col = 2; col < (*this).width - 1; col++) {
			index = row*(*this).width + col;

			//if not equal or is a space, skip row
			if ((*this).pieceBoard[index].disp == " " || (*this).pieceBoard[index].disp != val) {
				break;
			}
			//reached last col
			else if (col == (*this).width - 2) {
				return true;
			}

		}

	}
	//no row of all same found

	//Check All Cols:
	for (unsigned int col = 1; col < (*this).width - 1; col++) {

		//track first value (index of 1)
		index = xStart*(*this).width + col;
		val = (*this).pieceBoard[index].disp;

		//compare with rest of col
		for (unsigned int row = 2; row < (*this).height - 1; row++) {
			index = row*(*this).width + col;

			//if not equal skip col
			if ((*this).pieceBoard[index].disp == " " || (*this).pieceBoard[index].disp != val) {
				break;
			}
			//reached last row
			else if (row == (*this).height - 2) {
				return true;
			}
		}

	}
	//no COl of all same found

	//Diagonal Up starting@(1,1):
	index = xStart * (*this).width + yStart;
	val = (*this).pieceBoard[index].disp;

	for (unsigned int x = xStart + 1; x < width - 1; x++) {
		//get diagonal coord
		unsigned int y = x;
		index = x * (*this).width + y;

		if ((*this).pieceBoard[index].disp == " " || (*this).pieceBoard[index].disp != val) {
			break;
		}
		else if (x == height - 2) {
			return true;
		}
	}

	//Diagonal Down starting@(3,1):
	index = xStart * (*this).width + (height - 1 - yStart);
	val = (*this).pieceBoard[index].disp;

	for (unsigned int x = 2; x < width - 1; x++) {
		//get diagonal coord
		unsigned int y = (height - 1) - x;
		index = x * (*this).width + y;

		if ((*this).pieceBoard[index].disp == " " || (*this).pieceBoard[index].disp != val) {
			break;
		}
		else if (x == height - 2) {
			return true;
		}
	}
	//no winner
	return false;
}





//DRAW: if NO more moves are left and NO win, true ---- 
bool TicTacToeGame::draw() {
	//check winner
	if (!done()) {

		//check available
		for (unsigned int row = 1; row < (*this).height - 1; row++) {
			for (unsigned int col = 1; col < (*this).width - 1; col++) {

				unsigned int index = row*(*this).width + col;

				//check if unclaimed positions
				if ((*this).pieceBoard[index].disp == " ") {
					//found available move!
					return false;
				}
			}
		}
		//no available move
		return true;
	}

	//there is a winner/ more moves
	return false;
}








//requests users input according to there turn, Checks if move is valid ------
int TicTacToeGame::turn() {

	//player coords
	unsigned int x;
	unsigned int y;

	bool validPrompt = false;
	int promptResult;

	if (turnFirst) {
		cout << "Player X's Turn:" << endl;
	}
	else {
		cout << "Player O's Turn" << endl;
	}


	//get user prompt
	while (!validPrompt) {
		//get user input
		promptResult = prompt(x, y);

		//TERMINATE on user quit
		if (promptResult == quit) {
			return terminate;
		}
		//Try Coord
		else if (promptResult == success) {
			//check x Coord
			if (x <width - 1 && x > xCorner) {
				//check y Coord
				if (y < height - 1 && y > yCorner) {

					int index = (y*width) + x;

					//Check if Square is empty
					if (pieceBoard[index].disp == " ") {

						string player = "";
						string log;

						//string newEntry = x + ", " + y;

						//Set Piece at position (x,y)
						//Player 1: X
						if (turnFirst) {
							pieceBoard[index].name = "X";
							pieceBoard[index].disp = "X";

							//update print output
							player = "X";
							firstLog += to_string(x);
							firstLog += ", ";
							firstLog += to_string(y);
							firstLog += "; ";
							log = firstLog;
						}
						//Player 2: O
						else {
							pieceBoard[index].name = "O";
							pieceBoard[index].disp = "O";

							//update print output
							player = "O";

							secondLog += to_string(x);
							secondLog += ", ";
							secondLog += to_string(y);
							secondLog += "; ";
							log = secondLog;

						}

						//print updated board
						print();
						cout << endl;

						//remaining valid positions
						cout << "Player " << player << ": " << log << endl << endl;

						//switch to next player turn
						turnFirst = !turnFirst;

						return success;
					}
					else {
						cout << "Position " << x << ", " << y << " Taken! Pick from available" << endl;
					}
				}
				else {
					cout << "Invalid col coord! Must be between " << yStart << " and " << (height - 1 - yStart) << endl;
				}
			}
			else {
				cout << "Invalid row coord! Must be from " << xStart << " and " << (width - 1 - xStart) << endl;
			}
			//new line
			cout << endl;
		}

	}

	return fail;
}


//printing game board
ostream & operator<< (ostream & out, const TicTacToeGame & game) {
	

	//must match size
	if (game.pieceBoard.size() == (game.height * game.width)) {

		//display cell width
		int w = game.longestDisp;

		//index //as long
		long i = static_cast<long>(game.pieceBoard.size() - 1);
		out << endl;


		unsigned int rowIndex = game.height - 1;

		//iterate through vector
		while (i > -1) {
			
			//Iterate Row: ----
			out << setw(w) << rowIndex << " ";
			rowIndex -= 1;

			out << "| ";

			//correction to print correct direction
			int loc = i - (game.width - 1);

			//iterate through row and prints pieces
			for (unsigned int col = 0; col < game.width; col++) {
				string pStr = game.pieceBoard[loc].disp;

				out << setw(w) << pStr << " | ";

				loc++;

				i--;
			}
			out << endl;

		}
		//col index
		out << "    ";
		for (unsigned int col = 0; col < game.width; col++) {
			out << setw(w) << col << "   ";
		}
		out << flush;
		//cout << success;
	}
	else {
		//cout << vectorSizeMismatch;
	}
	return out;
}