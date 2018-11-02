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
    int row,col;
    getmaxyx(stdscr,row,col);
    //print screen title
    std::string mesg ="INSTRUCTIONS";
    screenPrompt(mesg,0);
    mesg = "You and an Artificial Intelligence player will be given two versions";
    screenPrompt(mesg,1);
    mesg = "of the same stack of pancakes. Your goal is to sort the pancakes from top to bottom";
    screenPrompt(mesg,2);
    mesg = "(meaning the smallest pancake will be on the top and the largest on bottom).";
    screenPrompt(mesg,3);
    mesg = "To do this, you will insert a spatula under any of the pancakes in the stack and";
    screenPrompt(mesg,4);
    mesg = "'flip' the pancakes at and above that pancake. The blinking pancake will";
    screenPrompt(mesg,5);
    mesg = "indicate which pancake your curser is on, and hitting ENTER will select";
    screenPrompt(mesg,6);
    mesg = "the pancake and flip the pancakes at and above that pancake after blinking for";
    screenPrompt(mesg,7);
    mesg = "a few seconds. Here is an example pancake of size 6:";
    screenPrompt(mesg,8);
    mesg = "+-----------+";
    screenPrompt(mesg,10);
    mesg = "|     6     |";
    screenPrompt(mesg,11);
    mesg = "+-----------+";
    screenPrompt(mesg,12);
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

void GraphicsEngine::drawStack(vector<std::string> stringStack, WINDOW* window, int blinkFrom) {
    

    if (blinkFrom != -1)
        attrset(A_BLINK | A_BOLD);
        
    for(int i = 0; i < stringStack.size(); i++ ){
        if (i == blinkFrom - 1) {
            attroff(A_BLINK);
            attroff(A_BOLD);
        }
        int rows, cols;
	    getmaxyx(window, rows, cols);
	    std::string the_string = stringStack.at(i);
        mvwprintw(window, i + 2, cols / 4, "%s", the_string.c_str());

    }

    
    return;


}   
/*
void GraphicsEngine::drawStack(std::string stringStack, int stackSize, WINDOW* window, int blinkFrom) {
    
    for(int i = stackSize - 1; i >= 0; i-- ){
        if (i == blinkFrom) 
            attrset(A_BLINK | A_BOLD);
        mvwprintw(window, 0, 0, "%s", stringStack[i]);
    }
    attroff(A_BLINK);
    attroff(A_BOLD);
    return;
}  */

void GraphicsEngine::drawSelectionStack(WINDOW* stack_win, int highlight, int n_choices) {
    //std::string choices[] = {"REPLACE"};
    //std::string choices[] = curr_game.stackToString(curr_game.getHumanStack(), curr_game.getStackSize());
    //char* choices = 
    vector<std::string> choices;
    choices = curr_game.stackToString(curr_game.getHumanStack(),curr_game.getStackSize());

    /*char choices[curr_game.getStackSize()];
    for (int i = 0; i < curr_game.getStackSize(); ++i) {
        choices[i] = s_choices.at(i).c_str();
    }*/


    int x, y, i;	

	x = 2;
	y = 2;
	box(stack_win, 0, 0);
	for(i = 0; i < n_choices; ++i) {
        if(highlight == i + 1) {
            wattron(stack_win, A_REVERSE); 
            mvwprintw(stack_win, y, x, "%s", choices[i].c_str());
            wattroff(stack_win, A_REVERSE);
        } else {
            mvwprintw(stack_win, y, x, "%s", choices[i].c_str());
        }
        ++y;
	}
	wrefresh(stack_win);


} 

