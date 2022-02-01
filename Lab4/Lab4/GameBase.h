// File name: GameBase.h
// Author: Pineapple - Kyerra Norton, Kiki Ogino, Leung Wai Liu
//
// Summary: (Lab 4) This header file contains the declarations for GameBase base class,
// as well as the enumerations for all the properties of the GameBase board.  

#pragma once

#include "GamePiece.h"
#include <vector>

// enum struct for board properties of GameBase board
enum struct board_properties
{
	STARTVALIDINDEX = 1,
	STARTFULLINDEX = 0,
	GOMOKUDEFAULTTOWIN = 5,
	GOMOKUDEFAULTDIMENSION = 19,
};

class GameBase
{
public:
	GameBase(int size);
	virtual bool done() = 0;
	virtual bool draw() = 0;
	int prompt(unsigned int& x, unsigned int& y);
	virtual int turn() = 0;
	int play();
	virtual void print() = 0;
	static GameBase* new_game (int argc, char* argv[]);

protected:
	int cols;
	int rows;
	int longest_piece;
	bool player_x;
	std::vector<GamePiece> game_board;
};


