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

void Game::getHighScores() {
    // Implementation...
	fstream scoreFile; 
	string filename = "scores.txt";
	//debug
	/*
	if(argc==2)
	{
		filename = "scores_full.txt";
	}
	*/
	
	//open file if it exists
	scoreFile.open(filename);
	if(scoreFile.is_open())
	{
		scoreFile.close();
		//print to screen
		printHighScores(filename);
		
		//replace for requesting user input
		screenPrompt("Enter your intials ", 6);
		
		char str[80];
		getstr(str);
		string initials = string(str);
		
		screenPrompt("Your score: "+findScore(filename, initials),0);
		
	}	
	//file does not exist
	else
	{
		screenPrompt("No score file exists ", -10);
		createFile(filename);
		
	}
	
	screenPrompt("Press any key to continue ", +10);
	getch();
}



/*
Game::~Game() {
    // Implementation...
}
*/

/* For dealing with the high scores file */

	void createFile(string filename)
	{
		//create score file since it does not exist
		fstream scoreFile(filename, fstream::out);
		//print to screen
		
		screenPrompt("Enter your intials ", 1);			
		
		//request user input to create file
		char str[80];
		getstr(str);
		string initials = string(str);
		
		scoreFile<<initials<<"\n"<<"0"<<"\n";
		screenPrompt(initials+" 0", -9);
		scoreFile.close();
	}
	
	string findScore(string filename, string user)
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
	
}