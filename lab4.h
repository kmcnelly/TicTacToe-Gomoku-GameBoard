// Lab4.h : Declares program enums and functions for calling/running a tictactoe game

#pragma once

//link other files
//#include "TicTacToe.h"
//include gomoku

#include <vector>
#include <string>

enum program { name, input, cmdNum, gmkDim, gmkDimAndWin };

enum result { success, fail, invalidInput, errorBoardExtraction, errorReadingLine, errorOpeningFile, vectorSizeMismatch, memoryError };

int usageMsg(char *c, char *error);

//takes in string and converts all 
void toLower(std::string &);