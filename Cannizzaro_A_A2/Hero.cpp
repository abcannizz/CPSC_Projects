/*
Alex Cannizzaro
Student ID: 2421315
acannizzaro@chapman.edu
CPSC-350-01
Programming Assignment 2: Not So Super Mario Bros
Contains function definitions for the Hero class
*/
#include "Hero.h"


//default constructor
Hero::Hero(){
    Hero(1);
}

/*
overloaded constructor
param initialLives (int) - will be assigned as the Hero's number of lives
*/
Hero::Hero(int initialLives){
    m_numLives = initialLives;
    m_coinCount = 0;
    m_powerLevel = 0;
    m_winCount = 0;
}

//default destructor
Hero::~Hero(){}

/*
getLives method
returns the Hero's number of lives
*/
int Hero::getLives(){
    return m_numLives;
}

/*
setLives method
param numLives (int) - the Hero's new number of lives
*/
void Hero::setLives(int numLives){
    m_numLives = numLives;
}

/*
getCoins method
returns the Hero's number of coins
*/
int Hero::getCoins(){
    return m_coinCount;
}

/*
setCoins method
param numCoins (int) - the Hero's new number of coins
*/
void Hero::setCoins(int numCoins){
    m_coinCount = numCoins;
}

/*
getPL method
returns the Hero's current power level
*/
int Hero::getPL(){
    return m_powerLevel;
}

/*
setPL method
param power (int) - the Hero's new power level
*/
void Hero::setPL(int power){
    m_powerLevel = power;
}

/*
getWins method
returns the Hero's number of wins
*/
int Hero::getWins(){
    return m_winCount;
}

/*
setWins method
param numWins (int) - the Hero's new number of wins
*/
void Hero::setWins(int numWins){
    m_winCount = numWins;
}