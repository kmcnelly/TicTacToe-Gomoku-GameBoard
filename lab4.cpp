// Lab3.cpp : Defines functions and main to create and run a full game of TicTacToe
// Kenneth McNelly
// kmcnelly@wustl.edu

#pragma once

#include "stdafx.h"

//link other files
#include "lab4.h"
#include "Base.h"
#include "TicTacToe.h"
#include <memory>
#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>
#include <string>

#include <vector>

using namespace std;

int main(int argc, char * argv[])
{
	
	try
	{
		shared_ptr<GameBase> game(GameBase::createGame(argc, argv));

		if (game == nullptr) { //singular
			char *errorInput = " Incorrect inputs! Required: lab4-mcnelly.exe 'TicTacToe' or 'Gomoku' or 'Gomoku #(>=3)' or 'Gomoku #(>=3) #(>=3)'   ";

			return usageMsg(argv[name], errorInput);
		}
		else {
			
			game->play();
			return success;
		}
	}
	catch (const std::bad_alloc) {
		char *memError = " Error! Bad Allocation";
		usageMsg(argv[name], memError);

		return memoryError;
	}
	catch (const std::exception&) {
		return fail;
	}
	



}


//usageMsg: returns a helpful statement of how to call program properly 
int usageMsg(char *c, char *error) {
	cout << "Invalid Command!" << endl;
	cout << "usage: " << c << error << endl;

	return fail;
}

//converts all string to lowercase
void toLower(string & a) {
	for (size_t i = 0; i < a.length(); i++) {
		char c = a.at(i);

		//if char is uppercase, add Ascii
		if (c > 'A' && c < 'Z') {
			c = c + 32;
		}
	}
}