/*
CSCE 315 503
Project 3
Group 17

Abdul Campos
Marshall Hobbs
McLain Johnson
Troy Fulton

AI.h - Interface for the Artificial Intelligence Player class
*/

#ifndef __AI__        // For #including more than once
#define __AI__

/************************************************
 *  INCLUDES
 ***********************************************/
#include <iostream>
#include <map>
#include "Player.h"

/************************************************
 * Supporting Class
 ***********************************************/

class Utility : public Player {
    
public:
    Utility();

    int operator()(int* temp_stack, int size);
} 

/************************************************
 * Main Class
 ***********************************************/

class AI : public Player {
private:
    std::map<int, int> tree;    // Not sure how this will be implemented...
    int difficulty;

public:
    // For the AI to decide under which pancake to flip:
    int calculateMove();

    AI(int num_pancakes, int* order, int diff);
};

#endif