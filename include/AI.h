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
using namespace std;

/************************************************
 * Main Class
 ***********************************************/

class AI : public Player {
private:
    int difficulty;

    class Helper {
        int operator()(vector<int> path);
    }

public:
    // For the AI to decide under which pancake to flip:
    int calculateMove();

    AI(int num_pancakes, int* order, int diff);
};

#endif