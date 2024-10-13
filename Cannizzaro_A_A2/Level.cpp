/*
Alex Cannizzaro
Student ID: 2421315
acannizzaro@chapman.edu
CPSC-350-01
Programming Assignment 2: Not So Super Mario Bros
Contains function definitions for the Level class
*/
#include "Level.h"

//default constructor
Level::Level(){
    Level(2, 0, 0, 0, 0, 0, false);
}

/*
overloaded constructor
param dimension (int) - will be assigned as the legnth and width of the grid
takes int parameters for the probability of:
coins, empty spaces, goombas, koopas, and mushrooms
param lastLevel - boolean that indicates weather this object is the last level in the world
*/
Level::Level(int dimension, int coinProb, int blankProb, int goombaProb, int koopaProb, int mushroomProb, bool lastLevel){
    m_gridSize = dimension;
    m_grid = new char*[m_gridSize];
    for (int i = 0; i < m_gridSize; i++){
        m_grid[i] = new char[m_gridSize];
    }
    populateGrid(coinProb, blankProb, goombaProb, koopaProb, mushroomProb, lastLevel);
}

//default destructor
Level::~Level(){
    for (int i = 0; i < m_gridSize; i++){
        delete[] m_grid[i];
    }
    delete[] m_grid;
}

/*
populateGrid method - assigns values to each element of the grid
takes int parameters for the probability of:
coins, empty spaces, goombas, koopas, and mushrooms
param lastLevel - boolean that indicates weather this object is the last level in the world
*/
void Level::populateGrid(int coinProb, int blankProb, int goombaProb, int koopaProb, int mushroomProb, bool lastLevel){
    int totalSquares = m_gridSize * m_gridSize;
    int numCoins = (totalSquares - 2) * (coinProb / 100.0);
    int numGoombas = (totalSquares - 2) * (goombaProb / 100.0);
    int numKoopas = (totalSquares - 2) * (koopaProb / 100.0);
    int numMushrooms = (totalSquares - 2) * (mushroomProb / 100.0);
    int tempRow = rand() % m_gridSize;
    int tempCol = rand() % m_gridSize;
    bool placed = false;
    //place boss
    m_grid[tempRow][tempCol] = 'b'; 
    //place warp pipe (if not the final level)
    if (!lastLevel){
        while(!placed){
            tempRow = rand() % m_gridSize;
            tempCol = rand() % m_gridSize;
            if (m_grid[tempRow][tempCol] == '\0'){
                m_grid[tempRow][tempCol] = 'w'; 
                placed = true;
            }
        }
    }
    //place coins
    while (numCoins > 0){
        tempRow = rand() % m_gridSize;
        tempCol = rand() % m_gridSize;
        if (m_grid[tempRow][tempCol] != '\0'){
            continue; 
        } 
        else {
            m_grid[tempRow][tempCol] = 'c';
            numCoins--;
        }
    }
    //place goombas
    while (numGoombas > 0){
        tempRow = rand() % m_gridSize;
        tempCol = rand() % m_gridSize;
        if (m_grid[tempRow][tempCol] != '\0'){
            continue; 
        } 
        else {
            m_grid[tempRow][tempCol] = 'g';
            numGoombas--;
        }
    }
    //place koopas
    while (numKoopas > 0){
        tempRow = rand() % m_gridSize;
        tempCol = rand() % m_gridSize;
        if (m_grid[tempRow][tempCol] != '\0'){
            continue; 
        } 
        else {
            m_grid[tempRow][tempCol] = 'k';
            numKoopas--;
        }
    }
    //place mushrooms
    while (numMushrooms > 0){
        tempRow = rand() % m_gridSize;
        tempCol = rand() % m_gridSize;
        if (m_grid[tempRow][tempCol] != '\0'){
            continue; 
        } 
        else {
            m_grid[tempRow][tempCol] = 'm';
            numMushrooms--;
        }
    }
    //fill blanks
    for (int i = 0; i < m_gridSize; i++){
        for (int j = 0; j < m_gridSize; j++){
            if (m_grid[i][j] == '\0'){
                m_grid[i][j] = 'x';
            }
        }
    }
}

/*
updateSquare method - changes the value of one element in the grid
params row and col (ints) - the coordinate of the element to be changed
param newVal (char) - the new character to occupy [row][col]
*/
void Level::updateSquare(int row, int col, char newVal){
    m_grid[row][col] = newVal;
}

/*
getHeroRow method
returns the row value of the Hero's current location in the grid
*/
int Level::getHeroRow(){
    return m_heroRow;
}

/*
setHeroRow method
param row (int) - new row value of the Hero's location
*/
void Level::setHeroRow(int row){
    m_heroRow = row;
}

/*
getHeroCol method
returns the column value of the Hero's current location in the grid
*/
int Level::getHeroCol(){
    return m_heroCol;
}

/*
setHeroCol method
param col (int) - new column value of the Hero's location
*/
void Level::setHeroCol(int col){
    m_heroCol = col;
}

/*
getSize method
returns the length/width of the Level
*/
int Level::getSize(){
    return m_gridSize;
}

/*
at method
returns the character at a certain location in the grid
param row (int) - the row value of the element to be returned
param col (int) - the column value of the element to be returned
*/
char Level::at(int row, int col){
    return m_grid[row][col];
}

/*
placeHero method
returns the character that the Hero lands on after being placed
*/
char Level::placeHero(){
    char ret = m_grid[m_heroRow][m_heroCol];
    m_grid[m_heroRow][m_heroCol] = 'H';
    return ret;
}

/*
display method
returns a string that visually represents the grid
*/
std::string Level::display(){
    std::string result = "";
    for (int i = 0; i < m_gridSize; i++){
        for (int j = 0; j < m_gridSize; j++){
            result += m_grid[i][j];
            result += " ";
        }
        result += "\n";
    }
    return result;
}