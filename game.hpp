#ifndef GAME_HPP
#define GAME_HPP
#include <string>
#include "player.hpp"

class Game
{
private:
    int rounds;
    int timesRun;
    int winner;
    char startChoice;
    std::string gameName;

public:
    //Player objects for player 1 and player 2 to store
    //die type, N count, roll.
    Player player1;
    Player player2;

    Game()
    {
        startChoice = 's';
        rounds = 1;
        timesRun = 0;
        gameName = "War";
    }

    //Menu functions to display, set settings, check to start or quit,
    //get menu choice.
    void displayMenu();
    void settings();
    char getMenuChoice();
    bool startCheck();

    //Validation functions for integer values for settings,
    //die choice for player 1 and player 2.
    int validateInt();
    void validateDieChoice(Player player);

    //Set functions for private member variables.
    void setStartChoice(char newChoice)
    {
        startChoice = newChoice;
    }
    void setRounds(int newRounds)
    {
        rounds = newRounds;
    }
    void setTimesRun(int newTimes)
    {
        timesRun = newTimes;
    }
    void setGameName(std::string newGameName)
    {
        gameName = newGameName;
    }
    void setWinner(int winner)
    {
        this->winner = winner;
    }

    //Get functions for private member variables.
    char getStartChoice()
    {
        return startChoice;
    }
    std::string getGameName()
    {
        return gameName;
    }
    int getRounds()
    {
        return rounds;
    }
    int getTimesRun()
    {
        return timesRun;
    }
    int getWinner()
    {
        return winner;
    }
};

#endif