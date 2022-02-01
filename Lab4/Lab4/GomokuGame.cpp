// File name: GomokuGame.cpp
// Author: Pineapple - Kyerra Norton, Kiki Ogino, Leung Wai Liu
// 
// Summary: (Lab 4) This GomokuGame.cpp source file contains the definitions for the public member functions of the
// GomokuGame class, which are necessary for the operation of the GomokuGame. It also contains the defintion of the
// overloaded insertion operator to display the game board data to the user.

#include "Lab4.h"
#include "GomokuGame.h"
#include "GameBase.h"
#include "GamePiece.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

// Default constructor for the GomokuGame class.
GomokuGame::GomokuGame(int size, int number_needed_to_win)
	:GameBase(size + 2), needed_to_win(number_needed_to_win)
{
	// modifying spacing of display based on the size of the board
	if (size >= 100)
	{
		longest_piece = 4;
	} 
	else if (size < 100 && size >= 10)
	{
		longest_piece = 3;
	}
	else
	{
		longest_piece = 2;
	}
}

// Overloaded insertion operator to print the Gomoku board properly
ostream& operator<< (ostream& output_stream, const GomokuGame& const_game)
{
	// Loops through the entire vector, in order from the top of the board to the bottom of the board, going
	// left to right.
	
	// We learned to use the "left" command to position the text on the left side of the spaces from
	// https: //en.cppreference.com/w/cpp/io/manip/left (located in the "See also" section from the cppreference
	// webpage for setw() linked in the Lab 4 instructions). 
	int spaces = const_game.longest_piece;
	for (int print_row = const_game.rows - 2; print_row >= static_cast<int>(board_properties::STARTVALIDINDEX); --print_row)
	{
		output_stream << left << setw(spaces) << print_row;

		for (int print_col = static_cast<int>(board_properties::STARTVALIDINDEX); print_col < const_game.cols; ++print_col)
		{
			int index = const_game.cols * print_row + print_col;
			GamePiece piece_to_print = const_game.game_board[index];
			output_stream << left << setw(spaces) << piece_to_print.piece_id_display;
		}

		output_stream << endl;
	}

	// Printing the axis label for the last row
	output_stream << left << setw(spaces) << "X";
	for (int i = 1; i <= const_game.rows - 2; ++i)
	{
		output_stream << left << setw(spaces) << i;
	}
	output_stream << endl;

	return output_stream;
}

