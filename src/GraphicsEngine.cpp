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

void GraphicsEngine::drawScoresScreen(string filename) {
    // Implementation
	//print screen title
	screenPrompt("Top 5 Scores", -10);
	
	//print 5 top scores
	fstream scoreFile(filename, fstream::in);
	
	for(int i=0; i<5; i++)
	{
		string name,score;
		getline(scoreFile,name);
		getline(scoreFile,score);
		//print to ncurses
		string line =name+" "+score;
		screenPrompt(line, i-9);
	}
	scoreFile.close();
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
    return true;
}     


/* Facilitating gameplay */

bool GraphicsEngine::playGame() {
    // Implementation
    return true;
}

void GraphicsEngine::startGame(int num_pancakes, int ai_difficulty, std::string fn) {
    // Pretty straighforward...
}

void screenPrompt(string text, int line)
{
	int row,col;
	getmaxyx(stdscr,row,col);	
	char mesg1[text.size()+1];
	strcpy(mesg1, text.c_str());
	mvprintw(row/2+line,(col-sizeof(mesg1))/2,"%s",mesg1);
}