int GraphicsEngine::getFlipSelection(WINDOW* window) {
    // Implementation
    // comment test
    //char* choices[] = 
    vector<std::string> choices;
    choices = curr_game.stackToString(curr_game.getHumanStack(),curr_game.getStackSize());
    int n_choices = (this->curr_game.getStackSize()) + 1;
    int highlight = 1;
	int choice = 0;
	int c;

    clear();
	noecho();
	cbreak();

    keypad(window, TRUE);
    mvprintw(0, 0, "Use the Arrow Keys (or WASD) to go up and down, then Press Enter to select a Pancake to insert the spatula below to flip:");
    refresh();
    drawSelectionStack(window, highlight, n_choices);

    while(1) {	
        c = wgetch(window);
		switch(c) {	
            case KEY_UP:
				if(highlight == 1)
					highlight = n_choices;
				else
					--highlight;
				break;
			case KEY_DOWN:
				if(highlight == n_choices)
					highlight = 1;
				else 
					++highlight;
				break;
			case 119:
				if(highlight == 1)
					highlight = n_choices;
				else
					--highlight;
				break;
			case 115:
				if(highlight == n_choices)
					highlight = 1;
				else 
					++highlight;
				break;
			case 10:
				choice = highlight;
				break;
			default:
				mvprintw(24, 0, "character digit: %3d, key: '%c'", c, c);
				refresh();
				break;
		}
        if(choice != 0)
			break;
    }
    mvprintw(23, 0, "You chose Pancake %d with index %d\n", choice,highlight);
    //blink pancakes,
    drawStack(choices, window, highlight); //blink pancakes
    timeout(3); //blink for 3 seconds
    this->curr_game.moveHuman(highlight);
    drawStack(choices, window,highlight); //draw updated stack
    mvprintw(20, 0, "Press any key to ");
    getch(); //wit for keypress for testing purposes

    // makeMove


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
    mesg = "****** Team 17 ******";
    screenPrompt(mesg,2);
    mesg = "Members:";
    screenPrompt(mesg,4);
    mesg = "Abdul Campos, Troy Fulton, Marshall Hobbs, McLain Johnson";
    screenPrompt(mesg,5);
    mesg = "Press ENTER to Start: ";
    screenPrompt(mesg,8);
    //int wattron(WINDOW *win, int attr);
    attrset(A_BLINK | A_BOLD);
    addstr("ENTER\n");
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
  echo();
  std::string scores = curr_game.getHighScores();
	//print screen title
	screenPrompt("Top 5 Scores", -10);
	screenPrompt(scores, -9);
}

void GraphicsEngine::drawEndScreen() {
  //in game: username and score
  //print username and scores
  screenPrompt(curr_game.username + " " + to_string(curr_game.getScore()),0);
  curr_game.writeScore();
}

/* For getting input from various screens */

bool GraphicsEngine::getSplashInput() {
    // hitting enter
    getch();

    // Clear the screen
    clear();

    // Show instructions and wait for another "ENTER"
    drawInstructions();
    getch();

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
  drawScoresScreen();
  //replace for requesting user input
  screenPrompt("Enter your intials ", 6);
  char str[80];
  getstr(str);
  std::string initials = std::string(str);
  curr_game.username = initials;
  screenPrompt(initials+": 0",0);
  return initials;
}

bool GraphicsEngine::getEndInput() {
    // Implementation
    drawEndScreen();

    return false;
}


/* Facilitating gameplay */

/*
bool GraphicsEngine::playGame(WINDOW* player_window, WINDOW* ai_window) {

    while (curr_game.checkWin()) {
        int player_selection = getFlipSelection();
        //drawStack(g.stackToString(g.getHumanStack(), g.getStackSize()), player_window, player_selection);
        // or blinkStack(player_selection);
        curr_game.moveHuman(player_stack);
        // redraw the human stack
        int AI_selection = curr_game.getAIMove();
        // blink the AI stack
        curr_game.moveAI(AI_selection);
        // redraw the ai stack
    }

    return getEndInput();
}

*/

bool GraphicsEngine::playGame() {

    bool is_playing = true;

    while (is_playing) {

    }

    int score = curr_game.computeScore(curr_game.getDifficulty(), curr_game.getStackSize(), curr_game.getHumanStack(), curr_game.getAIStack());




    int score = curr_game.computeScore(curr_game.getDifficulty(), curr_game.getStackSize(), curr_game.getHumanStack(), curr_game.getAIStack());
    if(score!= -1)
    {
      return false;
    }
    else
      return true;
}

void GraphicsEngine::startGame(int num_pancakes, int ai_difficulty, std::string fn, int* starting_order) {
    delete curr_game;
    curr_game = Game(num_pancakes, ai_difficulty, fn, starting_order);
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