// The done() function does not take in any parameters and returns a boolean for whether or not the game is done. Using the Gomoku rules, it checks
// the entire board to determine whether either Player 1 or Player 2 has won. 
bool GomokuGame::done()
{
	//horizontal check

	for (int check_row = static_cast<int>(board_properties::STARTVALIDINDEX) ; check_row < rows - 1; ++check_row) {
		
		// start with initial counters for black and white stones, initial streak for match is set to false at first
		bool b_match_streak = false;
		bool w_match_streak = false;
		int b_count = 0;
		int w_count = 0;

		for (int check_col = static_cast<int>(board_properties::STARTVALIDINDEX); check_col < cols - 1; ++check_col) {

			int index = cols * check_row + check_col;
			GamePiece to_check = game_board[index];
			
			// if the piece we are at is empty, reset the counter and streak to false
			if (to_check.piece_id_status == piece_id::EMPTY)
			{
				w_count = 0;
				b_count = 0;
				b_match_streak = false;
				w_match_streak = false;
			}
			// if the piece we are at is Player 1's piece
			else if (to_check.piece_id_status == piece_id::X)
			{
				// if the opposite streak is true, then reset opposite streak and set the correct counter and streak 
				if (b_match_streak == false && w_match_streak == true)
				{
					w_count = 0;
					w_match_streak = false;
					b_count = b_count + 1;
					b_match_streak = true;
				}
				else
				{
					b_count = b_count + 1;
					b_match_streak = true;
					w_count = 0;
					w_match_streak = false;
				}

			}
			// same logic applies for Player 2's pieces. 
			else if (to_check.piece_id_status == piece_id::O)
			{
				if (w_match_streak == false && b_match_streak == true)
				{
					b_count = 0;
					b_match_streak = false;
					w_count = w_count + 1;
					w_match_streak = true;
				}
				else
				{
					w_count = w_count + 1;
					w_match_streak = true;
					b_count = 0;
					b_match_streak = false;
				}

			}

			// if either the black stone or white stone counter reaches the needed_to_win number, return 
			// true for completion of game. 
			if (b_count == needed_to_win || w_count == needed_to_win)
			{
				return true;
			}
		}
	}

	// vertical check
	// same logic applies for vertical check as in the horizontal check, it is just iterating vertically instead of horizontally
	for (int check_col = static_cast<int>(board_properties::STARTVALIDINDEX); check_col < cols - 1; ++check_col) {

		bool b_match_streak = false;
		bool w_match_streak = false;
		int b_count = 0;
		int w_count = 0;

		for (int check_row = static_cast<int>(board_properties::STARTVALIDINDEX); check_row < rows - 1; ++check_row) {

			int index = cols * check_row + check_col;
			GamePiece to_check = game_board[index];

			if (to_check.piece_id_status == piece_id::EMPTY)
			{
				w_count = 0;
				b_count = 0;
				b_match_streak = false;
				w_match_streak = false;
			}
			else if (to_check.piece_id_status == piece_id::X)
			{
				if (b_match_streak == false && w_match_streak == true)
				{
					w_count = 0;
					w_match_streak = false;
					b_count = b_count + 1;
					b_match_streak = true;
				}
				else
				{
					b_count = b_count + 1;
					b_match_streak = true;
					w_count = 0;
					w_match_streak = false;
				}
				
			}
			else if (to_check.piece_id_status == piece_id::O)
			{
				if (w_match_streak == false && b_match_streak == true)
				{
					b_count = 0;
					b_match_streak = false;
					w_count = w_count + 1;
					w_match_streak = true;
				}
				else 
				{
					w_count = w_count + 1;
					w_match_streak = true;
					b_count = 0;
					b_match_streak = false;
				}
				
			}

			if (b_count == needed_to_win || w_count == needed_to_win)
			{
				return true;
			}
		}
	}
	

// diagonal check
	// loop through the rows from the bottom row to the top row of the board. 
	for (int on_row = static_cast<int>(board_properties::STARTVALIDINDEX); on_row < rows - 1; ++on_row) {

		// counters and match_streak indicators for both the black stone and white stone pieces.
		bool b_match_streak = false;
		bool w_match_streak = false;
		int b_count = 0;
		int w_count = 0;

		// check_row and check_col indicators are for iterating through the board diagonally
		int check_row = on_row; 
		int check_col = static_cast<int>(board_properties::STARTVALIDINDEX);
		
		// check if check_row and check_col indicators are within the bounds of the board. 
		bool within_bounds_diagonal_down = (check_row >= static_cast<int>(board_properties::STARTVALIDINDEX) && check_row < rows - 1)
			&& (check_col >= static_cast<int>(board_properties::STARTVALIDINDEX) && check_col < cols - 1);

		// looping diagonally downwards from the leftmos piece in the row 
		while (within_bounds_diagonal_down) {
			// same checking for matches logic as in vertical and horizontal
			int index = cols * check_row + check_col;
			GamePiece to_check = game_board[index];

			if (to_check.piece_id_status == piece_id::EMPTY)
			{
				w_count = 0;
				b_count = 0;
				b_match_streak = false;
				w_match_streak = false;
			}
			else if (to_check.piece_id_status == piece_id::X)
			{
				if (b_match_streak == false && w_match_streak == true)
				{
					w_count = 0;
					w_match_streak = false;
					b_count = b_count + 1;
					b_match_streak = true;
				}
				else
				{
					b_count = b_count + 1;
					b_match_streak = true;
					w_count = 0;
					w_match_streak = false;
				}

			}
			else if (to_check.piece_id_status == piece_id::O)
			{
				if (w_match_streak == false && b_match_streak == true)
				{
					b_count = 0;
					b_match_streak = false;
					w_count = w_count + 1;
					w_match_streak = true;
				}
				else
				{
					w_count = w_count + 1;
					w_match_streak = true;
					b_count = 0;
					b_match_streak = false;
				}

			}

			if (b_count == needed_to_win || w_count == needed_to_win)
			{
				return true;
			}

			// incrementing to the next diagonal piece down
			check_col = check_col + 1;
			check_row = check_row - 1;

			within_bounds_diagonal_down = (check_row >= static_cast<int>(board_properties::STARTVALIDINDEX) && check_row < rows - 1)
				&& (check_col >= static_cast<int>(board_properties::STARTVALIDINDEX) && check_col < cols - 1);
		}

		// reset to original left piece in the row that we are at
		b_match_streak = false;
		w_match_streak = false;
		b_count = 0;
		w_count = 0;

		// same logic applies, but just going upwards to take care of the other diagonal direction. 
		check_row = on_row;
		check_col = static_cast<int>(board_properties::STARTVALIDINDEX);

		bool within_bounds_diagonal_up = (check_row >= static_cast<int>(board_properties::STARTVALIDINDEX) && check_row < rows - 1)
			&& (check_col >= static_cast<int>(board_properties::STARTVALIDINDEX) && check_col < cols - 1);

		while (within_bounds_diagonal_up) {
			int index = cols * check_row + check_col;
			GamePiece to_check = game_board[index];

			if (to_check.piece_id_status == piece_id::EMPTY)
			{
				w_count = 0;
				b_count = 0;
				b_match_streak = false;
				w_match_streak = false;
			}
			else if (to_check.piece_id_status == piece_id::X)
			{
				if (b_match_streak == false && w_match_streak == true)
				{
					w_count = 0;
					w_match_streak = false;
					b_count = b_count + 1;
					b_match_streak = true;
				}
				else
				{
					b_count = b_count + 1;
					b_match_streak = true;
					w_count = 0;
					w_match_streak = false;
				}

			}
			else if (to_check.piece_id_status == piece_id::O)
			{
				if (w_match_streak == false && b_match_streak == true)
				{
					b_count = 0;
					b_match_streak = false;
					w_count = w_count + 1;
					w_match_streak = true;
				}
				else
				{
					w_count = w_count + 1;
					w_match_streak = true;
					b_count = 0;
					b_match_streak = false;
				}

			}

			if (b_count == needed_to_win || w_count == needed_to_win)
			{
				return true;
			}

			check_col = check_col + 1;
			check_row = check_row + 1;

			within_bounds_diagonal_up = (check_row >= static_cast<int>(board_properties::STARTVALIDINDEX) && check_row < rows - 1)
				&& (check_col >= static_cast<int>(board_properties::STARTVALIDINDEX) && check_col < cols - 1);
		}
		

	}

	// since the first loop only covers the top diagonal halves of the game board, this loop covers the bottom
	// diagonal halves of the board. The same logic applies as the loop that covers the top diagonal halves of the board. 
	for (int on_row = static_cast<int>(board_properties::STARTVALIDINDEX); on_row < rows - 1; ++on_row) {

		bool b_match_streak = false;
		bool w_match_streak = false;
		int b_count = 0;
		int w_count = 0;

		int check_row = on_row;
		int check_col = cols - 2;

		bool within_bounds_diagonal_down = (check_row >= static_cast<int>(board_properties::STARTVALIDINDEX) && check_row < rows - 1)
			&& (check_col >= static_cast<int>(board_properties::STARTVALIDINDEX) && check_col < cols - 1);

		while (within_bounds_diagonal_down) {
			int index = cols * check_row + check_col;
			GamePiece to_check = game_board[index];

			if (to_check.piece_id_status == piece_id::EMPTY)
			{
				w_count = 0;
				b_count = 0;
				b_match_streak = false;
				w_match_streak = false;
			}
			else if (to_check.piece_id_status == piece_id::X)
			{
				if (b_match_streak == false && w_match_streak == true)
				{
					w_count = 0;
					w_match_streak = false;
					b_count = b_count + 1;
					b_match_streak = true;
				}
				else
				{
					b_count = b_count + 1;
					b_match_streak = true;
					w_count = 0;
					w_match_streak = false;
				}

			}
			else if (to_check.piece_id_status == piece_id::O)
			{
				if (w_match_streak == false && b_match_streak == true)
				{
					b_count = 0;
					b_match_streak = false;
					w_count = w_count + 1;
					w_match_streak = true;
				}
				else
				{
					w_count = w_count + 1;
					w_match_streak = true;
					b_count = 0;
					b_match_streak = false;
				}

			}

			if (b_count == needed_to_win || w_count == needed_to_win)
			{
				return true;
			}

			check_col = check_col - 1;
			check_row = check_row - 1;

			within_bounds_diagonal_down = (check_row >= static_cast<int>(board_properties::STARTVALIDINDEX) && check_row < rows - 1)
				&& (check_col >= static_cast<int>(board_properties::STARTVALIDINDEX) && check_col < cols - 1);
		}


		b_match_streak = false;
		w_match_streak = false;
		b_count = 0;
		w_count = 0;

		check_row = on_row;
		check_col = cols - 2;

		bool within_bounds_diagonal_up = (check_row >= static_cast<int>(board_properties::STARTVALIDINDEX) && check_row < rows - 1)
			&& (check_col >= static_cast<int>(board_properties::STARTVALIDINDEX) && check_col < cols - 1);

		while (within_bounds_diagonal_up) {
			int index = cols * check_row + check_col;
			GamePiece to_check = game_board[index];

			if (to_check.piece_id_status == piece_id::EMPTY)
			{
				w_count = 0;
				b_count = 0;
				b_match_streak = false;
				w_match_streak = false;
			}
			else if (to_check.piece_id_status == piece_id::X)
			{
				if (b_match_streak == false && w_match_streak == true)
				{
					w_count = 0;
					w_match_streak = false;
					b_count = b_count + 1;
					b_match_streak = true;
				}
				else
				{
					b_count = b_count + 1;
					b_match_streak = true;
					w_count = 0;
					w_match_streak = false;
				}

			}
			else if (to_check.piece_id_status == piece_id::O)
			{
				if (w_match_streak == false && b_match_streak == true)
				{
					b_count = 0;
					b_match_streak = false;
					w_count = w_count + 1;
					w_match_streak = true;
				}
				else
				{
					w_count = w_count + 1;
					w_match_streak = true;
					b_count = 0;
					b_match_streak = false;
				}

			}

			if (b_count == needed_to_win || w_count == needed_to_win)
			{
				return true;
			}

			check_col = check_col - 1;
			check_row = check_row + 1;

			within_bounds_diagonal_up = (check_row >= static_cast<int>(board_properties::STARTVALIDINDEX) && check_row < rows - 1)
				&& (check_col >= static_cast<int>(board_properties::STARTVALIDINDEX) && check_col < cols - 1);
		}


	}
	
	


	return false;
}

