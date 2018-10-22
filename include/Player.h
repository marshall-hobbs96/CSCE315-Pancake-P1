/*
CSCE 315 503
Project 3
Group 17

Abdul Campos
Marshall Hobbs
McLain Johnson
Troy Fulton

Player.h - Interface for the Player class
*/

#ifndef __PLAYER__        // For #including more than once
#define __PLAYER__

/************************************************
 *  INCLUDES
 ***********************************************/
#include <iostream>

/************************************************
 * Main Class
 ***********************************************/

class Player {
protected:
    int *stack;         // Pancake Stack size
    int stack_size;     // Number of Pancakes
    std::string username;

public:
    int* getStack();
    void makeMove(int pancake);     // Same "flipping" action for all players

    Player(int num_pancakes, int* order, std::string un);
};

#endif