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

int* Game::generateStack(int stackSize, std::string stackState, bool test) {

if(test == false) {
   //printw("Please specify initial stack order, i.e. 1, 2, 3, 4,.., n. Press enter for random order\n");

       int* finalStack = new int[stackSize];
       //std::string stackState = getString();       //string for getting user input

       if(stackState.size() == 0){                 //if user just puts enter...generate random order

           printw("initializing random initial stack\n");

           for(int i = 0; i < stackSize; i++){

               finalStack[i] = i + 1;              //fill with 1 - n for shuffle

           }

           finalStack = gen_rand_stack(finalStack, stackSize);     //shuffle the stack, i.e. random

       }

       else {
           printw("initializing predefined stack\n");
           int finalStackIterator = 0;                             //for iterating through the string, pulling ints
           for(int i = 0; i < stackState.size(); i++){              //iterate through the user input string

               int temp = stackState.at(i) - '0';

               if((temp >= 0) && (temp <= 9)) {                    //if the input is an int, put it into final stack order

                   finalStack[finalStackIterator] = temp;
                   finalStackIterator++;

               }
           }

           if (finalStackIterator != (stackSize)) {            //stacksize is 5 and user put 1 2 3 4 or something like that

               printw("Error, invalid number of arguments\n");
               return NULL;

           }

       }


   return finalStack;
}

else{
        stackSize = 5;
       int* finalStack = new int[stackSize];
        std::string stackState = "1 4 2 5 3";

       if(stackState.size() == 0){                 //if user just puts enter...generate random order

           //printw("initializing random initial stack\n");

           for(int i = 0; i < stackSize; i++){

               finalStack[i] = i + 1;              //fill with 1 - n for shuffle

           }

           finalStack = gen_rand_stack(finalStack, stackSize);     //shuffle the stack, i.e. random

       }

       else {
           //printw("initializing predefined stack\n");
           int finalStackIterator = 0;                             //for iterating through the string, pulling ints
           for(int i = 0; i < stackState.size(); i++){              //iterate through the user input string

               int temp = stackState.at(i) - '0';

               if((temp >= 0) && (temp <= 9)) {                    //if the input is an int, put it into final stack order

                   finalStack[finalStackIterator] = temp;
                   finalStackIterator++;

               }
           }

           if (finalStackIterator != (stackSize)) {            //stacksize is 5 and user put 1 2 3 4 or something like that

               printw("Error, invalid number of arguments\n");
               return NULL;

           }

       }


   return finalStack;

}
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
//will return -1 if the game is not over, returns score otherwise
int Game::computeScore()
{
	int size = human.getStackSize();
	int difficulty = ai.getDifficulty();
	bool userSorted = checkStackOrder(human.getStack(), size);
	bool aiSorted = checkStackOrder(ai.getStack(), size);
	if(userSorted && aiSorted)
		return size*(difficulty+1);
	else if(aiSorted && !userSorted)
		return size;
	else if(!aiSorted && userSorted)
		return 2*size*(difficulty+1);
	else
		return -1;
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
		scoreFile<<user<<"\t"<<"0"<<"\n";
		return user+ " 0";
	}
}

int* Game::gen_rand_stack(int* stack, int stackSize) {

   std::default_random_engine randomEngine(std::time(nullptr));            //random engine for running shuffle function
   int* resultStack = new int[stackSize];
   resultStack = stack;
   std::shuffle(&stack[0], &stack[stackSize], randomEngine);               //shuffle the stack
   return resultStack;

}

vector<std::string> stackToString(int* stack, int stackSize) {

    vector<std::string> stringStack

    for(int i = 0; i < stackSize; i++){
        
        int pancakeSize = stack[i];
        std::string pancakeString = "+";
        for(int k = 0; k < (2*pancakeSize - 1); k++) {

            pancakeString = pancakeString + "-";

        }

        pancakeString = pancakeString + "+/n|";

        for(int k = 0; k < (2*pancakeSize - 1); k++) {

            pancakeString = pancakeString + " ";

        }

        pancakeString = pancakeString + "|/n+";

        for(int k = 0; k < (2*pancakeSize - 1); k++){

            pancakeString = pancakeString + "-";

        }

        pancakeString = pancakeString + "+/n";

        stringStack.push_back(pancakeString);

    }

    return stringStack;

}

/*
Game::~Game() {
    // Implementation...
}
*/