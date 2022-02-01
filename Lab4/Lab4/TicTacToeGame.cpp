// File name: TicTacToeGame.cpp
// Author: Pineapple - Kyerra Norton, Kiki Ogino, Leung Wai Liu
// 
// Summary: (Lab 4) This TicTacToeGame.cpp source file contains the definitions for the public member functions of the
// TicTacToeGame class, which are necessary for the operation of the TicTacToeGame. It also contains the defintion of the
// overloaded insertion operator to display the game board data to the user.

#include "Lab4.h"
#include "TicTacToeGame.h"
#include "GameBase.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

// Default constructor for the TicTacToeGame class.
TicTacToeGame::TicTacToeGame()
	:GameBase(5)
{
	
}

ostream& operator<< (ostream& output_stream, const TicTacToeGame& const_game)
{
	// Loops through the entire vector, in order from the top of the board to the bottom of the board, going
	// left to right.
	int spaces = const_game.longest_piece;
	for (int print_row = const_game.rows - 1; print_row >= static_cast<int>(tic_tac_toe_board_properties::STARTFULLINDEX); --print_row)
	{
		output_stream << print_row << " ";

		for (int print_col = static_cast<int>(tic_tac_toe_board_properties::STARTFULLINDEX); print_col < const_game.cols; ++print_col)
		{ 
			int index = const_game.cols * print_row + print_col;
			GamePiece piece_to_print = const_game.game_board[index];
			output_stream << setw(spaces) << piece_to_print.piece_id_display << " ";
		}

		output_stream << endl;
	}

	// Printing the axis label for the last row
	output_stream << " ";
	for (int i = 0; i < const_game.rows; ++i)
	{
		output_stream << " " << setw(spaces) << i;
	}
	output_stream << endl;

	return output_stream;
}

