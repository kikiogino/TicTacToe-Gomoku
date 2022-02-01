// File name: Lab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Author: Pineapple - Kyerra Norton, Kiki Ogino, Leung Wai Liu

// Summary: (Lab 4) Lab 4.cpp also contains the definition for the useful_message function.

#include "Lab4.h" 
#include "GameBase.h"
#include "GamePiece.h"
#include "TicTacToeGame.h"
#include "GomokuGame.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


// The useful_message function takes in a reference to a constant string as the parameter, which is the file name of the program (Lab3-LeungWai.exe). 
// This function runs only when there is incorrect arguments (number and/or syntax) are being passed, and prints out the correct way to 
// list the arguments in the Command Prompt when running the program. 
int useful_message(const string& file_name) {
    cout << "Error! Incorrect argument name and/or number of arguments" << endl;
    cout << "usage: " << file_name << " TicTacToe" << endl;
    cout << "or usage: " << file_name << " Gomoku" << endl;
    cout << "or usage: " << file_name << " Gomoku <board size>" << endl;
    cout << "or usage: " << file_name << " Gomoku <board size> <number of pieces to win>" << endl;

    return static_cast<int>(status::INCORRECTARGUMENTS);
}


int main(int argc, char* argv[])
{
    try 
    {
        GameBase* game = GameBase::new_game(argc, argv);
        auto shared_game_ptr = make_shared<GameBase*>(game);
        
        if (game == nullptr) {
            useful_message(argv[static_cast<int>(input_param::PROGRAMNAME)]);
        }
        else
        {
            return game->play();
        }
    }
        
    catch (bad_alloc)
    {
        return static_cast<int>(status::FAILURE);
    }
    
}


  
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file