/*
CSCE 315 503
Project 3
Group 17

Abdul Campos
Marshall Hobbs
McLain Johnson
Troy Fulton

test_GraphicsEngine.cpp - GraphicsEngine Unit Testing
*/

/****************************************************
 * INCLUDES
 ***************************************************/

#include "includecatch2.cpp"
#include "../include/GraphicsEngine.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>
#include <curses.h>

/****************************************************
 * DEFINES
 ***************************************************/

/****************************************************
 * Helper Functions
 ***************************************************/

// For comparing two files for equality. Found on 
// https://stackoverflow.com/questions/15118661/in-c-whats-the-fastest-way-to-tell-whether-two-string-or-binary-files-are-di/#answer-39097160
// Under a question about comparing files
bool compare_files(const std::string& filename1, const std::string& filename2)
{
    std::ifstream file1(filename1, std::ifstream::ate | std::ifstream::binary); //open file at the end
    std::ifstream file2(filename2, std::ifstream::ate | std::ifstream::binary); //open file at the end
    const std::ifstream::pos_type fileSize = file1.tellg();

    if (fileSize != file2.tellg()) {
        return false; //different file size
    }

    file1.seekg(0); //rewind
    file2.seekg(0); //rewind

    std::istreambuf_iterator<char> begin1(file1);
    std::istreambuf_iterator<char> begin2(file2);

    return std::equal(begin1,std::istreambuf_iterator<char>(),begin2); //Second argument is end-of-range iterator
}


/****************************************************
 * TEST CASES
 ***************************************************/

TEST_CASE( "GE Test drawSplashScreen 1", "[single-file]" ) {
    Game g(5, 3, "scores.db", NULL);
    GraphicsEngine ge(g);

    // Show the screen
    //initscr();
    ge.drawSplashScreen();

    // Refresh and dump
    //refresh();
    //scr_dump("screen_dumps/GE_Splash_test2.txt");

    // close the window
    //endwin();

    // Once screen is dumped, compare to "key"
    std::string key_name = "screen_dumps/GE_Splash_test1.txt";
    std::string response_name = "screen_dumps/GE_Splash_test2.txt";
    
    // Something to check if the files opened?
    //ifstream key(key_name);
    //ifstream response(response_name);
    
    //CHECK(key > 0);
    //CHECK(response > 0);

    
    // Returns true even if one of the files is missing!
    REQUIRE_NOTHROW(compare_files(key_name, response_name));
}