// The done() function does not take in any parameters and returns a boolean for whether or not the game is done. Using the TicTacToe rules, it checks
// the entire board to determine whether either Player X or Player O has won. 
bool TicTacToeGame::done()
{
	// Checking for horizontal wins
	for (int row = static_cast<int>(tic_tac_toe_board_properties::STARTVALIDINDEX); row < rows - 1; ++row)
	{
		int index_prefix = cols * row;
		bool horizontal_x_match = (game_board[index_prefix + static_cast<int>(tic_tac_toe_board_properties::LEFTCOL)].piece_id_status == piece_id::X && game_board[index_prefix + static_cast<int>(tic_tac_toe_board_properties::MIDDLECOL)].piece_id_status == piece_id::X && game_board[index_prefix + static_cast<int>(tic_tac_toe_board_properties::RIGHTCOL)].piece_id_status == piece_id::X);
		bool horizontal_o_match = (game_board[index_prefix + static_cast<int>(tic_tac_toe_board_properties::LEFTCOL)].piece_id_status == piece_id::O && game_board[index_prefix + static_cast<int>(tic_tac_toe_board_properties::MIDDLECOL)].piece_id_status == piece_id::O && game_board[index_prefix + static_cast<int>(tic_tac_toe_board_properties::RIGHTCOL)].piece_id_status == piece_id::O);

		bool row_match = horizontal_x_match || horizontal_o_match;

		if (row_match)
		{
			return true;
		}
	}

	// Checking for vertical wins
	for (int col = static_cast<int>(tic_tac_toe_board_properties::STARTVALIDINDEX); col < cols - 1; ++col)
	{
		bool vertical_x_match = (game_board[cols * static_cast<int>(tic_tac_toe_board_properties::BOTTOMROW) + col].piece_id_status == piece_id::X && game_board[cols * static_cast<int>(tic_tac_toe_board_properties::MIDDLEROW) + col].piece_id_status == piece_id::X && game_board[cols * static_cast<int>(tic_tac_toe_board_properties::TOPROW) + col].piece_id_status == piece_id::X);
		bool vertical_o_match = (game_board[cols * static_cast<int>(tic_tac_toe_board_properties::BOTTOMROW) + col].piece_id_status == piece_id::O && game_board[cols * static_cast<int>(tic_tac_toe_board_properties::MIDDLEROW) + col].piece_id_status == piece_id::O && game_board[cols * static_cast<int>(tic_tac_toe_board_properties::TOPROW) + col].piece_id_status == piece_id::O);

		bool col_match = vertical_x_match || vertical_o_match;

		if (col_match)
		{
			return true;
		}
	}

	// Checking for diagonal wins
	bool bottom_left_to_top_right_x_match = (game_board[cols * static_cast<int>(tic_tac_toe_board_properties::BOTTOMROW) + static_cast<int>(tic_tac_toe_board_properties::LEFTCOL)].piece_id_status == piece_id::X && game_board[cols * static_cast<int>(tic_tac_toe_board_properties::MIDDLEROW) + static_cast<int>(tic_tac_toe_board_properties::MIDDLECOL)].piece_id_status == piece_id::X && game_board[cols * static_cast<int>(tic_tac_toe_board_properties::TOPROW) + static_cast<int>(tic_tac_toe_board_properties::RIGHTCOL)].piece_id_status == piece_id::X);
	bool bottom_left_to_top_right_o_match = (game_board[cols * static_cast<int>(tic_tac_toe_board_properties::BOTTOMROW) + static_cast<int>(tic_tac_toe_board_properties::LEFTCOL)].piece_id_status == piece_id::O && game_board[cols * static_cast<int>(tic_tac_toe_board_properties::MIDDLEROW) + static_cast<int>(tic_tac_toe_board_properties::MIDDLECOL)].piece_id_status == piece_id::O && game_board[cols * static_cast<int>(tic_tac_toe_board_properties::TOPROW) + static_cast<int>(tic_tac_toe_board_properties::RIGHTCOL)].piece_id_status == piece_id::O);
	bool top_left_to_bottom_right_x_match = (game_board[cols * static_cast<int>(tic_tac_toe_board_properties::TOPROW) + static_cast<int>(tic_tac_toe_board_properties::LEFTCOL)].piece_id_status == piece_id::X && game_board[cols * static_cast<int>(tic_tac_toe_board_properties::MIDDLEROW) + static_cast<int>(tic_tac_toe_board_properties::MIDDLECOL)].piece_id_status == piece_id::X && game_board[cols * static_cast<int>(tic_tac_toe_board_properties::BOTTOMROW) + static_cast<int>(tic_tac_toe_board_properties::RIGHTCOL)].piece_id_status == piece_id::X);
	bool top_left_to_bottom_right_o_match = (game_board[cols * static_cast<int>(tic_tac_toe_board_properties::TOPROW) + static_cast<int>(tic_tac_toe_board_properties::LEFTCOL)].piece_id_status == piece_id::O && game_board[cols * static_cast<int>(tic_tac_toe_board_properties::MIDDLEROW) + static_cast<int>(tic_tac_toe_board_properties::MIDDLECOL)].piece_id_status == piece_id::O && game_board[cols * static_cast<int>(tic_tac_toe_board_properties::BOTTOMROW) + static_cast<int>(tic_tac_toe_board_properties::RIGHTCOL)].piece_id_status == piece_id::O);

	bool diagonal_match = bottom_left_to_top_right_x_match || bottom_left_to_top_right_o_match || top_left_to_bottom_right_x_match || top_left_to_bottom_right_o_match;

	if (diagonal_match)
	{
		return true;
	}

	// If no match for any combination, then return false
	return false;
}

// The draw() function does not take in any parameters and returns a boolean for whether or not the game is a draw. It scans through the entire board
// and checks to see if there are any empty spaces left. If there are none, then the game ends with a draw (returns true), 
// otherwise returns false
bool TicTacToeGame::draw()
{
	// If done() is true, then return false (because someone won)
	bool have_match = done();
	if (have_match)
	{
		return false;
	}

	// Checking for empty spaces - if there are empty spaces, then return false
	for (int row = static_cast<int>(tic_tac_toe_board_properties::STARTVALIDINDEX); row < rows - 1; ++row)
	{
		for (int col = static_cast<int>(tic_tac_toe_board_properties::STARTVALIDINDEX); col < cols - 1; ++col)
		{
			int index = cols * row + col;
			if (game_board[index].piece_id_status == piece_id::EMPTY)
			{
				return false;
			}
		}
	}

	// Otherwise return true for a draw
	return true;
}


