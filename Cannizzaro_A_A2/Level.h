/*
Alex Cannizzaro
Student ID: 2421315
acannizzaro@chapman.edu
CPSC-350-01
Programming Assignment 2: Not So Super Mario Bros
Header file for the Level class - contains class definition and member function declarations
*/
#ifndef LEVEL_H
#define LEVEL_H

#include <cstdlib>
#include <string>

class Level{
    public:
        //default constructor
        Level();

        /*
        overloaded constructor
        param dimension (int) - will be assigned as the legnth and width of the grid
        takes int parameters for the probability of:
        coins, empty spaces, goombas, koopas, and mushrooms
        param lastLevel - boolean that indicates weather this object is the last level in the world
        */
        Level(int dimension, int coinProb, int blankProb, int goombaProb, int koopaProb, int mushroomProb, bool lastLevel);

        //default destructor
        ~Level();

        /*
        populateGrid method - assigns values to each element of the grid
        takes int parameters for the probability of:
        coins, empty spaces, goombas, koopas, and mushrooms
        param lastLevel - boolean that indicates weather this object is the last level in the world
        */
        void populateGrid(int coinProb, int blankProb, int goombaProb, int koopaProb, int mushroomProb, bool lastLevel);

        /*
        updateSquare method - changes the value of one element in the grid
        params row and col (ints) - the coordinate of the element to be changed
        param newVal (char) - the new character to occupy [row][col]
        */
        void updateSquare(int row, int col, char newVal);

        /*
        getHeroRow method
        returns the row value of the Hero's current location in the grid
        */
        int getHeroRow();

        /*
        setHeroRow method
        param row (int) - new row value of the Hero's location
        */
        void setHeroRow(int row);

        /*
        getHeroCol method
        returns the column value of the Hero's current location in the grid
        */
        int getHeroCol();

        /*
        setHeroCol method
        param col (int) - new column value of the Hero's location
        */
        void setHeroCol(int col);

        /*
        getSize method
        returns the length/width of the Level
        */
        int getSize();

        /*
        at method
        returns the character at a certain location in the grid
        param row (int) - the row value of the element to be returned
        param col (int) - the column value of the element to be returned
        */
        char at(int row, int col);

        /*
        placeHero method
        returns the character that the Hero lands on after being placed
        */
        char placeHero();

        /*
        display method
        returns a string that visually represents the grid
        */
        std::string display();

    private:
        char** m_grid;  //the 2D array that represents the grid layout of the level
        int m_gridSize;  //the dimension of eavh array (length of one side of the grid)
        int m_heroRow;  //the row value of the Hero's current location
        int m_heroCol;  //the column value of the Hero's current location
};

#endif