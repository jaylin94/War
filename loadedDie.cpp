/*********************************************************************
** Program name: War Game
** Author: Jay Lin
** Date: 04/19/2019
** Description: This is a game played by 2 players. Two dice with specific
** side counts are selected for each player. Die may be normal or weighted,
** weighted having a higher chance of a higher roll value. The player with 
** the higher roll wins the round.
** Run the program by typing "make" in the terminal in the same 
** directory. Then type "./war" to run the program.
*********************************************************************/
#include <iostream>
#include "loadedDie.hpp"
using std::cout;
using std::cin;
using std::endl;

//Roll overload for loadedDie class. Generates a random
//roll value twice the value of what the original "normal"
//roll value would be. Regenerates the value if the value 
//is greater than the side count N of the die.
int LoadedDie::roll(int bias)
{
    int newRoll = (rand() % (getN()) * bias + 1);
    while(newRoll > getN())
    {
        newRoll = (rand() % (getN()) * bias + 1);
    }
    setRollValue(newRoll);
    cout << "This next roll is LOADED!" << endl;

    return newRoll;
}