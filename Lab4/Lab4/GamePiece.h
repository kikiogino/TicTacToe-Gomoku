// File name: GamePiece.h
// Author: Pineapple - Kyerra Norton, Kiki Ogino, Leung Wai Liu
//
// Summary: (Lab 4) The game piece header file contains the struct and the declarations for all the particular details and functions of 
// the GamePiece. 
//
// The piece_id enumeration struct contains enumerations for the type of the piece (X, O, or EMPTY). 
//
// The GamePiece struct contains the object properties of the GamePiece object. It contains the constructor, and the status, name, and
// display properties of the GamePiece. 


#pragma once
#include <string>


enum struct piece_id
{
	EMPTY = 0,
	X = 1,
	O = 2,
};


struct GamePiece
{
	GamePiece();
	piece_id piece_id_status;
	std::string piece_id_name;
	std::string piece_id_display;
};
