// File name: GomokuGame.h
// Author: Pineapple - Kyerra Norton, Kiki Ogino, Leung Wai Liu
//
// Summary: (Lab 4) This header file contains the declarations for GomokuGame class, the overloaded operator<< (insertion operator),
// as well as the enumerations for all the properties of the TicTacToe board. 

#pragma once
#include "GameBase.h"
#include <iostream>
#include <fstream>
#include <vector>

class GomokuGame : public GameBase
{
public:
	GomokuGame(int size, int number_needed_to_win);
	friend std::ostream& operator<< (std::ostream& output_stream, const GomokuGame& const_game);
	bool done() override;
	bool draw() override;
	int turn() override;
	void print() override;

protected:
	int needed_to_win;
};

// this is the declaration for the overloaded insertion operator function. It takes in 
// a reference to the outputstream, and a constant reference of the GomokuGame,
// and it sends the board data to the output stream to display the entire board for the user.
std::ostream& operator<< (std::ostream& output_stream, const GomokuGame& const_game);
