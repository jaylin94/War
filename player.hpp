#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>
#include "die.hpp"
#include "loadedDie.hpp"

class Player
{
private:
    int dieChoice;
    int roundsWon;
    int rollValue;
    int N;
    std::string dieType;

public:
    //Die and LoadedDie objects for each player
    Die die;
    LoadedDie loadedDie;

    Player()
    {
        dieChoice = 1;
        roundsWon = 0;
    }

    //Roll function for user to roll using normal Die or LoadedDie.
    int roll();

    //Sets roll value, side count N, die type for the specific player
    //using die/loadedDie methods.
    void newRollValue();
    void newN();
    void newType();

    //Set functions for dieChoice, roundsWon, dieType, N value, roll value.
    void setDieChoice(int newChoice)
    {
        dieChoice = newChoice;
    }
    void setRoundsWon(int wins)
    {
        roundsWon = wins;
    }
    void setDieType(std::string newType)
    {
        dieType = newType;
    }
    void setN(int newN)
    {
        N = newN;
    }
    void setRollValue(int newValue)
    {
        rollValue = newValue;
    }

    //Get functions for dieChoice, roundsWon, dieType, N value, roll value.
    int getN()
    {
        return N;
    }
    int getDieChoice()
    {
        return dieChoice;
    }
    int getRoundsWon()
    {
        return roundsWon;
    }
    int getRollValue()
    {
        return rollValue;
    }
    std::string getDieType()
    {
        return dieType;
    }
};

#endif