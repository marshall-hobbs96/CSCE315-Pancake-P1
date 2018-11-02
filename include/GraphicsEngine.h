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
	void screenPrompt(std::string text, int line);

    // Facilitating gameplay in playGame:
    int getFlipSelection();
    void blinkPancakes(int p);    // blink pancakes at and above pancake p

public:

    // Constructor:
    GraphicsEngine(Game g);
    GraphicsEngine();
    void drawStack(vector<std::string> stringStack, WINDOW *window);

    // For drawing various screens:
    void drawSplashScreen();
    void drawDifficultyScreen();
    void drawOrderScreen();
    void drawScoresScreen();
    void drawEndScreen();

    // For getting input from various screens:
    bool getSplashInput();
    bool isWithinRange(char arg, int a, int b);
    int* getDifficultyInput(bool test, char testA, char testB);      // Always returns [stack_size, ai_difficulty]
                                    // so size of next array is determined...
    std::string getOrderInput();
    std::string getScoresInput();
    bool getEndInput();

    // Facilitating gameplay:
    bool playGame();
    void startGame(int num_pancakes, int ai_difficulty, std::string fn);

    std::string getString();
};



#endif