// The turn() function takes in no parameters and returns an int indicating the status of the function operation. 
// The turn() function contains all the operations for either the Player X's or Player O's turns. 
// It creates x and y coordinate variables, prompts the user to input values, and stores their piece 
// into the board, and switches the indicator for whose turn it is once the player finished putting their piece.
// It also prints out the coordinates of the pieces that each player has put in already.

// I learned how to concatenate an int with a string using the to_string(int) method from StackOverflow
// https: //stackoverflow.com/questions/191757/how-to-concatenate-a-stdstring-and-an-int
int TicTacToeGame::turn()
{
	// Create variables for the possible x and y coordinates for the player.
	unsigned int x;
	unsigned int y;
	bool is_not_valid_piece = true;

	// For Player X's turn
	if (player_x == true)
	{
		cout << endl;
		cout << "Player 1 (X Piece)'s turn:" << endl;
		// keep looping to prompt the user when the piece is not valid.
		while (is_not_valid_piece)
		{
			int player_x_prompt_result = prompt(x, y);

			// Return if the user quits
			if (player_x_prompt_result == static_cast<int>(status::USERQUIT))
			{
				return player_x_prompt_result;
			}

			// Check if the coordinate leads to an empty piece, if not, then loop again to prompt.
			int index = cols * y + x;

			if (game_board[index].piece_id_status == piece_id::EMPTY)
			{
				game_board[index].piece_id_status = piece_id::X;
				game_board[index].piece_id_display = "X";
				game_board[index].piece_id_name = "X";
				print();
				cout << endl;
				cout << endl;

				string player_x_valid_plays = "Player 1 (X Piece):";
				for (int col = static_cast<int>(tic_tac_toe_board_properties::STARTVALIDINDEX); col < cols - 1; ++col)
				{
					for (int row = static_cast<int>(tic_tac_toe_board_properties::STARTVALIDINDEX); row < rows - 1; ++row)
					{
						if (game_board[cols * row + col].piece_id_status == piece_id::X)
						{
							player_x_valid_plays += " " + to_string(col) + "," + to_string(row) + ";";
						}
					}
				}
				player_x_valid_plays[player_x_valid_plays.length() - 1] = ' ';
				cout << player_x_valid_plays << endl;
				player_x = false;
				is_not_valid_piece = false;
			}
			else
			{
				cout << "This space in the board has been taken by a piece already. Please try again." << endl;
			}

		}

	}
	else
	{
		// Player O's turn
		cout << endl;
		cout << "Player 2 (O Piece)'s turn:" << endl;
		while (is_not_valid_piece)
		{
			// Check if Player O is in manual mode or in automatic mode (for the extra credit)
			int player_o_prompt_result = prompt(x, y);;
			
			// Return if the user quits
			if (player_o_prompt_result == static_cast<int>(status::USERQUIT))
			{
				return player_o_prompt_result;
			}

			// Check if the coordinate leads to an empty piece, if not, then loop again to prompt.
			int index = cols * y + x;

			if (game_board[index].piece_id_status == piece_id::EMPTY)
			{
				game_board[index].piece_id_status = piece_id::O;
				game_board[index].piece_id_display = "O";
				game_board[index].piece_id_name = "O";
				print();
				cout << endl;
				cout << endl;

				string player_o_valid_plays = "Player 2 (O Piece):";
				for (int col = static_cast<int>(tic_tac_toe_board_properties::STARTVALIDINDEX); col < cols - 1; ++col)
				{
					for (int row = static_cast<int>(tic_tac_toe_board_properties::STARTVALIDINDEX); row < rows - 1; ++row)
					{
						if (game_board[cols * row + col].piece_id_status == piece_id::O)
						{
							player_o_valid_plays += " " + to_string(col) + "," + to_string(row) + ";";
						}
					}
				}
				player_o_valid_plays[player_o_valid_plays.length() - 1] = ' ';
				cout << player_o_valid_plays << endl;
				player_x = true;
				is_not_valid_piece = false;
			}
			else
			{
				cout << "This space in the board has been taken by a piece already. Please try again." << endl;
			}

		}
	}

	return static_cast<int>(status::SUCCESS);
}

// print function to call the overloaded insertion operator to print the TicTacToeBoard.
void TicTacToeGame::print() {
	cout << *this << endl;
}

