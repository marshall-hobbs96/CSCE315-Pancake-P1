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

int main() {
    // Game g created so the scores file can be read from
    Game g(5, 3, "scores.db", NULL);

    initscr();

    // Then use it to make a graphics engine
    GraphicsEngine ge(g);
    bool keep_playing = true, new_game = true;
    
    // Splash Screen
    ge.drawSplashScreen();
    ge.getSplashInput();
    // ...which eventually calls ge.drawInstructions();
    /*
    while (new_game) {

        while (keep_playing) {
            ge.drawDifficultyScreen();
            int* diff = ge.getDifficultyInput();   // size defined above main

            ge.drawOrderScreen();
            int* order = ge.getOrderInput();

            // Instantiates a new inaccessible game object, ignoring the previous dummy
            ge.startGame(order[0], order[1], "filename");       // filename hardcoded?

            ge.drawScoresScreen();
            std::string username = ge.getScoresInput();

            keep_playing = ge.playGame();
        }
    
        ge.drawEndScreen();
        new_game = ge.getEndInput();
    }
    */
    
    getch();
    
    endwin();

    return 0;
}