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
#include "player.hpp"
using std::cin;
using std::cout;
using std::endl;

//Generates roll for player depending on Die choice.
int Player::roll()
{
    if (getDieChoice() == 1)
    {
        die.roll();
        return die.getRollValue();
    }
    else if (getDieChoice() == 2)
    {
        loadedDie.roll(2);
        return loadedDie.getRollValue();
    }
}

//Sets roll value for player depending on Die choice.
void Player::newRollValue()
{
    if (getDieChoice() == 1)
    {
        setRollValue(die.getRollValue());
    }
    else if (getDieChoice() == 2)
    {
        setRollValue(loadedDie.getRollValue());
    }
}

//Sets die side count N for player depending on Die choice.
void Player::newN()
{
    if (getDieChoice() == 1)
    {
        setN(die.getN());
    }
    else if (getDieChoice() == 2)
    {
        setN(loadedDie.getN());
    }
}

//Sets die description type depending on Die choice.
void Player::newType()
{
    if (getDieChoice() == 1)
    {
        setDieType("normal");
    }
    else if (getDieChoice() == 2)
    {
        setDieType("loaded");
    }
}