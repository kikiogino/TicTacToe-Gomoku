// File name: GameBase.h
// Author: Pineapple - Kyerra Norton, Kiki Ogino, Leung Wai Liu
// 
// Summary: (Lab 4) This header file contains the declarations for GameBase base class,
// as well as the enumerations for all the properties of the GameBase board.  

#include "GameBase.h"
#include "GamePiece.h"
#include "TicTacToeGame.h"
#include "GomokuGame.h"
#include "Lab4.h"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;


// default constructor
GameBase::GameBase(int size)
:rows(size), cols(size), longest_piece(1), player_x(true), game_board(size * size, GamePiece())
{
}


// The prompt() function takes in references to unsigned ints (for the x and y coordinates), and returns an int indicating status of function operation
// This function asks the user to input coordinates to put their piece in, and if the input coming in is incorrect
// (outside the range of the game board), or unreadable, it will loop until the user inputs a valid coordinate.
int GameBase::prompt(unsigned int& x, unsigned int& y)
{
	bool either_value_extraction_incorrect = true;
	while (either_value_extraction_incorrect)
	{
		cout << "Please enter a new coordinate, or type 'quit' to quit the game." << endl;
		string input;
		cin >> input;
		if (input == "quit")
		{
			return static_cast<int>(status::USERQUIT);
		}

		// replace a comma with a string
		for (int i = 0; i < input.length(); ++i)
		{
			if (input[i] == ',')
			{
				input[i] = ' ';
			}
		}

		istringstream input_istringstream(input);

		bool first_value_extraction_unsuccessful = !(input_istringstream >> x);
		bool second_value_extraction_unsuccessful = !(input_istringstream >> y);

		either_value_extraction_incorrect = first_value_extraction_unsuccessful || second_value_extraction_unsuccessful;
		if (either_value_extraction_incorrect)
		{
			cout << "One or both values failed to be extracted. Input format should be like '1,1', as one continuous phrase. Please try again." << endl;
		}
		else
		{
			bool outside_valid_index = x < static_cast<int>(board_properties::STARTVALIDINDEX) || x > cols - 2 || y < static_cast<int>(board_properties::STARTVALIDINDEX) || y > rows - 2;
			if (outside_valid_index) {
				cout << "The coordinates are outside the range of this game. Please try again." << endl;
				either_value_extraction_incorrect = true;
			}
			else
			{
				either_value_extraction_incorrect = false;
			}
		}

	}
	return static_cast<int>(status::SUCCESS);

}


// The play() function takes in no parameters, and returns an int indicating the status of the function completion. The 
// play() function runs the game (TicTacToe or Gomoku). It prints out the initial blank board, and repeatedly calls turn(), done(), and 
// draw() until the game as completed. It also keeps track of the total turns played (combined for both Player 1 and Player 2).
int GameBase::play()
{
	// Prints out the initial blank board and set up the variables. 
	print();
	cout << endl;
	bool game_not_complete = true;
	int turns_played = 0;
	bool is_draw = false;

	// Continue running the game while the game is not complete.
	while (game_not_complete)
	{
		// Call turn() function to complete a turn of the function. 
		// If the player quits, then display message and end function.
		int turn_result = turn();
		if (turn_result == static_cast<int>(status::USERQUIT))
		{
			cout << "You have quit the game. Thank you for playing!" << endl;
			cout << "Total Turns Played: " << turns_played << endl;
			return turn_result;
		}

		// Check if someone has won or if it is a draw.
		bool done_result = done();
		if (done_result == true)
		{
			game_not_complete = false;
		}

		bool draw_result = draw();
		if (draw_result == true)
		{
			game_not_complete = false;
			is_draw = true;
		}

		turns_played = turns_played + 1;
	}

	// Display the result message based on whether it is a draw, or whether either Player X or Player O has won.
	if (is_draw)
	{
		cout << "The game is a draw. Thank you for playing!" << endl;
		cout << "Total Turns Played: " << turns_played << endl;
		return static_cast<int>(status::GAMEDRAW);
	}
	else
	{
		// If the next turn is Player X's, then the previous round must be Player O, which was when the game was won.
		if (player_x)
		{
			cout << "Player 2 has won the game! Thank you for playing!" << endl;
			return static_cast<int>(status::SUCCESS);
		}
		else
		{
			cout << "Player 1 has won the game! Thank you for playing!" << endl;
			return static_cast<int>(status::SUCCESS);
		}
	}

	static_cast<int>(status::SUCCESS);
}

