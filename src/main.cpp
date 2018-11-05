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
    GraphicsEngine ge;

    initscr();
    bool keep_playing = true;
    
    // Start with the splash screen
    ge.getSplashInput();

    // Game "count" for testing:
    int count = 0;

    while (keep_playing) {
        // Gets the size of the stack and the AI's difficulty:
        // diff is [stack_size, ai_difficulty]
        int* diff = ge.getDifficultyInput(false, '3', '2');   // size defined above main

        int* stack = ge.getOrderInput(diff[0]);

        // Instantiates a new inaccessible game object, ignoring the previous dummy
        ge.startGame(diff[0], diff[1], "filename", stack);       // filename hardcoded?

        std::string username = ge.getScoresInput();

        // Initialize two subscreens for displaying pancakes
        clear();
        WINDOW* left_window = newwin(LINES - 4, COLS / 2, 0, 0);
        WINDOW* right_window = newwin(LINES - 4, COLS / 2, 0, COLS / 2);
        refresh();
        ge.drawStack(ge.stackToString(stack, diff[0]), left_window, -1);
        ge.drawStack(ge.stackToString(stack, diff[0]), right_window, -1);
        getch();

        keep_playing = ge.playGame(left_window, right_window);
        clear();

        delete[] diff;
        delete[] stack;

        // Testing using 2 tests:
        count++;
        if (count == 2) break;
    }

    clear();
    printw("All done...");
    refresh();
    getch();
    endwin();
    return 0;
}