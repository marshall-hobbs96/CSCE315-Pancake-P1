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

void GraphicsEngine::screenPrompt(std::string text, int line)
{
	int row,col;
	getmaxyx(stdscr,row,col);	
	char mesg1[text.size()+1];
	strcpy(mesg1, text.c_str());
	mvprintw(row/2+line,(col-sizeof(mesg1))/2,"%s",mesg1);
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

/* Default Constructor creates a dummy game with the file name so it can get scores */
GraphicsEngine::GraphicsEngine(Game g) :
    curr_game(g) {}
    
GraphicsEngine::GraphicsEngine() : curr_game(5, 3, "scores.db", NULL) {
}

/* For drawing various screens */

void GraphicsEngine::drawSplashScreen() {
    // Implementation
    /*
    printw("Enter something");
    refresh();
    getch();
    refresh();
    */
}     

void GraphicsEngine::drawDifficultyScreen() {
    // Implementation
}     

void GraphicsEngine::drawOrderScreen() {
    // Implementation
}     

void GraphicsEngine::drawScoresScreen(std::string scores) {
    // Implementation

	//print screen title
	screenPrompt("Top 5 Scores", -10);
	screenPrompt(scores, -9);

    //replace for requesting user input
    screenPrompt("Enter your intials ", 6);
    
    char str[80];
    getstr(str);
    std::string initials = std::string(str);
    
    screenPrompt("Your score: "+curr_game.findScore(initials),0);
	
}     

void GraphicsEngine::drawEndScreen() {
    // Implementation
}     

/* For getting input from various screens */

bool GraphicsEngine::getSplashInput() {
    // Implementation
    return true;
}

int* GraphicsEngine::getDifficultyInput() {
    // Always returns [stack_size, ai_difficulty]
    // so size of next array is determined...

    // Implementation...
    return NULL;
}      
                                
int* GraphicsEngine::getOrderInput() {
    // Implementation
    return NULL;
}     

std::string GraphicsEngine::getScoresInput() {
    // Implementation
    return "";
}     

bool GraphicsEngine::getEndInput() {
    // Implementation
    return false;
}     


/* Facilitating gameplay */

bool GraphicsEngine::playGame() {
    // Implementation
    return true;
}

void GraphicsEngine::startGame(int num_pancakes, int ai_difficulty, std::string fn) {
    // Pretty straighforward...
}