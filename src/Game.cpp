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

bool Game::checkStackOrder(int *stack, int size)
{
	bool sorted =true;
	int sizeStack = size;
	for(int i =0; i<sizeStack; i++)
	{
		if(stack[i]!=(sizeStack-i))
			sorted = false;
	}
	return sorted;
}



/*****************************************************
 * PUBLIC METHODS
 ****************************************************/

/* For starting the game */

Game::Game(int num_pancakes, int ai_difficulty, std::string fn, int* starting_order) :
    human(num_pancakes, starting_order, ""), ai(num_pancakes, starting_order, ai_difficulty),
    human_score(0), stack_size(num_pancakes), filename(fn)    {}


int* Game::getHumanStack() {
    return human.getStack();
}

int* Game::getAIStack() {
    return ai.getStack();
}

int Game::getStackSize() {
    // Implementation...
    return 0;
}

// For getting the result of AI.calculateMove()
int Game::getAIMove() {
    return ai.calculateMove();
}

/* For the gameplay loop */

void Game::moveHuman(int pancake) {
    human.makeMove(pancake);
}

void Game::moveAI(int pancake) {
    ai.makeMove(pancake);
}

bool Game::checkWin() {
    // Implementation...
    return computeScore(getDifficulty(), getStackSize(), getHumanStack(), getAIStack()) != -1;
}


int Game::getDifficulty()
{
	return ai.getDifficulty();
}
// For when the game is over:
//will return -1 if the game is not over, returns score otherwise


int Game::computeScore(int diff, int n, int* userS, int* aiS)
{
	int size = n;
	int difficulty = diff;
	bool userSorted = checkStackOrder(userS, size);
	bool aiSorted = checkStackOrder(aiS, size);
	if(userSorted && aiSorted)
	{
		human_score = size*(difficulty+1);
		return human_score;
	}
	else if(aiSorted && !userSorted)
	{
		human_score = size;
		return human_score;
	}
	else if(!aiSorted && userSorted){
		human_score = 2*size*(difficulty+1);
		return human_score;
	}
	else
	{
		human_score =  -1;
		return human_score;
	}
}

string Game::getHighScores() {
    // Implementation...
	ifstream scoreFile;

	//open file if it exists
	scoreFile.open(filename, fstream::in);
	string scores;
	if(scoreFile.is_open())
	{
		for(int i=0; i<5; i++)
		{
			string name,score;
			getline(scoreFile,name);
			getline(scoreFile,score);
			string line = name + " " + score;
			scores = scores + "\n" + line;
		}
	}

	scoreFile.close();
	return scores;
}

/* For dealing with the high scores file */

void Game::writeScore()
{
	//not implemented

}

int* Game::gen_rand_stack(int* stack, int stackSize) {

   std::default_random_engine randomEngine(std::time(nullptr));            //random engine for running shuffle function
   int* resultStack = new int[stackSize];
   resultStack = stack;
   std::shuffle(&stack[0], &stack[stackSize], randomEngine);               //shuffle the stack
   return resultStack;

}

vector<std::string> Game::stackToString(int* stack, int stackSize) {

    vector<std::string> stringStack;

    for(int i = 0; i < stackSize; i++){

	std::string pancakeString;
	
		for(int k = 0; k < 9 - stack[i]; k ++) {
			
			pancakeString = pancakeString + " ";
			
		}
		
        int pancakeSize = stack[i];
        pancakeString = pancakeString + "+";
        for(int k = 0; k < (2*pancakeSize - 1); k++) {

            pancakeString = pancakeString + "-";

        }

        pancakeString = pancakeString + "+";
		
		for(int k = 0; k < 9 - stack[i]; k++){
			
			pancakeString = pancakeString + " ";
			
		}

        stringStack.push_back(pancakeString);
		pancakeString = "";
		
		for(int k = 0; k < 9 - stack[i]; k ++) {
			
			pancakeString = pancakeString + " ";
			
		}
		
        pancakeString = pancakeString + "|";

        for(int k = 0; k < ((pancakeSize - 1)); k++) {

            pancakeString = pancakeString + " ";

        }

        char number = stack[i] + '0';
        pancakeString = pancakeString + number;


        for(int k = 0; k < ((pancakeSize - 1)); k++) {

            pancakeString = pancakeString + " ";

        }

        pancakeString = pancakeString + "|";
		
		for(int k = 0; k < 9 - stack[i]; k ++) {
			
			pancakeString = pancakeString + " ";
			
		}
		
        stringStack.push_back(pancakeString);
		pancakeString = "";
		
		for(int k = 0; k < 9 - stack[i]; k ++) {
			
			pancakeString = pancakeString + " ";
			
		}
		
        pancakeString = pancakeString + "+";

        for(int k = 0; k < (2*pancakeSize - 1); k++){

            pancakeString = pancakeString + "-";

        }

        pancakeString = pancakeString + "+";
		
		for(int k = 0; k < 9 - stack[i]; k ++) {
			
			pancakeString = pancakeString + " ";
			
		}

        stringStack.push_back(pancakeString);
        pancakeString = "";

    }

    return stringStack;

}


int Game::getScore()
{
	return this->human_score;
}
/*
Game::~Game() {
    // Implementation...
}
*/
