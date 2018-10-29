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

void GraphicsEngine::drawStack(std::string stringStack) {
    

    printw("%s", stringStack);
    return;


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
    int row,col;
    getmaxyx(stdscr,row,col);    
    //print screen title
    std::string mesg ="Ultimate Pancake Flipper Simulator 2018";    
    screenPrompt(mesg,0);
    mesg = "Team 17: No More ncurses Pls";
    screenPrompt(mesg,2);
    mesg = "Members:";
    screenPrompt(mesg,4);
    mesg = "Abdul Campos, Troy Fulton, Marshall Hobbs, McLain Johnson";
    screenPrompt(mesg,5);
    mesg = "Press ENTER to Start...";
    screenPrompt(mesg,8);
    //int wattron(WINDOW *win, int attr);
    attrset(A_BLINK | A_BOLD);
    addstr("ENTER\n");
    getch();
    attroff(A_BLINK);
    attroff(A_BOLD);
}       

void GraphicsEngine::drawDifficultyScreen() {
    // Implementation
}     

void GraphicsEngine::drawOrderScreen() {
    // Implementation
}     

void GraphicsEngine::drawScoresScreen() {
    // Implementation

    echo();

    std::string scores = curr_game.getHighScores();

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

bool GraphicsEngine::isWithinRange(char arg, int a, int b) {
    int intArg = arg - '0';
    if (intArg >= a && intArg <= b)
        return true;
    return false;
}

int* GraphicsEngine::getDifficultyInput(bool test, char testA, char testB) {
    
    noecho();
    refresh();

    if (!test) {
        char c;
        printw("Enter a number of pancakes from 2 to 9: ");
        while(!isWithinRange((c = getch()),2,9)) {
            printw("%c\n",c);
            clear();
            printw("Enter a number of pancakes from 2 to 9: ");
            
        }
        int numCakes = c - '0';
        clear();
        printw("Enter a number of pancakes from 2 to 9: %d",numCakes);
        printw("\nEnter a difficulty level from 1 to %d: ",numCakes);

        while(!isWithinRange((c = getch()),1,numCakes)) {
            clear();
            printw("Enter a number of pancakes from 2 to 9: %d",numCakes);
            printw("\nEnter a difficulty level from 1 to %d: ",numCakes);
        }
        int diff = c - '0';
        static int result[2] = {numCakes,diff};

        return result;
    } else {
        if (isWithinRange(testA,2,9) && isWithinRange(testB,1,(testA - '0'))) {
            static int result[2] = {(testA - '0'), (testB - '0')};
            return result;
        } else {
            return NULL;
        }
    }
    
   return NULL;
}     
                                
std::string GraphicsEngine::getOrderInput() {

   printw("Please specify initial stack order, i.e. 1, 2, 3, 4,.., n. Press enter for random order\n");
   std::string stackState = getString();       //string for getting user input
   return stackState;

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
    return false;
}

void GraphicsEngine::startGame(int num_pancakes, int ai_difficulty, std::string fn) {
    // Pretty straighforward...
}

std::string GraphicsEngine::getString() {

   std::string input;

   nocbreak();
   echo();
   int ch = getch();

   while ( ch != '\n' )
   {
       input.push_back( ch );
       ch = getch();
   }

   return input;

}
