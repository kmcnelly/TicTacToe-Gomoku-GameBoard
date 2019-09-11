// Gomoku.cpp : Defines functions of Gomoke, including all required to play full Gomoku game. Also, friend << operator .
// Kenneth McNelly
// kmcnelly@wustl.edu

#pragma once

#include "stdafx.h"

//link other files
#include "lab4.h"
#include "Gomoku.h"
#include "Pieces.h"

#include <iomanip>
#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>
#include <string>

#include <vector>

using namespace std;

//default game
GomokuGame::GomokuGame() : GameBase(max_height, max_width, board_height, board_width, win_Length,"Black", "White") {

	longestDisp = 2; // board 2 digits ~ because (0 --> 18)

}
//modified gameboard (nxn)
GomokuGame::GomokuGame(unsigned int dim, unsigned int winIn): GameBase(dim+boarder_count,dim+boarder_count, dim, dim, winIn, "Black", "White") {
	if (dim < 100) {
		longestDisp = 2; // board 2 digits ~ because (0 --> 18)
	}
	else if (dim < 1000) {
		longestDisp = 3; 
	}

}


//override print 
void GomokuGame::print() {
	cout << (*this) << endl;
}

//DONE: if SOMEONE has won, return true ----- 
bool GomokuGame::done() {
	unsigned int index;
	string val;

	//For each ROW:
	for (unsigned int row = yStart; row < (*this).height - 1; row++) {
		//check start of in-a-row from rest of row
		for (unsigned int startCol = yStart; startCol <= ((*this).boardWidth-(winLength-1)); startCol++) {
			//track first value
			index = row*(*this).width + startCol;
			val = (*this).pieceBoard[index].disp;

			//check if same pieces five times in a row
			for (unsigned int j = xStart; j < winLength; j++) {
				unsigned int col = startCol + j;
				index = row*(*this).width + col;

				//if not equal or is a space, skip row
				if ((*this).pieceBoard[index].disp == " " || (*this).pieceBoard[index].disp != val) {
					break;
				}
				//reached last col
				else if ((j+1) == winLength) {
					return true;
				}

			}
		}
	}
	//no row of all same found

	//Check All COLS:
	for (unsigned int col = xStart; col < (*this).width - 1; col++) {

		//check start of in-a-row from rest of col
		for (unsigned int startRow = xStart; startRow <= ((*this).boardHeight - (winLength-1)); startRow++) {
			//track first value
			index = startRow*(*this).width + col;
			val = (*this).pieceBoard[index].disp;

			//check if same pieces five times in a col
			for (unsigned int j = 1; j < winLength; j++) {
				unsigned int row = startRow + j;

				index = row*(*this).width + col;

				//if not equal skip col
				if ((*this).pieceBoard[index].disp == " " || (*this).pieceBoard[index].disp != val) {
					break;
				}
				//reached last row
				else if ((j + 1) == winLength) {
					return true;
				}
			}
		}
	}
	//no COl of all same found

	//DIAGONALS!!
	//iterate cols
	for (unsigned int colIn = xStart; colIn < (*this).width - 1; colIn++) {
		//iterate rows
		for (unsigned int rowIn = yStart; rowIn < (*this).height - 1; rowIn++) {
			
			index = rowIn*(*this).width + (colIn);
			val = (*this).pieceBoard[index].disp;

			//Check diagonal streak Diagonal Up
			for (unsigned int j = 1; j < winLength; j++) {
				
				//next right-up diagonal
				unsigned int row = rowIn + j;
				unsigned int col = colIn + j;
				
				//check if dimension in-bounds
				if (row < height && col < width) {

					index = (row)*(*this).width + (col);

					if ((*this).pieceBoard[index].disp == " " || (*this).pieceBoard[index].disp != val) {
						break;
					}
					//reached last row
					else if ((j + 1) == winLength) {
						return true;
					}
				}
				else {
					break;
				}
			}

			//Check diagonal streak Diagonal Down
			for (unsigned int j = 1; j < winLength; j++) {

				//next right-down diagonal
				unsigned int row = rowIn - j;
				unsigned int col = colIn + j;

				//check if dimension in-bounds
				if (row > xCorner && col < width) {

					index = (row)*(*this).width + (col);

					if ((*this).pieceBoard[index].disp == " " || (*this).pieceBoard[index].disp != val) {
						break;
					}
					//reached last row
					else if ((j + 1) == winLength) {
						return true;
					}
				}
				else{
					break;
				}
			}

		}
	}
	//no winner

	return false;


}
//DRAW: if NO more moves are left and NO win, true ---- 
	//utilizes Done's architecture but considers spaces as also potential same pieces
