/*
CSCE 315 503
Project 3
Group 17

Abdul Campos
Marshall Hobbs
McLain Johnson
Troy Fulton

Game.cpp - Implementations for Game methods for running the game and
        reporting the state of the game. Includes methods for reporting
        each player's stack, signaling moves, and dealing with the high
        scores file.
*/

#include "Game.h"

using namespace std;

/*****************************************************
 * PRIVATE / PROTECTED METHODS
 ****************************************************/

bool Game::checkStackOrder(int* stack, int sz) {
    // Implementation...
    return true;
}

/*****************************************************
 * PUBLIC METHODS
 ****************************************************/

/* For starting the game */

Game::Game(int num_pancakes, int ai_difficulty, std::string fn, int* starting_order) :
    human(num_pancakes, starting_order, ""), ai(num_pancakes, starting_order, ai_difficulty),
    human_score(0), stack_size(num_pancakes)    {}

int* Game::generateStack(int size, int* set_order = NULL) {
    // Implementation...
    return NULL;
}

int* Game::getHumanStack() {
    // Implementation...
    return NULL;
}

int* Game::getAIStack() {
    // Implementation...
    return NULL;
}

int Game::getStackSize() {
    // Implementation...
    return 0;
}

// For getting the result of AI.calculateMove()
int Game::getAIMove() {
    // Implementation...
    return 0;
}

/* For the gameplay loop */

void Game::moveHuman(int pancake) {
    // Implementation...
}

void Game::moveAI(int pancake) {
    // Implementation...
}

bool Game::checkWin() {
    // Implementation...
    return true;
}

// For when the game is over:

int Game::computeScore() {
    // Implementation...
    return 0;
}

string Game::getHighScores() {
    // Implementation...
	fstream scoreFile;
	
	//open file if it exists
	scoreFile.open(filename, fstream::in);
	string scores = "";

	if(scoreFile.is_open())
	{		
		for(int i=0; i<5; i++)
		{
			string name,score;
			getline(scoreFile,name);
			getline(scoreFile,score);
			//print to ncurses
			string line =name+" "+score;
			scores += line + "\n";
			//screenPrompt(line, i-9);
		}	
	}	
	//file does not exist
	else
	{
		// Report error
		//screenPrompt("No score file exists ", -10);		
	}

	scoreFile.close();	

	return scores;
}

/* For dealing with the high scores file */

string Game::findScore(string user)
{
	fstream scoreFile;
	bool scoreFound = false;
	string username;
	scoreFile.open(filename);
	
	while(getline(scoreFile,username))
	{	
		if(username==user)
		{
			string score;
			getline(scoreFile,score);
			return user +" "+score;
			scoreFound = true;
			break;
		}
	}
	scoreFile.close();
	if(!scoreFound)
	{
		scoreFile.open(filename, fstream::app);	
		scoreFile<<user<<"\n"<<"0"<<"\n";
		return user+ " 0";
	}
}


/*
Game::~Game() {
    // Implementation...
}
*/