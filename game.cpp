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
#include "game.hpp"
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

//Displays the main menu. Only runs once for the first
//call of the function to prevent confusing menu displays.
//Prompts to rerun if timesRun variable is incremented greater than 0.
void Game::displayMenu()
{
    //Times run checks if this is the first time running.
    //The welcome message will only be displayed if timesRun is 0.
    if (timesRun == 0)
    {
        //gameName is set by getGameName() in the constructor.
        cout << "This is " << getGameName() << "!" << endl;
        cout << "Two players each have a die. The player"
             << " with the higher roll wins the round." << endl;
        cout << "The player with the most rounds won, wins"
             << " the game." << endl;
        cout << "Enter 's' to start, or 'q' to quit. " << endl;
    }
    //Displays rerun prompt if timesRun is > 0.
    else if (timesRun > 0)
    {
        cout << "Run " << getGameName() << " again?"
             << " 's' to start, 'q' to quit." << endl;
    }
    setTimesRun(getTimesRun() + 1);
}

//Sets the settings for the game of War. Settings include
//the number of rounds, the die type for player 1 and 2, the
//side count for the die of player 1 and 2.
void Game::settings()
{
    cout << "How many rounds would you like to play?" << endl;
    setRounds(validateInt());

    cout << "What type of die for Player 1?" << endl;
    cout << "Enter 1 for normal, 2 for loaded." << endl;
    player1.setDieChoice(validateInt());
    validateDieChoice(player1);
    player1.newType();

    cout << "What type of die for Player 2?" << endl;
    cout << "Enter 1 for normal, 2 for loaded." << endl;
    player2.setDieChoice(validateInt());
    validateDieChoice(player2);
    player2.newType();

    cout << "How many sides on the die of Player 1?" << endl;
    cout << "Enter a valid integer > 0, < 32767. " << endl;
    if (player1.getDieChoice() == 1)
    {
        player1.die.setN(validateInt());
        player1.newN();
    }
    else
    {
        player1.loadedDie.setN(validateInt());
        player1.newN();
    }

    cout << "How many sides on the die of Player 2?" << endl;
    cout << "Enter a valid integer > 0, < 32767. " << endl;
    if (player2.getDieChoice() == 1)
    {
        player2.die.setN(validateInt());
        player2.newN();
    }
    else
    {
        player2.loadedDie.setN(validateInt());
        player2.newN();
    }
}

//Takes input from the user for an integer and validates the input.
//Values must be between 1 and 32767. Returns an integer for set
//functions in the class.
int Game::validateInt()
{
    //Float validation adapted from: https://www.quora.com/How-do-I-check-if-a-number-is-float-on-C++
    double choice = 0.0;
    int floatTest = 0;

    while (true)
    {
        while (!(cin >> choice))
        {
            cout << "test" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Please enter a valid integer > 0"
                 << ", < 32767." << endl;
        }
        floatTest = choice * 100000000.0;
        if (((floatTest % 100000000) > 0) || choice < 1 || choice > 32767)
        {
            //Clears extraction failure flag
            cin.clear();
            //Ignores next 10000 inputs in the buffer until \n
            cin.ignore(10000, '\n');
            cout << "Please enter a valid integer > 0"
                 << ", < 32767." << endl;
        }
        else
        {
            cin.ignore(10000, '\n');
            return choice;
        }
        
    }
}

//Validates menu input choice to start the program or quit.
//Ensures that input is a character of 's' to start or
//'q' to quit.
char Game::getMenuChoice()
{
    string choice;
    while (true)
    {
        cin >> (choice);
        char newChoice[1];
        newChoice[0] = choice[0];
        cin.ignore(10000, '\n');
        if (choice.length() > 1)
        {
            cout << "Please enter 's' to start or 'q' to quit." << endl;
        }
        else if (newChoice[0] == 's' || newChoice[0] == 'q')
        {
            setStartChoice(newChoice[0]);
            return newChoice[0];
        }
    }
}

//Validates die choice of player. Takes Player object as a parameter.
//Die choice must be 1 for normal, 2 for loaded, otherwise the user is
//reprompted for die type choice.
void Game::validateDieChoice(Player player)
{
    while (player.getDieChoice() != 1 && player.getDieChoice() != 2)
    {
        cout << "Please enter 1 for normal, 2 for loaded." << endl;
        player.setDieChoice(validateInt());
    }
}

//Prompts user for menu input to start or quit, using
//getMenuChoice(). Quits if user input is 'q'.
bool Game::startCheck()
{
    if (getMenuChoice() == 'q')
    {
        exit(EXIT_SUCCESS);
    }
    else
    {
        return true;
    }
}