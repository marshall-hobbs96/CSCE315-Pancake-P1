/*
CSCE 315 503
Project 3
Group 17

Abdul Campos
Marshall Hobbs
McLain Johnson
Troy Fulton

GaphicsEngine.h - Interface for the Graphics Engine class
*/

#ifndef __GRAPHICS__        // For #including more than once
#define __GRAPHICS__

/************************************************
 *  INCLUDES
 ***********************************************/
#include <iostream>
#include "Game.h"

/************************************************
 * Main Class
 ***********************************************/

class GraphicsEngine {
private:
    Game curr_game;

    // Helpers for drawing certain screens:
    void drawInstructions();      // to show the player how to play
    void drawScores(std::string scores);

    // Facilitating gameplay in playGame:
    void drawStack(int* stack, int sz);
    int getFlipSelection();
    void blinkPancakes(int p);    // blink pancakes at and above pancake p


public:

    // Constructor:
    GraphicsEngine(Game g);
    GraphicsEngine();

    // For drawing various screens:
    void drawSplashScreen();
    void drawDifficultyScreen();
    void drawOrderScreen();
    void drawScoresScreen();
    void drawEndScreen();

    // For getting input from various screens:
    bool getSplashInput();
    int* getDifficultyInput();      // Always returns [stack_size, ai_difficulty]
                                    // so size of next array is determined...
    int* getOrderInput();
    std::string getScoresInput();
    bool getEndInput();

    // Facilitating gameplay:
    bool playGame();
    void startGame(int num_pancakes, int ai_difficulty, std::string fn);
};



#endif