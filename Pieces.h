// Pieces.h : Declares program enums and functions for Pieces

#pragma once

//link other files
#include "lab4.h"

#include <string>


enum piece_color { invalid, noColor, white, red, black };

//returns lowercase of given color
std::string colorToStr(piece_color);

//returns color according to str
piece_color strToColor(std::string);

struct game_piece
{
	game_piece(piece_color, std::string, std::string);
	game_piece();
	piece_color color;
	std::string name;
	std::string disp;
};
