// Pieces.cpp : Defines functions to for game pieces .
// Kenneth McNelly
// kmcnelly@wustl.edu

#pragma once

#include "stdafx.h"

//link other files
#include "lab4.h"
#include "Pieces.h"

#include <string>


using namespace std;


//piece object containing color, name, and display string
game_piece::game_piece(piece_color colorIn, string nameIn, string dispIn) {
	color = colorIn;
	name = nameIn;
	disp = dispIn;
}

game_piece::game_piece() {
	disp = " ";
}

//returns lowercase str of given color from enum
string colorToStr(int color) {

	//if value match color value, else str invalid
	if (color == white) {
		return "white";
	}
	else if (color == red)
	{
		return "red";
	}
	else if (color == black)
	{
		return "black";
	}
	else if (color == noColor) {
		return "none";
	}
	else {
		return "invalid";
	}
}

//returns lowercase str of given color from enum
piece_color strToColor(string strIn) {

	//if string match name, else invalid value
	if (strIn.compare("white")) {
		return white;
	}
	else if (strIn.compare("red"))
	{
		return red;
	}
	else if (strIn.compare("black"))
	{
		return black;
	}
	else if (strIn.compare(" ")) {
		return noColor;
	}
	else {
		return invalid;
	}
}