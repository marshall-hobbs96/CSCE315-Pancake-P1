/*
CSCE 315 503
Project 3
Group 17

Abdul Campos
Marshall Hobbs
McLain Johnson
Troy Fulton

GraphicsEngine.cpp - Implementations for Engine methods for running the game and
        drawing the state to the screen. Includes methods for drawing specific
        screens, getting input from those screens, and facilitation of the gameplay.
        Uses ncurses to draw to the terminal window.
*/

#include "GraphicsEngine.h"

/*****************************************************
 * PRIVATE / PROTECTED METHODS
 ****************************************************/

/* Helpers for drawing certain screens */

// to show the player how to play
void GraphicsEngine::drawInstructions() {
    // Implementation
}     

// to report the high scores before and after the game
void GraphicsEngine::drawScores(std::string scores) {
    // Implementation
}     

/* Facilitating gameplay in playGame */

void GraphicsEngine::drawStack(int* stack, int sz) {
    // Implementation
}     

int GraphicsEngine::getFlipSelection() {
    // Implementation
    return 0;
}

void GraphicsEngine::blinkPancakes(int p) {
    // Implementation
}     

/*****************************************************
 * PUBLIC METHODS
 ****************************************************/

/* For drawing various screens */

void drawSplashScreen() {
    // Implementation
}     

void drawDifficultyScreen() {
    // Implementation
}     

void drawOrderScreen() {
    // Implementation
}     

void drawScoresScreen() {
    // Implementation
}     

void drawEndScreen() {
    // Implementation
}     

/* For getting input from various screens */

bool getSplashInput() {
    // Implementation
    return true;
}

int* getDifficultyInput() {
    // Always returns [stack_size, ai_difficulty]
    // so size of next array is determined...

    // Implementation...
    return NULL;
}      
                                
int* getOrderInput() {
    // Implementation
    return NULL;
}     

std::string getScoresInput() {
    // Implementation
    return "";
}     

bool getEndInput() {
    // Implementation
    return true;
}     


/* Facilitating gameplay */

bool playGame() {
    // Implementation
    return true;
}

void GraphicsEngine::startGame(int num_pancakes, int ai_difficulty, std::string fn) {
    // Pretty straighforward...
}