// The new_game() function takes in an int argc and a pointer to a character array argv, which are the command line arguments. 
// This function returns a pointer to the GameBase object. This function checks for the correct number of arguments, and creates
// a new Gomoku Game or TicTacToeGame based on the requirements. It returns a null pointer if it does not satisfy any of the requirements.
GameBase* GameBase::new_game(int argc, char* argv[])
{	
	// checks if the argument is less than 2 or more than 4, then return nullptr
	if (argc < static_cast<int>(input_param::TWOARGUMENTSEXACTLY) || argc > static_cast<int>(input_param::FOURARGUMENTSEXACTLY))
	{
		return nullptr;
	}

	// casts the strings of the second (and third arguments, if applicable)
	string second_argument = argv[static_cast<int>(input_param::ARGUMENTNAME)];
	if ((argc == static_cast<int>(input_param::TWOARGUMENTSEXACTLY)) && (second_argument == "TicTacToe"))
	{
		GameBase* t_ptr = new TicTacToeGame();
		return t_ptr;
	}

	// default Gomoku - 19x19, 5 to win
	if ((argc == static_cast<int>(input_param::TWOARGUMENTSEXACTLY)) && (second_argument == "Gomoku"))
	{
		GameBase* t_ptr = new GomokuGame(static_cast<int>(board_properties::GOMOKUDEFAULTDIMENSION), static_cast<int>(board_properties::GOMOKUDEFAULTTOWIN));
		return t_ptr;
	}

	// board dimensions nxn, default 5 to win 
	string third_argument;
	if ((argc == static_cast<int>(input_param::THREEARGUMENTSEXACTLY)) && (second_argument == "Gomoku"))
	{
		third_argument = argv[static_cast<int>(input_param::BOARDDIMENSIONARGUMENT)];
		
		// converting the argument from string to int with istringstream
		istringstream convert_third_argument_to_int(third_argument);
		int third_argument_int_default;
		convert_third_argument_to_int >> third_argument_int_default;

		GameBase* t_ptr = new GomokuGame(third_argument_int_default, static_cast<int>(board_properties::GOMOKUDEFAULTTOWIN));
		return t_ptr;
		
	}

	//Gomoku, custom dimensions, custom needed to win number
	string fourth_argument;
	if ((argc == static_cast<int>(input_param::FOURARGUMENTSEXACTLY)) && (second_argument == "Gomoku"))
	{
		third_argument = argv[static_cast<int>(input_param::BOARDDIMENSIONARGUMENT)];

		// converting the argument from string to int with istringstream
		istringstream convert_third_argument_to_int (third_argument);
		int third_argument_int_second_option;
		convert_third_argument_to_int >> third_argument_int_second_option;
		
		fourth_argument = argv[static_cast<int>(input_param::NEEDEDTOWINARGUMENT)];

		// converting the argument from string to int with istringstream
		istringstream convert_fourth_argument_to_int(fourth_argument);
		int fourth_argument_int;
		convert_fourth_argument_to_int >> fourth_argument_int;

		if ((fourth_argument_int > third_argument_int_second_option) || (fourth_argument_int < 3))
		{
			return nullptr;
		}
		else {
			GameBase* t_ptr = new GomokuGame(third_argument_int_second_option, fourth_argument_int);
			return t_ptr;
		}
	}

	return nullptr;

}
