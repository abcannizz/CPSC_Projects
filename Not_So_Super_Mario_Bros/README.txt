Alex Cannizzaro
alexcannizzaro16@gmail.com
Course: CPSC-350-01 (Data Structures and Algorithms)
Programming Assignment 2: Not So Super Mario Bros

Description:
    Simulates a text-based, mario-themed game, where levels are represented by grids.
    Randomly populates a grid with items, enemies, and warp pipes for each level.
    Statistics of the game are specified by integer values in an input file, input.txt.
    Runs a randomized simulation of a game with the specified statistics and outputs 
    a log of the results to a text file, outut.txt.

Source files included:
    Level.h
    Level.cpp
    Hero.h
    Hero.cpp
    Game.h
    Game.cpp
    main.cpp
    input.txt

Instructions:
    Compile:
        g++ *.cpp -o mario
    Run:
        ./mario input.txt
    Contents of input.txt (integers only):
        Number of levels
        Level Size
        Number of lives
        Coin probability
        Blank space probability
        Goomba probability
        Koopa probability
        Mushroom probability

References:
    https://cplusplus.com/reference/cstdlib/rand/
    https://stackoverflow.com/questions/11943525/seeding-a-random-number-generator-c
    I worked on portions of this assignment with classmate Ross Ziegler.