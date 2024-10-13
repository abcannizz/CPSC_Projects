
/*
Alex Cannizzaro
Student ID: 2421315
acannizzaro@chapman.edu
CPSC-350-01
Programming Assignment 2: Not So Super Mario Bros
Contains function definitions for the Game class
*/
#include "Game.h"

//default constructor
Game::Game(){
    Game(1, 2, 1, 0, 0, 0, 0, 0);
}

/*
overloaded constructor
param numLevels (int) - the number of levels to be in the world
param levelSize (int) - the dimension of each level in the world
param initialLives (int) - will be assigned as the Hero's number of lives
takes int parameters for the probability of:
coins, empty spaces, goombas, koopas, and mushrooms
*/
Game::Game(int numLevels, int levelSize, int initialLives, int coinProb, int blankProb, int goombaProb, int koopaProb, int mushroomProb){
    m_gameOver = false;
    m_wonGame = false;
    m_leavesBehind = 'x';
    m_numLevels = numLevels;
    m_levelSize = levelSize;
    outFS.open("output.txt");
    m_world = new Level*[numLevels];
    mario = new Hero(initialLives);
    for (int i = 0; i < numLevels - 1; i++){
        m_world[i] = new Level(levelSize, coinProb, blankProb, goombaProb, koopaProb, mushroomProb, false);
    }
    m_world[numLevels - 1] = new Level(levelSize, coinProb, blankProb, goombaProb, koopaProb, mushroomProb, true);
}

//default destructor
Game::~Game(){
    for (int i = 0; i < m_numLevels; i++){
        delete m_world[i];
    }
    delete[] m_world;
}


/*
runGame method - executes the simulation of a game of Mario
produces a log of the simulated game within an output file
*/
void Game::runGame(){
    char startsOn;
    char landsOn;
    //output each level with no mario
    for (int i = 0; i < m_numLevels; i++){
        outFS << "LEVEL " << i + 1 << ":" << std::endl;
        outFS << m_world[i]->display();
        outFS << "================" << std::endl;
    }
    //begin gameplay
    for (int i = 0; i < m_numLevels; i++){
        //to start each level:
        m_passLevel = false;
        m_world[i]->setHeroRow(rand() % m_levelSize);
        m_world[i]->setHeroCol(rand() % m_levelSize);
        outFS << "Mario is starting level " << i + 1 << " at position (" << m_world[i]->getHeroRow() << ", " << m_world[i]->getHeroCol() << ")." << std::endl;
        startsOn = m_world[i]->placeHero();
        outFS << "================" << std::endl;
        outFS << m_world[i]->display();
        outFS << "================" << std::endl;
        outFS << "Level " << i + 1 << std::endl;
        outFS << "Mario is at position (" << m_world[i]->getHeroRow() << ", " << m_world[i]->getHeroCol() << ")." << std::endl;
        outFS << "Mario is at power level " << mario->getPL() << std::endl;
        m_leavesBehind = interact(startsOn, i);
        outFS << "Mario has " << mario->getLives() << " lives left." << std::endl;
        outFS << "Mario has " << mario->getCoins() << " coins." << std::endl;
        if (mario->getLives() == 0){
                m_gameOver = true;
            }
        //once Mario has started the current level:
        while (!m_passLevel && !m_gameOver){
            outFS << "Mario will move ";
            landsOn = moveHero(m_leavesBehind, i);
            outFS << "================" << std::endl;
            outFS << m_world[i]->display();
            outFS << "================" << std::endl;
            outFS << "Level " << i + 1 << std::endl;
            outFS << "Mario is at position (" << m_world[i]->getHeroRow() << ", " << m_world[i]->getHeroCol() << ")." << std::endl;
            outFS << "Mario is at power level " << mario->getPL() << std::endl;
            m_leavesBehind = interact(landsOn, i);
            outFS << "Mario has " << mario->getLives() << " lives left." << std::endl;
            outFS << "Mario has " << mario->getCoins() << " coins." << std::endl;
            if (mario->getLives() == 0){
                m_gameOver = true;
            }
        }
        if (landsOn == 'w'){
            outFS << "Mario will WARP." << std::endl;
        }
        else if (m_passLevel && !m_wonGame){
            outFS << "Mario will advance to the next level." << std::endl;
        }
        if (m_gameOver){
            break;
        }
    }
    endGame();
}
    
/*
endGame method - outputs the final message of the game and closes the output stream
different messages for winning or losing the game
*/
void Game::endGame(){
    outFS << "Mario will stay put." << std::endl;
    if (m_gameOver){
        outFS << "GAME LOST! Better luck next time!" << std::endl;
    }
    else {
        outFS << "MARIO WINS! WAHOO!!" << std::endl;
    }
    outFS.close();
}

