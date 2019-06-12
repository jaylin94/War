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
#include <cstdlib>
#include <ctime>
#include <string>
#include "game.hpp"
#include "die.hpp"
#include "loadedDie.hpp"
using std::cin;
using std::cout;
using std::endl;

//Prompts user to press any key to continue.
void displayContinue();

int main()
{
    //Seeds rand() number generator with current time.
    srand(time(0));

    //Game Object to call player functions for player 1
    //and player2.
    Game game1;

    //Reruns War until user quits.
    while (game1.getStartChoice() == 's')
    {
        //Resets rounds won for each player per run of War.
        game1.player1.setRoundsWon(0);
        game1.player2.setRoundsWon(0);
        game1.displayMenu();
        game1.startCheck();
        game1.settings();

        //Runs the game for the number of rounds specified by
        //the user.
        for (int i = 0; i < game1.getRounds(); i++)
        {
            cout << "\nRound " << (i + 1) << "!" << endl;

            //Generates Player 1 roll value and displays information
            //for the user.
            game1.player1.roll();
            game1.player1.newRollValue();
            cout << "\n\n";
            cout << "Player 1 rolls... a " << game1.player1.getRollValue() << "!" << endl;
            cout << "Using a " << game1.player1.getDieType() << " die with " << game1.player1.getN() << " sides." << endl;
            cout << "\n\n";

            //Generates Player 2 roll value and displays information
            //for the user.
            game1.player2.roll();
            game1.player2.newRollValue();
            cout << "\n\n";
            cout << "Player 2 rolls... a " << game1.player2.getRollValue() << "!" << endl;
            cout << "Using a " << game1.player2.getDieType() << " die with " << game1.player2.getN() << " sides." << endl;
            cout << "\n\n";

            displayContinue();

            //Accounts for draws if player 1 and 2 roll the same value.
            //Replays the round until one player rolls a higher value.
            while (game1.player1.getRollValue() == game1.player2.getRollValue())
            {
                cout << "\n\n";
                cout << "Draw! Replay the round. " << endl;
                cout << "\n\n";

                displayContinue();
                cout << "\nReplay Round " << (i + 1) << "!" << endl;

                //Generates Player 1 roll value and displays information
                //for the user.
                game1.player1.roll();
                game1.player1.newRollValue();
                cout << "\n\n";
                cout << "Player 1 rolls... a " << game1.player1.getRollValue() << "!" << endl;
                cout << "Using a " << game1.player1.getDieType() << " die with " << game1.player1.getN() << " sides." << endl;
                cout << "\n\n";

                //Generates Player 1 roll value and displays information
                //for the user.
                game1.player2.roll();
                game1.player2.newRollValue();
                cout << "\n\n";
                cout << "Player 2 rolls... a " << game1.player2.getRollValue() << "!" << endl;
                cout << "Using a " << game1.player2.getDieType() << " die with " << game1.player2.getN() << " sides." << endl;
                cout << "\n\n";

                displayContinue();
            }

            //Adds to rounds won if player 1 or player 2 had a higher roll value
            //than the other player.
            if (game1.player1.getRollValue() > game1.player2.getRollValue())
            {
                game1.player1.setRoundsWon(game1.player1.getRoundsWon() + 1);
                cout << "Winner of round " << (i + 1) << " is Player 1!" << endl;
            }
            else if (game1.player2.getRollValue() > game1.player1.getRollValue())
            {
                game1.player2.setRoundsWon(game1.player2.getRoundsWon() + 1);
                cout << "Winner of round " << (i + 1) << " is Player 2!" << endl;
            }

            //Outputs round and die information to the user.
            cout << "Player 1 round wins: " << game1.player1.getRoundsWon() << endl;
            cout << "Using a " << game1.player1.getDieType() << " die with " << game1.player1.getN() << " sides." << endl;
            cout << "Player 2 round wins: " << game1.player2.getRoundsWon() << endl;
            cout << "Using a " << game1.player2.getDieType() << " die with " << game1.player2.getN() << " sides." << endl;
        }

        //Determines winner at the end of the game.
        if (game1.player1.getRoundsWon() > game1.player2.getRoundsWon())
        {
            cout << "The winner is PLAYER 1!" << endl;
        }
        else if (game1.player2.getRoundsWon() > game1.player1.getRoundsWon())
        {
            cout << "The winner is PLAYER 2!" << endl;
        }
        else if (game1.player1.getRoundsWon() == game1.player2.getRoundsWon())
        {
            cout << "Stalemate! There is no winner in War." << endl;
        }
    }
    return 0;
}

//Asks user to press any key and ENTER/RETURN to continue.
void displayContinue()
{
    std::string anyKey;
    cout << "Press any key and ENTER/RETURN to continue. " << endl;
    getline(cin, anyKey);
}
