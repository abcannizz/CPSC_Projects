/*
Alex Cannizzaro
alexcannizzaro16@gmail.com
Course: CPSC-350-01 (Data Structures and Algorithms)
Programming Assignment 2: Not So Super Mario Bros
Header file for the Hero class - contains class definition and member function declarations
*/
#ifndef HERO_H
#define HERO_H

class Hero{
    public:
        //default constructor
        Hero();

        /*
        overloaded constructor
        param initialLives (int) - will be assigned as the Hero's number of lives
        */
        Hero(int initialLives);

        //default destructor
        ~Hero();

        /*
        getLives method
        returns the Hero's number of lives
        */
        int getLives();

        /*
        setLives method
        param numLives (int) - the Hero's new number of lives
        */
        void setLives(int numLives);

        /*
        getCoins method
        returns the Hero's number of coins
        */
        int getCoins();

        /*
        setCoins method
        param numCoins (int) - the Hero's new number of coins
        */
        void setCoins(int numCoins);

        /*
        getPL method
        returns the Hero's current power level
        */
        int getPL();

        /*
        setPL method
        param power (int) - the Hero's new power level
        */
        void setPL(int power);

        /*
        getWins method
        returns the Hero's number of wins
        */
        int getWins();

        /*
        setWins method
        param numWins (int) - the Hero's new number of wins
        */
        void setWins(int numWins);

    private:
        int m_numLives;  //the Hero's current number of lives
        int m_coinCount;  //the Hero's current number of coins
        int m_powerLevel;  //the Hero's current power level
        int m_winCount;  //the Hero's current tally of wins
};

#endif