// File name: Lab4.h
// Author: Pineapple - Kyerra Norton, Kiki Ogino, Leung Wai Liu
// Summary: (Lab 4) This is the header file for the "Lab4.cpp" source file. It contains the enumerations for the 
// input parameters, and the statuses as the game as running, or has completed. It also contains the declaration 
// for the useful_message function, which displays a message for the user to input the correct syntax to run the program
// successfully.

#pragma once

#include "GameBase.h"
#include <string>
#include <vector>


enum struct input_param
{
	PROGRAMNAME = 0,
	ARGUMENTNAME = 1,
	BOARDDIMENSIONARGUMENT = 2,
	NEEDEDTOWINARGUMENT = 3,
	TWOARGUMENTSEXACTLY = 2,
	THREEARGUMENTSEXACTLY = 3,
	FOURARGUMENTSEXACTLY = 4
};


enum struct status
{
	SUCCESS = 0,
	FAILURE = 1,
	INCORRECTARGUMENTS = 2,
	USERQUIT = 3,
	GAMEDRAW = 4
};


// The declaration for the useful_message function, which displays a message for the user to input the correct syntax to run the program
// successfully.
int useful_message(const std::string& file_name);
