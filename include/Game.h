/*
CSCE 315 503
Project 3
Group 17

Abdul Campos
Marshall Hobbs
McLain Johnson
Troy Fulton

Game.h - Interface for the Game class
*/

#ifndef __GAME__        // For #including more than once
#define __GAME__

/************************************************
 *  INCLUDES
 ***********************************************/
#include <iostream>
#include "Player.h"
#include "AI.h"
#include <random>
#include <algorithm>
#include <chrono>

/************************************************
 * Main Class
 ***********************************************/

class Game {
private:

    Player human;
    AI ai;
    std::string filename;
    int human_score;
    int stack_size;     // new

    // To check if a stack is in order (for checkWin and generateStack)
    bool checkStackOrder(int* stack, int sz);

public:

    // For starting the game:
    Game(int num_pancakes, int ai_difficulty, std::string fn, int* starting_order);
    int* generateStack(int stackSize, std::string stackState, bool test == false);

    // For getting the state of each stack before and after each move:
    int* getHumanStack();
    int* getAIStack();
    int getStackSize();
    int getAIMove();         // For getting the result of AI.calculateMove()

    // For gameplay loop:
    void moveHuman(int pancake);
    void moveAI(int pancake);
    bool checkWin();
    
    // For when the game is over:
    int computeScore();
    std::string getHighScores();
    //~Game();

	// For dealing with the high scores file
	std::string findScore(std::string user);
};

#endif