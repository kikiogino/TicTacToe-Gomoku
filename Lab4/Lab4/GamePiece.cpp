// File name: GamePiece.cpp 
// Author: Pineapple - Kyerra Norton, Kiki Ogino, Leung Wai Liu
// 
// Summary: (Lab 4) The GamePiece.cpp file contains the definition of the GamePiece piece constructor, which creates
// an empty GamePiece for the GameBase board. 


#include "GamePiece.h"
#include <iostream>
using namespace std;

// Default constructor for the GamePiece object
GamePiece::GamePiece()
	:piece_id_status(piece_id::EMPTY), piece_id_name(""), piece_id_display(" ")
{

}