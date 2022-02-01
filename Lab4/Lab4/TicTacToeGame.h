// File name: TicTacToeGame.h
// Author: Pineapple - Kyerra Norton, Kiki Ogino, Leung Wai Liu
//
// Summary: (Lab 4) This header file contains the declarations for TicTacToeGame class, the overloaded operator<< (insertion operator),
// as well as the enumerations for all the properties of the TicTacToe board. 

#pragma once
#include "GameBase.h"
#include <iostream>
#include <fstream>
#include <vector>

// enum struct for TicTacToe Board properties
enum struct tic_tac_toe_board_properties
{
	STARTVALIDINDEX = 1,
	STARTFULLINDEX = 0,
	ENDFULLINDEX = 4,
	LEFTCOL = 1,
	BOTTOMROW = 1,
	MIDDLECOL = 2,
	MIDDLEROW = 2,
	RIGHTCOL = 3,
	TOPROW = 3
};

class TicTacToeGame : public GameBase 
{
public:
	TicTacToeGame();
	friend std::ostream& operator<< (std::ostream& output_stream, const TicTacToeGame& const_game);
	bool done() override;
	bool draw() override;
	int turn() override;
	void print() override;
};

// this is the declaration for the overloaded insertion operator function. It takes in 
// a reference to the outputstream, and a constant reference of the TicTacToeGame,
// and it sends the board data to the output stream to display the entire board for the user.
std::ostream& operator<< (std::ostream& output_stream, const TicTacToeGame& const_game);
