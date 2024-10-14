/*
Alex Cannizzaro
alexcannizzaro16@gmail.com
Course: CPSC-350-01 (Data Structures and Algorithms)
Programming Assignment 2: Not So Super Mario Bros
Main fiile containing main method
*/

#include "Game.h"
#include <fstream>

/*
main method - creates and runs a Game with data from an input file
returns an int 0
param argc (int) - the number of command line arguments
param argv (char**) - a vector containing the command line arguments
*/
int main(int argc, char** argv){
    srand(time(NULL));
    std::string inputFile = argv[1];
    std::ifstream inFS;
    inFS.open(inputFile);
    int L, N, V, coinProb, blankProb, goombaProb, koopaProb, mushroomProb;
    inFS >> L;
    inFS >> N;
    inFS >> V;
    inFS >> coinProb;
    inFS >> blankProb;
    inFS >> goombaProb;
    inFS >> koopaProb;
    inFS >> mushroomProb;
    inFS.close();
    Game theGame(L, N, V, coinProb, blankProb, goombaProb, koopaProb, mushroomProb);
    theGame.runGame();
    return 0;
}