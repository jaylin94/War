/*********************************************************************
** Program name: War Game
** Author: Jay Lin
** Date: 04/19/2019
** Description: This is a game played by 2 players. Two die with specific
** side counts are selected for each player. Die may be normal or weighted,
** weighted having a higher chance of a higher roll value. The player with 
** the higher roll wins the round.
** Run the program by typing "make" in the terminal in the same 
** directory. Then type "./war" to run the program.
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "die.hpp"
using std::cin;
using std::cout;
using std::endl;

// Generates a random roll value for the normal die.
// No parameters, tells user that the next roll will be generated
// by a normal die.
int Die::roll()
{
    //+1 to prevent 0 as a roll value.
    int newRoll = (rand() % N) + 1;
    setRollValue(newRoll);
    cout << "This next roll is normal. " << endl;

    return newRoll;
}