bool GomokuGame::draw() {
	unsigned int index;
	string val;

	//For each ROW:
	for (unsigned int row = yStart; row < (*this).height - 1; row++) {
		//check start of in-a-row from rest of row
		for (unsigned int startCol = yStart; startCol <= ((*this).boardWidth - (winLength - 1)); startCol++) {
			//track first value
			index = row*(*this).width + startCol;
			val = (*this).pieceBoard[index].disp;

			//check if same pieces five times in a row
			for (unsigned int j = xStart; j < winLength; j++) {
				unsigned int col = startCol + j;
				index = row*(*this).width + col;

				//set to next val in-a-row if blank
				if (val == " ") {
					val = (*this).pieceBoard[index].disp;
				}

				//if is OPPOSITE PIECE, skip
				if ((*this).pieceBoard[index].disp != " " && (*this).pieceBoard[index].disp != val) {
					break;
				}
				//reached last col
				else if ((j+1) == winLength) {
					return false;
				}

			}
		}
	}
	//no row of all same found

	//Check All COLS:
	for (unsigned int col = xStart; col < (*this).width - 1; col++) {

		//check start of in-a-row from rest of col
		for (unsigned int startRow = xStart; startRow <= ((*this).boardHeight - (winLength - 1)); startRow++) {
			//track first value
			index = startRow*(*this).width + col;
			val = (*this).pieceBoard[index].disp;

			//check if same pieces five times in a col
			for (unsigned int j = 1; j < winLength; j++) {
				unsigned int row = startRow + j;

				index = row*(*this).width + col;

				//set to next val in-a-row if blank
				if (val == " ") {
					val = (*this).pieceBoard[index].disp;
				}

				//if is OPPOSITE PIECE, skip 
				if ((*this).pieceBoard[index].disp != " " && (*this).pieceBoard[index].disp != val) {
					break;
				}
				//reached last row
				else if ((j + 1) == winLength) {
					return false;
				}
			}
		}
	}
	//no COl of all same found

	//DIAGONALS!!
	//iterate cols
	for (unsigned int colIn = xStart; colIn < (*this).width - 1; colIn++) {
		//iterate rows
		for (unsigned int rowIn = yStart; rowIn < (*this).height - 1; rowIn++) {

			index = rowIn*(*this).width + (colIn);
			val = (*this).pieceBoard[index].disp;

			//Check diagonal streak Diagonal Up
			for (unsigned int j = 1; j < winLength; j++) {

				//next right-up diagonal
				unsigned int row = rowIn + j;
				unsigned int col = colIn + j;

				//check if dimension in-bounds
				if (row < height && col < width) {

					index = (row)*(*this).width + (col);

					//set to next val in-a-row if blank
					if (val == " ") {
						val = (*this).pieceBoard[index].disp;
					}


					//if is OPPOSITE PIECE, skip 
					if ((*this).pieceBoard[index].disp != " " && (*this).pieceBoard[index].disp != val) {
						break;
					}
					//reached last row
					else if (j == winLength) {
						return false; //CAN WIN
					}
				}
				else { //out of bounds
					break;
				}
			}

			//Check diagonal streak Diagonal Down
			for (unsigned int j = 1; j < winLength; j++) {

				//next right-down diagonal
				unsigned int row = rowIn - j;
				unsigned int col = colIn + j;

				//check if dimension in-bounds
				if (row > xCorner && col < width) {

					index = (row)*(*this).width + (col);

					//set to next val in-a-row if blank
					if (val == " ") {
						val = (*this).pieceBoard[index].disp;
					}


					//if is OPPOSITE PIECE, skip 
					if ((*this).pieceBoard[index].disp != " " && (*this).pieceBoard[index].disp != val) {
						break;
					}
					//reached last row
					else if (j == winLength) {
						return false;
					}
				}
				else {
					break;
				}
			}

		}
	}
	

	return true; //NO possible wins
}

//requests users input according to there turn, Checks if move is valid ------
int GomokuGame::turn() {

	//player coords
	unsigned int x;
	unsigned int y;

	bool validPrompt = false;
	int promptResult;

	if (turnFirst) {
		cout << "Black's Turn:" << endl;
	}
	else {
		cout << "White's Turn" << endl;
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
							pieceBoard[index].name = "B";
							pieceBoard[index].disp = "B";

							//update print output
							player = "B";
							firstLog += to_string(x);
							firstLog += ", ";
							firstLog += to_string(y);
							firstLog += "; ";
							log = firstLog;
						}
						//Player 2: O
						else {
							pieceBoard[index].name = "W";
							pieceBoard[index].disp = "W";

							//update print output
							player = "W";

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
ostream & operator<< (ostream & out, const GomokuGame & game) {

	//must match size
	if (game.pieceBoard.size() == (game.height * game.width)) {

		//display cell width
		int w = game.longestDisp;

		//index //as long
		long i = static_cast<long>(game.pieceBoard.size() - 1);
		out << endl;


		long rowIndex = static_cast<long>(game.height - 1);

		//iterate through vector
		while (i > -1) {

			//Iterate Row: ----
			//Print only if within actual board
			if (rowIndex < (int)(game.height - GomokuGame::yStart) && rowIndex > GomokuGame::yCorner) {

				out << endl;
				out << setw(w) << rowIndex << " ";
				out << "| ";
			}
			
			rowIndex -= 1;

			//correction to print correct direction
			int loc = i - (game.width - 1);

			//iterate through row and prints pieces
			for (unsigned int col = 0; col < game.width; col++) {
				string pStr = game.pieceBoard[loc].disp;

				if (col <= game.boardWidth && col > GomokuGame::xCorner) {
					if (rowIndex < (int)game.boardHeight && rowIndex > -1) {
						out << setw(w) << pStr << " | ";
					}
				}
				

				loc++;

				i--;
			}
			

		}
		//col index
		out << endl << " X   ";
		for (unsigned int col = GomokuGame::xStart; col < game.width-GomokuGame::xStart; col++) {
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