/*
moveHero method - moves the Hero by one element in a random direction
returns the character that the Hero lands on after moving
param leavesBehind (char) - the character that is to be left on the Hero's current square after leaving
param currLevel (int) - index of the Level within m_world that is currently being played within runGame()
*/
char Game::moveHero(char leavesBehind, int currLevel){
    int direction = rand() % 4;
    char ret;
    m_world[currLevel]->updateSquare(m_world[currLevel]->getHeroRow(), m_world[currLevel]->getHeroCol(), leavesBehind);
    switch (direction){
        case 0:   //MOVE UP
            outFS << "UP." << std::endl;
            if (m_world[currLevel]->getHeroRow() == 0){   //if at the top
                m_world[currLevel]->setHeroRow(m_world[currLevel]->getSize() - 1);   //move to the bottom
            }
            else{
                m_world[currLevel]->setHeroRow(m_world[currLevel]->getHeroRow() - 1);
            }
            break;
        case 1:   //MOVE DOWN
            outFS << "DOWN." << std::endl;
            if (m_world[currLevel]->getHeroRow() == m_world[currLevel]->getSize() - 1){   //if at the bottom
                m_world[currLevel]->setHeroRow(0);   //move to the top
            }
            else{
                m_world[currLevel]->setHeroRow(m_world[currLevel]->getHeroRow() + 1);
            }
            break;
        case 2:   //MOVE RIGHT
            outFS << "RIGHT." << std::endl;
            if (m_world[currLevel]->getHeroCol() == m_world[currLevel]->getSize() - 1){   //if all the way to the right
                m_world[currLevel]->setHeroCol(0);;   //move all the way to the left
            }
            else{
                m_world[currLevel]->setHeroCol(m_world[currLevel]->getHeroCol() + 1);;
            }
            break;
        case 3:   //MOVE LEFT
            outFS << "LEFT." << std::endl;
            if (m_world[currLevel]->getHeroCol() == 0){   //if all the way to the left
                m_world[currLevel]->setHeroCol(m_world[currLevel]->getSize() - 1);   //move all the way to the right
            }
            else{
                m_world[currLevel]->setHeroCol(m_world[currLevel]->getHeroCol() - 1);
            }
            break;
        default:
            break;
    }
    ret = m_world[currLevel]->at(m_world[currLevel]->getHeroRow(), m_world[currLevel]->getHeroCol());
    m_world[currLevel]->updateSquare(m_world[currLevel]->getHeroRow(), m_world[currLevel]->getHeroCol(), 'H');
    return ret;
}

/*
interact method - updates Mario's stats based on the character that he interacts with
returns the character that Mario will leave behind after the interaction (once he moves off the square)
param squareValue (char) - represents the item/enemy/etc that Mario will interact with
param currLevel (int) - index of the Level within m_world that is currently being played within runGame()
*/
char Game::interact(char squareValue, int currLevel){
    switch (squareValue){
        case 'g':
            outFS << "Mario encountered a goomba and ";
            return fight(80, 'g');
        case 'k':
            outFS << "Mario encountered a koopa and ";
            return fight(65, 'k');
        case 'b':
            return bossFight(currLevel);
        case 'w':
            outFS << "Mario found a warp pipe." << std::endl;
            m_passLevel = true;
            return 'x';
        case 'c':
            mario->setCoins(mario->getCoins() + 1);
            if (mario->getCoins() == 20){
                mario->setLives(mario->getLives() + 1);
                mario->setCoins(0);
            }
            outFS << "Mario collected a coin." << std::endl;
            return 'x';
        case 'm':
            if (mario->getPL() < 2){
                mario->setPL(mario->getPL() + 1);
            }
            outFS << "Mario ate a mushroom." << std::endl;
            return 'x';
        default:
            outFS << "Mario visited an empty space." << std::endl;
            return 'x';
    }
}

/*
fight method - updates Mario's stats based on the outcome of the fight
returns the character that Mario will leave behind ('x' if he wins, or the char that was originally there if he loses)
param winProb (int) - the probability (out of 100) that Mario will win the fight
param prevChar (char) - the char that occupied the square before Mario
*/
char Game::fight(int winProb, char prevChar){
    int random = rand() % 100;
    if (random < winProb){  //mario wins
        mario->setWins(mario->getWins() + 1);
        if (mario->getWins() == 7){
            mario->setLives(mario->getLives() + 1);
            mario->setWins(0);
        }
        outFS << "won." << std::endl;
        return 'x';
    }
    else if (mario->getPL() == 0){  //mario loses at PL0
        mario->setLives(mario->getLives() - 1);
        outFS << "lost." << std::endl;
        return prevChar;
    }
    else {  //mario loses
        mario->setPL(mario->getPL() - 1);
        outFS << "lost." << std::endl;
        return prevChar;
    }
}

/*
bossFight method - updates Mario's stats based on the outcome of the fight
returns the char that Mario will leave behind
param currLevel (int) - index of the Level within m_world that is currently being played within runGame()
*/
char Game::bossFight(int currLevel){
    while (mario->getLives() > 0){
        int random = rand() % 2;
        if (random == 1){ //mario wins
            m_passLevel = true;
            if (currLevel == m_numLevels - 1){
                m_wonGame = true;
            }
            outFS << "Mario encountered a boss and won." << std::endl;
            return 'x';
        }
        else { //mario loses
            mario->setPL(mario->getPL() - 2);
            if (mario->getPL() < 0){
                mario->setLives(mario->getLives() - 1);
                mario->setPL(0);
            }
            outFS << "Mario encountered a boss and lost." << std::endl;
            if (mario->getLives() == 0){
                continue;
            }
            outFS << "Mario has " << mario->getLives() << " lives left." << std::endl;
            outFS << "Mario has " << mario->getCoins() << " coins." << std::endl;
            outFS << "Mario will stay put." << std::endl;
            outFS << "================" << std::endl;
            outFS << m_world[currLevel]->display();
            outFS << "================" << std::endl;
            outFS << "Level " << currLevel + 1 << std::endl;
            outFS << "Mario is at position (" << m_world[currLevel]->getHeroRow() << ", " << m_world[currLevel]->getHeroCol() << ")." << std::endl;
            outFS << "Mario is at power level " << mario->getPL() << std::endl;
        }
    }
    return 'b';
}