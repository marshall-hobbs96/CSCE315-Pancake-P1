/*
MAIN PSEUDOCODE
*/

/************************************************
 *  INCLUDES
 ***********************************************/
#include "GraphicsEngine.h"
#include <ncurses.h>

/************************************************
 *  DEFINES
 ***********************************************/
#define DIFF_SIZE 2

using namespace std;

int main() {
    // Dummy game for constructing Graphics Engine
    Game g(5, 3, "scores.txt", NULL);
    GraphicsEngine ge(g);

    initscr();
    bool keep_playing = true;
    
    // Start with the splash screen
    ge.getSplashInput();

    while (keep_playing) {
        // Gets the size of the stack and the AI's difficulty:
        // diff is [stack_size, ai_difficulty]
        int* diff = ge.getDifficultyInput(false, '3', '2');   // size defined above main

        string order = ge.getOrderInput();

        //***********************************Initialize two subscreens for displaying pancakes
        WINDOW* left_window = newwin(LINES / 2, COLS / 2, 0, 0);
        WINDOW* right_window = newwin(LINES / 2, COLS / 2, 0, COLS / 2);
        ge.drawStack(stackToString(g.getHumanStack(), g.getStackSize()), g.getStackSize(), left_window);
        ge.drawStack(stackToString(g.getHumanStack(), g.getStackSize()), g.getStackSize(), right_window);

        // Instantiates a new inaccessible game object, ignoring the previous dummy
        ge.startGame(order[0], order[1], "filename", stack);       // filename hardcoded?

        std::string username = ge.getScoresInput();

        keep_playing = ge.playGame(left_window, right_window);
    }
    
    getch();
    endwin();
    return 0;
}