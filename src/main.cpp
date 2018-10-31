/*
CSCE 315 503
Project 3
Group 17

Abdul Campos
Marshall Hobbs
McLain Johnson
Troy Fulton

main.cpp - contains main() for instantiating a graphics engine and 
        running the game for as many games as the player wants to play
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
    // Game g created so the scores file can be read from
    Game g(5, 3, "scores.txt", NULL);

    initscr();

    // Then use it to make a graphics engine
    GraphicsEngine ge(g);
    bool keep_playing = true, new_game = true;
    
    // Splash Screen
    ge.drawSplashScreen();
    ge.getSplashInput();
    // ...which eventually calls ge.drawInstructions();

    clear();
    
    while (new_game) {

        while (keep_playing) {
            ge.drawDifficultyScreen();
            int* diff = ge.getDifficultyInput(false, '3', '2');   // size defined above main
            
            clear();

            ge.drawOrderScreen();
            string order = ge.getOrderInput();

            //***********************************Initialize two subscreens for displaying pancakes

            //WINDOW* left_window = createnew_win(LINES / 2, COLS / 2, 0, 0);
            //WINDOW* right_window = createnew_win(LINES / 2, COLS / 2, 0, COLS / 2);
            //ge.drawStack(stackToString(g.getHumanStack(), g.getStackSize()), g.getStackSize(), left_window);
            //ge.drawStack(stackToString(g.getHumanStack(), g.getStackSize()), g.getStackSize(), right_window);

            // Instantiates a new inaccessible game object, ignoring the previous dummy
            //ge.startGame(order[0], order[1], "filename");       // filename hardcoded?
            
            clear();

            ge.drawScoresScreen();
            std::string username = ge.getScoresInput();

            keep_playing = ge.playGame();
        }

        // Inside:
        // printHighScores(curr_game.getHighScores);
        ge.drawEndScreen();
        new_game = ge.getEndInput();
    }
    
    
    getch();
    
    endwin();

    return 0;
}