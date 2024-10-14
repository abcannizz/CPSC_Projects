/*
Alex Cannizzaro
alexcannizzaro16@gmail.com
Course: CPSC-350-01 (Data Structures and Algorithms)
Programming Assignment 2: Not So Super Mario Bros
Header file for the Game class - contains class definition and member function declarations
*/
#ifndef GAME_H
#define GAME_H

#include "Hero.h"
#include "Level.h"

#include <fstream>

class Game{
    public:
        //default constructor
        Game();

        /*
        overloaded constructor
        param numLevels (int) - the number of levels to be in the world
        param levelSize (int) - the dimension of each level in the world
        param initialLives (int) - will be assigned as the Hero's number of lives
        takes int parameters for the probability of:
        coins, empty spaces, goombas, koopas, and mushrooms
        */
        Game(int numLevels, int levelSize, int initialLives, int coinProb, int blankProb, int goombaProb, int koopaProb, int mushroomProb);
        
        //default destructor
        ~Game();

        /*
        runGame method - executes the simulation of a game of Mario
        produces a log of the simulated game within an output file
        */
        void runGame();

    private:
        Hero* mario;  //the Hero that will be shown playing the game
        Level** m_world;  //an array of Levels representing a "world" within the game
        int m_numLevels;  //the number of levels in the world
        int m_levelSize;  //the dimension of each level in the world
        bool m_passLevel;  //a flag variable used in runGame()
        bool m_wonGame;  //a flag variable used in runGame()
        bool m_gameOver;  //a flag variable used in runGame()
        char m_leavesBehind;  //the char that Mario leaves behind when leaving a square
        std::ofstream outFS;  //output stream used to produce the game log

        /*
        moveHero method - moves the Hero by one element in a random direction
        returns the character that the Hero lands on after moving
        param leavesBehind (char) - the character that is to be left on the Hero's current square after leaving
        */
        char moveHero(char leavesBehind, int currLevel);

        /*
        interact method - updates Mario's stats based on the character that he interacts with
        returns the character that Mario will leave behind after the interaction (once he moves off the square)
        param squareValue (char) - represents the item/enemy/etc that Mario will interact with
        param currLevel (int) - index of the Level within m_world that is currently being played within runGame()
        */
        char interact(char squareValue, int currLevel);

        /*
        fight method - updates Mario's stats based on the outcome of the fight
        returns the character that Mario will leave behind ('x' if he wins, or the char that was originally there if he loses)
        param winProb (int) - the probability (out of 100) that Mario will win the fight
        param prevChar (char) - the char that occupied the square before Mario
        */
        char fight(int winProb, char prevChar);

        /*
        bossFight method - updates Mario's stats based on the outcome of the fight
        returns the char that Mario will leave behind
        param currLevel (int) - index of the Level within m_world that is currently being played within runGame()
        */
        char bossFight(int currLevel);

        /*
        endGame method - outputs the final message of the game and closes the output stream
        different messages for winning or losing the game
        */
        void endGame();
};

#endif