// The draw() function does not take in any parameters and returns a boolean for whether or not the game is a draw. It scans through the entire board
// and checks to see if there are any empty spaces left. If there are none, then the game ends with a draw (returns true), 
// otherwise returns false
bool GomokuGame::draw()
{
	// If done() is true, then return false (because someone won)
	bool have_match = done();
	if (have_match)
	{
		return false;
	}

	// Checking for empty spaces - if there are empty spaces, then return false
	for (int row = static_cast<int>(board_properties::STARTVALIDINDEX); row < rows - 1; ++row)
	{
		for (int col = static_cast<int>(board_properties::STARTVALIDINDEX); col < cols - 1; ++col)
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
int GomokuGame::turn()
{
	// Create variables for the possible x and y coordinates for the player.
	unsigned int x;
	unsigned int y;
	bool is_not_valid_piece = true;

	// For Player B's turn
	if (player_x == true)
	{
		cout << endl;
		cout << "Player 1 (Black Stone)'s turn:" << endl;
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
				game_board[index].piece_id_display = "B";
				game_board[index].piece_id_name = "Black Stone";
				print();
				cout << endl;
				cout << endl;

				string player_x_valid_plays = "Player 1 (Black Stone):";
				for (int col = static_cast<int>(board_properties::STARTVALIDINDEX); col < cols - 1; ++col)
				{
					for (int row = static_cast<int>(board_properties::STARTVALIDINDEX); row < rows - 1; ++row)
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
		// Player W's turn
		cout << endl;
		cout << "Player 2 (White Stone)'s turn:" << endl;
		while (is_not_valid_piece)
		{
			// Check if Player O is in manual mode or in automatic mode (for the extra credit)
			int player_o_prompt_result = prompt(x, y);

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
				game_board[index].piece_id_display = "W";
				game_board[index].piece_id_name = "White Stone";
				print();
				cout << endl;
				cout << endl;

				string player_o_valid_plays = "Player 2 (White Stone):";
				for (int col = static_cast<int>(board_properties::STARTVALIDINDEX); col < cols - 1; ++col)
				{
					for (int row = static_cast<int>(board_properties::STARTVALIDINDEX); row < rows - 1; ++row)
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

// This print function calls out the overloaded insertion operator to print the Gomoku board.
void GomokuGame::print() {
	cout << *this << endl;
}

